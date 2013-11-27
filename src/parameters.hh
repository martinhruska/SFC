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
  const static int MAX_DEFAULT_ITERATION = 1000;

private: // private data members
  int maxIterations_; // number of the maximal iterations
  String inputFile_; // path to a input file
  int antsNumber_; // number of ants
  bool graphComplete_; // should be graph complete
  float pheromonCoef_; // pheromon weight
  float distanceCoef_; // distance weight
  float pheromonConst_; // pheromon constant
  float pheromonEvaporCoef_; // pheromon evaporation
  int asImpl_;

public: // enum
  enum asImpl{AS_DEFAULT, AS_DENSITY, AS_QUANTITY};

public: // public methods
  Parameters() :
    maxIterations_(MAX_DEFAULT_ITERATION), inputFile_(), graphComplete_(false),
    pheromonCoef_(1.0), distanceCoef_(1.0), pheromonConst_(1.0),
    pheromonEvaporCoef_(1.0), asImpl_(AS_DEFAULT)
  {}

public: // getters and setters
  int getMaximalIterations() {return maxIterations_;}
  String getInputFile() {return inputFile_;}
  int getAntsNumber() {return antsNumber_;}
  bool getGraphComplete() {return graphComplete_;}
  float getPheromonCoef() {return pheromonCoef_;}
  float getDistanceCoef() {return distanceCoef_;}
  float getPheromonConst() {return pheromonConst_;}
  float getPheromonEvaporCoef() {return pheromonEvaporCoef_;}
  int getAsImpl() {return asImpl_;}

  void setMaximalIterations(int maxIterations) {maxIterations_ = maxIterations;}
  void setInputFile(String inputFile) {inputFile_ = inputFile;}
  void setAntsNumber(int antsNumber) {antsNumber_ = antsNumber;}
  void setGraphComplete() {graphComplete_ = true;}
  void setPheromonCoef(float coef) {pheromonCoef_ = coef;}
  void setDistanceCoef(float coef) {distanceCoef_ = coef;}
  void setPheromonConst(float pherConst) {pheromonConst_ = pherConst;}
  void setPheromonEvaporCoef(float coef) {pheromonEvaporCoef_ = coef;}
  void setAsImpl(int asImpl) {asImpl_ = asImpl;}
};
#endif
