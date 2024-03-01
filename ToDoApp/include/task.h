#include "common_type.h"

class task
{
    public:
        task(std::string _name, status_t _status);

        std::string get_task_name();

        void set_task_name(std::string _name);

        status_t get_task_status();

        void set_task_status(status_t _status);

    private:
        std::string name;
        status_t status;
};