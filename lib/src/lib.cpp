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

int minSwapsRequired(string s) {

    return 0;
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
