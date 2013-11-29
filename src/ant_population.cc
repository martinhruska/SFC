#include "ant_population.hh"

ACO::AntPopulation::AntPopulation(int populationSize,
    float pheromonCoef, float distanceCoef, bool randomChoice) :
  antId_(0), populationSize_(populationSize), actAnt_(0),
  pheromonCoef_(pheromonCoef), distanceCoef_(distanceCoef),
  randomChoice_(randomChoice)
{
  populate();
}

/**
 * Returns random ant from population.
 */
ACO::Ant& ACO::AntPopulation::getRandomAnt()
{
  if (population_.size() == 0)
  { // no ants are available
    throw std::runtime_error(e_noMoreAnt);
  }

  // later chose one random
  return *(population_.back());
}

/**
 * Create populations with size defined
 * in populationSize_ data member
 */
void ACO::AntPopulation::populate()
{
  for (int i=0; i < populationSize_; i++)
  {
    Ant& a = populationMap_.insert(std::make_pair(antId_,
          Ant(antId_, pheromonCoef_, distanceCoef_, randomChoice_))). // ant initialization
      first->second;
    population_.push_back(&a);
    antId_++;
  }
}
