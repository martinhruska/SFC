#include "parameters_parser.hh"

#include <iostream>
#include <stdexcept>
#include <unordered_set>

using ACO::ParametersParser;

void ParametersParser::printHelp()
{
  std::cout << "USAGE: aco -i file [options]" << std::endl;
  std::cout << "OPTIONS (compulsory):" << std::endl;
  std::cout << "  -i file ......... A path to input file" << std::endl;
  std::cout << "OPTIONS (optional):" << std::endl;
  std::cout << "  -v .............. Make program verbose" << std::endl;
  std::cout << "  -a integer ...... Value is integer defining number of the ants" << std::endl;
  std::cout << "  -m integer ...... Value is integer defining number of the iteration of algorithm" << std::endl;
  std::cout << "  -p float ........ Weight of pheromon on an edge for chosing another vertex in an ant solutin." << std::endl;
  std::cout << "  -d float ........ Weight of distance of a an edge for chosing another vertex in an ant solutin." << std::endl;
  std::cout << "  -c float ........ Constant of pheromon addition to the edges after one iteration" << std::endl;
  std::cout << "  -e float ........ Constant from interval <0,1> defines speed of evaporation of phermon" << std::endl;
  std::cout << "  -g string ....... Version on the ACO algorithm" << std::endl;
  std::cout << "  -r .............. Turn on randomness in chosing path with the same probability" << std::endl;
  std::cout << "  Following version are available" << std::endl;
  std::cout << "    default ....... Default version of algorithm" << std::endl;
  std::cout << "    density ....... Ant-Density modification of ACO algorithm" << std::endl;
  std::cout << "    quality ....... Ant-Quality version of ACO algorithm" << std::endl;
  std::cout << "    elitist ....... Elitist version of ACO algorithm" << std::endl;
  std::cout << "    acs ........... Ant Colony System version" << std::endl;
  std::cout << "    maxmin ........ Maxmin Ant System version" << std::endl;
  std::cout << "    ranked ........ Rank-base Ant System version" << std::endl;
  std::cout << "  Following options are dependent on the chosen algorithm (they are ignored with the others algorithms)" << std::endl;
  std::cout << "    -x float ...... Maximal value of pheromon on an edge (MaxMin Ant System)" << std::endl;
  std::cout << "    -n float ...... Minimal value of pheromon on an edge (MaxMin Ant System)" << std::endl;
  std::cout << "    -w int ........ Number of the best ants used for evaluation of the next pheromon level (Rank-based algorithm)" << std::endl;
  std::cout << "    -q float ...... Constant from interval <0,1> used for chosing method of creating ant solution (ACS algorithm)" << std::endl;
  std::cout << "Please see documentation for the default values of parameters" << std::endl;
}

/**
 * Parses the raw parameters to output structure
 */
void ParametersParser::parseParameters()
{
  std::unordered_set<String> usedOptions;

  int state = 0; // starting state for parsing
  for (int i=1; i < parametersCount_; i++)
  {
    // currently processed parameter
    String parameterRaw(parametersRaw_[i]);
    switch(state)
    {
      case(0):
        if (usedOptions.count(parameterRaw))
        { // options already used -> thrown used
          throw std::runtime_error(errorOptionUsed_ + parameterRaw);
        }

        if (parameterRaw == "-h" || parameterRaw == "--help")
        {
          parameters_.setHelpPrinted(true);
          printHelp();
          return;
        }
        else if (parameterRaw == "-i")
        {
          state = 1;
        }
        else if (parameterRaw == "-m") 
        {
          state = 2;
        }
        else if (parameterRaw == "-a")
        {
          state = 3;
        }
        else if (parameterRaw == "-o")
        {
          state = 0;
          parameters_.setGraphComplete();
        }
        else if (parameterRaw == "-p")
        {
          state = 4;
        }
        else if (parameterRaw == "-d")
        {
          state = 5;
        }
        else if (parameterRaw == "-c")
        {
          state = 6;
        }
        else if (parameterRaw == "-e")
        {
          state = 7;
        }
        else if (parameterRaw == "-g")
        {
          state = 8;
        }
        else if (parameterRaw == "-x")
        {
          state = 9;
        }
        else if (parameterRaw == "-n")
        {
          state = 10;
        }
        else if (parameterRaw == "-w")
        {
          state = 11;
        }
        else if (parameterRaw == "-q")
        {
          state = 12;
        }
        else if (parameterRaw == "-r")
        {
          parameters_.setRandom(false); 
          state = 0;
        }
        else if (parameterRaw == "-v")
        {
          parameters_.setVerbose(true);
          state = 0;
        }
        else
        {
          throw std::runtime_error(errorMessage_ + parameterRaw);
        }

        usedOptions.insert(parameterRaw);
       break;
       
      case(1): // set input file
       parameters_.setInputFile(parameterRaw);
       state = 0;
       break;

      case(2): // set maximal iteration
        try 
        {
          parameters_.setMaximalIterations(stoi(parameterRaw));
        }
        catch (std::exception e)
        {
          throw std::runtime_error(errorMessage_ + parameterRaw);
        }
        state = 0;
        break;

      case(3): // set number of ants
        try 
        {
          parameters_.setAntsNumber(stoi(parameterRaw));
        }
        catch (std::exception e)
        {
          throw std::runtime_error(errorMessage_ + parameterRaw);
        }
        state = 0;
        break;

      case(4): // set pheromon coeficient
        try 
        {
          parameters_.setPheromonCoef(stof(parameterRaw));
        }
        catch (std::exception e)
        {
          throw std::runtime_error(errorPheromon_);
        }
        state = 0;
        break;
      case(5): // set distance coeficient
        try 
        {
          parameters_.setDistanceCoef(stof(parameterRaw));
        }
        catch (std::exception e)
        {
          throw std::runtime_error(errorDistance_);
        }
        state = 0;
        break;
      case(6): // set pheromon constant
        try 
        {
          parameters_.setPheromonConst(stof(parameterRaw));
        }
        catch (std::exception e)
        {
          throw std::runtime_error(errorMessage_ + parameterRaw);
        }
        state = 0;
        break;
      case(7): // set pheromon evaporation coeficient
        try 
        {
          parameters_.setPheromonEvaporCoef(stof(parameterRaw));
        }
        catch (std::exception e)
        {
          throw std::runtime_error(errorMessage_ + parameterRaw);
        }
        state = 0;
        break;
      case(8): // set aco algorithm
        if (parameterRaw == "default")
        {
          parameters_.setAsImpl(Parameters::AS_DEFAULT);
        }
        else if (parameterRaw == "density")
        {
          parameters_.setAsImpl(Parameters::AS_DENSITY);
        }
        else if (parameterRaw == "quantity")
        {
          parameters_.setAsImpl(Parameters::AS_QUANTITY);
        }
        else if (parameterRaw == "elitist")
        {
          parameters_.setAsImpl(Parameters::AS_ELITIST);
        }
        else if (parameterRaw == "maxmin")
        {
          parameters_.setAsImpl(Parameters::AS_MAXMIN);
        }
        else if (parameterRaw == "ranked")
        {
          parameters_.setAsImpl(Parameters::AS_RANKED);
        }
        else if (parameterRaw == "acs")
        {
          parameters_.setAsImpl(Parameters::AS_ACS);
        }
        else
        {
          throw std::runtime_error(errorImplementation_);
        }
        state = 0;
        break;
      case(9): // set maximal pheromon value for maxmin alg
        try 
        {
          parameters_.setPheromonMax(stof(parameterRaw));
        }
        catch (std::exception e)
        {
          throw std::runtime_error(errorMessage_ + parameterRaw);
        }
        state = 0;
        break;
      case(10): // set minimal pheromon value for maxmin alg
        try 
        {
          parameters_.setPheromonMin(stof(parameterRaw));
        }
        catch (std::exception e)
        {
          throw std::runtime_error(errorMessage_ + parameterRaw);
        }
        state = 0;
        break;
      case(11): // set maximun ants number for ranked alg
        try 
        {
          parameters_.setMaxAnts(stoi(parameterRaw));
        }
        catch (std::exception e)
        {
          throw std::runtime_error(errorMessage_ + parameterRaw);
        }
        state = 0;
        break;
      case(12): // set random constant for acs
        try 
        {
          parameters_.setRandomConst(stof(parameterRaw));
        }
        catch (std::exception e)
        {
          throw std::runtime_error(errorMessage_ + parameterRaw);
        }
        state = 0;
        break;
      default:
        throw std::runtime_error(errorMessage_ + parameterRaw);
    }
  }
}
