/****************************************************************
 * ACO algorithm
 * Project to Soft computing at FIT BUT
 * Author: Martin Hruska
 * E-mail: xhrusk16@stud.fit.vutbr.cz
 *
 * Class for parsing parameters from raw format to
 * object which provides better manipulation with parameters.
 ****************************************************************/

#ifndef ACO_PARAMETERS_PARSER
#define ACO_PARAMETERS_PARSER

#include <string>

#include "parameters.hh"

namespace ACO
{
  class ParametersParser;
}

class ACO::ParametersParser
{
private: // private data type
  typedef std::string String;

private: // private data members
  Parameters& parameters_; // output structure
  int parametersCount_; // number of parameters
  char** parametersRaw_; // raw paratemers in char

private: // private constants
  // error thrown due to not enought parameters problem
  String errorNotEnoughParameters_;
  // option used twice
  String errorOptionUsed_;
  // error thrown due to wrong parameters
  String errorMessage_;
  // Pheromon coeficient wrong format
  String errorPheromon_;
  // Distance coeficient wrong format
  String errorDistance_;
  // Wrong implementation
  String errorImplementation_;

  // expected number of parameters
  int EXPECTED_PARAMETERS_NUMBER;

public: // getters
  Parameters& getParameters() {return parameters_;} // returns output

public: // public methods
  /**
   * Constructor saves output structure, parameter number,
   * raw parameters
   */
  ParametersParser(Parameters& parameters, int parametersCount,
      char** parametersRaw) :
    parameters_(parameters), parametersCount_(parametersCount),
    parametersRaw_(parametersRaw),
    errorNotEnoughParameters_("Not enough parameters"),
    errorOptionUsed_("Option used twice "),
    errorMessage_("Error in parsing parameters"),
    errorPheromon_("Pheromon coeficient must be float"),
    errorDistance_("Distance coeficient must be float"),
    errorImplementation_("Unknow implementation of ant system (-g parameter)"),
    EXPECTED_PARAMETERS_NUMBER(7)
  {}

  /**
   * Parses the raw parameters to output structure
   */
  void parseParameters();

private: // private methods
  void printHelp();
};

#endif
