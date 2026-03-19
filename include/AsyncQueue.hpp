#ifndef ASYNC_QUEUE_HPP
#define ASYNC_QUEUE_HPP

#include <condition_variable>
#include <cstddef>
#include <mutex>
#include <queue>
#include <stdexcept>
#include <utility>

template <typename T>
class AsyncQueue {
   private:
    std::queue<T> _queue;
    mutable std::mutex _mutex;
    std::condition_variable _condVar;
    bool _shutDown = false;

   public:
    AsyncQueue() = default;
    ~AsyncQueue() { shutdown(); }

    AsyncQueue(const AsyncQueue&) = delete;
    AsyncQueue& operator=(const AsyncQueue&) = delete;

    void push(const T& val) {
        std::unique_lock<std::mutex> lock(_mutex);
        if (_shutDown) {
            throw std::runtime_error("Queue is shutdown\n");
        }
        _queue.push(val);
        lock.unlock();
        _condVar.notify_one();
    }

    bool pop(T& val) {
        std::unique_lock<std::mutex> lock(_mutex);
        _condVar.wait(lock, [&]() { return !_queue.empty() || _shutDown; });
        if (_queue.empty()) {
            return false;
        }
        val = std::move(_queue.front());
        _queue.pop();
        return true;
    }

    bool tryPop(T& val) {
        std::unique_lock<std::mutex> lock(_mutex);
        if (_queue.empty()) {
            return false;
        }
        val = std::move(_queue.front());
        _queue.pop();
        return true;
    }

    void shutdown() {
        std::unique_lock<std::mutex> lock(_mutex);
        _shutDown = true;
        lock.unlock();
        _condVar.notify_all();
    }

    std::size_t size() const {
        std::unique_lock<std::mutex> lock(_mutex);
        return _queue.size();
    }

    bool isShutDown() const {
        std::unique_lock<std::mutex> lock(_mutex);
        return _shutDown;
    }
};

#endif
