#include "TaskManager.h"
#include <fstream>
#include <iostream>

TaskManager::TaskManager() {
    if (!loadData("data.txt")) {
        this->totalTasks = 0;
    }
}
TaskManager::~TaskManager() {
    saveData("data.txt");
}

bool TaskManager::loadData(const char* fileName) {
    std::ifstream fileIn;
    fileIn.open(fileName, std::ios::in);
    if (!fileIn.is_open()) return false;

    int total;
    fileIn >> total;
    setTotalTasks(total);

    std::string line;
    std::getline(fileIn, line);
    for (int i = 0; i < total; i++) {
        Task t;
        std::getline(fileIn, line);
        t.setID(line);
        
        std::getline(fileIn, line);
        t.setTitle(line);
        
        std::getline(fileIn, line);
        t.setDescription(line);
        
        Date d;
        std::getline(fileIn, line);
        enterDate(d, line);
        t.setDueDate(d);
       
        std::getline(fileIn, line);
        t.setStatus(line);
        
        tasksList.push_back(t);
    }

    fileIn.close();
    return true;
}

bool TaskManager::saveData(const char* fileName) {
    std::ofstream fileOut;
    fileOut.open(fileName, std::ios::out);
    if (!fileOut.is_open()) return false;

    fileOut << getTotalTasks() << "\n";
    for (int i = 0; i < getTotalTasks(); i++) {
        fileOut << tasksList[i].getID() << "\n";
        fileOut << tasksList[i].getTitle() << "\n";
        fileOut << tasksList[i].getDescription() << "\n";

        Date d = tasksList[i].getDueDate();
        fileOut << d.getDay() << "/" 
            << d.getMonth() << "/" 
            << d.getYear() << "\n";
        
        fileOut << tasksList[i].getStatus() << "\n";
    }
    fileOut.close();
    return true;
}

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
            << " - " << tasksList[i].getStatus()
            << "\n";
    }
    return true;
}

void TaskManager::addTask() {
    Task t;
    enterTaskInfo(t);
    tasksList.push_back(t);
    setTotalTasks(getTotalTasks() + 1);
}

void TaskManager::removeTask(int index) {
    if (index >= getTotalTasks() || index < 0) return;

    tasksList.erase(tasksList.begin() + index);
    setTotalTasks(getTotalTasks() - 1);
}

int TaskManager::findTask(const std::string& titleOrID) const {
    for (int i = 0; i < getTotalTasks(); i++) {
        if (titleOrID == tasksList[i].getTitle() 
        || titleOrID == tasksList[i].getID())
            return i;
    }

    return -1;
}