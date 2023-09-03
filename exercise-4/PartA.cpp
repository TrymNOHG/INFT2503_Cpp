//
// Created by Trym Hamer Gudvangen on 9/3/23.
//

#include <iostream>
#include <vector>
#include <algorithm>
/*
 * Part 1.
 *
 * Lag et lite program:

Opprett en vektor av double. Legg inn fem tall (behøver ikke leses inn.)

Prøv ut medlemsfunksjonene front() og back(). De returnerer hver et element, og de har ingen argumenter.

Bruk emplace() til å sette inn et tall etter det første elementet. Skriv ut resultatet av front() etterpå.

Prøv ut STL-algoritmen find(). Den tar tre argumenter: start, slutt og søkeverdi. De to første er iteratorer
 til søkeintervallet. Funksjonen returnerer en iterator til den funne verdien, hvis den finnes. Hvis den ikke
 finnes, er returverdien lik end()-iteratoren. Lag et if-uttrykk som sjekker om resultatet av find() er vellykket
 eller ikke, og dersom resultatet var vellykket, skriv ut den funne verdien.
 *
 */

bool num_exists(const std::vector<double> &vector, double val);
void print_element(const std::vector<double> &vector, double val);

int main() {

    std::vector<double> double_vector = {0.0, 1.1, 2.2, 4.0, 5.23};

    std::cout << "Front returns: " << double_vector.front() << "\n";
    std::cout << "End returns: " << double_vector.back() << "\n";

    double_vector.emplace(double_vector.begin(), -1.1);

    std::cout << "New front: " << double_vector.front() << "\n";

    print_element(double_vector, 5.0);
    print_element(double_vector, 5.23);


    return 0;
}

bool num_exists(const std::vector<double> &vector, double val) {
    return std::find(vector.begin(), vector.end(), val) != vector.end();
}

void print_element(const std::vector<double> &vector, double val) {
    if(num_exists(vector, val)) {
        std::cout << val << " was found!" << "\n";
    }
    else {
        std::cout << "Value " << val << " does not exist in the vector\n";
    }
}
