#include <stdio.h>
#include <stdlib.h>
#include "notacion_posfija.h"
#include "testing.h"
#include "strutil.h"

void pruebas_operaciones_notacion_posfija() {
   printf("--------------------------------------------------\n");
   printf("PRUEBAS OPERACIONES NOTACIÓN POSFIJA\n");
   printf("--------------------------------------------------\n");

   char *str_1 = "5 3 +";
   char *str_2 = "5 3 -";
   char *str_3 = "5 3 /";
   char *str_4 = "3 5 8 + +";
   char *str_5 = "3 5 8 + -";
   char *str_6 = "3 5 - 8 +";
   char *str_7 = "1 -1 0 ?";
   char *str_8 = "5 sqrt";
   char *str_9 = "0 1 ?";
   char *str_10 = "2 2 + +";
   char *str_11 = "-5 sqrt";
   char *str_12 = "60 sqrt";
   char *str_13 = "20 -3 /";
   char *str_14 = "18 2 log";

   char **strv_1 = split(str_1, ' ');
   char **strv_2 = split(str_2, ' ');
   char **strv_3 = split(str_3, ' ');
   char **strv_4 = split(str_4, ' ');
   char **strv_5 = split(str_5, ' ');
   char **strv_6 = split(str_6, ' ');
   char **strv_7 = split(str_7, ' ');
   char **strv_8 = split(str_8, ' ');
   char **strv_9 = split(str_9, ' ');
   char **strv_10 = split(str_10, ' ');
   char **strv_11 = split(str_11, ' ');
   char **strv_12 = split(str_12, ' ');
   char **strv_13 = split(str_13, ' ');
   char **strv_14 = split(str_14, ' ');

   int *numero_1 = notacion_posfija(strv_1);
   int *numero_2 = notacion_posfija(strv_2);
   int *numero_3 = notacion_posfija(strv_3);
   int *numero_4 = notacion_posfija(strv_4);
   int *numero_5 = notacion_posfija(strv_5);
   int *numero_6 = notacion_posfija(strv_6);
   int *numero_7 = notacion_posfija(strv_7);
   int *numero_8 = notacion_posfija(strv_8);
   int *numero_9 = notacion_posfija(strv_9);
   int *numero_10 = notacion_posfija(strv_10);
   int *numero_11 = notacion_posfija(strv_11);
   int *numero_12 = notacion_posfija(strv_12);
   int *numero_13 = notacion_posfija(strv_13);
   int *numero_14 = notacion_posfija(strv_14);

   print_test("5 3 + devuelve 8", 8 == *numero_1);
   print_test("5 3 - devuelve 2", 2 == *numero_2);
   print_test("5 3 / devuelve 1", 1 == *numero_3);
   print_test("3 5 8 + + devuelve 16", 16 == *numero_4);
   print_test("3 5 8 + - devuelve -10", -10 == *numero_5);
   print_test("3 5 - 8 + devuelve 6", 6 == *numero_6);
   print_test("1 -1 0 ? devuelve -1", -1 == *numero_7);
   print_test("5 sqrt devuelve 2", 2 == *numero_8);
   print_test("0 1 ? devuelve NULL", !numero_9);
   print_test("2 2 + + devuelve NULL", !numero_10);
   print_test("-5 sqrt devuelve NULL", !numero_11);
   print_test("60 sqrt devuelve 7", 7 == *numero_12);
   print_test("20 -3 / devuelve -6", -6 == *numero_13);
   print_test("18 2 log devuelve 4", 4 == *numero_14);

   free_strv(strv_1);
   free_strv(strv_2);
   free_strv(strv_3);
   free_strv(strv_4);
   free_strv(strv_5);
   free_strv(strv_6);
   free_strv(strv_7);
   free_strv(strv_8);
   free_strv(strv_9);
   free_strv(strv_10);
   free_strv(strv_11);
   free_strv(strv_12);
   free_strv(strv_13);
   free_strv(strv_14);

   free(numero_1);
   free(numero_2);
   free(numero_3);
   free(numero_4);
   free(numero_5);
   free(numero_6);
   free(numero_7);
   free(numero_8);
   free(numero_12);
   free(numero_13);
   free(numero_14);
}

void pruebas_notacion_posfija() {
  pruebas_operaciones_notacion_posfija();
}
