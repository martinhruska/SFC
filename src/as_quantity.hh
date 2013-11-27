#ifndef ACO_AS_QUANTITY
#define ACO_AS_QUANTITY

#include "as_implementation.hh"

namespace ACO
{
  class ASQuantity;
}

class ACO::ASQuantity : public ACO::ASImplementation
{
public:
  virtual float makeOneDelta(float pheromonConst, float distance, float pathCost);
};

#endif
