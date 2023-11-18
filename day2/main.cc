#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::string> split_string(std::string string, const std::string &delimiter);

struct Movement;


int main() {
  int depth = 0;
  int position = 0;

  const std::string delimiter = " ";
  Movement movement = Movement();

  std::string line;
  std::ifstream file("test.txt");

  if (file.is_open()) {
    while (std::getline(file, line)) {
      std::vector<std::string> string = split_string(line, delimiter); 
      std::string command = string.at(0);
      int value = std::stoi(string.at(1));
      std::cout << command << " " << value << '\n';
      switch (command) {
        case Movement.forward:
          position += value;
          break;
        case "down":
          depth += value;
          break;
        case "up":
          depth -= value;
          break;
      }
    }
  }
}

struct Movement {
  std::string forward = "forward";
  std::string down = "down";
  std::string up = "up";
};

std::vector<std::string> split_string(std::string string, const std::string &delimiter) {
  size_t pos;
  std::vector <std::string> tokens;
  while ((pos = string.find(delimiter)) != std::string::npos) {
    tokens.push_back(string.substr(0, pos));
    string.erase(0, pos + delimiter.length());
  }
  tokens.push_back(string);
  return tokens;
}
