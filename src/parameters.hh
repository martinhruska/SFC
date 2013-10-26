/****************************************************************
 * ACO algorithm
 * Project to subject Soft computing at FIT BUT
 * Author: Martin Hruska
 * E-mail: xhrusk16@stud.fit.vutbr.cz
 *
 * Class for structured description of program parameters.
 ****************************************************************/


#ifndef ACO_PARAMETERS
#define ACO_PARAMETERS

#include <string>

namespace ACO
{
  class Parameters;
}

class ACO::Parameters
{

private: // private data types
  typedef std::string String;
private: // private constants
  const int MAX_DEFAULT_ITERATION = 1000;

private: // private data members
  int maxIterations_; // number of the maximal iterations
  String inputFile_; // path to a input file
  int antsNumber_; // number of ants

public: // public methods
  Parameters() : maxIterations_(MAX_DEFAULT_ITERATION), inputFile_()
  {}

public: // getters and setters
  int getMaximalIterations() {return maxIterations_;}
  String getInputFile() {return inputFile_;}
  int getAntsNumber() {return antsNumber_;}

  void setMaximalIterations(int maxIterations) {maxIterations_ = maxIterations;}
  void setInputFile(String inputFile) {inputFile_ = inputFile;}
  void setAntsNumber(int antsNumber) {antsNumber_ = antsNumber;}
};
#endif
