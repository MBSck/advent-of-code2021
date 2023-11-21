#include <stdio.h>
#include <vector>
#include <string>

#include "readfile.h"


struct Movement {
  int depth;
  int position;
  int aim;
};


Movement get2DMovement(std::vector<std::pair<std::string, int>> &values);
Movement get3DMovement(std::vector<std::pair<std::string, int>> &values);


int main() {
  std::vector<std::pair<std::string, int>> values = readFileToVectorTuple("input.txt");
  Movement movement = get2DMovement(values);
  printf("Multiplication of position and depth 2D: %d\n", movement.position*movement.depth);

  movement = get3DMovement(values);
  printf("Multiplication of position and depth 3D: %d\n", movement.position*movement.depth);
}


Movement get2DMovement(std::vector<std::pair<std::string, int>> &values) {
  Movement position {0, 0, 0};
  for (const auto &value: values) {
    if (value.first == "forward") {
      position.position += value.second;
    } else if (value.first == "down") {
      position.depth += value.second;
    } else if (value.first == "up") {
      position.depth -= value.second;
    }
  }
  return position;
}


Movement get3DMovement(std::vector<std::pair<std::string, int>> &values) {
  Movement position {0, 0, 0};
  for (const auto &value: values) {
    if (value.first == "forward") {
      position.position += value.second;
      position.depth += position.aim * value.second;
    } else if (value.first == "down") {
      position.aim += value.second;
    } else if (value.first == "up") {
      position.aim -= value.second;
    }
  }
  return position;
}
