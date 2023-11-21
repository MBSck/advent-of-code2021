#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>

#include "readfile.h"

std::vector<int> getRow(const std::vector<std::string> &strings);
std::vector<std::vector<int>> createMatrix(const std::vector<std::string> &strings);
int binaryToDecimal(std::string binary);
bool getMostOccurence(const std::vector<int> &row);
int getGamma(const std::vector<std::vector<int>> &numbers);
int getEpsilon(const std::vector<std::vector<int>> &numbers);
void getLastRemainingElement(int index,
                             std::vector<std::string> &elements_to_keep,
                             const std::vector<std::string> &strings,
                             const std::string match_condition);
int getOxygenGeneratorRating(const std::vector<std::vector<int>> &numbers,
                             const std::vector<std::string> &strings);
int getCO2ScrubberRating(const std::vector<std::vector<int>> &numbers,
                         const std::vector<std::string> &strings);

int main() {
  std::vector<std::string> strings = readFileToStringVector("test.txt");
  std::vector<std::vector<int>> numbers = createMatrix(strings);

  printf("Gamma x Epsilon %d\n", getGamma(numbers) * getEpsilon(numbers));
  printf("Oxygen Generator Rating %d\n", getOxygenGeneratorRating(numbers, strings));
  printf("CO2 Scrubber Rating %d\n", getCO2ScrubberRating(numbers, strings));
  printf("Oxygen x CO2 %d\n",
         getOxygenGeneratorRating(numbers, strings)*getCO2ScrubberRating(numbers, strings));
  return 0;
}

std::vector<int> getRow(int index, const std::vector<std::string> &strings) {
  std::vector<int> row;
  for (const auto &string: strings) {
    row.push_back(string.at(index) - '0');
  }
  return row;
}

std::vector<std::vector<int>> createMatrix(const std::vector<std::string> &strings) {
  std::vector<std::vector<int>> numbers;
  for (int i = 0; i < strings.at(0).size(); i++) {
    numbers.push_back(getRow(i, strings));
  }
  return numbers;
}

int binaryToDecimal(std::string binary) {
  int base = 1;
  int decimal = 0;
  for (int i = binary.size() - 1; i >= 0; i--) {
    decimal += base * (binary.at(i) - '0');
    base *= 2;
  }
  return decimal;
}

bool getMostOccurence(const std::vector<int> &row) {
  int counter = 0;
  for (const auto &num: row) {
    if (num == 1) {
      counter++;
    }
  }
  printf("counter: %d, length %d\n", counter, static_cast<int>(row.size())-counter);
  if ((counter >= row.size() / 2) | (counter == row.size() / 2)) {
    return true;
  }
  return false;
}

int getGamma(const std::vector<std::vector<int>> &numbers) {
  std::string gamma_string = "";
  for (const auto &row: numbers) {
      gamma_string += getMostOccurence(row) ? "1" : "0";
    }
  return binaryToDecimal(gamma_string);
}

int getEpsilon(const std::vector<std::vector<int>> &numbers) {
  std::string epsilon_string = "";
  for (const auto &row: numbers) {
      epsilon_string += !getMostOccurence(row) ? "1" : "0";
  }
  return binaryToDecimal(epsilon_string);
}

void getLastRemainingElement(int index,
                             std::vector<std::string> &elements_to_keep,
                             const std::vector<std::string> &strings,
                             const std::string match_condition) {
  for (const auto &string: strings) {
    auto condition = [match_condition, index](const std::string &element) {
      return element.at(index) != match_condition.at(0);
    };

    elements_to_keep.erase(
      std::remove_if(elements_to_keep.begin(), elements_to_keep.end(), condition),
      elements_to_keep.end());
    }
  }

int getOxygenGeneratorRating(const std::vector<std::vector<int>> &numbers,
                             const std::vector<std::string> &strings) {
  std::vector<std::string> elements_to_keep = strings;
  for (int i = 0; i < numbers.size(); i++) {
    std::string most_common = getMostOccurence(numbers[i]) ? "1" : "0";
    getLastRemainingElement(i, elements_to_keep, strings, most_common);
    if (elements_to_keep.size() == 1) {
      return binaryToDecimal(elements_to_keep.at(0));
    }
  }
  return -1;
}

int getCO2ScrubberRating(const std::vector<std::vector<int>> &numbers,
                         const std::vector<std::string> &strings) {
  std::vector<std::string> elements_to_keep = strings;
  for (int i = 0; i < numbers.size(); i++) {
    std::string least_common = !getMostOccurence(numbers[i]) ? "1" : "0";
    getLastRemainingElement(i, elements_to_keep, strings, least_common);
    if (elements_to_keep.size() == 1) {
      return binaryToDecimal(elements_to_keep.at(0));
    }
  }
  return -1;
}
