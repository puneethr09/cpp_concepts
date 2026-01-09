#include "multithread.hpp"
#include <thread>
#include <chrono>
#include <iostream>
#include <pthread.h>

using namespace std;
using namespace std::chrono;
// #define timeNow chrono::high_resolution_clock::now()

typedef unsigned long long ull;

void findEven(ull start, ull end)
{
    cout << "Currently in findEven, with thread id " << this_thread::get_id() << endl;
    auto st = high_resolution_clock::now();

    ull count = 0;
    for (ull i = start; i < end; i++)
    {
        if (i % 2 == 0)
        {
            ++count;
        }
    }

    auto et = high_resolution_clock::now();
    auto duration = chrono::duration_cast<microseconds>(et - st);
    cout << "Currently in findEven, with thread id done " << this_thread::get_id() << " count is " << count << " time elapsed " << duration.count() / 1000000 << endl;
}

void findOdd(ull start, ull end)
{
    cout << "Currently in findOdd, with thread id " << this_thread::get_id() << endl;
    auto st = high_resolution_clock::now();

    ull count = 0;
    for (ull i = start; i < end; i++)
    {
        if (i % 2 != 0)
        {
            ++count;
        }
    }

    auto et = high_resolution_clock::now();
    auto duration = chrono::duration_cast<microseconds>(et - st);
    cout << "Currently in findOdd, with thread id done " << this_thread::get_id() << " count is " << count << " time elapsed " << duration.count() / 1000000 << endl;
}

void multithreaded()
{
    cout << "Currently in Main, with thread id " << this_thread::get_id() << endl;

    auto st = high_resolution_clock::now();

    ull start = 0, end = 1900000000;
    // thread t1(findEven, start, end);
    // thread t2(findOdd, start, end);

    // t1.join();
    // t2.join();

    findEven(start, end);
    findOdd(start, end);

    auto et = high_resolution_clock::now();

    auto duration = chrono::duration_cast<microseconds>(et - st);

    cout << "Currently in Main, with thread id " << this_thread::get_id() << " all execution done with time taken as " << duration.count() / 1000000 << endl;
}