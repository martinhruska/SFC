// standard libraries
#include <stdexcept>
#include <iostream>
#include <unordered_set>

// ACO libraries
#include "graph_parser.hh"

void ACO::GraphParser::parseGraphFromFile(std::ifstream& inputFile,
    ACO::Graph& graph)
{
  String readLine;

  if (!inputFile.is_open())
  {
    throw std::runtime_error(e_cannotRead);
  }

  while (getline(inputFile, readLine))
  {
    parseFormatedLine(readLine, graph);
    std::cout << readLine << std::endl;
  }
}

/**
 * Parse a line given as a string and add it to
 * the result string
 */
void ACO::GraphParser::parseFormatedLine(String& line, ACO::Graph& graph)
{
  unsigned long int spacePosition = 0;
  const char space = ' ';
  String node1, node2;
  int distance;

  // parse first node
  spacePosition = line.find(space);
  if (spacePosition == String::npos)
  {
    throw std::runtime_error(e_badFormat+line);
  }
  node1 = line.substr(0, spacePosition);
 
  // parse second node
  int lastSpace = spacePosition;
  spacePosition = line.find(space, spacePosition+1);
  if (spacePosition == String::npos)
  {
    throw std::runtime_error(e_badFormat+line);
  }
  node2 = line.substr(lastSpace+1, spacePosition-lastSpace);

  //TRANSLATE string to intern representation
  // pointerV1, pointerV2, add(pE,pV1,pV2)
  // parse distance
  try 
  {
    distance = std::stoi(line.substr(spacePosition+1));
  }
  catch (std::exception e)
  {
    throw std::runtime_error(e_badFormat+line);
  }

  addTransitionToGraph(node1, node2, distance, graph);
}

/**
 * Add transition to graph.
 * It translates vertexes to intern representation and
 * then add their connection
 */
void ACO::GraphParser::addTransitionToGraph(String& node1, String& node2,
    int distance, Graph& graph)
{
  Vertex& v1 = graph.translateVertex(node1);
  Vertex& v2 = graph.translateVertex(node2);

  try
  {
    graph.addEdge(v1, v2, distance);
  }
  catch (std::exception e)
  {
    // edge has not been added
  }
}
