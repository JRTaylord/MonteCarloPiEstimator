#include <iostream>
#include <string>

#include "lib.hpp"

static auto approximate_pi() -> double {
  return 0.0;
}

auto main() -> int
{
  double piApprox = approximate_pi();
  std::cout << piApprox << '\n';
  return 0;
}
