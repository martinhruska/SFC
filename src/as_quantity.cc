#include "as_quantity.hh"

float ACO::ASQuantity::makeOneDelta(float pheromonConst,
    float distance, Ant* ant, int order)
{
  return pheromonConst/distance;
}
