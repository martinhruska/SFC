#include "aco_algorithm.hh"

#include <iostream>
#include <string>

void ACO::ACOAlgorithm::compute()
{
  for (int i=0; i < maxIteration_; i++)
  {
    if (verbose_)
    {
      std::cout << i+1 << ". iterace ===========================" << std::endl;
    }
    try
    {
      setRandomVertices();
      createAntSolution();
      saveBestPath();
      updatePheromon();
      restart();

      if (verbose_)
      {
        std::cout << "Dosud nejlepsi reseni: ";
        for (Vertex* v : bestPath_)
        {
         std::cout << graph_.getTranslationFromId(v->getId())  <<  " ";
        }
        if (bestPathCost_ == FLT_MAX)
        {
          std::cout << "Reseni nenalezeno" << std::endl;
        }
        else
        {
          std::cout << "Cena " << bestPathCost_ << std::endl;
        }
      }
    }
    catch (std::runtime_error& e)
    {
      throw std::runtime_error("Internal error: "+std::string(e.what()));
    }
    if (verbose_)
    {
      std::cout <<"========================================" << std::endl << std::endl;
    }
  }
}


/**
 * Creates solution for each ant
 */
void ACO::ACOAlgorithm::createAntSolution()
{
  RawPopulation notFinishedAnts;
  for (Ant* a : population_.getPopulation())
  { // initialization
    notFinishedAnts.push_back(a);
  }

  while (notFinishedAnts.size() != 0)
  {
    Ant *ant = notFinishedAnts.back();
    notFinishedAnts.pop_back();

    try
    {
      as_.prepareStep();
      ant->makeStep(as_);
    }
    catch (std::runtime_error& e)
    { // cannot make another step -> local extereme
      continue;
    }
    
    if (!isGoalReached(*ant))
    { // ant does not satisfied goal
      notFinishedAnts.insert(notFinishedAnts.begin(),ant);
    }
    else
    { // goal satisfied, ant goes back to the start
      ant->returnToStart();
      ant->setGoalStatisfied(isPathComplete(*ant));
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
  Ant* bestAnt = population_.getPopulation().back();

  for (Ant* ant : population_.getPopulation())
  { // get best solution from last iteration
    if (verbose_)
    {
      std::cout << "Mravenec " << ant->getId() << ": "
        << printPath(ant->getPath()) << " cena "
        << ant->getPathCost() << " a cil splnen: " << ant->isGoalSatisfied()
        << std::endl;
    }

    if (ant->isGoalSatisfied() &&
        ant->getPathCost() < bestAnt->getPathCost())
    {
      bestAnt = ant;
    }
    else if (ant->isGoalSatisfied() && !bestAnt->isGoalSatisfied())
    { // first randomly chosen ant has not satisfied goal
      bestAnt = ant;
    }
  }

  // saves best ant
  if (bestAnt->isGoalSatisfied())
  {
    bestAnt_ = bestAnt;
  }
  else
  {
    bestAnt_ = NULL;
    return;
  }

  if (verbose_)
  {
    std::cout << "Nejlepsi cesta iterace " << printPath(bestAnt->getPath())
      << " cena " << bestAnt->getPathCost() << std::endl;
  }
  if (bestAnt->getPathCost() <= bestPathCost_)
  {
    bestPath_.clear();
    bestPath_.insert(bestPath_.begin(),bestAnt->getPath().begin(),bestAnt->getPath().end());
    bestPathCost_ = bestAnt->getPathCost();
  }
}

/**
 * Update pheromon on the edges when the solutions are built
 */
void ACO::ACOAlgorithm::updatePheromon()
{
  as_.setBestPath(bestPath_);
  as_.setBestPathCost(bestPathCost_);
  as_.setBestAnt(bestAnt_);
  as_.updatePheromon(graph_);
}

/**
 * Restart all ants and edges before next iteration
 */
void ACO::ACOAlgorithm::restart()
{
  for (Ant* a : population_.getPopulation())
  {
    a->restart();
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
  for (Ant* ant : population_.getPopulation())
  {
    try
    {
      int random = random_.getRandomNumberFromInterval(graph_.getVerticesNumber());
      ant->setActualVertex(graph_.getVertexAt(random));
      /*
      if (verbose_)
      {
        std::cout << "Ant " << ant->getId() << " " << "starts at " <<
          //random << " city " << 
          "city " << 
          graph_.getTranslationFromId(ant->getActualVertex()->getId())
          <<  std::endl;
      }
      */
    } catch (std::runtime_error e)
    {
      throw e;
    }
  }
}

/**
 * Check whether given ant reaches the goal - visited all vertices
 */
bool ACO::ACOAlgorithm::isGoalReached(Ant& ant)
{
  if (ant.getVisitedVerticesNumber() != graph_.getVerticesNumber())
  {
    return false;
  }
  else
  {
    return true;
  }
}

/**
 * Check whether given ant completed path through graph - visited all vertices
 * and returned to start vertex
 */
bool ACO::ACOAlgorithm::isPathComplete(Ant& ant)
{
  if (ant.getPath().size() != (graph_.getVerticesNumber()+1))
  {
    return false;
  }
  else
  {
    return true;
  }
}

/**
 * Methods serialize path and its cost to string
 */
std::string ACO::ACOAlgorithm::printPath(Path path)
{
  std::string res="";
  for (Vertex* v : path)
  {
    res += graph_.getTranslationFromId(v->getId()) + " ";
  }

  return res;
}
