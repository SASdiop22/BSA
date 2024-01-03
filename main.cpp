#include <iostream>
#include <string>
#include <vector>
#include "BSA.h"
#include "benchmarks.h"
int main()
{
    OriginalBSA A{1000,100,8};
    std::vector<double> upper{5,5};
    std::vector<double> lower{-5,-5};

    //A.solve(lower,upper,rosenbrock,1.0);
    std::vector<double> param{0.458767,0.201833,0,2.04112e-232,5.25455e-315,5.95606e-304,0.00993209,1.53124e-314};
    std::cout << rosenbrock(param)<<std::endl;
    std::cout << "Weierstrass(param,0.5,3.0) = "<<weierstrass(param,0.5,3.0)<<std::endl;;
    std::cout << "Michalewics(param,10) = "<<michalewicz(param,10)<<std::endl;;


}
