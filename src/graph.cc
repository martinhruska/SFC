#include "graph.hh"

#include <stdexcept>

/**
 * Return pointer to Vertex object.
 * If vertex with a name given in paramater was not already
 * created, it creates a new one and stores it to the
 * hash map.
 */
ACO::Vertex& ACO::Graph::translateVertex(String& name)
{
  if (verticesTranslator_.count(name) == 0)
  {
    std::pair<std::string, Vertex> pair(name, Vertex(name, vertexId_++));
    Vertex& v = verticesTranslator_.insert(pair).first->second;
    vertices_.insert(&v);

    return v;
  }
  else
  {
    return verticesTranslator_.find(name)->second;
  }
}

/**
 * Add a new edge which connects vertices v1 and v2
 * and has a concrete distance.
 * It checks whether vertices are not already connected first,
 * and they are not the edge is added.
 */
ACO::Edge& ACO::Graph::addEdge(Vertex& v1, Vertex& v2, int distance)
{
  std::unordered_set<int> v1Neighbours;

  v1.getAllNeighboursId(v1Neighbours);

  if (v1Neighbours.count(v2.getId()) != 0)
  { // vertices allready connected
    throw std::runtime_error(e_edgeAlreadyDeclared);
  }
 
  edges_.push_back(Edge(v1, v2, distance));
  Edge& e = edges_.back();
  v1.addEdge(&e);
  v2.addEdge(&e);
  return e;
}

ACO::Vertex* ACO::Graph::getRandomVertex()
{
  return nullptr;
}

ACO::Edge* ACO::Graph::getRandomEdge()
{
  return nullptr;
}
