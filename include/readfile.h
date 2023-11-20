#ifndef __READFILE__
#define __READFILE__

#include <string>
#include <vector>

int readFileToIntVector(const char *file_name, std::vector<int> &numbers);
int readFileToStringVector(const char *file_name, std::vector<std::string> &strings);
int readFileToVectorTuple(const char *file_name, std::vector<std::pair<std::string, int>> &values);

#endif // __READFILE__
