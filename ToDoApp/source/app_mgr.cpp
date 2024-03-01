#include "app_mgr.h"

void app_mgr::add_task(std::string _name, int _status_in_number)
{
    status_t task_status;

    switch (_status_in_number)
    {
        case 1:
            task_status = status_t::TO_DO;
            break;
        case 2:
            task_status = status_t::IN_PROGRESS;
            break;
        case 3:
            task_status = status_t::DONE;
            break;
        default:
            break;
    }

    task* new_task = new task(_name, task_status);
    task_list.push_back(new_task);
    std::cout << "Add task successfully!!! \n";
};

void app_mgr::display_task_list()
{
    std::cout << "==== Task list ===\n";

    int i = 1;
    std::vector<task*>::iterator it;
    for (it = task_list.begin(); it < task_list.end(); it++)
    {
        std::cout << i << ". " << (*it)->get_task_name() << " - status: " << (int)((*it)->get_task_status()) << "\n";
        i++;
    }
    std::cout << "==================== \n";
};

void app_mgr::delete_task_by_index(int index)
{
    std::vector<task*>::iterator it = task_list.begin();

    // free task object instance
    delete task_list[index - 1];
    task_list.erase(it + (index - 1));
    std::cout << "Delete task successfully!!! \n";
};

void app_mgr::update_task_name_by_index(int index, std::string _name)
{
    task_list[index - 1]->set_task_name(_name);
};

void app_mgr::update_task_status_by_index(int index, int _status_in_number)
{
    status_t task_status;

    switch(_status_in_number)
    {
        case 1:
            task_status = status_t::TO_DO;
            break;
        case 2:
            task_status = status_t::IN_PROGRESS;
            break;
        case 3:
            task_status = status_t::DONE;
            break;
        default:
            break;
    }
    task_list[index -1]->set_task_status(task_status);
};
