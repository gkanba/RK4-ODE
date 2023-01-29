#ifndef IG_H_RK4_SOLVER_
#define IG_H_RK4_SOLVER_

#include <cstddef>
#include <string>
#include <vector>
#include <functional>

namespace kanba{

    struct RK4_Solver
    { 
        // Function pointer for f(x, t)
        std::function<double(double, double)> f;
        // Discrete time increment
        double delta_t;
        // Container for result
        std::vector<double> x;
        std::vector<double> t;

        // Constructor
        RK4_Solver(const std::function<double(double, double)> f_i, const double delta_t_i, const double init_x_i);
        // Solve ODE and contain results in vectors
        void solve(const std::size_t N);
        void save(const std::string filename);
    };
}

#endif
