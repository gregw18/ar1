#include <algorithm>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include <lib.h>

using namespace std;

//const string generateHelloString(const string & personName) {
//    return "Hello " + personName;
//}

/*
 * Complete the 'minSwapsRequired' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

/*
    Note to reviewer: I don't like the HackerRank environment for programming - I can't write and run
                        my own tests. Thus, I set up a local environment, with a template project
                        of my own design, in VS Code and copied the resulting code into hackerrank
                        when complete. The complete evolution of the program can be found at 
                        github.com\gregw18\ar1.
                        Ran out of time, one function (the longest) has bug, so not working.
    Problem:
    Given a binary string, swap any two characters, as many times as necessary, to create a palindrome.
    Return the minimum number of swaps required. Return -1 if impossible.
    Notes:
        1. If have even number of digits, but odd number of 1's (and thus, also 0's), won'd be able
            to create a palindrome. Otherwise, should be possible.
        2. If have odd number of digits, need one of the odd digits in the middle.
    Approach:
        Check if possible. Return -1 if not.
        Create 2 vectors. First is list of indexes of 0's that are out of place - i.e. the mirrorred
        item in the string doesn't match. Don't include middle item, if odd number of items.
        Second is list of indexes of 1's that are out of place. Again, don't include middle item.
        If swap first item from 0's vector with 2nd item from 1's vector, fixes both. If length of
        one list is even, n = length/2, else roundup(length/2).
        If both lists contain just one item, swap those, n = 1.
        isPalindromePossible(string)
        createMismatchedLists(string)
        calcSwapsRequired(vector, vector)
*/

bool isPalindromePossible(string s) {
    bool isPossible = true;

    int numDigits = (int) s.length();
    if (numDigits % 2 == 0) {
        int numOnes = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.substr(i, 1) == "1") numOnes++;
        }
        if (numOnes % 2 == 1) isPossible = false;
    }

    return isPossible;
}

pair<vector<int>, vector<int>> createMismatchedLists(string s) {
    vector<int> mmzeroPositions;
    vector<int> mmonePositions;

    int mirrori;
    int strLen = (int) s.length();
    if (strLen > 1) {
        int middlePos = strLen / 2;
        for (int i = 0; i <= middlePos; i++) {
            mirrori = strLen - i - 1;
            if (s.substr(i, 1) != s.substr(mirrori, 1)) {
                if (s.substr(i, 1) == "0") {
                    mmzeroPositions.push_back(i);
                    mmonePositions.push_back(mirrori);
                }
                else {
                    mmonePositions.push_back(i);
                    mmzeroPositions.push_back(mirrori);
                }
            }
        }
    }

    return make_pair(mmzeroPositions, mmonePositions);
}

int calcSwapsRequired(vector<int> mmzeroPositions, vector<int> mmonePositions) {
// If swap first item from 0's vector with 2nd item from 1's vector, fixes both. If length of
// one list is even, n = length/2, else roundup(length/2).

    int numRequired = 0;

    int badZeroes = (int) mmzeroPositions.size();
    int badOnes = (int) mmonePositions.size();

    if (badZeroes % 2 == 0) numRequired = badZeroes / 2;
    else numRequired = badZeroes / 2 + 1;

    return numRequired;
}

int minSwapsRequired(string s) {

    int numSwaps = -1;
    if (isPalindromePossible(s)) {
        auto results = createMismatchedLists(s);
        numSwaps = calcSwapsRequired(results.first, results.second);
    }
    else numSwaps = -1;
    
    return numSwaps;
}

int pm_main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = minSwapsRequired(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
