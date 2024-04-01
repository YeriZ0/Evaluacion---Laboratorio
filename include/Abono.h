#ifndef ABONO_H
#define ABONO_H

#include "Fecha.h"


class Abono
{
    public:
        Abono(Fecha*, float);
        virtual ~Abono();
        Fecha *getFechaAbono();
        float getMontoAbono();

    protected:

    private:
        Fecha *fecha;
        float montoAbono;
};

#endif // ABONO_H
