#ifndef lib.h incluida
#define lib.h incluida
#include <stdio.h>

typedef struct
        {
        int p1,f1,p2,f2;
        }tipo;
int aux,estado;
/**Uso dos variables globales ya que es la unica manera de poder mantener el dato del ultimo estado valido para
el control manual despues de un ingreso de hora invalido. Esta parte se podria eliminar del codigo definitivo
ya que la hora se obtendria sola mediante una funcion de la libreria time.h y no habria ingresos invalidos**/
tipo inicio(void);
int abierto(tipo config);
int cerrado(tipo config);

#endif
