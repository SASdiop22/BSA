#ifndef BSA_H_INCLUDED
#define BSA_H_INCLUDED
#define PI 3.14159265

#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include <functional>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

class OriginalBSA
{
public:
    OriginalBSA(int epoch1 = 1000, int popSize1 = 100, int dimension1 = 30);
    std::vector<double> solve(std::vector<double> &lb,std::vector<double> &ub, std::function<double(std::vector<double>)> func, double mixrate);
private:
    void trierPopulationEnFonctionDeFitness(std::vector<double>& fitn, std::vector<std::vector<double>>& population);
    double amendPosition(double& pos, double lb, double ub);
    int epoch;
    int popSize;
    int dimension;

//    std::vector<std::vector<double>> d_P, d_oldP, d_T;
// void selectionI();
//    std::vector<std::vector<double>> mutation();
//    void selectionII();

};


#endif // BSA_H_INCLUDED
