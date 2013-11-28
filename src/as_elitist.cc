#include "as_elitist.hh"

#include "graph.hh"

#include <unordered_set>

/**
 * Update pheromon only on the best edges
 */
void ACO::ASElitist::updatePheromon(Graph& graph)
{
  std::unordered_set<Vertex *> bestPathSet(bestPath_.begin(), bestPath_.end());
  for (Edge* e : graph.getEdges())
  {
    if (bestPathSet.count(&e->getVertex1()) && bestPathSet.count(&e->getVertex2()))
    {
      e->updatePheromon(*this);
    }
  }
}

/**
 * An addition to a new pheromon value according to the elitist version
 * of ACO algorithm
 */
float ACO::ASElitist::getPheromonAddition(const float pheromonConst,
    unsigned int antsNum)
{
  return antsNum*pheromonConst/bestPathCost_;
}
