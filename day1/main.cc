#include <stdio.h>
#include <stdlib.h>
#include <vector>

int count_depth_increase(const char *file_name);
int count_depth_average_increase(const char *file_name);
float average(std::vector<int> values);

int readFileToVector(const char *file_name, std::vector<int> &values) {
  if (!file) {
    while ((file, line)) {
      if (atoi(line.c_str()) > measurement) {
        counter++;
      }
      measurement = std::stoi(line.c_str());
    }
  }
}


int main() {
  std::string file_name = "depth.txt";
  int counter = count_depth_increase(file_name);
  printf("Number of individual increases:%d \n", counter);

  counter = count_depth_average_increase(file_name);
  printf("Number of averaged increases: %d\n", counter);
}

int count_depth_increase(std::string file_name) {
  const char *file_name = "depth.txt";
  FILE *file = fopen(file_name, "r");

  int counter = -1;
  int measurement = 0;

  if (!file) {
    while ()) {
        counter++;
      }
      measurement = std::stoi(line.c_str());
    }
  }
  return counter;
}

int count_depth_average_increase(const char *file_name) {
  const char *file_name = "depth.txt";
  FILE *file = fopen(file_name, "r");

  int counter = 0;
  int measurement = 0;
  std::vector<int> values;

  if (file.is_open()) {
    while (std::getline(file, line)) {
      values.push_back(std::stoi(line.c_str()));
    }
  }
  for (int i = 0; i < values.size(); i++) {
    float avg = average(std::vector<int>(values.begin() + i, values.begin() + i + 3));
    float avg_next = average(std::vector<int>(values.begin() + i + 1, values.begin() + i + 4));
    if (avg_next > avg) {
      counter++;
    }
  }
  return counter;
}

float average(std::vector<int> values) {
  float avg = 0;
  for (const auto i: values) {
    avg += i;
  }
  avg /= values.size();
  return avg;
}
