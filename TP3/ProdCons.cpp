#include "ProdCons.h"

ProdCons::ProdCons(int taille) : taille(taille), data(),
                                 mut(),
                                 vide(),
                                 plein()
{
}

void ProdCons::put(rect e)
{
    std::unique_lock<std::mutex> unk(mut);

    while (data.size() == taille)
    {
        plein.wait(unk);
    }
    data.push(e);
    vide.notify_one();
}

rect ProdCons::get()
{
    std::unique_lock<std::mutex> unk(mut);
    while (data.size() == 0)
    {
        vide.wait(unk);
    }
    rect result = data.front();
    data.pop();
    plein.notify_one();
    return result;
}