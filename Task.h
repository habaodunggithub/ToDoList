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
    const std::string& getStatus() const;
    void setStatus(const std::string&);

private:
    std::string id;
    std::string title;
    std::string description;
    Date dueDate;
    std::string status;
};

void enterTaskInfo(Task&);
void printTaskInfo(const Task&);