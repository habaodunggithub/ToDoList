#include "TaskManager.h"

TaskManager::TaskManager() : tasksList({}), totalTasks(0) {}
TaskManager::~TaskManager() {}

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

void TaskManager::addTask() {
    Task t;
    enterTaskInfo(t);
    tasksList.push_back(t);
    setTotalTasks(getTotalTasks() + 1);
}

void TaskManager::removeTask(int index) {
    if (index >= getTotalTasks() || index < 0) return;

    for (int i = index; i < getTotalTasks() - 1; i++) {
        tasksList[i] = tasksList[i + 1];
    }
    setTotalTasks(getTotalTasks() - 1);
}