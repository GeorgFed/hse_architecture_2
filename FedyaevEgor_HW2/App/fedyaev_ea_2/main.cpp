//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()
#include <cstring>

#include "Collection/container.h"

using std::cout;
using std::endl;

void errMessage1() {
    cout << "incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n";
}

void errMessage2() {
    cout << "incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n";
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    if(argc != 5) {
        errMessage1();
        return 1;
    }
    try {
    clock_t start = clock();
    Container *c = new Container();

    if(!strcmp(argv[1], "-f")) {
        ifstream ifst(argv[2]);
        c->In(&ifst);
    }
    else if(!strcmp(argv[1], "-n")) {
        size_t size = atoi(argv[2]);
        if((size < 1) || (size > 10000)) {
            cout << "incorrect number of numbers = "
                 << size
                 << ". Set 0 < number <= 10000\n";
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел
        c->InRnd(size);
    }
    else {
        errMessage2();
        return 2;
    }

    // Вывод содержимого контейнера в файл
    ofstream ofst1(argv[3]);
    ofst1 << "Filled container:\n";
    c->Out(&ofst1);

    // Вторая часть задания
    ofstream ofst2(argv[4]);
    c->SortDescending();
    c->Out(&ofst2);

    c->Clear();
    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.6f\n", elapsed);
    delete c;
    } catch(std::exception& exception) {
        std::cout << exception.what() << std::endl;
    }
    return 0;
}
