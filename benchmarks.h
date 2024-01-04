#ifndef BENCHMARKS_H_INCLUDED
#define BENCHMARKS_H_INCLUDED
<<<<<<< HEAD
#include"math.h"
#include<vector>
#include <cmath>


=======

>>>>>>> 3ba78e8535ba397010ef2690bfe3fea878d56aed
//Bornes [-5,5]
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
//Bornes [-5.12,5.12]
inline double rastrigin(const std::vector<double>& x) {
    int n = x.size();
    double sum = 10.0 * n;

    for (int i = 0; i < n; ++i) {
        sum += (x[i] * x[i] - 10 * cos(2 * M_PI * x[i]));
    }
    return sum;
}
//Bornes [-500,500]
inline double schwefel(const std::vector<double>& x) {
    int n = x.size();
	double sum = 418.9829 * n;
	double subSum = 0.0;
	for (unsigned int i = 0; i < n; i++) {
		subSum += (x[i] * std::sin(std::sqrt(std::abs(x[i]))));
	}
	return sum - subSum;
}

//fonction Weierstrass bornes [-1.0,1.0]

double weierstrass(const std::vector<double>& x){
    double a =0.5, b= 3.0;
    double resultat = 0.0;
    for(int i = 0; i< x.size(); i++){
        resultat += pow(a,-i) * cos(pow(b,i) * PI * x[i]);
    }
    return resultat;
}
//fonction Michalewicz bornes[0,PI]
double michalewicz(const std::vector<double>& x){
    double resultat = 0.0;
    int m=10;
    int n = x.size();
    for(int i=0; i< n; i++){
        resultat += sin(x[i]) * pow(sin((i+1)*x[i]*x[i]/PI),2*m);
    }
    return -resultat;
}

//fonction Griewank

double griewank(const std::vector<double>& x)
{
    int n= x.size();
    double sum=0.0;
    double prod=1.0;
    for(int i{0}; i<n ; i++)
        {
            sum+= x[i]*x[i];
            prod*= cos(x[i]/sqrt(i+1));
        }
        return 1+sum/4000- prod;
}

//fonction ackley
double ackley(const std::vector<double>& x)
{    double a=20, b=0.2, c=2.0*M_PI;
    int n= x.size();
    double sum=0.0;
    double sumCos= 0.0;
    for(int i{0}; i<n; i++)
        {
            sum+= x[i]*x[i];
            sumCos+=cos(c* x[i]);
        }
    double partie1= -a*exp(-b*sqrt(sum/n));
    double partie2= -exp(sumCos/n);
    return partie1+ partie2+ a+ exp(1.0);
}

#endif // BENCHMARKS_H_INCLUDED
