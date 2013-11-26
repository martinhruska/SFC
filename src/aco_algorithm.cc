#include "aco_algorithm.hh"

#include <iostream>

void ACO::ACOAlgorithm::compute()
{
  for (int i=0; i < maxIteration_; i++)
  {
    try
    {
      setRandomVertices();
      createAntSolution();
      saveBestPath();
      updatePheromon();
      restart();

      for (Vertex* v : bestPath_)
      {
        std::cout << graph_.getTranslationFromId(v->getId())  <<  " ";
      }
      std::cout << std::endl;
    } catch (std::runtime_error e)
    {
      std::cerr << "Internal error: " << e.what() << std::endl;
      break;
    }
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

ACO::ACOAlgorithm::Path& ACO::ACOAlgorithm::getResult()
{
  return bestPath_;
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
 * Update pheromon on the edges when the solutions are built
 */
void ACO::ACOAlgorithm::updatePheromon()
{
  for (Edge* e : graph_.getEdges())
  {
    e->updatePheromon();
  }
    
}

/**
 * Restart all ants and edges before next iteration
 */
void ACO::ACOAlgorithm::restart()
{
  for (Ant& a : population_.getPopulation())
  {
    a.restart();
  }

  for (Edge* e : graph_.getEdges())
  {
    e->restart();
  }
}

/**
 * Put each ant on a random vertice.
 */
void ACO::ACOAlgorithm::setRandomVertices()
{
  for (Ant& ant : population_.getPopulation())
  {
    try
    {
      int random = random_.getRandomNumberFromInterval(graph_.getVerticesNumber());
      ant.setActualVertex(graph_.getVertexAt(random));
    } catch (std::runtime_error e)
    {
      continue;
      throw e;
    }
  }
}

/**
 * Check whether given ant reaches the goal
 */
bool ACO::ACOAlgorithm::isGoalReached(Ant& ant)
{
  if (ant.getVisitedVerticesNumber() != graph_.getVerticesNumber())
  {
    return false;
  }
  else
  {
    ant.returnToStart();
    return true;
  }
}
