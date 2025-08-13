#include "Task.h"
#include <cstdlib>
#ifdef _WIN32
#include <windows.h>
#endif
#include <thread>

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

#ifdef _WIN32
// Bật ANSI cho Windows 10+
void enableAnsiOnWindows() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) return;
    DWORD mode = 0;
    if (!GetConsoleMode(hOut, &mode)) return;
    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, mode);
}
#endif

// Xóa từ dòng i đến dòng j (tính từ dưới lên, 0 = dòng hiện tại ở dưới cùng).
void deleteRangeFromBottom(int i, int j) {
    if (i < 0 || j < i) return;
#ifdef _WIN32
    enableAnsiOnWindows();
#endif
    int n = j - i + 1;
    // 1) Lên tới dòng j (đỉnh của đoạn cần xóa)
    std::cout << "\033[" << j << "A";
    // 2) Xóa n dòng và kéo phần dưới lên
    std::cout << "\033[" << n << "M";
    // 3) (Tuỳ chọn) quay về dưới cùng
    std::cout << "\033[" << i - 1 << "B"; // Xuống 1 dòng
    std::cout.flush();
}

void enterTaskInfo(Task& task) {
    std::string temp;

    std::cout << "Task's ID: ";
    std::getline(std::cin, temp);
    task.setID(temp);

    
    std::cout << "Task's title: ";
    std::getline(std::cin, temp);
    task.setTitle(temp);
    
    std::cout << "Task's description: ";
    std::getline(std::cin, temp);
    task.setDescription(temp);
    
    Date d;
    std::cout << "Task's due date (dd/mm/yyyy): ";
    std::getline(std::cin, temp);
    while (enterDate(d, temp) == false) {
        deleteRangeFromBottom(0, 0);
        std::cout << "Invalid date!\n";
        std::cout << "Task's due date (dd/mm/yyyy): ";
        std::getline(std::cin, temp); 
        deleteRangeFromBottom(2, 2);  
    }

    int choice = 1;
    std::cout << "Task's status:\n";
    std::cout << "1. Not started.\n";
    std::cout << "2. In progress.\n";
    std::cout << "3. Complete.\n";
    std::cout << "Enter your option: ";
    std::cin >> choice;
    deleteRangeFromBottom(0, 5);
    
    while (choice != 1 && choice != 2 && choice != 3) {
        std::cout << "ERROR:INVALID_CHOICE.\nPlease choose again!\n";
        std::cout << "Choose task's status:\n";
        std::cout << "1. Not started.\n";
        std::cout << "2. In progress.\n";
        std::cout << "3. Complete.\n";
        std::cout << "Enter your option: ";
        std::cin >> choice;
        deleteRangeFromBottom(0, 7);
    }
    std::cout << "Task's status: ";
    if (choice == 1) std::cout << "Not started.\n";
    else if (choice == 2) std::cout << "In progress.\n";
    else std::cout << "Complete.\n";

    std::this_thread::sleep_for(std::chrono::seconds(2));
    system("cls");
}
