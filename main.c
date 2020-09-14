#include "lib.h"

int main()
{
    cerrado();//Estado inicial

    /**Con punteros a funciones**/
    int (*selectora[])(void)={cerrado,abierto,cerrado1,abierto1,error};
    while (1) (*selectora[inicio()])();


    /**Con switch case:
    while (1)
        switch(inicio())
            {
            case 0:
                cerrado();
                break;
            case 1:
                abierto();
                break;
            case 2:
                cerrado1();
                break;
            case 3:
                abierto1();
                break;
            case 4:
                error();
                break;
            }**/

    return 0;
}

