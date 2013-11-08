#include "edge.hh"
#include "vertex.hh"

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
void updatePheromon()
{
  return;
}
