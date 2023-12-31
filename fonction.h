#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include <random>
#include <vector>
#include <ctime>

//fonction qui permet de melanger les elements d'un vector
//inline void permuting(std::vector<std::vector<double>>& Tab)
//{
//   // std::random_device rd;
//    std::mt19937 generateur(static_cast<unsigned int>(std::time(nullptr)));
//    std::shuffle(Tab.begin(), Tab.end(), generateur);
//}
//inline void permuting(std::vector<int>& Tab)
//{
//   // std::random_device rd;
//    std::mt19937 generateur(static_cast<unsigned int>(std::time(nullptr)));
//    std::shuffle(Tab.begin(), Tab.end(), generateur);
//}

//inline double randomDistributorU(double inf, double sup)
//{
//    //std::random_device rd;
//    std::mt19937 generateur(static_cast<unsigned int>(std::time(nullptr))); //rd());
//    std::uniform_real_distribution<double> U(inf, sup);
//    return U(generateur);
//}
//
//inline double normalDistributorN(double moyenne, double ecartType)
//{
//    std::mt19937 generateur(static_cast<unsigned int>(std::time(nullptr)));
//    std::normal_distribution<double> N(moyenne, ecartType);
//    return N(generateur);
//}

//Foction qui permet de creer un copie d'un vector aulieu d'utiliser =
inline std::vector<std::vector<double>> copie(const std::vector<std::vector<double>>& Tab)
{
    std::vector<std::vector<double>> C{};
    if(!Tab.empty())
    {
        C.resize(Tab.size(),std::vector<double>(Tab[0]));
        for (unsigned int i = 0; i < Tab.size(); ++i)
        {
            std::copy(Tab[i].begin(), Tab[i].end(), C[i].begin());
        }
    }
    return C;
}
inline void affiche(const std::vector<std::vector<double>>& Tab)
{
    int N = Tab.size(), D = Tab[0].size();
    for(int i{0}; i< N; ++i)
    {
        for(int j{0}; j < D; ++j)
        {
            std::cout << Tab[i][j] << "    ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}
inline void affiche(const std::vector<double>& Tab)
{
    int N = Tab.size();
    for(int i{0}; i< N; ++i)
    {
        std::cout << Tab[i] << "    ";
    }
    std::cout << '\n';
}

#endif // FONCTION_H_INCLUDED
