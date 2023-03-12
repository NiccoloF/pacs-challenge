#ifndef READPARAMETERS_HPP
#define READPARAMETERS_HPP

#include <string>
#include "Getpot"
#include "parameters.hpp"

//read parameters from a GetPot file
parameters readParam(const std::string& filename,bool verbose);

#endif //READPARAMETERS_HPP
