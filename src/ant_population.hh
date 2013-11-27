#ifndef ACO_ANT_POPULATION
#define ACO_ANT_POPULATION

#include <string>
#include <vector>
#include <unordered_map>

#include "ant.hh"

namespace ACO
{
  class AntPopulation;
}

class ACO::AntPopulation
{
public: // private data types
  typedef std::vector<Ant*> Population;
  typedef std::unordered_map<int,Ant> PopulationMap;

private: // private constants
  std::string e_noMoreAnt = "No ants are available";

public: // data members
  int antId_;
  int populationSize_;
  int actAnt_;
  Population population_;
  PopulationMap populationMap_;
  const float pheromonCoef_; // weight of pheromon in ant step
  const float distanceCoef_; // weight of distance in ant step

public: // constructor
  AntPopulation(int populationSize, float pheromonCoef, float distanceCoef);

public: // public methods
  Ant& getRandomAnt();
  Ant& getNextAnt() {return *(population_.at(actAnt_++));}

private: // private methods
  void populate();

public: // getters
  Population& getPopulation() {return population_;}
};

#endif
