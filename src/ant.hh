#ifndef ACO_ANT
#define ACO_ANT

#include <vector>
#include <unordered_set>
#include <string>
#include <cfloat>

#include "aco_classes.hh"

class ACO::Ant
{
public: // public data types
  typedef std::vector<Vertex *> Path;
  typedef float PathCost;
private: // private data types
  typedef std::unordered_set<Vertex *> Vertices;
  typedef std::unordered_set<Edge *> Edges;

private: // private error messages
  std::string e_vertexAlreadyVisited = "Vertex has been already visited";
  std::string e_noBestEdge = "No best edge found";
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
  void returnToStart();

private: // private methods
  void addVertexToVisited(Vertex* v);
  float sumAllEdges(); // sum pheromon times distance for all edges
  Edge* getBestEdge(float allEdges); // get edge with best probability to be chosen

public: // getters
  int getId() {return id_;}
  const Vertices& getVisitedVertices() const {return visitedVertices_;}
  int getVisitedVerticesNumber() {return visitedVertices_.size();}
  bool isGoalSatisfied() {return goalSatisfied_;}
  PathCost getPathCost() {return pathCost_;}
  Path& getPath() {return path_;}

public: // setters
  void setGoalStatisfied() {goalSatisfied_ = true;}
  void setActualVertex(Vertex* v);
};
#endif
