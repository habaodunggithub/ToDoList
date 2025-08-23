#pragma once

#include "Task.h"
#include <iostream>
#include <vector>

class TaskManager {
public:
    TaskManager();
    ~TaskManager();

    Task& getTask(int);
    bool loadData(const char*);
    bool saveData(const char*);
    int getTotalTasks() const;
    void setTotalTasks(int);
    bool printTasksList() const;
    void addTask();
    void removeTask(int);
    int findTask(const std::string&) const;
private:
    std::vector<Task> tasksList;
    int totalTasks;
};

