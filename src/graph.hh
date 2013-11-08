#ifndef ACO_GRAPH
#define ACO_GRAPH

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

#include "edge.hh"
#include "vertex.hh"

namespace ACO
{
  class Graph;
}

class ACO::Graph
{
private: // private data types
  typedef std::string String;

private: // private constants
  const String e_edgeAlreadyDeclared = "The edge has been already declared";

private: // private data members
  int vertexId_;
  int edgeId_;

  std::unordered_set<Vertex *> vertices_;
  std::vector<Edge> edges_;

  std::unordered_map<String, Vertex> verticesTranslator_;

public: // public methods
  Graph() : vertexId_(0), edgeId_(0) {};

  Vertex& translateVertex(String& name);

  //void addVertex(Vertex *vertex) {vertices_.push_back(vertex);}
  Edge& addEdge(Vertex& v1, Vertex& v2, int distance);

  Vertex* getRandomVertex();
  Edge* getRandomEdge();
};

#endif
