// standard libraries
#include <stdexcept>
#include <iostream>

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

void ACO::GraphParser::parseFormatedLine(String& line, ACO::Graph& graph)
{
  unsigned long int spacePosition = 0;
  unsigned long int startSearchFrom = spacePosition;
  const char space = ' ';

  for (int i = 0; i < 2; i++)
  {
    spacePosition = line.find(space, startSearchFrom);

    if (spacePosition == String::npos)
    {
      throw std::runtime_error(e_badFormat+line);
    }
    else
    {
      std::cout << line.substr(startSearchFrom, spacePosition-startSearchFrom) << std::endl;
    }
    startSearchFrom = spacePosition+1;
  }

  //TRANSLATE string to intern representation
  // pointerV1, pointerV2, add(pE,pV1,pV2)
  std::cout << line.substr(startSearchFrom) << std::endl;
  std::cout << std::endl;
}
