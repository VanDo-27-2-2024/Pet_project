#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <map>
#include <vector>
#include <string>

#include "account.h"
#include "bank_management.h"
#include "common_type.cpp"


class Transaction
{
    private:
        static Transaction* instance;

    public:
        static Transaction* get_instance()
        {
            if(instance == nullptr)
            {
                instance = new Transaction;
            }

            return instance;
        };

        bool check_tras_request(int passcode, int client_id)
        {
            bank_management* bank_mgr = bank_management::get_instance();

            if (passcode != 1)
            {
                return false;
            }

            // check valid user_id
            if (bank_mgr->is_client_id_valid(client_id) == false)
            {
                std::cout << "client ID is invalid!!! \n";
                return false;
            }

            return true;
        }

        bool withdraw(TransRequest& transReq)
        {
            int client_id = transReq.client_id;
            TransType type = transReq.type;
            int passcode = transReq.passcode;
            int modify_value = transReq.modify_value;

            if(type != TransType::WITHDRAW)
            {
                std::cout << "Request is invalid!!!\n";
                return false;
            }

            if(check_tras_request(passcode, client_id) != true)
            {
                std::cout << "Request is invalid!!!\n";
                return false;
            }

            bank_management* bank_mgr = bank_management::get_instance();
            Account* account = bank_mgr->get_account(client_id);
            account->set_balance(0 - modify_value);

            // Store the transaction info
            account->add_transaction(transReq);

            std::cout << "Withdraw completed \n";

            return true;
        }

        bool deposit(TransRequest& transReq)
        {
            int client_id = transReq.client_id;
            TransType type = transReq.type;
            int passcode = transReq.passcode;
            int modify_value = transReq.modify_value;

            if(type != TransType::DEPOSIT)
            {
                std::cout << "Request is invalid!!!\n";
                return false;
            }

            if(check_tras_request(passcode, client_id) != true)
            {
                std::cout << "Request is invalid!!!\n";
                return false;
            }

            bank_management* bank_mgr = bank_management::get_instance();
            Account* account = bank_mgr->get_account(client_id);
            account->set_balance(modify_value);

            // Store the transaction info
            account->add_transaction(transReq);

            std::cout << "Deposit completed \n";

            return true;
        }
};

#endif
