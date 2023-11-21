#ifndef __READFILE__
#define __READFILE__

#include <string>
#include <vector>

std::vector<int> readFileToIntVector(const char *file_name);
std::vector<std::string> readFileToStringVector(const char *file_name);
std::vector<std::pair<std::string, int>> readFileToVectorTuple(const char *file_name);

#endif // __READFILE__
