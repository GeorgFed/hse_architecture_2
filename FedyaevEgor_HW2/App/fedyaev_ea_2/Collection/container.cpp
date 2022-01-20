//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

Container::Container() {
    len = 0;
}

Container::~Container() {
    Clear();
}
//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Container::Clear() {
    for(int i = 0; i < len; i++) {
        delete cont[i];
    }
    len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void Container::In(ifstream *ifst) {
    while(!(*ifst).eof()) {
        if((cont[len] = Number::GlobalIn(ifst)) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void Container::InRnd(int size) {
    while(len < size) {
        if((cont[len] = Number::GlobalInRnd()) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Container::Out(ofstream *ofst) {
    *ofst << "Container contains " << len << " elements." << std::endl;
    for(int i = 0; i < len; i++) {
        *ofst << i << ": ";
        cont[i]->Out(ofst);
    }
}

//------------------------------------------------------------------------------
// Сортировка Шелла по возрастанию
void Container::SortAscending() {
    // Переставляем элементы в интервалах размером n / 2, n / 4 ...
    for (int interval = len / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < len; i += 1) {
            Number* temp = cont[i];
            int j;
            // Сдвигаем отсортированные элементы
            for (j = i; j >= interval && cont[j - interval]->ToReal() > temp->ToReal(); j -= interval) {
                cont[j] = cont[j - interval];
            }
            // Ставим элемент на корректную позицию
            cont[j] = temp;
        }
    }
}
