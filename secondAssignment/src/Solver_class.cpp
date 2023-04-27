#include <Solver_class.hpp>

SolverTraits::ResultType QuasiNewton::solve() const
{
  Real x0_ = x0;
  Real y0 = fun(x0_);
  Real resid = std::abs(y0);
  auto dfun = apsc::makeCenteredDerivative<1>(fun, h);
  unsigned int iter{0u};
  Real check = tol_it.first * resid + tola;
  bool goOn = resid > check;
  while (goOn && iter < tol_it.second)
  {
    ++iter;
    x0_ += -y0 / dfun(x0_);
    y0 = fun(x0_);
    resid = std::abs(y0);
    goOn = resid > check;
  }
  return std::make_tuple(x0_, (iter < tol_it.second));
}

SolverTraits::ResultType Secant::solve() const
{
  Real a_ = a;
  Real b_ = b;
  Real ya = fun(a_);
  Real resid = std::abs(ya);
  Real c{a_};
  unsigned int iter{0u};
  Real check = tol_it.first * resid + tola;
  bool goOn = resid > check;
  while (goOn && iter < tol_it.second)
  {
    ++iter;
    Real yb = fun(b_);
    c = a_ - ya * (b_ - a_) / (yb - ya);
    Real yc = fun(c);
    resid = std::abs(yc);
    goOn = resid > check;
    ya = yc;
    a_ = c;
  }
  return std::make_tuple(c, (iter < tol_it.second));
}

SolverTraits::ResultType Bisection::solve() const
{
  Real a_ = a;
  Real b_ = b;
  Real ya = fun(a_);
  Real yb = fun(b_);
  Real delta = b_ - a_;
  Real yc{ya};
  Real c{a_};
  while (std::abs(delta) > 2 * tol_it.first)
  {
    c = (a_ + b_) / 2.;
    yc = fun(c);
    if (yc * ya < 0.0)
    {
      yb = yc;
      b_ = c;
    }
    else
    {
      ya = yc;
      a_ = c;
    }
    delta = b_ - a_;
  }
  return std::make_tuple((a_ + b_) / 2., ya * yb < 0);
}
