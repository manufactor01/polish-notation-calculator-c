## Calculadora Polaca

Ejemplo de varias operaciones, y su resultado:

```
$ cat oper.txt
5 3 +
5 3 -
5 3 /
3 5 8 + +
3 5 8 + -
3 5 - 8 +
2 2 + +
0 1 ?
1 -1 0 ?
5 sqrt

$ ./dc < oper.txt
8
2
1
16
-10
6
ERROR
ERROR
-1
2
```

[rpn-en]: https://en.wikipedia.org/wiki/Reverse_Polish_notation
[rpn-es]: https://es.wikipedia.org/wiki/Notaci%C3%B3n_polaca_inversa


### Funcionamiento

- Todas las operaciones trabajarán con números enteros, y devolverán números enteros. Se recomienda usar el tipo de C `long` para permitir operaciones de más de 32 bits (p.ej. **3^3^3**).

- El conjunto de operadores posibles es: suma (`+`), resta (`-`), multiplicación (`*`), división entera (`/`), raíz cuadrada (`sqrt`), exponenciación (`^`), logaritmo (`log`) en base arbitraria, y operador ternario (`?`).

  - <!-- https://github.com/gettalong/kramdown/issues/486 -->

    Todos los operadores funcionan con dos operandos, excepto `sqrt` (toma un solo argumento) y el operador ternario (toma tres).

- Tal y como se describe en la bibliografía enlazada, cualquier operación aritmética _a op b_ se escribe en postfijo como `a b op` (por ejemplo, **3 - 2** se escribe en postfijo como `3 2 -`).

  Es útil modelar la expresión como una pila cuyo tope es el extremo derecho de la misma (por ejemplo en `3 2 -`, el tope es `-`); entonces, se puede decir que lo primero que se desapila es el operador, y luego los operandos **en orden inverso**.

  - <!-- gettalong/kramdown#486 -->

    Para operaciones con un solo operando, el formato es obviamente `a op` (por ejemplo, `5 sqrt`). Por su parte, para el operador ternario, el ordenamiento de los argumentos seguiría el mismo principio, transformándose `a ? b : c` en `a b c ?`.

- Ejemplos (nótese que toda la aritmética es entera, y el resultado siempre se trunca):

  - `20 11 -` → `20-11 = 9`
  - `20 -3 /` → `20/-3 = -6`
  - `20 10 ^` → `20^10 = 10240000000000`
  - `60 sqrt` → `√60 = 7`
  - `256 4 ^ 2 log` → `log₂(256⁴) = 32`
  - `1 -1 0 ?` → `1 ? -1 : 0 = -1` (funciona [como en C][ternref])

[ternref]: https://syntaxdb.com/ref/c/ternary


