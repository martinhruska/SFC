#include "aco_algorithm.hh"

void ACO::ACOAlgorithm::compute()
{
  setRandomVertices();
  createAntSolution();
  // save best
  // update pheromon
  // check iteration
}

void ACO::ACOAlgorithm::getResult(std::vector<Vertex>)
{
}

/**
 * Saves the best path. If current best path is better, it is kept,
 * otherwise, the best path get from last ant solution is set as best one
 * globally.
 */
void ACO::ACOAlgorithm::saveBestPath()
{
  // init best path cost
  Ant& bestAnt = population_.getPopulation().back();

  for (Ant ant : population_.getPopulation())
  { // get best solution from last iteration
    if (ant.getPathCost() < bestAnt.getPathCost())
    {
      bestAnt = ant;
    }
  }

  if (bestAnt.getPathCost() < bestPathCost_)
  {
    bestPath_.clear();
    bestPath_.insert(bestPath_.begin(),bestAnt.getPath().begin(),bestAnt.getPath().end());
    bestPathCost_ = bestAnt.getPathCost();
  }
}

/**
 * Put each ant on a random vertice.
 */
void ACO::ACOAlgorithm::setRandomVertices()
{
  for (Ant& ant : population_.getPopulation())
  {
    int random = random_.getRandomNumberFromInterval(graph_.getVerticesNumber());
    ant.setActualVertex(graph_.getVertexAt(random));
  }
}

/**
 * Creates solution for each ant
 */
void ACO::ACOAlgorithm::createAntSolution()
{
  RawPopulation notFinishedAnts;
  for (Ant& a : population_.getPopulation())
  {
    notFinishedAnts.push_back(&a);
  }

  while (notFinishedAnts.size() != 0)
  {
    Ant *ant = notFinishedAnts.back();
    notFinishedAnts.pop_back();

    ant->makeStep();
    if (!isGoalReached(*ant))
    { // ant does not satisfied goal
      notFinishedAnts.insert(notFinishedAnts.begin(),ant);
    }
  }
}

/**
 * Check whether given ant reaches the goal
 */
bool ACO::ACOAlgorithm::isGoalReached(Ant& ant)
{
  if (ant.getVisitedVerticesNumber() != graph_.getVerticesNumber()-1)
  {
    return false;
  }
  else
  {
    return true;
  }
}
