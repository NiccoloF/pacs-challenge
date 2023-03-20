# THETA METHOD FOR A CAUCHY PROBLEM

- A Cauchy problem is a problem of determining a function (or several functions) satisfying a differential equation (or system of differential equations) and assuming given values at some fixed point.

- *Here* [GitHub](https://github.com/NiccoloF/pacs-challenge/tree/main/firstAssignment) you can find the code to solve a Cauchy problem using ***Theta Method***.    
> **Note** this program makes use of the ***Newton algorithm*** to find the zero of the function:
$\ F(x) = x - \frac{h}{2} * (f(t_{n+1},x)+f(t_{n},u_{n})) - u_{n}$

## CONTENT

Here you can find:  
- ```Include``` --> General Include Files  
- ```src``` --> Directory with the sources files  
- ```plot.sh``` --> Bash script to plot the solution using ***Gnuplot***  

## HOW TO COMPILE

- In order to compile and run the code: 
>- Go into the ```src/``` directory
>- Installing muParser library,
>- In the **Makefile**, you should change the variables LDFLAGS and LDLIBS adding your local path.
>- set your parameters in **parameters.pot**
>- Run ```Make```

### ADDITIONAL FLAGS

- You can execute the code adding ```-v``` flag to show verbose input parameters.
- Defining Macro ```CONVERGENCE_RATE``` allows you to compute the converge rate of the numerical method. 

## PLOT

- ***Plot.sh*** is a bash script that allows you to plot the Numerical vs the Analytic solution.

## ADDITIONAL COMMENTS 
- Inside ```muParser_fun.cpp``` you'll find 
``` cpp
    double a = t_value;  
    double b = y_value;  
    muParser.DefineVar("t",&a);  
    muParser.DefineVar("y",&b);    
```
 This is completely useless but, if deleted, sometimes muParser gives wrong results.  
 You can check the results in ***result.dat***
