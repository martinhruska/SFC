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
  const static int MAX_DEFAULT_ITERATION = 100;

private: // private data members
  int maxIterations_; // number of the maximal iterations
  String inputFile_; // path to a input file
  int antsNumber_; // number of ants
  bool graphComplete_; // should be graph complete
  float pheromonCoef_; // pheromon weight
  float distanceCoef_; // distance weight
  float pheromonConst_; // pheromon constant
  float pheromonEvaporCoef_; // pheromon evaporation
  float pheromonMin_; // minimal pheromon
  float pheromonMax_; // maximal pheromon
  int maxAnts_; // maximum of ants in ranked algorithm
  float randomConst_; // constant for acs algorithm
  bool helpPrinted_; // print help
  bool verbose_; // be verbose
  bool randomChoice_; // random choice with same prob
  int asImpl_;

public: // enum
  enum asImpl{AS_DEFAULT, AS_DENSITY, AS_QUANTITY, AS_ELITIST, AS_MAXMIN,
  AS_RANKED, AS_ACS};

public: // public methods
  Parameters() :
    maxIterations_(MAX_DEFAULT_ITERATION), inputFile_(), antsNumber_(10), graphComplete_(false),
    pheromonCoef_(1.0), distanceCoef_(1.0), pheromonConst_(1.0),
    pheromonEvaporCoef_(0.5), pheromonMin_(0.1), pheromonMax_(0.8), maxAnts_(10),
    randomConst_(0.5), helpPrinted_(false), verbose_(false), randomChoice_(true),
    asImpl_(AS_DEFAULT)
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
  float getPheromonMax() {return pheromonMax_;}
  float getPheromonMin() {return pheromonMin_;}
  int getMaxAnts() {return maxAnts_;}
  float getRandomConst() {return randomConst_;}
  bool isHelp() {return helpPrinted_;}
  bool isVerbose() {return verbose_;}
  bool isRandom() {return randomChoice_;}

  void setMaximalIterations(int maxIterations) {maxIterations_ = maxIterations;}
  void setInputFile(String inputFile) {inputFile_ = inputFile;}
  void setAntsNumber(int antsNumber) {antsNumber_ = antsNumber;}
  void setGraphComplete() {graphComplete_ = true;}
  void setPheromonCoef(float coef) {pheromonCoef_ = coef;}
  void setDistanceCoef(float coef) {distanceCoef_ = coef;}
  void setPheromonConst(float pherConst) {pheromonConst_ = pherConst;}
  void setPheromonEvaporCoef(float coef) {pheromonEvaporCoef_ = coef;}
  void setAsImpl(int asImpl) {asImpl_ = asImpl;}
  void setPheromonMax(float max) {pheromonMax_ = max;}
  void setPheromonMin(float min) {pheromonMin_ = min;}
  void setMaxAnts(int max) {maxAnts_ = max;}
  void setRandomConst(float randomConst) {randomConst_ = randomConst;}
  void setHelpPrinted(bool printed) {helpPrinted_ = printed;}
  void setVerbose(bool verbose) {verbose_ = verbose;}
  void setRandom(bool random) {randomChoice_ = random;}
};
#endif
