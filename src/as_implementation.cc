#include "as_implementation.hh"

float ACO::ASImplementation::makeOneDelta(float pheromonConst,
    float distance, float pathCost)
{
  return pheromonConst/pathCost;
}
