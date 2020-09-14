#include "lib.h"

int main()
{
    tipo config;
    estado=0;//Estado inicial
    config=inicio();//Carga variables
    int (*selectora[])(tipo)={cerrado,abierto};
    while (1) estado=(*selectora[estado])(config);
    return 0;
}

