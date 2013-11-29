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
#include "as_elitist.hh"
#include "as_maxmin.hh"
#include "as_ranked.hh"

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

ASImplementation* getAlgorithm(Parameters parameters)
{
  int parameter = parameters.getAsImpl();
  if (parameter == Parameters::AS_DEFAULT)
  {
    return new ASImplementation();
  }
  else if (parameter == Parameters::AS_DENSITY)
  {
    return new ASDensity();
  }
  else if (parameter == Parameters::AS_QUANTITY)
  {
    return new ASQuantity();
  }
  else if (parameter == Parameters::AS_ELITIST)
  {
    return new ASElitist();
  }
  else if (parameter == Parameters::AS_MAXMIN)
  {
    return new ASMaxMin(parameters.getPheromonMax(),
        parameters.getPheromonMin());
  }
  else if (parameter == Parameters::AS_RANKED)
  {
    return new ASRanked(parameters.getMaxAnts());
  }
  else if (parameter == Parameters::AS_ACS)
  {
//    return new ASAcs(parameters.getRandomConst());
  }

  // default implementation
  return new ASImplementation();
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
  ASImplementation* as = getAlgorithm(parameters);

  ACOAlgorithm aco(ants, graph, RandomProvider(),
      parameters.getMaximalIterations(), *as);
  aco.compute();
  Ant::Path path = aco.getResult();

  for (Vertex* v : path)
  { // print best path
    std::cout << graph.getTranslationFromId(v->getId())  <<  " ";
  }
  std::cout << "Cost " << aco.getPathCost() << std::endl;

  delete as;
  return EXIT_SUCCESS;
}
