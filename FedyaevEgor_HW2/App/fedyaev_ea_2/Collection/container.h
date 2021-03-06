#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "../Number/number.h"
#include "algorithm"

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
class Container {
public:
    Container();
    ~Container();

    // Инициализация контейнера
    void Init();

    // Очистка контейнера от элементов (освобождение памяти)
    void Clear();

    // Ввод содержимого контейнера из указанного потока
    void In(ifstream *ifst);

    // Случайный ввод содержимого контейнера
    void InRnd(int size);

    // Вывод содержимого контейнера в указанный поток
    void Out(ofstream *ofst);

    // StraightSelection сортировка по убыванию  в контейнере
    void SortAscending();

private:
    enum {max_len = 10000}; // максимальная длина
    int len; // текущая длина
    Number* cont[max_len];
};

#endif
