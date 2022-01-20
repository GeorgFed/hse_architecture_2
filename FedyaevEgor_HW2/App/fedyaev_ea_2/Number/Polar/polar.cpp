//
// Created by Georg on 03.10.2021.
//

#include "polar.h"

using std::ifstream;
using std::ofstream;

Polar::~Polar() = default;

// Ввод параметров из потока.
void Polar::In(ifstream *ifst) {
    *ifst >> rad >> endpoint.x >> endpoint.y;
}

// Рандомная генерация параметров.
void Polar::InRnd() {
    rad = Random();
    endpoint.x = Random();
    endpoint.y = Random();
}

// Вывод данных в файл.
void Polar::Out(ofstream *ofst) {
    *ofst << "It is Polar: angle (radians) = "
         << rad << ", point = (" << endpoint.x << ", " << endpoint.y << "). "
         << "Real: " << ToReal() << "\n";
}

// Вычисление действительного числа.
double Polar::ToReal() {
    return (double)(sqrt(endpoint.x * endpoint.x + endpoint.y * endpoint.y));
}