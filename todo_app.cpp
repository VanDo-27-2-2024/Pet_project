#include <iostream>
#include <vector>
#include <string>


enum status_t
{
    TO_DO,
    IN_PROGRESS,
    DONE,
};

class task
{
    public:
        task(std::string _name, status_t _status)
        {
            name = _name;
            status = _status;
        }

        std::string get_task_name()
        {
            return name;
        };

        void set_task_name(std::string _name)
        {
            name = _name;
        };

        status_t get_task_status()
        {
            return status;
        };

        void set_task_status(status_t _status)
        {
            status = _status;
        };

    private:
        std::string name;
        status_t status;
};

class app_mgr
{
    private:
        std::vector<task*> task_list;

    public:
        // CRUD

        void add_task(std::string _name, status_t _status)
        {
            task* new_task = new task(_name, _status);
            task_list.push_back(new_task);

            std::cout << "Add task successfully!!! \n";
        };

        std::vector<task*> get_task_list()
        {
            return task_list;
        };

        void delete_task_by_index(int index)
        {
            std::vector<task*>::iterator it;
            task_list.erase(it + (index - 1));
        }

        void update_task_name_by_index(int index, std::string _name)
        {
            task_list[index]->set_task_name(_name);
        }

        void update_task_status_by_index(int index, status_t _status)
        {
            task_list[index]->set_task_status(_status);
        }

};

int main()
{

    app_mgr* app_mgr_ins = new app_mgr;

    while(true)
    {
        std::cout << "1. Add task \n";
        std::cout << "2. Show task list \n";
        std::cout << "3. Delete task \n";
        std::cout << "4. Update task \n";
        std::cout << "Enter your choice: \n";

        int user_input;
        std::cin >> user_input;

        switch(user_input)
        {
            case 1:
            {
                std::cin.ignore(10000, '\n'); // when use getline it read the input stream buffer -
                                              // which is left by cin with an /n -> it will stop reading the input from user

                // Add task
                std::cout << "Enter task_name: \n";
                std::string task_name;
                getline(std::cin, task_name);

                std::cout << "The status for task: \n 1. TO_DO \n 2. IN_PROGRESS \n 3. DONE \n";
                std::cout << "Enter your choice: \n";
                int choice;
                std::cin >> choice;

                status_t task_status;

                switch (choice)
                {
                    case 1:
                        task_status = TO_DO;
                        break;
                    case 2:
                        task_status = IN_PROGRESS;
                        break;
                    case 3:
                        task_status = DONE;
                        break;
                    default:
                        break;
                }

                app_mgr_ins->add_task(task_name, task_status);
                break;
            }
            // case 2:
            //     break;
            // case 3:
            //     break;
            // case 4:
            //     break;
            default:
                std::cout << "Invalid choice!!!";
        }

    }

    return 0;
}












