//
// Created by Niccolò Feresini on 11/03/23.
//

#ifndef PACS_CHALLENGES_SOLVER_H
#define PACS_CHALLENGES_SOLVER_H

#include <functional>
#include <array>
#include <vector>
#include <iostream>
#include "basicZeroFun.hpp"


class Solver {
using function = std::function<double(double time,double point)>;
public:
    Solver(const function& f,const function& df,double u0 = 0.,double T = 10.,unsigned int nSteps = 1e3);
    [[nodiscard]] std::array<std::vector<double>,2> crankNicolson(double toll = 1e-6,double tola = 1e-10) const;

private:
    const function& m_f;
    const function& m_df;
    const double m_u0;
    const double m_T;
    const unsigned int m_nSteps;
    const double m_h;
};

#endif //PACS_CHALLENGES_SOLVER_H
