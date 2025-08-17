#pragma once

#include "Task.h"
#include <iostream>
#include <vector>

class TaskManager {
public:
    TaskManager();
    ~TaskManager();

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

