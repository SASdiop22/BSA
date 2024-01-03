#ifndef BENCHMARKS_H_INCLUDED
#define BENCHMARKS_H_INCLUDED
#include"math.h"

inline double rosenbrock(const std::vector<double>& x) {
    double sum = 0.0;
    int n = x.size();
    for (int i = 0; i < n - 1; ++i) {
        double term1 = 100 * pow(x[i + 1] - x[i] * x[i], 2);
        double term2 = pow(1 - x[i], 2);
        sum += term1 + term2;
    }

    return sum;
}

double sixHumpCamelback(const std::vector<double>& x)
{
    return (4 - 2.1 * x[0] * x[0] + std::pow(x[0], 4) / 3) * x[0] * x[0] + x[0] * x[1] + (-4 + 4 * x[1] * x[1]) * x[1] * x[1];
}


//fonction Weierstrass

double weierstrass(const std::vector<double>& x, double a, double b){
    double resultat = 0.0;
    for(int i = 0; i< x.size(); i++){
        resultat += pow(a,i) * cos(pow(b,i) * PI * x[i]);
    }
    return resultat;
}

double michalewicz(const std::vector<double>& x, int m=10){
    double resultat = 0.0;
    int n = x.size();
    for(int i=0; i< n; i++){
        resultat += -sin(x[i]) * pow(sin((i+1)*x[i]*x[i]/PI),2*m);
    }
    return resultat;
}


#endif // BENCHMARKS_H_INCLUDED
