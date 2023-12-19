#ifndef BSA_H_INCLUDED
#define BSA_H_INCLUDED
class BSA
{
private:
    int d_N, d_D, d_maxCycles;
    double d_mixRate,globalminimum;
    std::vector<double>& d_lowerBounds, d_upperBounds;

public:
BSA(int N, int D,int maxCycles, double mixRate,const std::vector<double>& lowerBounds, const std::vector<double>& upperBounds);

};

void permuting(std::vector<std::vector<double>>& Tab)
{
    //A ecrire
}
double distributorU()
{
    //A ecrire
}
#endif // BSA_H_INCLUDED
