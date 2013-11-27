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

private: // private data types
  typedef std::unordered_map<int, Edge> EdgesTranslator;
  typedef std::unordered_map<String, Vertex> VerticesTranslator;
  typedef std::unordered_map<int, String> VerticesBackTranslator;
  typedef std::vector<Edge *> Edges;
  typedef std::vector<Vertex *> Vertices;
private: // private data members
  int vertexId_;
  int edgeId_;

  Vertices vertices_;
  Edges edges_;

  VerticesTranslator verticesTranslator_;
  VerticesBackTranslator verticesBackTranslator_;
  EdgesTranslator edgesTranslator_;
  
  // coeficients for edges
  const float pheromonConst_;
  const float evaporationCoef_;

public: // constructors
  Graph(float pheromonConst, float evaporationCoef) : vertexId_(0),
    edgeId_(0), pheromonConst_(pheromonConst),
    evaporationCoef_(evaporationCoef)
  {};

public: // public methods
  // Translates vertex from string to intern representation
  Vertex& translateVertex(String& name);
  // Add edge if it is not already present in graph
  Edge& addEdge(Vertex& v1, Vertex& v2, Distance distance);
  // Serializes graph to string
  String serialize();
  Vertex* getRandomVertex();
  Edge* getRandomEdge();

  bool checkCompletness();

public: // public getters
  int getEdgesNumber() {return edges_.size();}
  int getVerticesNumber() {return vertices_.size();}
  Vertex* getVertexAt(int position) {return vertices_.at(position);}
  const Vertices& getVertices() const {return vertices_;}
  const String& getTranslationFromId(int id) const {return verticesBackTranslator_.at(id);}
  const Edges& getEdges() {return edges_;}
};

#endif
