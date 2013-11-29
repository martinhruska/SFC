#include "as_acs.hh"

#include <iostream>

float ACO::ASAcs::getEdgeProb(float thisEdge, float allEdges)
{
  if (actualRandom_ > randomConst_)
  {
    return thisEdge/allEdges;
  }
  return thisEdge;
}

void ACO::ASAcs::prepareStep()
{
  actualRandom_ = random_.getRandomNumberFromInterval(1000)/1000.0;
}
