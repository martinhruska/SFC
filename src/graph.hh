#ifndef ACO_GRAPH
#define ACO_GRAPH

#include <vector>

#include "vertex.hh"
#include "edge.hh"

namespace ACO
{
  class Graph;
}

class ACO::Graph
{
private: // private data members
  std::vector<Vertex *> vertices_;
  std::vector<Edge *> edges_;

public: // public methods
  Graph() {};

  void addVertex(Vertex *vertex) {vertices_.push_back(vertex);}
  void addEdge(Edge * edge) {edges_.push_back(edge);}

  Vertex* getRandomVertex();
  Edge* getRandomEdge();
};

#endif
