#include "ProdCons.h"

ProdCons::ProdCons()
{
}

void ProdCons::put(rect e)
{
    mtx.lock();
    while (nb_element >= TAILLE_LISTE)
    {
        plein.wait(mtx);
    }
    fifo[(premier_element + nb_element) % TAILLE_LISTE] = e;
    ++nb_element;
    vide.notify_one();
    mtx.unlock();
}

rect ProdCons::get()
{
    mtx.lock();
    while (nb_element == 0)
    {
        vide.wait(mtx);
    }
    rect res = fifo[premier_element];
    --nb_element;
    ++premier_element;
    plein.notify_one();
    mtx.unlock();
    return res;
}