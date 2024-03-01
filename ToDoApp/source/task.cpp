#include "task.h"

task::task(std::string _name, status_t _status)
{
    name = _name;
    status = _status;
}

std::string task::get_task_name()
{
    return name;
};

void task::set_task_name(std::string _name)
{
    name = _name;
};

status_t task::get_task_status()
{
    return status;
};

void task::set_task_status(status_t _status)
{
    status = _status;
};
