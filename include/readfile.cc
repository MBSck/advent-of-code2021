#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <utility>

#include "readfile.h"


std::vector<int> readFileToIntVector(const char *file_name) {
  std::vector<int> numbers;
  FILE *file = fopen(file_name, "r");
  if (!file) {
    printf("Unable to read file %s!\n", file_name);
  }

  int num;
  while (fscanf(file, "%d", &num) != EOF) {
    numbers.push_back(num);
  }
  return numbers;
}

std::vector<std::string> readFileToStringVector(const char *file_name) {
  std::vector<std::string> strings;
  FILE *file = fopen(file_name, "r");
  if (!file) {
    printf("Unable to read file %s!\n", file_name);
  }

  char string[100];
  while (fscanf(file, "%s", string) != EOF) {
    strings.emplace_back(string);
  }
  return strings;
}

std::vector<std::pair<std::string, int>> readFileToVectorTuple(const char *file_name) {
  std::vector<std::pair<std::string, int>> values;
  FILE *file = fopen(file_name, "r");
  if (!file) {
    printf("Unable to read file %s!\n", file_name);
  }

  int num;
  char string[100];
  while (fscanf(file, "%s %d", string, &num) != EOF) {
    std::string str = string;
    values.emplace_back(std::make_pair(string, num));
  }
  return values;
}
