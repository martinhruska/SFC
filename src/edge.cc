#include "edge.hh"
#include "vertex.hh"
#include "ant.hh"

#include <iostream>
#include <algorithm>

/**
 * Get the second vertex when the first one is
 * given as a parameter.
 */
ACO::Vertex& ACO::Edge::getSecondVertex(Vertex& v)
{
  if (v == v1_)
  {
    return v2_;
  }
  else
  {
    return v1_;
  }
}

/**
 * Update current level of pheromon according to
 * passed ants.
 */
void ACO::Edge::updatePheromon(ASImplementation& as)
{
  float sumDelta = 0.0f;

  int i=1; // ant order for rank based alg
  for (Ant *a : passedAnts_)
  {
    if (!a->isGoalSatisfied())
    {
      continue;
    }
    sumDelta += as.makeOneDelta(pheromonConst_, distance_, a, i++);
  }
  //std::cerr << "A old pheromon value is " << pheromon_ << std::endl;
  //std::cerr << "Delta is " << sumDelta << std::endl;
  pheromon_ = (1-evaporationCoef_)*pheromon_ + sumDelta;
  pheromon_ += as.getPheromonAddition(pheromonConst_, passedAnts_.size());
  pheromon_ = as.maxMinCorrection(pheromon_);
  //std::cerr << "A new pheromon value is " << pheromon_ << std::endl;
}

/**
 * Order ants passed through this edge by the quality
 * of their solution
 */
void ACO::Edge::orderAnts()
{
  auto comp = [] (Ant* a1, Ant *a2) -> bool {
      return a1->getPathCost() <= a2->getPathCost();};

  std::sort(passedAnts_.begin(), passedAnts_.end(), comp);
}

/**
 * Restarts edges data members before a next iteration
 */
void ACO::Edge::restart()
{
  passedAnts_.clear();
}
