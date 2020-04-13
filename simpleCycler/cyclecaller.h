#ifndef CYCLECALLER_H
#define CYCLECALLER_H

#include <chrono>
#include <functional>
#include <thread>
#include <vector>

// Cyclically executes given functions with time interval between every call
class CycleCaller
{
public:
    explicit CycleCaller();
    virtual ~CycleCaller();

    void start();
    void pause();
    void stop();

    void addFunction(const std::function<void()>& fun);
    void clearFunctions();

    void setEverycallSleeptime(double ms);
    void setFullcycleSleeptime(double ms);

private:
    void callWorker() const;

private:
    std::vector<std::function<void()>> _callSequence;
    std::chrono::duration<double, std::milli> _sleeptimeCall;
    std::chrono::duration<double, std::milli> _sleeptimeFull;
    std::thread* _workerThread;
    bool _isCycling;
    bool _isFullcycleSleep;
    bool _isPause;
};

#endif // CYCLECALLER_H
