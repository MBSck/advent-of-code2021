#ifndef __READFILE__
#define __READFILE__

#include <string>
#include <vector>

int readFileToVector(const char *file_name, std::vector<int> &numbers);
int readFileToVectorTuple(const char *file_name, std::vector<std::pair<std::string, int>> &values);

#endif
