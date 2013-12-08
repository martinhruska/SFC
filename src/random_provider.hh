#ifndef ACO_RANDOM_PROVIDER
#define ACO_RANDOM_PROVIDER

/****************************************************************
 * ACO algorithm
 * Project to Soft computing at FIT BUT
 * Author: Martin Hruska
 * E-mail: xhrusk16@stud.fit.vutbr.cz
 *
 * Class providing random numbers.
 ****************************************************************/

namespace ACO
{
  class RandomProvider;
}

class ACO::RandomProvider
{
public: // constructors
  RandomProvider();

public: // public methods
  int getRandomNumber();
  int getRandomNumberFromInterval(int interval);
};

#endif
