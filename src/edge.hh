#ifndef ACO_EDGE
#define ACO_EDGE

#include <vector>

#include "aco_classes.hh"

class ACO::Edge
{
public: // public data types
  typedef float Distance;
  typedef float Pheromon;
  typedef std::vector<Ant *> AntSet;

private: // private data memebers
  int id_;
  Vertex& v1_;
  Vertex& v2_;
  Distance distance_;
  Pheromon pheromon_;
  AntSet passedAnts_;

public: // constructor
  Edge(int id, Vertex& v1, Vertex& v2, Distance distance) : id_(id),
    v1_(v1), v2_(v2), distance_(distance), pheromon_(0.0f) {}

public: // public methods
  Vertex& getSecondVertex(Vertex& v);
  void addAnt(Ant *a) {passedAnts_.push_back(a);}
  void clearAnt() {passedAnts_.clear();}
  void updatePheromon();

public: // public getters
  Vertex& getVertex1() {return v1_;}
  Vertex& getVertex2() {return v2_;}
  Distance getDistance() {return distance_;}
  Pheromon getPheromon() {return pheromon_;}
};

#endif
