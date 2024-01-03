#include <iostream>
#include <string>
#include <vector>
#include "BSA.h"
#include "fonction.h"
#include "benchmarks.h"
int main()
{
    OriginalBSA A{10000,30,30};
    std::vector<double> upper(30,5);
    std::vector<double> lower(30,-5);
    affiche(A.solve(lower,upper,rastrigin,1.0));
}
