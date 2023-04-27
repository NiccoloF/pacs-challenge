#ifndef SOLVER_PARAMETERS_HPP
#define SOLVER_PARAMETERS_HPP

#include <string>

class SolverParameters
{
public:
  SolverParameters() = default;

  std::string solver_name;
  std::string f;
  double a;
  double b;
  double tol;
  unsigned int max_it;
};

class QuasiNewtonParameters
{
public:
  QuasiNewtonParameters() = default;

  double tol_a;
  double h;
};

class SecantParameters
{
public:
  SecantParameters() = default;

  double tol_a;
};

class Parameters
{
public:
  Parameters(const std::string &filename);

  SolverParameters solver;
  SecantParameters secant;
  QuasiNewtonParameters newton;
};

#endif // SOLVER_PARAMETERS_HPP
