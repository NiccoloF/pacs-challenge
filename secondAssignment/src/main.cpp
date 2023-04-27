#include <SolverFactory.hpp>
#include <SolverParameters.hpp>
#include <Solver_class.hpp>
#include <cmath>
#include <functional>
#include <iostream>
#include <tuple>

int main()
{

  using T = SolverType;

  SolverFactory factory("solver_params.dat");

  // test bisection
  auto point_to_bisection = factory(T::bisection);
  auto sol_bool1 = point_to_bisection->solve();
  double sol1 = std::get<0>(sol_bool1);
  std::cout << "solution bisection: " << sol1 << std::endl;

  // test secant
  auto point_to_secant = factory(T::secant);
  auto sol_bool2 = point_to_secant->solve();
  double sol2 = std::get<0>(sol_bool2);
  std::cout << "solution secant: " << sol2 << std::endl;

  // test quasi newton
  auto point_to_newton = factory(T::quasiNewton);
  auto sol_bool3 = point_to_newton->solve();
  double sol3 = std::get<0>(sol_bool3);
  std::cout << "solution quasi newton: " << sol3 << std::endl;

  return 0;
}

// this challenge is a collaboration between Matteo Coppellotti and Niccolò Feresini
