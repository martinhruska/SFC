#ifndef ACO_VERTEX
#define ACO_VERTEX

#include <unordered_set>
#include <string>

#include "edge.hh"

// Class declared in edge.hh

class ACO::Vertex
{
private: // private data types
  typedef std::string String;
  
private:
  String name_; // name of vertex
  int id_; // id of vertex
  std::unordered_set<Edge *> edges_;

public: // constructor
  Vertex(String name, int id) : name_(name), id_(id) {}

public: // public methods
  void getAllNeighboursId(std::unordered_set<int>& neighbours);
  void addEdge(Edge *edge) {edges_.insert(edge);}

public: // getters and setters
  int getId() const {return id_;}

public: //operators
  bool operator ==(const Vertex& vertex) const;

};

#endif
