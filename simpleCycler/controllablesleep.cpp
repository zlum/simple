#include "controllablesleep.h"

ControllableSleep::ControllableSleep():
    terminate(false)
{
}

ControllableSleep::~ControllableSleep()
{
}

void ControllableSleep::kill()
{
    std::unique_lock<std::mutex> lock(m);
    terminate = true;
    cv.notify_all();
}
