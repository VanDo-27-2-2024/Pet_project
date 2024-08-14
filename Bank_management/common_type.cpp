#ifndef COMMON_TYPE_H
#define COMMON_TYPE_H

#include <iostream>


enum class TransType
{
    INVALID,
    WITHDRAW,
    DEPOSIT,

};

struct TransRequest
{
    int client_id;
    TransType type;
    int passcode;
    int modify_value;
};

enum class timer_type
{
    DELETE_TRASACTION,
};



#endif
