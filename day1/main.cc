#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "readfile.h"

float average(std::vector<int> &numbers);
int count_depth_increase(std::vector<int> &numbers);
int count_depth_average_increase(std::vector<int> &numbers);


int main() {
  const char *file_name = "depths.txt";
  std::vector<int> numbers;
  readFileToVector(file_name, numbers);

  int counter = count_depth_increase(numbers);
  printf("Number of individual increases: %d \n", counter);

  counter = count_depth_average_increase(numbers);
  printf("Number of averaged increases: %d\n", counter);
}


float average(std::vector<int> values) {
  float avg = 0;
  for (const auto i: values) {
    avg += i;
  }
  avg /= values.size();
  return avg;
}


int count_depth_increase(std::vector<int> &numbers) {
  int count = 0;
  for (int i = 1; i < numbers.size(); i++) {
    if (numbers.at(i-1) < numbers.at(i)) {
      count++;
    }
  }
  return count;
}


int count_depth_average_increase(std::vector<int> &numbers) {
  int count = 0;
  for (int i = 0; i < numbers.size(); i++) {
    float prev = average(std::vector<int>(numbers.begin()+i, numbers.begin()+i+3));
    float current = average(std::vector<int>(numbers.begin()+i+1, numbers.begin()+i+4));
    if (current > prev) {
      count++;
    }
  }
  return count;
}
