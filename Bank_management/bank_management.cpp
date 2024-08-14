#ifndef BANK_MANAGEMENT_CPP
#define BANK_MANAGEMENT_CPP

#include <iostream>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "bank_management.h"


// Define static members
bank_management* bank_management::instance = nullptr;
Shared_memory bank_management::shared_memory;

bank_management* bank_management::get_instance()
{
    if(instance == nullptr)
    {
        // create new object in shared memory
        void* shm_addr = shared_memory.create_shared_memory();

        // Construct the object in shared memory using placement new
        // use new operator here will ensure constructor and destructor will be called when object is deleted
        // improve with directly casting the pointer on GeektoGeek page
        instance = new (shm_addr) bank_management();
    }

    return instance;
};

bool bank_management::is_client_id_valid(int id)
{
    auto it = clientID_to_account.find(id);
    if (it != clientID_to_account.end())
    {
        return true;
    }
    return false;
}

void bank_management::add_account(int _balance, int _account_id, int _client_id, std::string _client_name)
{
    if(is_client_id_valid(_client_id))
    {
        std::cout << "A account is already created with this client ID \n";
        return;
    }

    // create new object in shared memory
    void* shm_addr = shared_memory.create_shared_memory(_client_id);
    Account* account = new (shm_addr) Account(_balance, _account_id, _client_id, _client_name);

    clientID_to_account[_client_id] = account;

};

void bank_management::remove_account(int _client_id)
{
    //Account* account = clientID_to_account[_client_id];
    // bad code: in case the map do not have this id

    auto it = clientID_to_account.find(_client_id);
    if (it != clientID_to_account.end())
    {
        Account* account = it->second;

        // Detach from shared memory
        if (shmdt(account) == -1) {
            perror("shmdt");
        }

        // Optionally remove the shared memory segment
        key_t key = ftok("shmfile_account", _client_id);
        int shmid = shmget(key, sizeof(Account), 0666 | IPC_CREAT);
        if (shmid == -1)
        {
            perror("shmget");
        }
        else
        {
            if (shmctl(shmid, IPC_RMID, nullptr) == -1)
            {
                perror("shmctl");
            }
        }

        clientID_to_account.erase(_client_id);
    }
    else
    {
        std::cout << "Client_id not exist \n";
    }
};

Account* bank_management::get_account(int _client_id)
{
    Account* account = nullptr;

    auto it = clientID_to_account.find(_client_id);
    if (it != clientID_to_account.end())
    {
        account = it->second;
        return account;
    }
    else
    {
        std::cout << "Client_id not exist \n";
    }

    return account;

}

#endif
