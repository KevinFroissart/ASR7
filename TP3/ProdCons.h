#ifndef PRODCONS_H
#define PRODCONS_H
#include <iostream>
#include <mutex>
#include <condition_variable>

static const int TAILLE_LISTE = 100;
struct rect
{
    int slice_number;
    int y_start;
    rect(){};
    rect(int sn, int y) : slice_number(sn), y_start(y){};
};

class ProdCons
{
public:
    ProdCons();
    void put(rect e);
    rect get();

private:
    std::mutex mtx;
    std::condition_variable_any vide;
    std::condition_variable_any plein;
    rect fifo[TAILLE_LISTE];
    int premier_element = 0;
    int nb_element = 0;
};

#endif