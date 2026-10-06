#include <stdio.h>
#include "String.h"

/*
 * todosiguales — imprime 1 si todos los argumentos son iguales, 0 si no.
 *
 * Uso: ./todosiguales hola hola hola  →  1
 *      ./todosiguales hola mundo      →  0
 *
 * Pista: compara cada argumento contra argv[1] usando AreEqual.
 *        Iterá con puntero (char **arg), no con indice entero.
 */

int main(int argc, char *argv[]) {
    /*(void)argc; (void)argv;*/
    if (argc < 2)
    {
        return 1;
    }
    
    char* argumento = argv[1];
    for (char **arg = argv + 2 ; *arg != NULL; arg++)
    {
        if (!AreEqual(argumento, *arg))
        {
            printf("%d\n", 0);
            return 0;
        }
    }
    printf("%d\n", 1);
    return 1;
}
