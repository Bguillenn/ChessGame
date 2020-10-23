#ifndef REINA_H
#define REINA_H

#include "Pieza.h"

class Reina : public Pieza
{
public:
    explicit Reina(QWidget *parent = nullptr);
    void MoverPieza();
};

#endif // REINA_H
