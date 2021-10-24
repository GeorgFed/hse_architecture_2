//
// Created by Georg on 03.10.2021.
//

#include "complex.h"
#include "../number.h"

using std::ifstream;
using std::ofstream;

Complex::~Complex() = default;

// Ввод параметров из потока.
void Complex::In(ifstream *ifst) {
    *ifst >> d >> i;
}

// Рандомная генерация параметров.
void Complex::InRnd() {
    d = Random();
    i = Random();
}

// Вывод данных в файл.
void Complex::Out(ofstream *ofst) {
    *ofst << "It is Complex: d = "
         << d << ", i = " << i
         << ". Real = " << ToReal() << "\n";
}

// Вычисление дейтсвительного числа.
double Complex::ToReal() {
    return (double)(sqrt(d * d + i * i));
}