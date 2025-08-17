#include "TaskManager.h"

TaskManager::TaskManager() : tasksList({}), totalTasks(0) {}

int TaskManager::getTotalTasks() const {
    return totalTasks;
}

void TaskManager::setTotalTasks(int numOfTasks) {
    totalTasks = numOfTasks;
}

bool TaskManager::printTasksList() const {
    if (getTotalTasks() == 0) {
        std::cout << "Tasks list is empty.\n";
        return false;
    }
    
    std::cout << "Tasks list:\n";
    for (int i = 0; i < getTotalTasks(); i++) {
        std::cout << i + 1 << ". "
            << tasksList[i].getTitle() 
            << " - " << tasksList[i].getID()
            << "\n";
    }
    return false;
}