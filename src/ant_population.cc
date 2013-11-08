#include "ant_population.hh"

ACO::AntPopulation::AntPopulation(int populationSize) :
  antId_(0), populationSize_(populationSize)
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
  return population_.back();
}


/**
 * Create populations with size defined
 * in populationSize_ data member
 */
void ACO::AntPopulation::populate()
{
  for (int i=0; i < populationSize_; i++)
  {
    population_.push_back(Ant(antId_++));
  }
}
