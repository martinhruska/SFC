#include "random_provider.hh"

#include <stdlib.h>
#include <time.h>

ACO::RandomProvider::RandomProvider()
{
  srand(time(NULL));
}

/**
 * Returns random number
 */
int ACO::RandomProvider::getRandomNumber()
{
  return rand();
}

/**
 * Get random number from interval
 */
int ACO::RandomProvider::getRandomNumberFromInterval(int interval)
{
  return getRandomNumber()%interval;
}
