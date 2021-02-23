#ifndef PRODCONS_H
#define PRODCONS_H
#include <iostream>
#include <mutex>
#include <queue>
#include <condition_variable>

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
    ProdCons(int taille = 10);
    //~ProdCons();
    void put(rect e);
    rect get();

private:
    unsigned int taille;
    std::queue<rect> data;
    std::mutex mut;
    std::condition_variable vide;
    std::condition_variable plein;
};

#endif