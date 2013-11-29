#include "as_implementation.hh"
#include "graph.hh"

/**
 * Updates pheromon on the edges of a given graph
 */
void ACO::ASImplementation::updatePheromon(Graph& graph)
{
  for (Edge* e : graph.getEdges())
  {
    e->updatePheromon(*this);
  }
}

/**
 * Compute delta for a given distance (legnth of edge) and constants
 */
float ACO::ASImplementation::makeOneDelta(float pheromonConst,
    float distance, Ant* ant, int order)
{
  return pheromonConst/ant->getPathCost();
}

/**
 * An addition to a new pheromon value which is zero in default
 * implementation of the algorithm
 */
float ACO::ASImplementation::getPheromonAddition(const float pheromonConst,
    unsigned int antsNum)
{
  return 0.0f;
}

/**
 * No max min values are used in default algorithm.
 */
float ACO::ASImplementation::maxMinCorrection(float pheromon)
{
  return pheromon;
}

float ACO::ASImplementation::getEdgeProb(float thisEdge, float allEdges)
{
  if (allEdges == 0)
  {
    return 0;
  }
  return thisEdge/allEdges;
}

void ACO::ASImplementation::prepareStep()
{
  return;
}
