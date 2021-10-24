//------------------------------------------------------------------------------
// number.cpp - содержит процедуры связанные с обработкой обобщенного числа
// и создания произвольного числа
//------------------------------------------------------------------------------

#include "number.h"

using std::ifstream;
using std::ofstream;

#include "Fraction/fraction.h"
#include "Complex/complex.h"
#include "Polar/polar.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенного числа из файла
Number* Number::GlobalIn(ifstream *ifst) {
    Number* sp = nullptr;
    int k;
    *ifst >> k;
    switch(k) {
        case 1:
            sp = new Fraction;
            break;
        case 2:
            sp = new Complex;
            break;
        case 3:
            sp = new Polar;
            break;
        default:
            return nullptr;
    }
    sp->In(ifst);
    return sp;
}

// Случайный ввод обобщенного числа
Number* Number::GlobalInRnd() {
    Number *sp;
    auto k = rand() % 2 + 1;
    switch(k) {
        case 1:
            sp = new Fraction;
            break;
        case 2:
            sp = new Complex;
            break;
        case 3:
            sp = new Polar;
            break;
        default:
            return nullptr;
    }
    sp->InRnd();
    return sp;
}

