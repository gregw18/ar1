#pragma once

#include <string>
#include <utility>
#include <vector>

//_declspec(dllexport) const std::string generateHelloString(const std::string & personName);
//const std::string generateHelloString(const std::string & personName);

int pm_main();

bool isPalindromePossible(std::string s);
std::pair<std::vector<int>, std::vector<int>> createMismatchedLists(std::string s);
int calcSwapsRequired(std::vector<int> mmzeroPositions, std::vector<int> mmonePositions);
