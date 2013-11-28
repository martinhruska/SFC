#ifndef ACO_AS_ELITIST
#define ACO_AS_ELITIST

#include "as_implementation.hh"

namespace ACO
{
  class ASElitist;
  class Graph;
}

class ACO::ASElitist : public ASImplementation
{
public:
  virtual float getPheromonAddition(const float pheromonConst, unsigned int antsNum);
  virtual void updatePheromon(Graph& graph);
};

#endif
