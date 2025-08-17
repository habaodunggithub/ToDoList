#pragma once

#include "Task.h"
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
private:
    std::vector<Task> tasksList;
    int totalTasks;
};

