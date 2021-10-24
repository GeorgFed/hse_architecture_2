#ifndef __complex__
#define __complex__

//------------------------------------------------------------------------------
// complex.h - содержит описание комплексных чисел
//------------------------------------------------------------------------------

#include <fstream>
#include <cmath>

#include "../../Random/random.h"
#include "../number.h"

using std::ifstream;
using std::ofstream;

class Number;

//------------------------------------------------------------------------------
// комплексные числа
class Complex: public Number {
public:
    ~Complex();
    virtual void In(ifstream *ifst);
    virtual void InRnd();
    virtual void Out(ofstream *ofst);
    // Вычисление действительного числа
    virtual double ToReal();
private:
    double d, i; // дейтсивтельная и мнимая часть
};

#endif //__complex__
