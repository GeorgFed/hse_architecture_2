//
// Created by Georg on 03.10.2021.
//

#include "fraction.h"

using std::ifstream;
using std::ofstream;

Fraction::~Fraction() = default;

// Ввод параметров из потока.
void Fraction::In(ifstream *ifst) {
    *ifst >> numerator >> denominator;
}

// Рандомная генерация параметров.
void Fraction::InRnd() {
    numerator = Random();
    denominator = Random();
}

// Вывод данных в файл.
void Fraction::Out(ofstream *ofst) {
    *ofst << "It is Fraction: numenator = "
         << numerator << ", denominator = " << denominator
         << ". Real = " << ToReal() << "\n";
}

// Вычисление дейтсвительного числа.
double Fraction::ToReal() {
    return (double)(numerator / denominator);
}