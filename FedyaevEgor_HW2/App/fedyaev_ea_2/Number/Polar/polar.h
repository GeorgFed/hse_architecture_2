#ifndef __polar__
#define __polar__

//------------------------------------------------------------------------------
// polar.h - содержит описание полярных координат
//------------------------------------------------------------------------------

#include <fstream>
#include <cmath>

#include "../../Random/random.h"
#include "../../Helper/point.h"
#include "../number.h"

using std::ifstream;
using std::ofstream;

class Number;

//------------------------------------------------------------------------------
// полярные координаты
class Polar: public Number {
public:
    ~Polar();
    virtual void In(ifstream *ifst);
    virtual void InRnd();
    virtual void Out(ofstream *ofst);
    // Вычисление действительного числа
    virtual double ToReal();
private:
    double rad;
    point endpoint;
};

#endif //__polar__
