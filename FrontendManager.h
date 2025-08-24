#include "TaskManager.h"

class FrontendManager {
public:
    FrontendManager();
    ~FrontendManager();

    int printMenu();
    int taskSelection();
    int printTaskInteractionMenu(int);
    int detailSelection(int);
    void processEdit(Task&, int);
    void run();
private:
    TaskManager tm;
};