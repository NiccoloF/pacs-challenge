//
// Created by Niccolò Feresini on 11/03/23.
//

#include "Solver.hpp"

Solver::Solver(const muParser_fun& f,const muParser_fun& df,const mu::Parser& uex,double u0 ,double T,unsigned int nSteps,double theta):
m_f(f),
m_df(df),
m_uex(uex),
m_u0(u0),
m_T(T),
m_nSteps(nSteps),
m_h(T/static_cast<double>(nSteps)),
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

std::array<std::vector<double>,2> Solver::compute_exact_solution() const
{
    // initialization data_structure to store (t,u_h)
    std::vector<double> initial_values;
    initial_values.resize(m_nSteps+1,0.);
    std::array<std::vector<double>,2> result{initial_values,initial_values};

    double time_t;
    m_uex.DefineVar("t",&time_t);

    for(size_t i = 0; i <= m_nSteps; ++i)
    {
        time_t = i*m_h;
        double solution_t = m_uex.Eval();
        result[0][i] = time_t;
        result[1][i] = solution_t;
    }
    return result;
}

double compute_error(const std::vector<double>& u_h,const std::vector<double>& uex) 
{
    std::vector<double> v_error;
    v_error.resize(u_h.size());
    const auto function = [](double uh_i,double uex_i)
    {
        return std::abs(uh_i-uex_i);
    };

    std::transform(u_h.begin(),u_h.end(),uex.begin(),v_error.begin(),function);
    return *(std::max_element(v_error.begin(),v_error.end()));
}