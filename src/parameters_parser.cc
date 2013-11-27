#include "parameters_parser.hh"

#include <iostream>
#include <stdexcept>
#include <unordered_set>

using ACO::ParametersParser;

/**
 * Parses the raw parameters to output structure
 */
void ParametersParser::parseParameters()
{
  if (parametersCount_ < EXPECTED_PARAMETERS_NUMBER)
  {
    throw std::runtime_error(errorNotEnoughParameters_);
  }

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
          throw std::runtime_error(errorMessage_);
        }

        if (parameterRaw == "-i")
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
        else
        {
          throw std::runtime_error(errorMessage_);
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
          throw std::runtime_error(errorMessage_);
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
          throw std::runtime_error(errorMessage_);
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
          throw std::runtime_error(errorDistance_);
        }
        state = 0;
        break;
      case(7): // set pheromon constant
        try 
        {
          parameters_.setPheromonEvaporCoef(stof(parameterRaw));
        }
        catch (std::exception e)
        {
          throw std::runtime_error(errorDistance_);
        }
        state = 0;
        break;
      case(8): // set pheromon constant
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
        else
        {
          throw std::runtime_error(errorImplementation_);
        }
        state = 0;
        break;
      default:
        throw std::runtime_error(errorMessage_);
    }
  }
}
