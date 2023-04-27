#ifndef SOLVERCLASS_SOLVERFACTORY_HPP
#define SOLVERCLASS_SOLVERFACTORY_HPP

#include <basicZeroFun.hpp>
#include "SolverParameters.hpp"
#include "Solver_class.hpp"
#include "muparser_fun.hpp"

#include <memory>
#include <muParser.h>
#include <string>

// list of implemented solver types
enum class SolverType
{
  bisection,
  secant,
  quasiNewton
};

class SolverFactory
{
public:
  SolverFactory(const std::string &filename_) : filename(filename_) {}

  std::unique_ptr<SolverBase> operator()(const SolverType &type);

  void set_filename(const std::string &filename_) { filename = filename_; }

private:
  std::string filename;
};

#endif // SOLVERCLASS_SOLVERFACTORY_HPP
