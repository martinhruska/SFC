#ifndef ACO_AS_MAXMIN
#define ACO_AS_MAXMIN

/****************************************************************
 * ACO algorithm
 * Project to Soft computing at FIT BUT
 * Author: Martin Hruska
 * E-mail: xhrusk16@stud.fit.vutbr.cz
 *
 * Ant System MaxMin implementation class header.
 ****************************************************************/

#include "as_implementation.hh"

namespace ACO
{
  class ASMaxMin;
  class Graph;
}

class ACO::ASMaxMin : public ACO::ASImplementation
{
private:
  float pheromonMax_;
  float pheromonMin_;

public: // public constructors
  ASMaxMin(float max, float min) : pheromonMax_(max), pheromonMin_(min)
  {}

public: // public methods
  virtual float makeOneDelta(const float pheromonConst, float distance, Ant* ant,
      int order);
  virtual void updatePheromon(Graph& graph);
  virtual float maxMinCorrection(float pheromon);
};

#endif
