cmake_minimum_required(VERSION 3.20)
project(fedyaev_ea_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(fedyaev_ea_1 main.cpp Number/Fraction/fraction.cpp Number/Fraction/fraction.h Number/Complex/complex.cpp Number/Complex/complex.h Number/Polar/polar.cpp Number/Polar/polar.h Collection/container.cpp Collection/container.h Random/random.cpp Random/random.h Helper/point.h Number/number.cpp Number/number.h)
