#ifndef STRINGFUNCTIONS_H_DEFINED
#define STRINGFUNCTIONS_H_DEFINED
#include <string>
void upperString(std::string &str);
void swapChars(std::string &str, int p1, int p2);
bool askClosed(std::string str, std::string errStr, std::string positive, std::string negative);
#endif