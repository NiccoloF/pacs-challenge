
// plot "result.dat" w p lw 2 title 'uh' , log(1-x**2/2)  lw 2 title 'u_ex'

#include <iostream>
#include <cmath>

#include "Solver.hpp"
#include "Getpot"
#include "readparameters.hpp"
#include "muParser_fun.hpp"


int main(int argc,char** argv) {
    
    GetPot c1(argc,argv);
    /*
      -v : show a list of parameters 
      -p : specify the file name 
    */
    bool verbose = c1.search(1,"-v");
    std::string filename = c1.follow("parameters.pot","-p");

    std::cout<<"reading file from "<<filename<<std::endl;

    // read parameter from filename and store the result in the parameters class 
    parameters param = readParam(filename,verbose);
    const auto& [f,df,uex,T,N,u0,theta] = param;

    // initialize a muparser object 
    muParser_fun f_(f);
    muParser_fun df_(df);
    mu::Parser uex_;
    uex_.SetExpr(uex);

    // build up the solver using
    /*
    * f(t,y) is the forcing term
    * df(t,y) is the exact derivative
    * uex is the exact solution of the problem 
    * T is the last instant
    * N is the number of intervals 
    * theta is the parameter that characterizes the method : [0,1]
    */  
    Solver solver(f_,df_,uex_,u0,T,N,theta);
    
    // compute exact solution and numerical solution
    const auto exact_solution = solver.compute_exact_solution();
    const auto result = solver.theta_method();
 
    // write the result in ../result.dat 
    std::cout << "Result file: result.dat" << std::endl;
    std::ofstream of("../result.dat");
    of.width(16);

    of << "#TIME\t\tU_H"<<"\n";
    for(size_t i = 0;i<result[0].size();++i)
    {
      of.setf(std::ios::left, std::ios::adjustfield);
      of.width(16);
      of<<result[0][i]<<"\t\t"<< result[1][i]<<"\n";
    }
    of.close();

    #ifdef CONVERGENCE_RATE
    //Compute the infinity-norm error
    //std::cout<<"select the number of iterations to compute the convergence rate: ";
    //unsigned int NUMBER_ITERATIO
    //std::cin<<
    std::vector<double> error_v;
    error_v.resize(CONVERGENCE_RATE);
    for(unsigned int i = 0; i < CONVERGENCE_RATE;++i)
    {
       const auto result = solver.theta_method();
       const auto exact_solution = solver.compute_exact_solution();
       const auto error = compute_error(result[1],exact_solution[1]);
       
       error_v[i] = error;

       //update number of intervals N and time_shift h
       const unsigned int N = solver.get_nSteps();
       solver.set_nSteps(2*N);
    }

    //compute the convergence rate log2(err(i)/err(i+1))
    std::vector<double> error_rate;
    error_rate.resize(error_v.size()-1);
    std::transform(error_v.begin(),error_v.end()-1,error_v.begin()+1,error_rate.begin(),[](double err1,double err2)
    {
      return log2(err1/err2);
    });
    
    std::ofstream oRate("../error_rate.dat");

    for_each(error_rate.begin(),error_rate.end(),[&oRate](double e)
    {
        oRate.setf(std::ios::left, std::ios::adjustfield);
        oRate<<e<<"\n";
    });
    oRate.close();
    std::cout<<"Convergence rate file: error_rate.dat"<<std::endl;
    #endif

    return 0;
}

