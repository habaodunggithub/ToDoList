#include "FrontendManager.h"
#include <stdlib.h>
#include <string>

FrontendManager::FrontendManager() {}
FrontendManager::~FrontendManager() {}

void FrontendManager::run() {
    while (true) {
        int choice = printMenu();
        if (choice == 1) {
            int taskIdx = taskSelection() - 1;
            Task& task = tm.getTask(taskIdx);
            int taskInteraction = detailSelection(taskIdx);
            processEdit(task, taskInteraction);
        }
        else if (choice == 2) {
            tm.addTask();
        }
        else if (choice == 3) break;
        else system("cls");
    }
}

int FrontendManager::printMenu() {
    std::cout << "Menu:\n";
    std::cout << "1) Current tasks\n";
    std::cout << "2) Add task\n";
    std::cout << "3) Exit\n";
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;
    std::cin.ignore();
    system("cls");
    return choice;
}

int FrontendManager::taskSelection() {
    tm.printTasksList();
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;
    system("cls");
    return choice;
}

int FrontendManager::detailSelection(int taskIdx) {
    Task task = tm.getTask(taskIdx);
    std::cout << "Edit " << task.getTitle() << ":\n";
    std::cout << "1) ID\n";
    std::cout << "2) Title\n";
    std::cout << "3) Description\n";
    std::cout << "4) Due date\n";
    std::cout << "5) Status\n";
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;
    std::cin.ignore();
    system("cls");
    return choice;
}

void FrontendManager::processEdit(Task& task, int idx) {
    if (idx == 1) {
        std::cout << "Current ID: " << ": " << task.getID() << "\n";

        std::cout << "Enter new ID: ";
        std::string temp;
        std::getline(std::cin, temp);
        task.setID(temp);
    }
    else if (idx == 2) {
        std::cout << "Current title: " << task.getTitle() << "\n";

        std::cout << "Enter new title: ";
        std::string temp;
        std::getline(std::cin, temp);
        task.setTitle(temp);
    }
    else if (idx == 3) {
        std::cout << "Current Description: " << ": " << task.getDescription() << "\n";

        std::cout << "Enter new description: ";
        std::string temp;
        std::getline(std::cin, temp);

        task.setDescription(temp);
    }
    else if (idx == 4) {
        Date d = task.getDueDate();
        std::cout << "Current due date: " << ": " << getDateString(d) << "\n";

        std::cout << "Enter new due date(dd/mm/yyyy): ";
        std::string temp;
        std::getline(std::cin, temp);
        enterDate(d, temp);
        task.setDueDate(d);
    }
    else if (idx == 5) {
        std::cout << "Current status: " << ": " << task.getStatus() << "\n";

        std::cout << "Enter new status:\n";
        std::cout << "1) Not started\n";
        std::cout << "2) in progress\n";
        std::cout << "3) Complete\n";
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            task.setStatus("Not started");
        }
        else if (choice == 2) {
            task.setStatus("In progress");
        }
        else {
            task.setStatus("Complete");
        }
    }
    system("cls");
}