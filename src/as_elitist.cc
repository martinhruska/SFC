#include "as_elitist.hh"

#include "graph.hh"

#include <unordered_set>

/**
 * Update pheromon only on the best edges
 */
void ACO::ASElitist::updatePheromon(Graph& graph)
{
  for (Edge* e : graph.getEdges())
  {
      currentEdge_ = e;
      e->updatePheromon(*this);
  }
}

/**
 * An addition to a new pheromon value according to the elitist version
 * of ACO algorithm
 */
float ACO::ASElitist::getPheromonAddition(const float pheromonConst,
    unsigned int antsNum)
{
  std::unordered_set<Vertex *> bestPathSet(bestPath_.begin(), bestPath_.end());
  if (bestPathSet.count(&currentEdge_->getVertex1()) &&
      bestPathSet.count(&currentEdge_->getVertex2()))
  {
    return antsNum*pheromonConst/bestPathCost_;
  }

  return 0;
}
