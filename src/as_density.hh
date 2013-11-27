#ifndef ACO_AS_DENSITY
#define ACO_AS_DENSITY

#include "as_implementation.hh"

namespace ACO
{
  class ASDensity;
}

class ACO::ASDensity : public ACO::ASImplementation
{
public:
  virtual float makeOneDelta(float pheromonConst, float distance, float pathCost);
};

#endif
