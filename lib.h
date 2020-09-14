#ifndef lib.h incluida
#define lib.h incluida
#include <stdio.h>

int aux;
/**Uso una variable global ya que es la unica manera de poder mantener el dato del ultimo estado valido para
el control manual despues de un ingreso de hora invalido. Esta parte se podria eliminar del codigo definitivo
ya que la hora se obtendria sola mediante una funcion de la libreria time.h y no habria ingresos invalidos**/
int inicio();
void abierto();
void cerrado();
void abierto1();
void cerrado1();
void error();

#endif
