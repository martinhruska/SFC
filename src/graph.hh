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
public: // public data types
  typedef Edge::Distance Distance;
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

public: // constructors
  Graph() : vertexId_(0), edgeId_(0) {};

public: // public methods
  // Translates vertex from string to intern representation
  Vertex& translateVertex(String& name);
  // Add edge if it is not already present in graph
  Edge& addEdge(Vertex& v1, Vertex& v2, Distance distance);
  // Serializes graph to string
  String serialize();
  Vertex* getRandomVertex();
  Edge* getRandomEdge();
};

#endif
