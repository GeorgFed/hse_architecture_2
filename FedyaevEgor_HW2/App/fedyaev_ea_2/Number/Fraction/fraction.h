#ifndef __fraction__
#define __fraction__

//------------------------------------------------------------------------------
// fraction.h - содержит описание дробных чисел
//------------------------------------------------------------------------------

#include <fstream>
#include <cmath>

#include "../../Random/random.h"
#include "../number.h"

using std::ifstream;
using std::ofstream;

class Number;

//------------------------------------------------------------------------------
// дробные числа
class Fraction: public Number {
public:
    ~Fraction();
    virtual void In(ifstream *ifst);
    virtual void InRnd();
    virtual void Out(ofstream *ofst);
    // Вычисление действительного числа
    virtual double ToReal();
private:
    int numerator, denominator; // дейтсивтельная и мнимая часть
};
#endif //__fraction__
