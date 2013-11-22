#ifndef ACO_RANDOM_PROVIDER
#define ACO_RANDOM_PROVDIER

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
