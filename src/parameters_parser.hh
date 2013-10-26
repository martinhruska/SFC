/****************************************************************
 * ACO algorithm
 * Project to subject Soft computing at FIT BUT
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

private: // private constant
  // error thrown due to not enought parameters problem
  String errorNotEnoughParameters_ = "Not enough parameters";
  // option used twice
  String errorOptionUsed_ = "Option used twice";
  // error thrown due to wrong parameters
  String errorMessage_ = "Error in parsing input";

  // expected number of parameters
  int EXPECTED_PARAMETERS_NUMBER = 7;

private: // private data members
  Parameters& parameters_; // output structure
  int parametersCount_; // number of parameters
  char** parametersRaw_; // raw paratemers in char

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
    parametersRaw_(parametersRaw)
  {}

  /**
   * Parses the raw parameters to output structure
   */
  void parseParameters();
};

#endif
