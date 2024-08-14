#include <iostream>
#include <map>
#include <vector>
#include <string>

#include "common_type.cpp"
#include "bank_management.h"
#include "transaction.h"
#include "timer.h"

using namespace std;


void menu()
{
    cout << "Select one of the following:" << endl << endl;
    cout << "   W - Withdrawal" << endl;
    cout << "   D - Deposit" << endl;
    cout << "   N - New account" << endl;
    cout << "   B - Balance" << endl;
    cout << "   I - Account Info" << endl;
    cout << "   H - Account Info plus Account Transaction History" << endl;
    cout << "   C - Close Account (close but do not delete the account)" << endl;
    cout << "   R - Reopen a closed account" << endl;
    cout << "   X - Delete Account (close and delete the account from the database))" << endl;
    cout << "   Q - Quit" << endl;
};



int main()
{
    string choice;
    bool stop = false;

    int client_id = 0;
    std::string name;
    int account_id = 0;
    int balance = 0;

    

    do
    {
        cout << endl;
        menu();
        cout << "Your choice: ";
        cin >> choice;

        if (choice == "Q" || choice == "q")
        {
            stop = true;
        }
        else if (choice == "W" || choice == "w")
        {
            TransRequest transReq;
            transReq.type = TransType::WITHDRAW;

            cout << "Enter client ID \n";
            cin >> transReq.client_id;
            cout << "Enter passcode \n";
            cin >> transReq.passcode;
            cout << "Enter money to WITHDRAW \n";
            cin >> transReq.modify_value;

            Transaction* trans = Transaction::get_instance();
            trans->withdraw(transReq);
        }
        else if (choice == "D" || choice == "d")
        {
            TransRequest transReq;
            transReq.type = TransType::DEPOSIT;

            cout << "Enter client ID \n";
            cin >> transReq.client_id;
            cout << "Enter passcode \n";
            cin >> transReq.passcode;
            cout << "Enter money to DEPOSIT \n";
            cin >> transReq.modify_value;

            Transaction* trans = Transaction::get_instance();
            trans->deposit(transReq);
        }
        else if (choice == "N" || choice == "n")
        {
            int client_id = 0;
            std::string name;
            int account_id = 0;
            int balance = 0;

            cout << "Enter client ID: \n";
            cin >> client_id;
            cout << "Enter name: \n";
            cin >> name;
            cout << "Enter account ID: \n";
            cin >> account_id;
            cout << "Enter money for the balance: \n";
            cin >> balance;

            bank_management* bank_mgr = bank_management::get_instance();
            bank_mgr->add_account(balance, account_id, client_id, name);

            timer timer_ins;
            timer_ins.start_timer(30, timer_type::DELETE_TRASACTION);
        }
        else if (choice == "B" || choice == "b")
        {

        }
        else if (choice == "I" || choice == "i")
        {
            int client_id;
            std::cout << "Enter client ID: ";
            std::cin >> client_id;

            bank_management* bank_mgr = bank_management::get_instance();
            Account* account = bank_mgr->get_account(client_id);

            Client client = account->get_client();

            std::cout << client.get_client_id() << std::endl;
            std::cout << client.get_client_name() << std::endl;
            std::cout << account->get_account_id() << std::endl;
            std::cout << account->get_balance() << std::endl;

        }
        else if (choice == "H" || choice == "h")
        {
            int client_id;
            std::cout << "Enter client ID: ";
            std::cin >> client_id;

            bank_management* bank_mgr = bank_management::get_instance();
            Account* account = bank_mgr->get_account(client_id);
            Client client = account->get_client();

            std::cout << client.get_client_id() << std::endl;
            std::cout << client.get_client_name() << std::endl;
            std::cout << account->get_account_id() << std::endl;
            std::cout << account->get_balance() << std::endl;

            std::cout << "===== History traction =====\n";
            std::queue<TransRequest> history = account->get_tras_history();
            while (!history.empty())
            {
                std::cout << '\t' << "TYPE: " << (int)history.front().type << ", VALUE: " <<  (int)history.front().modify_value;
                history.pop();
            }
            cout << '\n';



        }
        else if (choice == "C" || choice == "c")
        {

        }
        else if (choice == "R" || choice == "r")
        {

        }
        else if (choice == "X" || choice == "x")
        {

        }
        else
        {
            cout << "Invalid choice, please try again." << endl;
        }
    } while (!stop);





    return 0;
}