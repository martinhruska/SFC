#include "parameters_parser.hh"

#include <iostream>
#include <stdexcept>
#include <unordered_set>

using ACO::ParametersParser;

void ParametersParser::printHelp()
{
  std::cout << "POUZITI: aco -i cesta [parametry]" << std::endl;
  std::cout << "PARAMETRY (povinne):" << std::endl;
  std::cout << "  -i cesta ......... Cesta k vstupnimu souboru" << std::endl;
  std::cout << "PARAMETRY (volitelne):" << std::endl;
  std::cout << "  -v .............. Program demostruje svoji cinnost pomoci vypisu" << std::endl;
  std::cout << "  -a integer ...... Cele cislo udavajici pocet mravencu" << std::endl;
  std::cout << "  -m integer ...... Cele cislo udavajici pocet iteraci" << std::endl;
  std::cout << "  -p float ........ Realne cislo udavajici vahu feromonu na hrane pro vyber dalsi cesty" << std::endl;
  std::cout << "  -d float ........ Realne cislo udavajici vahu delky hrany pro vyber dalsi cesty" << std::endl;
  std::cout << "  -c float ........ Realne cislo udavajici mnozstvi feromonu vypusteneho jednim mravencem v jedne iteraci" << std::endl;
  std::cout << "  -e float ........ Realne cisto z intervalu <0,1> udavajici koeficient odparovani feromonu" << std::endl;
  std::cout << "  -r .............. Vypne nahodny vyber z hran se stejnou pravdepodobnosti vyberu pro dalsi cestu" << std::endl;
  std::cout << "  -g string ....... Verze ACO algoritu" << std::endl;
  std::cout << "  Nasledujici verze jsou dostupne" << std::endl;
  std::cout << "    default ....... Ant System" << std::endl;
  std::cout << "    density ....... Ant System Density" << std::endl;
  std::cout << "    quantity ...... Ant System Quantity" << std::endl;
  std::cout << "    elitist ....... Ant System Elitisti" << std::endl;
  std::cout << "    acs ........... Ant Colony System" << std::endl;
  std::cout << "    maxmin ........ Maxmin Ant System" << std::endl;
  std::cout << "    ranked ........ Rank-based Ant System" << std::endl;
  std::cout << "  Nasledujici volby jsou zavisle na volbe algoritmu (jinak jsou ignorovany)" << std::endl;
  std::cout << "    -x float ...... Maximalni hodnota feromonu na hrane (MaxMin Ant System)" << std::endl;
  std::cout << "    -n float ...... Minimalni hodnota feromonu na hrane (MaxMin Ant System)" << std::endl;
  std::cout << "    -w int ........ Pocet mravencu vypoustejicich feromon (Rank-based algorithm)" << std::endl;
  std::cout << "    -q float ...... Konstanta z intervalu <0,1> pouzita pro vyber metodiky vyberu dalsiho cesty (ACS algorithm)" << std::endl;
  std::cout << "Blizsi popis parametru lze najit v dokumentaci" << std::endl;
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
