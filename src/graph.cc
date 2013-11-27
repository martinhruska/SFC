#include "graph.hh"

#include <stdexcept>
#include <iostream>

/**
 * Return pointer to Vertex object.
 * If vertex with a name given in paramater was not already
 * created, it creates a new one and stores it to the
 * hash map.
 */
ACO::Vertex& ACO::Graph::translateVertex(String& name)
{
  if (verticesTranslator_.count(name) == 0)
  { // added verices to translator, backtranslator and to list of vertices
    Vertex& v = verticesTranslator_.insert(std::make_pair(name, Vertex(name, vertexId_))).first->second;
    verticesBackTranslator_.insert(std::make_pair(vertexId_, name));
    vertexId_++;
    vertices_.push_back(&v);
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
ACO::Edge& ACO::Graph::addEdge(Vertex& v1, Vertex& v2, Distance distance)
{
  std::unordered_set<int> v1Neighbours;

  v1.getAllNeighboursId(v1Neighbours);

  if (v1Neighbours.count(v2.getId()) != 0)
  { // vertices allready connected
    throw std::runtime_error(e_edgeAlreadyDeclared);
  }

  std::pair<int, Edge> pair(edgeId_,
      Edge(edgeId_, v1, v2, distance, pheromonConst_, evaporationCoef_));
  edgeId_++;
  Edge& e = edgesTranslator_.insert(pair).first->second;
  edges_.push_back(&e);
  v1.addEdge(&e);
  v2.addEdge(&e);
  return e;
}

/**
 * Serializes graph to string
 */
std::string ACO::Graph::serialize()
{
  String res;

  for (Edge* e : edges_)
  { // add edges to result
    res += e->getVertex1().getName() + " " + e->getVertex2().getName()
      + " " + std::to_string(e->getDistance()) + "\n";
  }

  return res;
}

ACO::Vertex* ACO::Graph::getRandomVertex()
{
  return nullptr;
}

ACO::Edge* ACO::Graph::getRandomEdge()
{
  return nullptr;
}

/**
 * Checks whether for each vertex is defined edge to all other vertices
 */
bool ACO::Graph::checkCompletness()
{
  for (Vertex* v : vertices_)
  {
    if (v->getSizeEdges() != vertices_.size()-1)
    {
      return false;
    }
  }

  return true;
}
