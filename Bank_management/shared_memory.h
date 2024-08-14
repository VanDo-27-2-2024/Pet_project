#include <iostream>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>


class Shared_memory
{
    private:
        static int key_bank_mgr;


    public:
        Shared_memory()
        {

        }

        void* create_shared_memory(int _key = key_bank_mgr, int size_of_memory = 1024)
        {
            // create new object in shared memory

            // ftok to generate unique key
            key_t key = ftok("shmfile", _key);
            if (key == -1)
            {
                perror("ftok");
                exit(EXIT_FAILURE);
            }

            // shmget returns an identifier in shmid
            int shmid = shmget(key, size_of_memory, 0666 | IPC_CREAT);

            std::cout << "Shared memory is created !!!! \n Size of shared memory used: " << size_of_memory << std::endl;

            if (shmid == -1)
            {
                perror("shmget");
                exit(EXIT_FAILURE);
            }

            // Attach to shared memory
            void* shm_addr = shmat(shmid, nullptr, 0);
            if (shm_addr == (void*) -1)
            {
                perror("shmat");
                exit(EXIT_FAILURE);
            }

            return shm_addr;
        }
};
