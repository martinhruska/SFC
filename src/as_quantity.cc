#include "as_quantity.hh"

float ACO::ASQuantity::makeOneDelta(float pheromonConst,
    float distance, float pathCost)
{
  return pheromonConst/distance;
}
