#include "readparameters.hpp"
#include <fstream>

parameters readParam(const std::string& filename,bool verbose)
{
  // Parameter default constructor fills it with the defaults values
  parameters defaults;
  // checks if file exixts and is readable
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

  GetPot ifile(filename.c_str());
  parameters values;
  values.time = ifile("time/T",defaults.time);
  values.N = ifile("steps/N",defaults.N);
  values.y_0 = ifile("initial_condition/y_0",defaults.y_0);
  if(verbose)
  {
    std::cout << "PARAMETER VALUES IN GETPOT FILE"
              << "\n";
    ifile.print();
    std::cout << std::endl;
    std::cout << "ACTUAL VALUES"
              << "\n"
              << values;
  }
  return values;
}
