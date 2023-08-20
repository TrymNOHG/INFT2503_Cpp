//
// Created by Trym Hamer Gudvangen on 8/20/23.
//

/*
 * Oppgave 4.
 *
 * Finn alle syntaksfeil i følgende programbit:

    int a = 5;
    int &b;
    int *c;
    c = &b;
    *a = *b + *c;
    &b = 2;
    Legg setningene inn i en .cpp-fil og endre koden slik at den kompilerer.
    Beskriv årsaken til hver enkelt av kompileringsfeilene i kommentarer.
 *
 *
 */

int main() {

    int a = 5;
    //int &b; Først, man kan ikke definere/deklarere en variabel som en referanse
    // uten å initialisere den ved å ha en annen variabel å referere til.
    int b;
    int *c;
    c = &b;
    // *a = *b + *c; Man kan ikke bruke en indirection operator på en variabel som ikke er en peker eller referanse.
    //&b = 2; Man kan ikke referere til en primitiv verdi.

    return 0;
}

