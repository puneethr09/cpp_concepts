#include <gtest/gtest.h>
#include "cpp_vocabulary.hpp"

TEST(VocabularyTest, StaticKeyword) {
    StaticDemo::sharedCount = 0;
    StaticDemo::increment();
    StaticDemo::increment();
    EXPECT_EQ(StaticDemo::sharedCount, 2);
}

TEST(VocabularyTest, MutableKeyword) {
    const Monitor mon;
    mon.check(); // const method calls
    mon.check();
    EXPECT_EQ(mon.accessCount, 2); // mutable allowed change
}

TEST(VocabularyTest, ExplicitKeyword) {
    Wrapper w(10); // OK
    // Wrapper w2 = 10; // Compile Error (Good!)
    EXPECT_TRUE(true);
}

TEST(VocabularyTest, FriendKeyword) {
    SecretBox box;
    Hacker hacker;
    EXPECT_EQ(hacker.steal(box), 1234);
}

TEST(VocabularyTest, EnumClass) {
    Color c = Color::RED;
    // int x = Color::RED; // Compile Error (Good! Strongly Typed)
    EXPECT_EQ(c, Color::RED);
}

TEST(VocabularyTest, Constexpr) {
    static_assert(square(10) == 100, "Constexpr failed at compile time");
    int runtimeVal = square(5);
    EXPECT_EQ(runtimeVal, 25);
}

TEST(VocabularyTest, TypeTraits) {
    decltype(10) x = 5; // x is int
    EXPECT_TRUE((std::is_same<decltype(x), int>::value));
}
