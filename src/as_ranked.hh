#ifndef ACO_AS_RANKED
#define ACO_AS_RANKED

/****************************************************************
 * ACO algorithm
 * Project to Soft computing at FIT BUT
 * Author: Martin Hruska
 * E-mail: xhrusk16@stud.fit.vutbr.cz
 *
 * Rank based Ant System implementation class header.
 ****************************************************************/

#include "as_implementation.hh"

namespace ACO
{
  class ASRanked;
  class Graph;
}

class ACO::ASRanked : public ACO::ASImplementation
{
private: // private data members
  int maxAnts_;

public: // public constructors
  ASRanked(int maxAnts) : maxAnts_(maxAnts)
  {}

public: // public methods
  virtual float makeOneDelta(const float pheromonConst, float distance,
      Ant* ant, int order);
  virtual void updatePheromon(Graph& graph);
  virtual float getPheromonAddition(const float pheromonConst, unsigned int antsNum);
};

#endif
