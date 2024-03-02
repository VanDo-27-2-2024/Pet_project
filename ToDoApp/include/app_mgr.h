#include "common_type.h"
#include <fstream>
#include "task.h"

class app_mgr
{
    private:
        std::vector<task*> task_list;
        std::string profile_name;
        bool is_profile_exist;

    public:
        app_mgr();
        ~app_mgr();

        // CRUD
        void add_task(std::string _name, int _status_in_number);

        std::vector<task*> get_task_list();

        void display_task_list();

        void delete_task_by_index(int index);

        void update_task_name_by_index(int index, std::string _name);

        void update_task_status_by_index(int index, int _status_in_number);

        // Interface for manipulate the task profile
        std::string enum_to_string(status_t status);

        void save_profile();
};