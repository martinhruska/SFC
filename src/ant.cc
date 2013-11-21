#include "ant.hh"

#include "vertex.hh"
#include "edge.hh"

#include <iostream>

void ACO::Ant::restart()
{
  return;
}

void ACO::Ant::makeStep()
{
  for (Edge *edge : actualVertex_->getEdges())
  {
    Vertex* v2 = &(edge->getSecondVertex(*actualVertex_));
    if (visitedVertices_.count(v2) != 0)
    { // path to already visited vertex
      continue;
    }

    setActualVertex(v2);
    break;
  }
  
  //pathCost_ += pathCost + chosenEdge.getDistance();
  return;
}

/**
 * Set actual vertex of the ant.
 * If the given vertex has been already visited,
 * an exception is thrown.
 */
void ACO::Ant::setActualVertex(Vertex* v)
{
  try
  {
    addVertexToVisited(v);
  } catch (std::runtime_error& e)
  {
    throw e;
  }
  actualVertex_ = v;
}

/**
 * Add vertex to vector of visited vertices.
 * If vertex has been already visited an exception
 * is thrown
 */
void ACO::Ant::addVertexToVisited(Vertex* v)
{
  if (visitedVertices_.count(v) != 0)
  {
    throw new std::runtime_error(e_vertexAlreadyVisited);
  }

  visitedVertices_.insert(v);
  path_.push_back(v);
}
