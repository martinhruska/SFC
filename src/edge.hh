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
  const float newPheromonCoef_;
  const float evaporationCoef_;

public: // constructor
  Edge(int id, Vertex& v1, Vertex& v2, Distance distance) : id_(id),
    v1_(v1), v2_(v2), distance_(distance), pheromon_(0.1f), newPheromonCoef_(3.0f),
    evaporationCoef_(0.5f) {}

public: // public methods
  Vertex& getSecondVertex(Vertex& v);
  void addAnt(Ant *a) {passedAnts_.push_back(a);}
  void clearAnt() {passedAnts_.clear();}
  void updatePheromon();
  void restart();

public: // public getters
  int getId() {return id_;}
  const Vertex& getVertex1() const {return v1_;}
  const Vertex& getVertex2() const {return v2_;}
  Distance getDistance() {return distance_;}
  Pheromon getPheromon() {return pheromon_;}
};

#endif
