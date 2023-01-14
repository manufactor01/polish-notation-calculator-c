#include <stdlib.h>
#include <string.h>
#include "strutil.h"
#include <stdio.h>


/* ******************************************************************
 * *                        FUNCIONES AUXILIARES
 * * *****************************************************************/
char **create_strv(const char * str, char sep) {
  size_t count_sep = 0;
  for(size_t i = 0; i < strlen(str); i++) {
    if(str[i] == sep) count_sep++;
  }
  return malloc((count_sep + 2) * sizeof(char *)); 
}

char *create_str(char **strv) {
  size_t size_str = 0;
  for(size_t i = 0; strv[i]; i++) {
    size_str += strlen(strv[i]);
    size_str++;
  }
  return calloc((size_str + 1), sizeof(char));
}

/* ******************************************************************
 * *                        PROGRAMA PRINCIPAL
 * * *****************************************************************/
char *substr(const char *str, size_t n) {
  char *str_result = calloc(n + 1, sizeof(char));
  for(size_t i = 0; i < n; i++){
    str_result[i] = str[i];
  }
  return str_result;
}

char** split(const char* str, char sep){
  char **strv = create_strv(str, sep);
  size_t size_str = strlen(str);
  size_t j = 0;
  size_t k = 0;
  for(size_t i = 0; i <= size_str; i++) {
      if(str[i] == sep || str[i] == '\0') {
        strv[k++] = substr(str + j, i - j);
        j = i + 1;
      }
  }
  strv[k] = NULL;
  return strv;
}

char* join(char** strv, char sep) {
  char *str = create_str(strv);
  size_t j = 0;
  size_t i = 0;
  while(strv[i]){
    size_t size_str = strlen(strv[i]);
    strncpy(str + j, strv[i], size_str);
    j += size_str;
    i++;
    if(sep != '\0' && strv[i]) {
      str[j++] = sep;
    }
  }
  return str;
}

void free_strv(char* strv[]) {
  for(size_t i = 0; strv[i]; i++) {
    free(strv[i]);
  }
  free(strv);
}

