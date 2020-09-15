#ifndef lib.h incluida
#define lib.h incluida
#include <stdio.h>
#include <time.h>

time_t(currenttime);

typedef struct
        {
        int p1,f1,p2,f2;
        }tipo;

typedef enum
        {
        cerrado=0,
        abierto=1
        }tipoestado;

tipoestado estado;
tipo inicio(void);
tipoestado abrir(tipo config);
tipoestado cerrar(tipo config);

#endif
