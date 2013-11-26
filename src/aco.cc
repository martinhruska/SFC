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
#include "ant_population.hh"
#include "aco_algorithm.hh"

using namespace ACO;

const std::string e_FileRead = "Cannot read a given file";

/**
 * Parameters are processed here
 */
Parameters parseParameters(int argc, char** argv)
{
  Parameters parameters;
  ParametersParser paramsParser(parameters, argc, argv);

  paramsParser.parseParameters();

  return parameters;
}

/**
 * Graph is parsed from input file
 */
void parseGraph(std::string pathInputFile, Graph& graph)
{
  GraphParser graphParser;

  std::ifstream inputFile(pathInputFile);
  if (!inputFile.is_open())
  {
    throw std::runtime_error(e_FileRead);
  }
  graphParser.parseGraphFromFile(inputFile, graph);
}

int main(int argc, char** argv)
{
  Parameters parameters = parseParameters(argc, argv);
  
  Graph graph;

  try
  {// tries parse graph
    parseGraph(parameters.getInputFile(), graph);
  }
  catch (std::runtime_error& e)
  {
    std::cerr  << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  std::cerr << graph.serialize() << std::endl;

  if (parameters.getGraphComplete() && !graph.checkCompletness())
  {
    std::cerr << "Graph is not complete"  << std::endl;
    return EXIT_FAILURE;
  }

  if (parameters.getAntsNumber() <= 0)
  {
    std::cerr  <<  "Population of ants is to small"  <<  std::endl;
    return EXIT_FAILURE;
  }
  AntPopulation ants(parameters.getAntsNumber());
  std::cerr << "Population size is: " << ants.getPopulation().size() << std::endl;
 
  ACOAlgorithm aco(ants, graph, RandomProvider(),
      parameters.getMaximalIterations());
  aco.compute();
  Ant::Path path = aco.getResult();

  for (Vertex* v : path)
  {
    std::cout << graph.getTranslationFromId(v->getId())  <<  " ";
  }
  std::cout << std::endl;

  // algorithm alone
  // get result
  // show result

  return EXIT_SUCCESS;
}
