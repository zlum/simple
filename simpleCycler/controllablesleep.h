#ifndef CONTROLLABLESLEEP_H
#define CONTROLLABLESLEEP_H

#include <condition_variable>

class ControllableSleep
{
public:
    explicit ControllableSleep();
    virtual ~ControllableSleep();

    // returns false if killed:
    template<typename R, typename P>
    bool wait_for(std::chrono::duration<R, P> const& time)
    {
        std::unique_lock<std::mutex> lock(m);
        return !cv.wait_for(lock, time, [&] {return terminate;});
    }

    void kill();

private:
    std::condition_variable cv;
    std::mutex m;
    bool terminate;
};

#endif // CONTROLLABLESLEEP_H
