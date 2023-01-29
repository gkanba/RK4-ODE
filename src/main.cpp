#include <cstdint>

#include "rk4_solver.hpp"

double func(double x, double t){
    return 1.0;
}

std::int32_t main (std::int32_t argc, char *argv[])
{
    
    kanba::RK4_Solver solver = kanba::RK4_Solver(func, 0.01, 1.0);
    solver.solve(1000);
    solver.save("result.txt");
    return 0;
}
