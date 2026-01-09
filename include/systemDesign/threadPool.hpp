#ifndef THREAD_POOL_HPP
#define THREAD_POOL_HPP

#include <vector>
#include <thread>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <iostream>

// Thread Pool
// Goal: Re-use a fixed number of threads to execute many tasks, avoiding the overhead of creating/destroying threads.
// Mechanics:
// 1. Task Queue: A queue of std::function objects (jobs to do).
// 2. Worker Threads: A vector of threads that infinite-loop, waiting for tasks.
// 3. Synchronization:
//    - Mutex: Protects the queue from race conditions.
//    - Condition Variable: Allows threads to sleep when queue is empty and wake up when a task is added.

class ThreadPool {
private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    
    std::mutex queueMutex;
    std::condition_variable condition;
    std::atomic<bool> stop; // Atomic flag to signal threads to stop

public:
    // Constructor: Launches N threads
    ThreadPool(size_t numThreads = std::thread::hardware_concurrency()) : stop(false) {
        for (size_t i = 0; i < numThreads; ++i) {
            workers.emplace_back([this] {
                while (true) {
                    std::function<void()> task;

                    // Critical Section
                    {
                        std::unique_lock<std::mutex> lock(queueMutex);
                        
                        // Wait until task is available OR pool is stopped
                        condition.wait(lock, [this] {
                            return stop || !tasks.empty();
                        });

                        // Exit if stopped and queue is empty
                        if (stop && tasks.empty()) {
                            return;
                        }

                        // Get task
                        task = std::move(tasks.front());
                        tasks.pop();
                    } 
                    // lock releases here, allowing other threads to access queue

                    // Execute task outside lock (parallelism)
                    task();
                }
            });
        }
    }

    // Add task to the pool
    // Can accept lambdas, function pointers, etc.
    template <typename F>
    void enqueue(F&& f) {
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            tasks.emplace(std::forward<F>(f));
        }
        condition.notify_one(); // Wake up one worker
    }

    // Destructor: Clean shutdown
    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            stop = true; // Signal stop
        }
        condition.notify_all(); // Wake up all threads so they can check 'stop' and exit

        for (std::thread& worker : workers) {
            if (worker.joinable()) {
                worker.join(); // Wait for everyone to finish
            }
        }
    }
};

#endif // THREAD_POOL_HPP
