#include "lib.hpp"

auto main() -> int
{
  auto const lib = library {};

  return lib.name == "MonteCarloPiEstimator" ? 0 : 1;
}
