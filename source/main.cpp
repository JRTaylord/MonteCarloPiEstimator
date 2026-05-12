#include <cmath>
#include <iostream>
#include <string>
#include <random>

#include "lib.hpp"

static auto getDist(double x1, double y1, double x2, double y2) -> double {
  return sqrt(pow(x1 - x2, 2) - pow(y1-y2,2));
}

static auto approximate_pi() -> double {
  std::random_device rand;
  std::mt19937 gen(rand());
  std::uniform_real_distribution<double> dist(0.0, 1.0);

  const int length = 100;
  double points[length][2];

  for(auto & point : points) {
    point[0] = dist(gen);
    point[1] = dist(gen);
  }

  int pointsIn = 0;

  for (auto & point : points) {
    if(0.5 <= getDist(point[0],point[1],0.5,0.5)){
      pointsIn++;
    }
  }
  // Area of square is A = s^2
  // Area of circle is A = Pi*r^2

  return 0.0;
}

auto main() -> int
{
  double piApprox = approximate_pi();
  std::cout << piApprox << '\n';
  return 0;
}
