#ifndef ACO_AS_ELITIST
#define ACO_AS_ELITIST

/****************************************************************
 * ACO algorithm
 * Project to Soft computing at FIT BUT
 * Author: Martin Hruska
 * E-mail: xhrusk16@stud.fit.vutbr.cz
 *
 * Ant System Elitisti strategy implementation class header.
 ****************************************************************/

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
