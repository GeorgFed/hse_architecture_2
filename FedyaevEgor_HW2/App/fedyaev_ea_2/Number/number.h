#ifndef __number__
#define __number__

//------------------------------------------------------------------------------
// number.h - содержит описание обобщающе числа,
//------------------------------------------------------------------------------

#include <fstream>
#include <cmath>

using std::ifstream;
using std::ofstream;

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся числа
class Number {
public:
    virtual ~Number() = default;

    static Number* GlobalIn(ifstream *ifst);
    static Number* GlobalInRnd();

    virtual void  In(ifstream *ifst) = 0;
    virtual void InRnd() = 0;
    virtual void Out(ofstream *ofst) = 0;

    virtual double ToReal() = 0;
};

#endif
