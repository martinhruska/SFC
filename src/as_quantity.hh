#ifndef ACO_AS_QUANTITY
#define ACO_AS_QUANTITY

/****************************************************************
 * ACO algorithm
 * Project to Soft computing at FIT BUT
 * Author: Martin Hruska
 * E-mail: xhrusk16@stud.fit.vutbr.cz
 *
 * Ant System Quantity implementation class header.
 ****************************************************************/

#include "as_implementation.hh"

namespace ACO
{
  class ASQuantity;
}

class ACO::ASQuantity : public ACO::ASImplementation
{
public:
  virtual float makeOneDelta(float pheromonConst, float distance, Ant *ant,
      int order);
};

#endif
