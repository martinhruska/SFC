#ifndef ACO_GRAPH_PARSER
#define ACO_GRAPH_PARSER

// standard libraries
#include <fstream>
#include <string>

// ACO libraries
#include "graph.hh"

namespace ACO
{
  class GraphParser;
}

class ACO::GraphParser
{
private: // private data types
  typedef std::string String;

private: // private constants
  const String e_cannotRead = "Cannot read given file";
  const String e_badFormat = "File had a wrong format: ";

public: // public methods
  GraphParser() {}
  void parseGraphFromFile(std::ifstream& graphFile, Graph& graph);

private: // private methods
  void parseFormatedLine(String& line, Graph& graph);
  void addTransitionToGraph(String& node1, String& node2,
      int distance, Graph& graph);
};

#endif
