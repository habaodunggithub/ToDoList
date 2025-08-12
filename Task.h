#pragma once

#include <string>
#include "Date.h"

class Task {
public:
    Task();
    const std::string& getID() const;
    void setID(const std::string&);
    const std::string& getTitle() const;
    void setTitle(const std::string&);
    const std::string& getDescription() const;
    void setDescription(const std::string&);
    const Date& getDueDate() const;
    void setDueDate(const Date&);
    int getStatus() const;
    void setStatus(int);

private:
    std::string id;
    std::string title;
    std::string description;
    Date dueDate;
    int status;
};

void enterTastInfo(const Task&);
void printTaskInfo(const Task&);