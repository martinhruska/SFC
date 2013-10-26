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

// aco libraries
#include "parameters.hh"
#include "parameters_parser.hh"

using namespace ACO;

int main(int argc, char** argv)
{
  Parameters parameters;
  ParametersParser paramsParser(parameters, argc, argv);

  paramsParser.parseParameters();

  //generate population
  // algorithm alone
  // get result
  // show result

  return EXIT_SUCCESS;
}
