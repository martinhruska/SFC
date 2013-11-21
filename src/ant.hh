#ifndef ACO_ANT
#define ACO_ANT

#include <vector>
#include <unordered_set>
#include <string>

#include "aco_classes.hh"

class ACO::Ant
{
private: // private data types
  typedef std::vector<Vertex *> Path;
  typedef std::unordered_set<Vertex *> Vertices;
  typedef std::unordered_set<Edge *> Edges;
  typedef float PathCost;

private: // private error messages
  const std::string e_vertexAlreadyVisited = "Vertex has been already visited";
private: // private data members
  int id_;
  Vertex* actualVertex_;
  Vertices visitedVertices_;
  Path path_;
  Edges visitedEdges_;
  PathCost pathCost_;
  bool goalSatisfied_;

public: // public constructors
  Ant(int id) : id_(id), actualVertex_(NULL), pathCost_(0), goalSatisfied_(false) {};

public: // public methods
  void makeStep();
  void restart();

private: // private methods
  void addVertexToVisited(Vertex* v);

public: // getters
  int getId() {return id_;}
  const Vertices& getVisitedVertices() const {return visitedVertices_;}
  int getVisitedVerticesNumber() {return visitedVertices_.size();}
  bool isGoalSatisfied() {return goalSatisfied_;}

public: // setters
  void setGoalStatisfied() {goalSatisfied_ = true;}
  void setActualVertex(Vertex* v);
};
#endif
