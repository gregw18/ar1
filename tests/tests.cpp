#include "gtest/gtest.h"
#include "lib.h"

//TEST(Tests, testHello) {
//    ASSERT_STREQ("Hello Jim", generateHelloString("Jim").c_str());
//}

TEST(Tests, testisPossbileYes) {
    std::string s = "1110";
    bool isPossible = isPalindromePossible(s);
    ASSERT_EQ(false, isPossible);
}

TEST(Tests, testisPossbileNo) {
    std::string s = "11101";
    bool isPossible = isPalindromePossible(s);
    ASSERT_EQ(true, isPossible);
}

//bool isPalindromePossible(string s) {
