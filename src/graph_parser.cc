// standard libraries
#include <stdexcept>
#include <unordered_set>
#include <iostream>

// ACO libraries
#include "graph_parser.hh"

/**
 * Read whole input file and parse each line
 */
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
  }
}

/**
 * Parse a line given as a string and add it to
 * the result string
 */
void ACO::GraphParser::parseFormatedLine(String& line, Graph& graph)
{
  unsigned long int spacePosition = 0;
  const char space = ' ';
  String node1, node2;
  Graph::Distance distance;

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
  node2 = line.substr(lastSpace+1, spacePosition-lastSpace-1);

  try 
  { // parse distance
    String::size_type endOfInt;
    String distanceString = line.substr(spacePosition+1);
    distance = std::stof(distanceString, &endOfInt);

    if (endOfInt != distanceString.size())
    { // some mess after integer was not parsed
      throw std::runtime_error(e_badFormat+line);
    }
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
    Graph::Distance distance, Graph& graph)
{
  Vertex& v1 = graph.translateVertex(node1);
  Vertex& v2 = graph.translateVertex(node2);

  try
  {
    graph.addEdge(v1, v2, distance);
  }
  catch (std::exception e)
  {
    std::cerr << e_warning << std::endl <<
      node1 << " " << node2 << " " << distance << std::endl;
    // edge has not been added
  }
}
