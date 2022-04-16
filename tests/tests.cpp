#include "gtest/gtest.h"
#include "lib.h"

//TEST(Tests, testHello) {
//    ASSERT_STREQ("Hello Jim", generateHelloString("Jim").c_str());
//}

TEST(Tests, testisPossibleYes) {
    std::string s = "1110";
    bool isPossible = isPalindromePossible(s);
    ASSERT_EQ(false, isPossible);
}

TEST(Tests, testisPossibleNo) {
    std::string s = "11101";
    bool isPossible = isPalindromePossible(s);
    ASSERT_EQ(true, isPossible);
}

// To Test:
    // Single zero.
    // Impossible string.
    // Valid string.
    // Even len string.
    // Odd len string.
TEST(Tests, testcreateLists1) {
    std::string s = "1";
    auto res = createMismatchedLists(s);
    std::vector<int> expectedZeroes = {};
    std::vector<int> expectedOnes = {};
    ASSERT_EQ(expectedZeroes, res.first);
    ASSERT_EQ(expectedOnes, res.second);
}

TEST(Tests, testcreateLists2) {
    std::string s = "1110";
    auto res = createMismatchedLists(s);
    std::vector<int> expectedZeroes = {3};
    std::vector<int> expectedOnes = {0};
    ASSERT_EQ(expectedZeroes, res.first);
    ASSERT_EQ(expectedOnes, res.second);
}

TEST(Tests, testcreateLists3) {
    std::string s = "101000";
    auto res = createMismatchedLists(s);
    std::vector<int> expectedZeroes = {0, 2};
    std::vector<int> expectedOnes = {3, 5};
    ASSERT_EQ(expectedZeroes, res.first);
    ASSERT_EQ(expectedOnes, res.second);
}

// To Test:
    // Even counts.
    // Odd count for one.
    // Empty counts
TEST(Tests, testCalcEvenCount) {
    // "101000"
    std::vector<int> badZeroes = {0, 3};
    std::vector<int> badOnes = {3, 5};
    int calcReq = calcSwapsRequired(badZeroes, badOnes);
    int expReq = 1;
    ASSERT_EQ(expReq, calcReq);
}

TEST(Tests, testCalcOneOdd) {
    // "1001010"
    std::vector<int> badZeroes = {0, 3};
    std::vector<int> badOnes = {1};
    int calcReq = calcSwapsRequired(badZeroes, badOnes);
    int expReq = 1;
    ASSERT_EQ(expReq, calcReq);
}

//int calcSwapsRequired(vector<int> mmzeroPositions, vector<int> mmonePositions) {
