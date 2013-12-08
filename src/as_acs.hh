#ifndef ACC_AS_ACS
#define ACS_AS_ACS

/****************************************************************
 * ACO algorithm
 * Project to Soft computing at FIT BUT
 * Author: Martin Hruska
 * E-mail: xhrusk16@stud.fit.vutbr.cz
 *
 * Ant Colony System implementation class.
 ****************************************************************/

#include "as_implementation.hh"
#include "random_provider.hh"

namespace ACO
{
  class ASAcs;
}

class ACO::ASAcs : public ACO::ASImplementation 
{
private: // private data members
  float randomConst_;
  RandomProvider random_;
  float actualRandom_;

public: // public constructors
  ASAcs(float randomConst, RandomProvider random) :
    randomConst_(randomConst), random_(random), actualRandom_(0.5f)
  {}

public: //public methods
  virtual float getEdgeProb(float thisEdge, float allEdges);
  virtual void prepareStep();
};

#endif
