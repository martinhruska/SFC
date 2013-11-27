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
#include "as_implementation.hh"
#include "as_density.hh"
#include "as_quantity.hh"

using namespace ACO;

const std::string e_FileRead = "Cannot read a given file";

/**
 * Parameters are processed here
 */
Parameters parseParameters(int argc, char** argv)
{
  Parameters parameters;
  ParametersParser paramsParser(parameters, argc, argv);

  try
  {
    paramsParser.parseParameters();
  }
  catch (std::runtime_error& e)
  {
    throw e;
  }

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
  Parameters parameters;
  try
  {
    parameters = parseParameters(argc, argv);
  }
  catch (std::runtime_error& e)
  {
    std::cerr  <<  "Error in parsing parameters: " <<
      e.what()  <<  std::endl;
    return EXIT_FAILURE;
  }
  
  Graph graph(parameters.getPheromonConst(), parameters.getPheromonEvaporCoef());

  try
  {// tries parse graph
    parseGraph(parameters.getInputFile(), graph);
  }
  catch (std::runtime_error& e)
  {
    std::cerr  << "Error in parsing graph: "  << e.what()
      << std::endl;
    return EXIT_FAILURE;
  }
  std::cerr << graph.serialize() << std::endl;

  if (parameters.getGraphComplete() && !graph.checkCompletness())
  {
    std::cerr << "Graph is not complete"  << std::endl;
    return EXIT_FAILURE;
  }

  if (parameters.getAntsNumber() <= 0)
  { // check number of ants
    std::cerr  <<  "Population of ants is to small"  <<  std::endl;
    return EXIT_FAILURE;
  }
  // generate ant population
  AntPopulation ants(parameters.getAntsNumber(), parameters.getPheromonCoef(),
     parameters.getDistanceCoef());
  std::cerr << "Population size is: " << ants.getPopulation().size() << std::endl;
 
  // computation alone
  ASImplementation* as;
  if (parameters.getAsImpl() == Parameters::AS_DEFAULT)
  {
    as = new ASImplementation();
  }
  else if (parameters.getAsImpl() == Parameters::AS_DENSITY)
  {
    as = new ASDensity();
  }
  else if (parameters.getAsImpl() == Parameters::AS_QUANTITY)
  {
    as = new ASQuantity();// ASQuantity();
  }
  ACOAlgorithm aco(ants, graph, RandomProvider(),
      parameters.getMaximalIterations(), *as);
  aco.compute();
  Ant::Path path = aco.getResult();

  for (Vertex* v : path)
  { // print best path
    std::cout << graph.getTranslationFromId(v->getId())  <<  " ";
  }
  std::cout << "Cost " << aco.getPathCost() << std::endl;

  return EXIT_SUCCESS;
}
