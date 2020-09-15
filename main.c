#include "lib.h"

int main()
{
    tipo config;
    estado=cerrado;
    config=inicio();//Carga variables
    tipoestado (*selectora[])(tipo)={cerrar,abrir};
    while (1)
        {
        while (!kbhit())//Control automático
            estado=(*selectora[estado])(config);

        while (kbhit()!=0)//Control manual
            {
            getch();//Reinicia el kbhit

            while (!kbhit())
                {
                if(estado==abierto)
                    (*selectora[0])(config);
                if(estado==cerrado)
                    (*selectora[1])(config);
                printf("Pulse algo para volver al control automatico\n----------\n");
                sleep(1);
                }

            if(kbhit()!=0)//Sale del control manual
                {
                getch();//Reinicia el kbhit
                break;
                }
            }
        }
    return 0;
}

