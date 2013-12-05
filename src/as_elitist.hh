#ifndef ACO_AS_ELITIST
#define ACO_AS_ELITIST

#include "as_implementation.hh"

namespace ACO
{
  class ASElitist;
  class Graph;
  class Edge;
}

class ACO::ASElitist : public ASImplementation
{
private: // private data members
  Edge *currentEdge_;
public:
  virtual float getPheromonAddition(const float pheromonConst, unsigned int antsNum);
  virtual void updatePheromon(Graph& graph);
};

#endif
