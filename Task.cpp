#include "Task.h"

Task::Task() {}

const std::string& Task::getID() const {
    return id;
}

void Task::setID(const std::string& id) {
    this->id = id;
}

const std::string& Task::getTitle() const {
    return title;
}

void Task::setTitle(const std::string& title) {
    this->title = title;
}

const std::string& Task::getDescription() const {
    return description;
}

void Task::setDescription(const std::string& description) {
    this->description = description;
}

const Date& Task::getDueDate() const {
    return dueDate;
}

void Task::setDueDate(const Date& date) {
    this->dueDate = date;
}

int Task::getStatus() const {
    return status;
}

void Task::setStatus(int status) {
    this->status = status;
}

void enterTaskInfo(Task& task) {
    
}