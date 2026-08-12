#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/* ═══════════════════════════════════════════════════════════════════════════
 *  TESTS ESCRITOS — ya funcionan, son el punto de partida
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_carrito_nuevo(void) {
    printf("\n[carrito nuevo]\n");
    Carrito c;
    carrito_init(&c);
    ASSERT_IGUAL(0, carrito_contar(&c));
}

void test_agregar_uno(void) {
    printf("\n[agregar un producto]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 1};
    ASSERT_IGUAL(1, carrito_agregar(&c, p));   /* devuelve 1 = exito */
    ASSERT_IGUAL(1, carrito_contar(&c));
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE A — Agregar el siguiente test (ver README.md, Parte 4)
 * ═══════════════════════════════════════════════════════════════════════════ */


void test_total_precio_unitario(void) {
    printf("\n[total: un producto, cantidad 1]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 1};
    carrito_agregar(&c, p);
    ASSERT_IGUAL(350, carrito_total(&c));
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE B — Completar los blancos (ver README.md, Parte 5)
 * ═══════════════════════════════════════════════════════════════════════════ */


void test_total_con_cantidad(void) {
    printf("\n[total: un producto, cantidad 2]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 2};  /* 350 x 2 = 700 */
    carrito_agregar(&c, p);
    ASSERT_IGUAL(700, carrito_total(&c));  /* <-- completar el valor esperado */
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE C — Escribir un test propio (ver README.md, Parte 7)
 * ═══════════════════════════════════════════════════════════════════════════ */


void test_carrito_lleno(void){
    printf("\n[Agregar un producto mas a un carrito lleno]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 1};  
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    ASSERT_IGUAL(0 , carrito_agregar(&c, p)); 

}

void test_carrito_buscar(void){ /*Ejercitacion extra*/
    printf("\n[La posicion del producto es 0]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 1};
    carrito_agregar(&c, p);
    ASSERT_IGUAL(0 , carrito_buscar(&c,"Leche"));
    
}

void test_buscar_producto_en_carrito_vacio(void){ /*Ejercitacion extra*/
    printf("\n[El producto no esta en el carrito]\n");
    Carrito c;
    carrito_init(&c);
    ASSERT_IGUAL(-1 , carrito_buscar(&c,"Leche"));
}

void test_carrito_encuentra_el_primer_producto_con_ese_nombre(void){ /*Ejercitacion extra*/
    printf("\n[Devuelve la posicion de la primera gaseosa]\n");
    Carrito c;
    carrito_init(&c);
    Producto p1 = {"Azucar", 350, 2};
    Producto p2 = {"Pan", 100, 2};
    Producto p3 = {"Gaseosa", 350, 1};
    Producto p4 = {"Gaseosa", 300, 1};
    carrito_agregar(&c, p1);
    carrito_agregar(&c, p2);
    carrito_agregar(&c, p3);
    carrito_agregar(&c, p4);
    ASSERT_IGUAL(2 , carrito_buscar(&c,"Gaseosa"));
}

void test_carrito_ignora_productos_con_cantidad_menor_o_igual_a_cero(void){ /*Ejercitacion extra*/
    printf("\n[Ignora la Azucar]\n");
    Carrito c;
    carrito_init(&c);
    Producto p1 = {"Azucar", 350, -1};
    Producto p2 = {"Pan", 100, 1};
    carrito_agregar(&c, p1);
    carrito_agregar(&c, p2);
    ASSERT_IGUAL(100 , carrito_total(&c));
}

void test_que_fallaba(void) { /*Ejercitacion extra*/
    printf("\n[total: un producto, cantidad 2]\n");
    Carrito c;
    carrito_init(&c);
    Producto p = {"Leche", 350, 2};  
    carrito_agregar(&c, p);
    ASSERT_IGUAL(700, carrito_total(&c)); 
    /*El framework nos dice que test fallo, su valor esperado y el valor que devolvio*/
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  main
 * ═══════════════════════════════════════════════════════════════════════════ */

int main(void) {
    printf("=== Tests unitarios ===");
    test_carrito_nuevo();
    test_agregar_uno();
    /* Descomentar a medida que agregues las funciones: */
    test_total_precio_unitario(); 
    test_total_con_cantidad();    
    test_carrito_lleno();
    test_carrito_buscar();
    test_buscar_producto_en_carrito_vacio();
    test_carrito_encuentra_el_primer_producto_con_ese_nombre();
    test_carrito_ignora_productos_con_cantidad_menor_o_igual_a_cero();
    test_que_fallaba();
    RESUMEN();
    return EXIT_CODE();
}
