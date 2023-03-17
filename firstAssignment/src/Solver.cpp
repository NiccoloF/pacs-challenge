//
// Created by Niccolò Feresini on 11/03/23.
//

#include "Solver.hpp"

Solver::Solver(const muParser_fun& f,const muParser_fun& df,double u0 ,double T,unsigned int nSteps,double theta):
m_f(f),
m_df(df),
m_u0(u0),
m_T(T),
m_nSteps(nSteps),
m_h(T/nSteps),
m_theta(theta) 
{}

std::array<std::vector<double>,2> Solver::theta_method(double toll,double tola) const
{   
    // initialization data_structure to store (t,u_h)
    std::vector<double> initial_values;
    initial_values.resize(m_nSteps+1,0.);
    std::array<std::vector<double>,2> result{initial_values,initial_values};
    
    // initial condition y(0)=0 
    result[1][0] = m_u0;

    /*
        solve the equation using theta_method 
        solve non-linear problem using Newton method 
    */
    for(unsigned int countStep = 0; countStep < m_nSteps; ++countStep )
    {
        result[0][countStep+1] = (countStep+1)*m_h;

        const auto F = [this,&tn = result[0][countStep],&un = result[1][countStep]]
                       (double x) {return x - (m_h) * (m_theta * m_f(tn+m_h,x) + (1-m_theta) * m_f(tn,un)) - un;};

        const auto DF = [this,&tn = result[0][countStep],&un = result[1][countStep]]
                        (double x) {return 1 - (m_h) * (m_theta) * m_df(tn+m_h,x);};

        auto newtonZero = apsc::Newton(F,DF,result[1][countStep],toll,tola,m_nSteps);

        result[1][countStep+1] = std::get<0>(newtonZero);

    }
    return result;
}
