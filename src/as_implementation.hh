#ifndef ACO_AS_IMPL
#define ACO_AS_IMPL

namespace ACO
{
  class ASImplementation;
}

class ACO::ASImplementation
{
public:
  virtual float makeOneDelta(float pheromonConst, float distance, float pathCost);
};

#endif
