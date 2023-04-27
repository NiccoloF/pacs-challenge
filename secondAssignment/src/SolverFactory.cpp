#include <SolverFactory.hpp>

std::unique_ptr<SolverBase> SolverFactory::operator()(const SolverType &type)
{
  Parameters params(filename);

  // defining aliases
  const SecantParameters &secant = params.secant;
  const SolverParameters &solver = params.solver;
  const QuasiNewtonParameters &newton = params.newton;

  muparser_fun fun(solver.f);

  if (type == SolverType::bisection)
  {
    std::function<double(double)> f = fun;
    auto [x1, x2, condition] = apsc::bracketInterval(f, (solver.a + solver.b) / 2);
    if (!condition)
    {
      std::cerr << "the interval passed does not bracket a zero!" << std::endl;
      return nullptr;
    }
    return std::make_unique<Bisection>(fun, solver.a, solver.b, std::make_pair(solver.tol, solver.max_it));
  }

  if (type == SolverType::secant)
    return std::make_unique<Secant>(fun, solver.a, solver.b, std::make_pair(solver.tol, solver.max_it), secant.tol_a);

  if (type == SolverType::quasiNewton)
    return std::make_unique<QuasiNewton>(fun, solver.a, solver.b, std::make_pair(solver.tol, solver.max_it), newton.tol_a, newton.h);

  std::cerr << "Unvalid method!" << std::endl;
  return nullptr;
}
