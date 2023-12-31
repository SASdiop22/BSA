#include "BSA.h"
#include "fonction.h"
#include <limits>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <random>
//std::random_device rd;
//std::mt19937 generateur(rd());
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generateur(seed);
std::uniform_real_distribution<double> U(0.0,1.0);
std::normal_distribution<double> N(1.0, 0.0);

OriginalBSA::OriginalBSA(int epoch1, int popSize1, int dimension1):
    epoch{epoch1}, popSize{popSize1}, dimension{dimension1}
{

}

void OriginalBSA::trierPopulationEnFonctionDeFitness(std::vector<double>& fitn, std::vector<std::vector<double>>& population) {

}

//corriger la posisition si hors des limites
double OriginalBSA::amendPosition(double& pos, double lb, double ub) {
    if(pos < lb || pos > ub)
    {

        pos = U(generateur)*(ub-lb) + lb;
    }
}

//algo du  BSA
std::vector<double> OriginalBSA::solve(std::vector<double> &lb,std::vector<double> &ub, std::function<double(std::vector<double>)> func,double mixrate)
{
    //Initialisation
    double globalMinimum = std::numeric_limits<double>::infinity();
    std::vector<double> globalMinimizer(popSize);
    std::vector<std::vector<double>> P(popSize,std::vector<double>(dimension));
    std::vector<std::vector<double>> oldP(popSize,std::vector<double>(dimension));
    std::vector<double> fitnessP(popSize);

    for(int i{0}; i < popSize; ++i)
    {
        for(int j{0}; j < dimension; ++j)
        {
            P[i][j] = U(generateur)*(ub[j] - lb[j]) + lb[j];
            oldP[i][j] = U(generateur)*(ub[j] - lb[j]) + lb[j];
        }
        fitnessP[i] =  func(P[i]);
    }



    int iter{0};
    while(globalMinimum > 1e-16 && iter < epoch)
    {
        iter += 1;
        //SelectionI
        double a = U(generateur);
        double b = U(generateur);
        //std::cout << " a = " << a << " b = " << b << '\n';
        if(a<b)
        {
           oldP  = copie(P);
        }
        std::shuffle(oldP.begin(), oldP.end(), generateur);



            // Mutation
            std::vector<std::vector<double>> mutant{};
            mutant.resize(popSize,std::vector<double>(dimension));
            for (int i = 0; i <popSize ; ++i)
                {
                    for (int j = 0; j < dimension; ++j)
                    {

                        mutant[i][j] = P[i][j] + (3.0*N(generateur))* (oldP[i][j] - P[i][j]);
                    }
                }
            // mutant = d_P + (3.0*normalDistributorN(0.0,1.0))*(d_oldP - d_P);
            std::vector<std::vector<bool>> map(popSize, std::vector<bool>(dimension,true));
            std::vector<int> TD(dimension);
            for(int i{0}; i < dimension; i++)
            {
                TD[i] = i+1;
            }
            std::shuffle(TD.begin(), TD.end(), generateur);
            double c = U(generateur);
            double d = U(generateur);
            if(c < d)
            {
                for(int i{0}; i < popSize; ++i)
                {
                    int x = TD[mixrate * static_cast<int>(U(generateur)) *dimension];
                    map[i][x] = 0;
                }
            }
            else
            {
                for(int i {0}; i < popSize; ++i)
                {
                    std::uniform_real_distribution<double> Ux(0.0,dimension);
                    int x = static_cast<int>(Ux(generateur));
                    map[i][x] = 0;
                }
            }
            std::vector<std::vector<double>> T = mutant;
            for(int i{0}; i < popSize; ++i)
            {
                for(int j{0}; j < dimension; ++j)
                {
                    if(map[i][j] == 1)
                        T[i][j] = P[i][j];
                }
            }
            for(int i{0}; i < popSize; ++i)
            {
                for(int j{0}; j < dimension; ++j)
                {
                    amendPosition(T[i][j],lb[j],ub[j]);
                }
            }


        //SelectionII
        std::vector<double> fitnessT(popSize);
        for(int i{0}; i < popSize; ++i)
        {
            fitnessT[i] = func(T[i]);
        }
        for(int i{0}; i < popSize; ++i)
        {
            if(fitnessT[i] < fitnessP[i])
            {
                fitnessP[i] = fitnessT[i];
                P[i] = T[i];
            }
        }
        //double fitnessPbest = *std::min_element(fitnessP.begin(),fitnessP.end());
        int best = 0;
        for(int i{1}; i < popSize; ++i)
        {
            if(fitnessP[i]<fitnessP[best])
            {
                best = i;
            }
        }
        if(fitnessP[best] < globalMinimum)
        {
            globalMinimum = fitnessP[best];
            globalMinimizer = P[best];
        }
        std::cout << "------------------------------------------------------------------------------------------------------"<<'\n';

//        std::cout << "Population P : " << '\n';
//        affiche(P);
//        std::cout << "Population oldP : " << '\n';
//        affiche(oldP);
        std::cout << "Meilleur individu: " << '\n';
        affiche(globalMinimizer);
        std::cout<<"globalMinimum: " ;
        std::cout<<globalMinimum << '\n';
    }
    std::cout<< "Nombre iteration realise: " << iter << '\n';
}
