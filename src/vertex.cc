#include "vertex.hh"
#include "edge.hh"

/**
 * Fill given set with ids of neighbours of vertex
 */
void ACO::Vertex::getAllNeighboursId(std::unordered_set<int>& neighbours)
{
  for (Edge* e : edges_)
  {
    neighbours.insert(e->getSecondVertex(*this).getId());
  }
}

/**
 * Fill a given set with pointers to neighbours
 */
void ACO::Vertex::getAllNeighbours(std::unordered_set<Vertex *>& neighbours)
{
  for (Edge* e : edges_)
  {
    neighbours.insert(&e->getSecondVertex(*this));
  }
}

/**
 * Operator of comparsion
 */
bool ACO::Vertex::operator==(const ACO::Vertex& vertex) const
{
  return getId() == vertex.getId();
}
