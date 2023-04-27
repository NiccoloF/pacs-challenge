#include <SolverParameters.hpp>
#include <GetPot>

Parameters::Parameters(const std::string &filename)
{
  // reading parameters from a .dat file using getpot
  GetPot file(filename.c_str());

  {
    const std::string subsection = "solver/";
    solver.f = file((subsection + "f").c_str(), "x^2");
    solver.a = file((subsection + "a").c_str(), 0);
    solver.b = file((subsection + "b").c_str(), 1);
    solver.tol = file((subsection + "tol").c_str(), 1e-4);
    solver.max_it = file((subsection + "max_it").c_str(), 150);
  }

  {
    const std::string subsection = "secant/";
    secant.tol_a = file((subsection + "tol_a").c_str(), 1.e-10);
  }

  {
    const std::string subsection = "newton/";
    newton.tol_a = file((subsection + "tol_a").c_str(), 1.e-10);
    newton.h = file((subsection + "h").c_str(), 1.e-4);
  }
}
