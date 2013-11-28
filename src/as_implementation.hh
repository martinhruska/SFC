#ifndef ACO_AS_IMPL
#define ACO_AS_IMPL

#include "ant_population.hh"
#include "ant.hh"

namespace ACO
{
  class ASImplementation;
  class Graph;
}

class ACO::ASImplementation
{
private: // private data types
  typedef Ant::Path Path;
  typedef Ant::PathCost PathCost;

protected: // private data members
  Path bestPath_;
  PathCost bestPathCost_;
  Ant* bestAnt_;

public: // public constructors
  ASImplementation() : bestPathCost_(1.0f), bestAnt_(NULL)
  {}

  ~ASImplementation()
  {}

public:
  virtual float makeOneDelta(const float pheromonConst, float distance,
      Ant* ant, int order);
  virtual float getPheromonAddition(const float pheromonConst, unsigned int antsNum);
  virtual void updatePheromon(Graph& graph);
  virtual float maxMinCorrection(float pheromon);

public: // settters
  void setBestPath(Path& path) {bestPath_ = path;}
  void setBestPathCost(PathCost cost) {bestPathCost_ = cost;}
  void setBestAnt(Ant* ant) {bestAnt_ = ant;}
};

#endif
