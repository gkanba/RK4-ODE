#include "rk4_solver.hpp"
#include <cstddef>
#include <ios>
#include <string>
#include <vector>
#include <functional>
#include <fstream>
#include <iostream>
#include <iomanip>

namespace kanba{

    RK4_Solver::RK4_Solver(const std::function<double(double, double)> f_i, const double delta_t_i, const double init_x_i) : f(f_i), delta_t(delta_t_i) {
        x = std::vector<double>();
        t = std::vector<double>();
        x.push_back(init_x_i);
        t.push_back(0.0);
    }

    void RK4_Solver::solve(const std::size_t N){
        for(std::size_t n = 0; n < N; n++){
            double k_1 = f(x[n], t[0]);
            double k_2 = f(x[n] + 0.5 * delta_t * k_1, t[0] + 0.5 * delta_t);
            double k_3 = f(x[n] + 0.5 * delta_t * k_2, t[0] + 0.5 * delta_t);
            double k_4 = f(x[n] + delta_t * k_3, t[0] + delta_t);

            x.push_back(x[n] + (delta_t / 6.0) * k_1 
                            + (delta_t / 3.0) * k_2 
                            + (delta_t / 3.0) * k_3
                            + (delta_t / 6.0) * k_4);
            t.push_back(t[n] + delta_t);
        }
    }

    void RK4_Solver::save(const std::string filename){
        std::ofstream stream = std::ofstream(filename);
        if(!stream){
            std::cerr << "Unable to open file : " << filename << std::endl;
        }
        else{
            for(std::size_t n = 0; n < x.size(); n++){
                stream << std::scientific << t[n] << " " << std::scientific << x[n] << std::endl;
            }
            stream.close();
        }
    }
}
