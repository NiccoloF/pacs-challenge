//
// Created by Niccolò Feresini on 11/03/23.
//

#ifndef PACS_CHALLENGES_SOLVER_H
#define PACS_CHALLENGES_SOLVER_H

#include <array>
#include <vector>
#include <iostream>
#include <algorithm>
#include "basicZeroFun.hpp"
#include "muParser_fun.hpp"


class Solver {
public:
    Solver(const muParser_fun& f,
           const muParser_fun& df,
           const mu::Parser& uex,
           double u0 = 0.,
           double T = 10.,
           unsigned int nSteps = 1e3,
           double theta = 0.5 );

    [[nodiscard]] std::array<std::vector<double>,2> theta_method(double toll = 1e-6,double tola = 1e-10) const;
     std::array<std::vector<double>,2> compute_exact_solution() const;
     double& set_theta(){return m_theta;};
     const double& get_theta(){return m_theta;};
     void set_nSteps(unsigned int N){m_nSteps = N; m_h = m_T/static_cast<double>(m_nSteps);};
     const unsigned int& get_nSteps(){return m_nSteps;};
private:
    mutable muParser_fun m_f;
    mutable muParser_fun m_df;
    mutable mu::Parser m_uex; 
    const double m_u0;
    const double m_T;
    unsigned int m_nSteps;
    double m_h;
    double m_theta;
};

double compute_error(const std::vector<double>& u_h,const std::vector<double>& uex);

#endif //PACS_CHALLENGES_SOLVER_H
