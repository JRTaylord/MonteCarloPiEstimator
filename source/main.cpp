#include <cmath>
#include <iostream>
#include <string>
#include <random>

#include "lib.hpp"

static auto getDist(double x1, double y1, double x2, double y2) -> double {
  return sqrt(pow(x1 - x2, 2) + pow(y1-y2,2));
}

static auto approximate_pi() -> double {
  std::random_device rand;
  std::mt19937 gen(rand());
  std::uniform_real_distribution<double> dist(0.0, 1.0);

  const int pointsTotal = 1000000;

  int pointsIn = 0;

  for (int i=0; i<pointsTotal; i++) {
    if(0.5 >= getDist(dist(gen),dist(gen),0.5,0.5)){
      pointsIn++;
    }
  }
  // Area of square is A = s^2
  // Area of circle is A = Pi*r^2
  //
  // The percentage of points in the circle should be pointsIn/pointsTotal = (Pi*r^2)/(s^2)
  // Then I need to pull Pi out from this:
  // pointsTotal/pointsIn = (s^2)/(Pi*r^2)
  // Pi * pointsTotal/pointsIn = (s^2)/(r^2)
  // Pi = (s^2)/(r^2) * pointsIn/pointsTotal
  // Pi = (r*2)^2)/(r^2) * pointsIn/pointsTotal
  // Pi = (r*r*4)/(r*r) * pointsIn/pointsTotal
  // Pi = 4 * pointsIn/pointsTotal
  std::cout << "pointsIn: " << pointsIn << '\n';
  std::cout << "pointsTotal: " << pointsTotal << '\n';

  return 4.0 * static_cast<double>(pointsIn)/static_cast<double>(pointsTotal);
}

auto main() -> int
{
  double piApprox = approximate_pi();
  std::cout << "Pi is:" << '\n';
  std::cout << piApprox << '\n';
  return 0;
}
