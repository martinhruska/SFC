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
  float allEdges = sumAllEdges();
  Edge* nextEdge = getBestEdge(allEdges);

  if (nextEdge == NULL)
  {
    throw new std::runtime_error(e_noBestEdge);
  }
 
  pathCost_ += nextEdge->getDistance();
  setActualVertex(&nextEdge->getSecondVertex(*actualVertex_));
  return;
}

/**
 * Computes which edge has the highest probability to be chosen
 * as the next edge for this ant
 */
ACO::Edge* ACO::Ant::getBestEdge(float allEdges)
{
  float best = -1;
  Edge* bestEdge = NULL;

  for (Edge *edge : actualVertex_->getEdges())
  {
    Vertex* v2 = &(edge->getSecondVertex(*actualVertex_));
    if (visitedVertices_.count(v2) != 0)
    {
      continue;
    }

    // checks whether the edge is not the one with the highest probability
    float temp = ((1/edge->getDistance())*edge->getPheromon())/allEdges;
    if (best <= temp)
    {
      best = temp;
      bestEdge = edge;
    }
  }

  return bestEdge;
}

/**
 * Computes sum of product of pheromon with
 * 1/distance for each edge accessable from this vertex
 */
float ACO::Ant::sumAllEdges()
{
  float res = 0;
  for (Edge *edge : actualVertex_->getEdges())
  {
    Vertex* v2 = &(edge->getSecondVertex(*actualVertex_));
    if (visitedVertices_.count(v2) != 0)
    { // path to already visited vertex
      continue;
    }

    res += (1/edge->getDistance())*edge->getPheromon();
  }

  return res;
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
