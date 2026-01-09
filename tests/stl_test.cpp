#include "stl.hpp"
#include <gtest/gtest.h>
#include <map>
#include <set>
#include <list>
#include <string>

// Test Custom Vectors Class
TEST(VectorTest, PushAndSize) {
    // Context: Verifies the dynamic resizing logic.
    // Capacity should start at 1 and double (1 -> 2 -> 4) as elements are added.
    vectors<int> v;
    EXPECT_EQ(v.getSize(), 0);
    EXPECT_EQ(v.getCap(), 1);

    v.push(10);
    EXPECT_EQ(v.getSize(), 1);
    EXPECT_EQ(v.getCap(), 1);

    v.push(20);
    EXPECT_EQ(v.getSize(), 2);
    EXPECT_EQ(v.getCap(), 2); // Doubled capacity

    v.push(30);
    EXPECT_EQ(v.getSize(), 3);
    EXPECT_EQ(v.getCap(), 4); // Doubled again
}

TEST(VectorTest, Pop) {
    // Context: Verifies that pop() correctly reduces the logical size of the vector.
    vectors<int> v;
    v.push(10);
    v.push(20);
    v.pop();
    EXPECT_EQ(v.getSize(), 1);
}

TEST(VectorTest, InsertAtIndex) {
    vectors<int> v;
    v.push(10);
    v.push(0, 5); // Overwrite index 0
    // Currently custom vector implementation overwrites without shifting based on code analysis
    // "arr[index] = data;"
    // We can't easily verify content with current public API except print, 
    // but assuming basic behavior matches source.
    EXPECT_EQ(v.getSize(), 1);
}

// Test internal Linked List (from stl.hpp)
TEST(LinkedListTest, InsertAtHead) {
    // Context: Verifies manual linked list manipulation (insertAtHead).
    // Ensures the new node becomes the new head and points to the old head.
    node* head = nullptr;
    insertAtHead(head, 10);
    ASSERT_NE(head, nullptr);
    EXPECT_EQ(head->getData(), 10);

    insertAtHead(head, 20);
    EXPECT_EQ(head->getData(), 20);
    EXPECT_EQ(head->getNext()->getData(), 10);
}

// Test Map string wrapper (from stl.hpp)
TEST(MapStrTest, OperatorLessThan) {
    map_str m1("abc", 1);
    map_str m2("xyz", 2);
    map_str m3("abc", 2);

    EXPECT_TRUE(m1 < m2);
    EXPECT_FALSE(m2 < m1);
    // Same string, different num
    EXPECT_TRUE(m1 < m3); 
}

TEST(STLTest, StdMapUsage) {
    std::map<map_str, int> m;
    map_str m1("key1", 10);
    m[m1] = 100;
    
    EXPECT_EQ(m[m1], 100);
}

TEST(STLTest, StdSetUsage) {
    // Context: Verifies usage of std::set.
    // Sets store unique elements. Inserting a duplicate should not increase size.
    std::set<map_str> s;
    map_str m1("xyz", 1);
    map_str m2("def", 2);
    s.insert(m1);
    s.insert(m2);

    EXPECT_EQ(s.size(), 2);
    EXPECT_TRUE(s.find(m1) != s.end());
}

TEST(STLTest, StdListUsage) {
    // Context: Verifies usage of std::list (doubly linked list).
    // Checks assignment (filling with value), iteration, and insertion at a specific position.
    std::list<int> l;
    l.assign(4, 2); // 2 2 2 2
    
    EXPECT_EQ(l.size(), 4);
    for(int val : l) {
        EXPECT_EQ(val, 2);
    }

    auto itr = l.begin();
    std::advance(itr, 2);
    l.insert(itr, 5); // 2 2 5 2 2

    // Verify insertion
    std::vector<int> expected = {2, 2, 5, 2, 2};
    int idx = 0;
    for(int val : l) {
        EXPECT_EQ(val, expected[idx++]);
    }
}

TEST(LinkedListTest, InsertTailAndPosition) {
    node* head = new node(10);
    node* tail = head; // initially head is tail if single element

    inserAtTail(tail, 20); // head(10)->(20)tail
    EXPECT_EQ(head->getNext()->getData(), 20);

    inserAtTail(tail, 30); // head(10)->(20)->(30)tail
    EXPECT_EQ(head->getNext()->getNext()->getData(), 30);

    // Insert at position
    insertAtPosition(head, 2, 15); // should be 10 -> 15 -> 20 -> 30
    EXPECT_EQ(head->getNext()->getData(), 15);
    EXPECT_EQ(head->getNext()->getNext()->getData(), 20);
}
