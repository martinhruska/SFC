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
#include "as_acs.hh"

using namespace ACO;

const std::string e_FileRead = "Nelze precist zadany soubor";

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
    return new ASAcs(parameters.getRandomConst(), RandomProvider());
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
    std::cerr  <<  "Chyba pri zpracovani parametru: " <<
      e.what()  <<  std::endl;
    return EXIT_FAILURE;
  }

  if (parameters.isHelp()) // help was printed, program ends
  {
    return EXIT_SUCCESS;
  }
  
  Graph graph(parameters.getPheromonConst(), parameters.getPheromonEvaporCoef());

  try
  {// tries parse graph
    if (parameters.getInputFile().size() == 0)
    { // no input file
      std::cerr  <<  "Nebyl zadan vstupni soubor. Pro vice informaci ctete napovedu (./aco -h)"  << std::endl;
      return EXIT_FAILURE;
    }
    parseGraph(parameters.getInputFile(), graph);
  }
  catch (std::runtime_error& e)
  {
    std::cerr  << "Chyba v parsovani grafu: "  << e.what()
      << std::endl;
    return EXIT_FAILURE;
  }
  if (parameters.isVerbose())
  {
    std::cout << graph.serialize() << std::endl;
  }

  /*
  if (parameters.getGraphComplete() && !graph.checkCompletness())
  {
    std::cerr << "Graph is not complete"  << std::endl;
    return EXIT_FAILURE;
  }
  */

  if (parameters.getAntsNumber() <= 0)
  { // check number of ants. If there are no ants defined, it will end
    std::cerr  <<  "Zadana prilis mala populace mravencu pro beh programu"  <<  std::endl;
    return EXIT_FAILURE;
  }

  // generate ant population
  AntPopulation ants(parameters.getAntsNumber(), parameters.getPheromonCoef(),
     parameters.getDistanceCoef(), parameters.isRandom());
  if (parameters.isVerbose())
  {
    std::cout << "Velikost populace mravencu je: " << ants.getPopulation().size() << std::endl;
  }
 
  // computation alone
  ASImplementation* as = getAlgorithm(parameters);
  ACOAlgorithm aco(ants, graph, RandomProvider(),
      parameters.getMaximalIterations(), *as, parameters.isVerbose());
  try
  {
    aco.compute(); // ACO algorithm
  }
  catch (std::runtime_error& e)
  {
    std::cerr  <<  e.what()  <<  std::endl;
  }
  Ant::Path path = aco.getResult();

  std::cout  <<  "Nejlepsi nalezena cesta: ";
  if (path.size() == 0)
  {
    std::cout  <<  "Reseni nenalezeno"  <<  std::endl;
  }
  else
  {
    for (Vertex* v : path)
    { // print best path
      std::cout << graph.getTranslationFromId(v->getId())  <<  " ";
    }
    std::cout << "Cost " << aco.getPathCost() << std::endl;
  }

  delete as;
  return EXIT_SUCCESS;
}
