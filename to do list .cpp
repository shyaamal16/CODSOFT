#include <iostream>
#include <vector>

std::vector<std::string> tasks;

void addTask() {
    std::string task;
    std::cout << "Enter a new task: ";
    std::cin.ignore();
    std::getline(std::cin, task);
    tasks.push_back(task);
}

void viewTasks() {
    if (tasks.empty()) {
        std::cout << "No tasks added yet!\n";
        return;
    }
    std::cout << "Your tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i] << std::endl;
    }
}

void deleteTask() {
    int taskNumber;
    viewTasks();
    if (!tasks.empty()) {
        std::cout << "Enter the task number to delete: ";
        std::cin >> taskNumber;
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            std::cout << "Task deleted!\n";
        } else {
            std::cout << "Invalid task number!\n";
        }
    }
}

int main() {
    int choice;

    do {
        std::cout << "\nTo-Do List Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Delete Task\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice, please try again!\n";
        }
    } while (choice != 4);

    return 0;
}
