#include "readparameters.hpp"
#include <fstream>

parameters readParam(const std::string& filename,bool verbose)
{
  // Parameter default constructor fills it with the defaults values
  parameters defaults;

  // checks if the file exists and is readable
  std::ifstream check(filename);
  if(!check)
    {
      std::cerr << "ERROR: Parameter file " << filename << " does not exist"
                << std::endl;
      std::cerr << "Reverting to default values." << std::endl;
      if(verbose)
        std::cout << defaults;
      check.close();
      return defaults;
    }
  else
    check.close();

  
  //read parameters from a getpot file
  GetPot ifile(filename.c_str());
  parameters values;
  values.f = ifile("function/f",defaults.f);
  values.df = ifile("function/df",defaults.df);
  values.time = ifile("time/T",defaults.time);
  values.N = ifile("steps/N",defaults.N);
  values.y_0 = ifile("initial_condition/y_0",defaults.y_0);
  values.theta = ifile("theta/theta",0.5);

  if(verbose)
    std::cout<<values<<std::endl;

  return values;
}
