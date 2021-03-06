#ifndef ACO_ACO_ALGORITHM
#define ACO_ACO_ALGORITMH

/****************************************************************
 * ACO algorithm
 * Project to Soft computing at FIT BUT
 * Author: Martin Hruska
 * E-mail: xhrusk16@stud.fit.vutbr.cz
 *
 * Aco algorithm execution
 ****************************************************************/


#include "ant_population.hh"
#include "graph.hh"
#include "random_provider.hh"
#include "as_implementation.hh"

#include <cfloat>

namespace ACO
{
  class ACOAlgorithm;
}

class ACO::ACOAlgorithm
{
private: // private data types
  // ants withou wrapping object
  typedef std::vector<Ant*> RawPopulation;
  typedef Ant::Path Path;
  typedef Ant::PathCost PathCost;

private: // private data memebers
  AntPopulation population_;
  Graph graph_;
  RandomProvider random_;
  int maxIteration_;
  PathCost bestPathCost_;
  Path bestPath_;
  Ant* bestAnt_;
  ASImplementation& as_;
  bool verbose_;

public: // constructors
  ACOAlgorithm(AntPopulation population, Graph graph, RandomProvider random,
      int maxIter, ASImplementation& as, bool verbose) :
    population_(population), graph_(graph), random_(random),
    maxIteration_(maxIter), bestPathCost_(FLT_MAX), bestAnt_(NULL),
    as_(as), verbose_(verbose)
  {}

public: // public methods
  void compute();
  Path& getResult();
  PathCost getPathCost() {return bestPathCost_;}

private: // private methods
  void setRandomVertices();
  void createAntSolution();
  bool isGoalReached(Ant& ant);
  bool isPathComplete(Ant& ant);
  void saveBestPath();
  void updatePheromon();
  void restart();
  std::string printPath(Path path);
};

#endif
