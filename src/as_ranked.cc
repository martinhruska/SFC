#include "as_ranked.hh"
#include "graph.hh"

float ACO::ASRanked::makeOneDelta(float pheromonConst,
    float distance, Ant* ant, int order)
{
  if (order > maxAnts_)
  {
    return 0;
  }
  return (maxAnts_-order)*pheromonConst/ant->getPathCost();
}

/**
 * Updates pheromon on the edges of a given graph
 */
void ACO::ASRanked::updatePheromon(Graph& graph)
{
  for (Edge* e : graph.getEdges())
  {
    e->updatePheromon(*this);
  }
}

float ACO::ASRanked::getPheromonAddition(const float pheromonConst,
    unsigned int antsNum)
{
  return maxAnts_*pheromonConst/bestPathCost_;
}


