#include <stdio.h>
#include "testing.h"
#include "pruebas_notacion_posfija.c"

/* ******************************************************************
 * *                        PROGRAMA PRINCIPAL
 * * *****************************************************************/

int main(void) {
  /*  Ejecuta todas las pruebas unitarias */
  printf("~~~ PRUEBAS ALUMNO ~~~\n");
  pruebas_notacion_posfija();

  return failure_count() > 0;
}
