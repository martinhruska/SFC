#ifndef ACO_ANT_POPULATION
#define ACO_ANT_POPULATION

#include <string>
#include <vector>

#include "ant.hh"

namespace ACO
{
  class AntPopulation;
}

class ACO::AntPopulation
{
private: // private data types
  typedef std::vector<Ant> Population;

private: // private constants
  std::string e_noMoreAnt = "No ant are available";

public: // data members
  int antId_;
  int populationSize_;
  Population population_;

public: // constructor
  AntPopulation(int populationSize) : antId_(0),
    populationSize_(populationSize) {}

public: // public methods
  Ant& getRandomAnt();

private: // private methods
  void populate();
};

#endif
