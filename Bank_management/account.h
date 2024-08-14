#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <mutex>

#include "client.h"
#include "common_type.cpp"

class Account
{
    private:
        int account_id;
        int balance;

        Client client;

        std::queue<TransRequest> history;
        std::mutex mtx; // Mutex to protect the transactions

    public:
        Account(int _balance, int _account_id, int _client_id, std::string _client_name)
        {
            balance = _balance;
            account_id = _account_id;

            client.set_client_id(_client_id);
            client.set_client_name(_client_name);
        }

        int get_account_id()
        {
            return account_id;
        }

        void set_account_id(int _new_account_id)
        {
            account_id = _new_account_id;
        }

        int get_balance()
        {
            return balance;
        }

        void set_balance(int _modify_value)
        {
            balance = balance + _modify_value;
        }

        Client get_client()
        {
            return client;
        }

        void add_transaction(TransRequest transReq)
        {
            std::lock_guard<std::mutex> lock(mtx);
            history.push(transReq);
        }

        void delete_numbers_transaction(int number)
        {
            std::lock_guard<std::mutex> lock(mtx);
            if (history.empty() != true)
            {
                for (int i = 0; i < number; i++)
                {
                    if (history.empty() == true)
                    {
                        return;
                    }
                    history.pop();
                }
            }
        }

        std::queue<TransRequest> get_tras_history()
        {
            std::lock_guard<std::mutex> lock(mtx);
            return history;
        }

};

#endif