#include "pointers.hpp"
#include <gtest/gtest.h>

TEST(SmartPointerTest, UniquePtrBasic) {
    // Context: Verifies that uniquePtr takes ownership of a raw pointer and allows access to its members.
    // Also indirectly verifies proper destruction (no leaks) via standard execution flow, 
    // though usually requires a mock or sanitizer to strictly prove deletion.
    pun* raw_ptr = new pun("test", 123);
    uniquePtr<pun> uptr(raw_ptr);
    
    EXPECT_EQ(uptr->getNum(), 123);
    
    uptr->setNum(456);
    EXPECT_EQ(uptr->getNum(), 456);
    
    // Destructor will be called automatically, valgrind/asan would catch leaks
}

TEST(SmartPointerTest, SharedPtrCount) {
    // Context: Tests the reference counting mechanism.
    // 1. Initial count should be 1.
    // 2. Creating a copy should increment count to 2.
    // 3. Destroying the copy (scope exit) should decrement count back to 1.
    shared_pointer<pun> sp1(new pun("shared", 10));
    EXPECT_EQ(sp1.getCount(), 1);
    
    {
        shared_pointer<pun> sp2 = sp1;
        EXPECT_EQ(sp1.getCount(), 2);
        EXPECT_EQ(sp2.getCount(), 2);
    }
    
    EXPECT_EQ(sp1.getCount(), 1);
}

TEST(SmartPointerTest, SharedPtrAccess) {
    // Context: Ensures the shared_pointer provides access to the underlying object functionality.
    shared_pointer<pun> sp(new pun("access", 99));
    EXPECT_EQ(sp->getNum(), 99);
}
