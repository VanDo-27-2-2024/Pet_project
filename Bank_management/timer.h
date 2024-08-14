#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>

#include "common_type.cpp"
#include <thread>
#include <chrono>
#include "bank_management.h"


class timer
{
    private:


    public:
        void start_timer(int interval, timer_type type);
        void stop_timer(timer_type type);
};

class handler
{
    public:
        static void delete_transaction(int interval)
        {
            while(1)
            {
                std::this_thread::sleep_for(std::chrono::seconds(interval));

                bank_management* bank_mgr = bank_management::get_instance();
                std::vector<int> client_id_list = bank_mgr->get_client_id_list();

                for(auto id : client_id_list)
                {
                    Account* account = bank_mgr->get_account(id);
                    account->delete_numbers_transaction(1);
                }

                std::cout << "===== Delete traction =====\n";
            }
        }
};



#endif