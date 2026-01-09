#include "multithread.hpp"
#include <gtest/gtest.h>
#include <thread>

// Test that we can call the functions without crashing.
// Note: These functions print to stdout, capturing output is hard in basic testing without redirecting buffers.
// For now, we verify they execute.
TEST(ConcurrencyTest, FindEvenBasic) {
    // Context: Smoke test to ensure the background logic for finding evens runs without throwing exceptions.
    EXPECT_NO_THROW(findEven(0, 100));
}

TEST(ConcurrencyTest, FindOddBasic) {
    EXPECT_NO_THROW(findOdd(0, 100));
}

TEST(ConcurrencyTest, MultithreadedExecution) {
    // Context: Verifies the full multithreaded workflow.
    // Creates threads, runs them parallel (measured by chrono inside), and joins them.
    // Proper execution without deadlock/crash is the success condition here.
    EXPECT_NO_THROW(multithreaded());
}
