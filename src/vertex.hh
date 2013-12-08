#ifndef ACO_VERTEX
#define ACO_VERTEX

/****************************************************************
 * ACO algorithm
 * Project to Soft computing at FIT BUT
 * Author: Martin Hruska
 * E-mail: xhrusk16@stud.fit.vutbr.cz
 *
 * Class for representation of vertex.
 ****************************************************************/

#include <unordered_set>
#include <string>

#include "aco_classes.hh"

// Class declared in edge.hh

class ACO::Vertex
{
private: // private data types
  typedef std::string String;
  typedef std::unordered_set<Edge *> Edges;
private:
  String name_; // name of vertex
  int id_; // id of vertex
  Edges edges_;

public: // constructor
  Vertex(String name, int id) : name_(name), id_(id) {}

public: // public methods
  void getAllNeighboursId(std::unordered_set<int>& neighbours);
  void getAllNeighbours(std::unordered_set<Vertex *>& neighbours);
  void addEdge(Edge *edge) {edges_.insert(edge);}

public: // getters and setters
  int getId() const {return id_;}
  const String& getName() const {return name_;}
  unsigned int getSizeEdges() {return edges_.size();}
  const Edges& getEdges() const {return edges_;}

public: //operators
  bool operator ==(const Vertex& vertex) const;
};

#endif
