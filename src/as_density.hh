#ifndef ACO_AS_DENSITY
#define ACO_AS_DENSITY

/****************************************************************
 * ACO algorithm
 * Project to Soft computing at FIT BUT
 * Author: Martin Hruska
 * E-mail: xhrusk16@stud.fit.vutbr.cz
 *
 * Ant System Density implementation class header.
 ****************************************************************/

#include "as_implementation.hh"

namespace ACO
{
  class ASDensity;
}

class ACO::ASDensity : public ACO::ASImplementation
{
public:
  virtual float makeOneDelta(float pheromonConst, float distance, Ant* ant, int order);
};

#endif
