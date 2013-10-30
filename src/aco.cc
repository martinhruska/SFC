/****************************************************************
 * ACO algorithm
 * Project to subject Soft computing at FIT BUT
 * Author: Martin Hruska
 * E-mail: xhrusk16@stud.fit.vutbr.cz
 *
 * Main function of program.
 ****************************************************************/

// standard libraries
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

// aco libraries
#include "parameters.hh"
#include "parameters_parser.hh"
#include "graph.hh"
#include "graph_parser.hh"

using namespace ACO;

const std::string e_FileRead = "Cannot read a given file";

Parameters parseParameters(int argc, char** argv)
{
  Parameters parameters;
  ParametersParser paramsParser(parameters, argc, argv);

  paramsParser.parseParameters();

  return parameters;
}

Graph parseGraph(std::string pathInputFile)
{
  Graph graph;
  GraphParser graphParser;

  std::ifstream inputFile(pathInputFile);
  if (!inputFile.is_open())
  {
    throw std::runtime_error(e_FileRead);
  }
  graphParser.parseGraphFromFile(inputFile, graph);

  return graph;
}

int main(int argc, char** argv)
{
  Parameters parameters = parseParameters(argc, argv);
  
  Graph graph;

  try
  {
    graph = parseGraph(parameters.getInputFile());
  }
  catch (std::runtime_error& e)
  {
    std::cerr  << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  
  //generate population
  // algorithm alone
  // get result
  // show result

  return EXIT_SUCCESS;
}
