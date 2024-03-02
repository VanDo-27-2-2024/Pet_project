#include "app_mgr.h"
#include <sys/stat.h>

int main()
{
    app_mgr* app_mgr_ins = new app_mgr;


    // Check if folder task_profile is exist
    const char* dir = "../task_profile";

    // Structure which would store the metadata
    struct stat sb;

    // Calls the function with path as argument
    // If the file/directory exists at the path returns 0
    // If block executes if path exists
    // Else automatically create folder for saving profile
    if (stat(dir, &sb) == 0)
    {
        std::cout << "The path is VALID!";
        //list out current profile
    }
    else
    {
        std::cout << "The Path is INVALID! \n";
        if(mkdir("../task_profile", 0777) == 0) {
            std::cout << "Folder created successfully.\n" << std::endl;
        }
        else
        {
            std::cout << "Failed to create folder.\n" << std::endl;
            return 0;
        }
    }




    while(true)
    {
        std::cout << "===================== \n";
        std::cout << "===== TO-DO APP ===== \n";
        std::cout << "1. Add task \n";
        std::cout << "2. Show task list \n";
        std::cout << "3. Delete task \n";
        std::cout << "4. Update task \n";
        std::cout << "5. Save task list \n";
        std::cout << "Enter your choice: \n";

        int user_input;
        std::cin >> user_input;

        std::cout << "===================== \n";

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

                app_mgr_ins->add_task(task_name, choice);
                break;
            }
            case 2:
            {
                // Show task list
                app_mgr_ins->display_task_list();
                break;
            }
            case 3:
            {
                // delete task
                std::cout << "Enter index of task that will be deleted: \n";
                int index;
                std::cin >> index;

                app_mgr_ins->delete_task_by_index(index);
                break;
            }
            case 4:
            {
                // Edit task
                std::cout << "Enter index of task that will be editted: \n";
                int index;
                std::cin >> index;

                std::cin.ignore(10000, '\n');
                std::cout << "Enter new task name: \n";
                std::string task_name;
                getline(std::cin, task_name);

                std::cout << "Enter new task status: \n";
                int choice;
                std::cin >> choice;

                app_mgr_ins->update_task_name_by_index(index, task_name);
                app_mgr_ins->update_task_status_by_index(index, choice);
                break;
            }
            case 5:
            {
                app_mgr_ins->save_profile();

            }
            default:
                std::cout << "Invalid choice!!!";
        }

    }

    delete app_mgr_ins;

    return 0;
}