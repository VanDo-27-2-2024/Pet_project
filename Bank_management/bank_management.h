#ifndef BANK_MANAGEMENT_H
#define BANK_MANAGEMENT_H

#include <iostream>
#include <map>
#include <vector>
#include <string>

#include "account.h"
#include "shared_memory.h"


class bank_management
{
    private:
        std::map <int, Account* > clientID_to_account; // map clientID with account
        static bank_management* instance;

        static Shared_memory shared_memory;

    public:
        bank_management()
        {
        }

        ~bank_management()
        {
            for (auto& pair : clientID_to_account)
            {
                Account* account = pair.second;

                // Detach from shared memory
                if (shmdt(account) == -1) {
                    perror("shmdt");
                }

                // Optionally remove the shared memory segment
                key_t key = ftok("shmfile_account", pair.first);
                int shmid = shmget(key, sizeof(Account), 0666 | IPC_CREAT);
                if (shmid == -1) {
                    perror("shmget");
                } else {
                    if (shmctl(shmid, IPC_RMID, nullptr) == -1) {
                        perror("shmctl");
                    }
                }
            }

            // Clear the account map
            clientID_to_account.clear();

            // Detach from shared memory for the bank_management instance
            if (shmdt(instance) == -1) {
                perror("shmdt");
            }

            // Optionally remove the shared memory segment for the bank_management instance
            key_t key = ftok("shmfile", 1001);
            int shmid = shmget(key, sizeof(bank_management), 0666 | IPC_CREAT);
            if (shmid == -1) {
                perror("shmget");
            } else {
                if (shmctl(shmid, IPC_RMID, nullptr) == -1) {
                    perror("shmctl");
                }
            }

            instance = nullptr;
        }

        static bank_management* get_instance();

        bool is_client_id_valid(int id);

        void add_account(int _balance, int _account_id, int _client_id, std::string _client_name);

        void remove_account(int client_id);

        std::vector<int> get_client_id_list()
        {
            std::vector<int> client_id_list;

            for (auto& pair : clientID_to_account)
            {
                client_id_list.push_back(pair.first);
            }

            return client_id_list;
        }

        Account* get_account(int client_id);
};

#endif // BANK_MANAGEMENT_H
