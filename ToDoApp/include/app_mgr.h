#include "common_type.h"
#include "task.h"

class app_mgr
{
    private:
        std::vector<task*> task_list;

    public:
        // CRUD
        void add_task(std::string _name, int _status_in_number);

        std::vector<task*> get_task_list();

        void display_task_list();

        void delete_task_by_index(int index);

        void update_task_name_by_index(int index, std::string _name);

        void update_task_status_by_index(int index, int _status_in_number);
};