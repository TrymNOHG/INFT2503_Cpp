//
// Created by Trym Hamer Gudvangen on 8/16/23.
//

#include <iostream>

int main() {

    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    std::cout << "Value of i: " << i << "\n";
    std::cout << "Address of i: " << &i << "\n";

    std::cout << "Value of p: " << p << "\n";
    std::cout << "Address of p: " << &p << "\n";
    std::cout << "Value p is pointing to: " << *p << "\n" << std::endl;

    std::cout << "Value of j: " << j << "\n";
    std::cout << "Address of j: " << &j << "\n";

    std::cout << "Value of q: " << q << "\n";
    std::cout << "Address of q: " << &q << "\n";
    std::cout << "Value q is pointing to: " << *q << "\n" << std::endl;

    *p = 7;
    *q += 4;
    *q = *p + 1;
    p = q;
    std::cout << *p << " " << *q << std::endl;


    char *ptr = nullptr;
    strcpy(ptr, "This is text");

    return 0;
}


/*
 * Oppgave 2.
 *
    Hva vil skje hvis du skriver:

    char *line = nullptr;   // eller char *line = 0;
    strcpy(line, "Dette er en tekst");
 *
 * Hvis man gjør dette, får man en segmentation fault siden man går utenfor det allokerte minnet.
 * Den prøver da å kopiere strengen inn i områder som kan være i bruk fra før.
 */


/*
 * Oppgave 3.
 *
    Finn ting som kan gå galt i følgende programbit:

    char text[5];
    char *pointer = text;
    char search_for = 'e';
    cin >> text;
    while (*pointer != search_for) {
      *pointer = search_for;
      pointer++;
    }
 *
 * Hvis det ikke eksisterer noen e i text, kommer while loopen til å fortsette og pointeren
 * kommer til å gå utenfor allokerte minnet til text array-en.
 */