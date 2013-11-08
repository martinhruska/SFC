#ifndef ACO_ANT
#define ACO_ANT

#include <vector>
#include <unordered_set>

#include "aco_classes.hh"

class ACO::Ant
{
private: // private data types
  typedef std::vector<Vertex *> Vertices;
  typedef std::unordered_set<Edge *> Edges;
  typedef float PathCost;

private: // private data members
  int id_;
  Vertices visitedVertices_;
  Edges visitedEdges_;
  PathCost pathCost_;
  bool goalSatisfied_;

public: // public constructors
  Ant(int id) : id_(id), pathCost_(0), goalSatisfied_(false) {};

public: // public methods
  void makeStep();
  void restart();

public: // getters
  int getId() {return id_;}
  const Vertices& getVisitedVertices() const {return visitedVertices_;}
  bool isGoalSatisfied() {return goalSatisfied_;}

public: // setters
  void setGoalStatisfied() {goalSatisfied_ = true;}
};
#endif
