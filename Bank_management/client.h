#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>

#include "common_type.cpp"

class Client
{
    private:
        int id;
        std::string name;

    public:
        void set_client_id(int _id)
        {
            id = _id;
        }

        int get_client_id()
        {
            return id;
        }

        std::string get_client_name()
        {
            return name;
        }

        void set_client_name(std::string _name)
        {
            name = _name;
        }
};

#endif