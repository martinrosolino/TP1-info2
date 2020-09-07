#include "lib.h"

int main()
{
    cargadatos();
    int (*selectora[])(void)={cerrado,abierto,main};
    while(1)
        {
        inicio();
        hola=(*selectora[estado])();
        }
    return 0;
}

