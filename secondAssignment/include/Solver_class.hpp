#ifndef SOLVERCLASS_SOLVER_CLASS_HPP
#define SOLVERCLASS_SOLVER_CLASS_HPP

#include <Derivatives.hpp>

#include <cmath>
#include <functional>
#include <iostream>
#include <utility>

struct SolverTraits
{
  using Real = double;

  // type of the objects returned by the solvers:
  // the value obtained by the method and
  // a boolean to indicate whether the method succeeded or not
  using ResultType = std::tuple<Real, bool>;

  // options include in this case the tolerance and the maximum number of iterations
  using OptionsType = std::pair<Real, unsigned int>;

  using Function = std::function<Real(const Real &)>;
};

// abstract class used that all the methods inherit from
class SolverBase : public SolverTraits
{
protected:
  Function fun;
  Real a;
  Real b;
  OptionsType tol_it = {1e-4, 150};

public:
  SolverBase(const Function &fun_,
             const Real &a_,
             const Real &b_,
             const OptionsType &options_)
      : fun{fun_}, a{a_}, b{b_}, tol_it{options_} {}

  virtual ~SolverBase() {}

  virtual ResultType solve() const = 0;

  void set_interval(const Real &a_, const Real &b_)
  {
    a = a_;
    b = b_;
  }

  void set_options(const Real &tol, const unsigned int max_it)
  {
    tol_it = std::make_pair(tol, max_it);
  }
};

// implementation of the quasi newton method solver class
class QuasiNewton : public SolverBase
{
private:
  Real tola;
  Real h;
  Real x0;

public:
  QuasiNewton(const Function &fun_,
              const Real &a_,
              const Real &b_,
              const OptionsType &options_,
              const Real tola_ = 1.e-4,
              const Real h_ = 1.e-4)
      : SolverBase{fun_, a_, b_, options_}, tola{tola_}, h{h_}, x0{(a + b) / 2} {}

  ResultType solve() const override;
};

// implementation of the bisection method solver class
class Bisection : public SolverBase
{
public:
  Bisection(const Function &fun_,
            const Real &a_,
            const Real &b_,
            const OptionsType &options_)
      : SolverBase{fun_, a_, b_, options_} {}

  ResultType solve() const override;
};

// implementation of the secant method solver class
class Secant : public SolverBase
{
private:
  Real tola;

public:
  Secant(const Function &fun_,
         const Real &a_,
         const Real &b_,
         const OptionsType &options_,
         const Real tola_ = 1.e-10)
      : SolverBase{fun_, a_, b_, options_}, tola{tola_} {}

  ResultType solve() const override;
};

#endif // SOLVERCLASS_SOLVER_CLASS_HPP
