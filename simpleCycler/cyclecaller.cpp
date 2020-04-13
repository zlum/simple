#include "cyclecaller.h"

using namespace std;
using namespace chrono;

CycleCaller::CycleCaller():
    _sleeptimeCall(100.0),
    _sleeptimeFull(100.0),
    _workerThread(nullptr),
    _isCycling(true),
    _isFullcycleSleep(false),
    _isPause(true)
{
}

CycleCaller::~CycleCaller()
{
    stop();
}

void CycleCaller::start()
{
    _isCycling = true;
    _isPause = false;

    if(_workerThread == nullptr)
    {
        _workerThread = new thread(&CycleCaller::callWorker, this);
    }
}

void CycleCaller::pause()
{
    _isPause = true;
}

void CycleCaller::stop()
{
    _isCycling = false;

    if(_workerThread == nullptr) return;

    _workerThread->join();
    delete _workerThread;
    _workerThread = nullptr;
}

void CycleCaller::addFunction(const function<void()>& fun)
{
    _callSequence.push_back(fun);

    if(_isFullcycleSleep)
    {
        _sleeptimeCall = _sleeptimeFull / _callSequence.size();
    }
}

void CycleCaller::clearFunctions()
{
    _callSequence.clear();
}

void CycleCaller::setEverycallSleeptime(double ms)
{
    _isFullcycleSleep = false;
    _sleeptimeCall = duration<double, std::milli>(ms);
}

void CycleCaller::setFullcycleSleeptime(double ms)
{
    // Divide by zero protection
    size_t size(_callSequence.empty() ? 1 : _callSequence.size());

    _isFullcycleSleep = true;
    _sleeptimeFull = duration<double, std::milli>(ms);
    _sleeptimeCall = _sleeptimeFull / size;
}

void CycleCaller::callWorker() const
{
    while(_isCycling)
    {
        for(const auto& fun : _callSequence)
        {
            if(!_isCycling) break;
            if(!_isPause) fun();
            this_thread::sleep_for(_sleeptimeCall);
        }

        if(!_isCycling) break;
        if(_callSequence.empty()) this_thread::sleep_for(_sleeptimeCall);
    }
}
