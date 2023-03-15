//
// Created by Niccolò Feresini on 11/03/23.
//

#include "Solver.hpp"

Solver::Solver(const muParser_fun& f,const muParser_fun& df,double u0 ,double T,unsigned int nSteps):m_f(f),m_df(df),m_u0(u0),
                                                                                             m_T(T),m_nSteps(nSteps),m_h(T/nSteps) {};

std::array<std::vector<double>,2> Solver::crankNicolson(double toll,double tola) const
{   /*
    std::tuple<double, bool>
    Newton(Function const &f, Dfunction const & df, double a, double tol = 1e-4,
           double tola = 1.e-10, unsigned int maxIt = 150)
    */
    std::vector<double> values;
    values.resize(m_nSteps+1,0.);
    std::array<std::vector<double>,2> result {values,values};
    result[1][0] = m_u0;
    for(unsigned int countStep = 0; countStep < m_nSteps; ++countStep )
    {
        result[0][countStep+1] = (countStep+1)*m_h;

        const auto F = [this,&tn = result[0][countStep],&un = result[1][countStep]]
                       (double x) {return x - (m_h/2) * (m_f(tn+m_h,x) + m_f(tn,un)) - un;};

        const auto DF = [this,&tn = result[0][countStep],&un = result[1][countStep]]
                        (double x) {return 1 - (m_h/2) * m_df(tn+m_h,x);};

        auto newtonZero = apsc::Newton(F,DF,result[1][countStep],toll,tola,m_nSteps);

        result[1][countStep+1] = std::get<0>(newtonZero);

        //std::cout<<"newtonZero = "<<result[1][countStep+1]<<std::endl;

    }
    return result;
}
