#ifndef BENCHMARKS_H_INCLUDED
#define BENCHMARKS_H_INCLUDED

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

#endif // BENCHMARKS_H_INCLUDED
