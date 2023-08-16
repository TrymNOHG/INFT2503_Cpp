//
// Created by Trym Hamer Gudvangen on 8/16/23.
//
#include <iostream>
#include <fstream>
#include <cstdlib>

void read_temperatures(double temperatures[], int length);

int main() {
    const int length = 5;
    const char fileName[] = "../temperatures.dat";

    std::ifstream file;
    file.open(fileName);

    if(!file) {
        std::cerr << "An error has occurred while attempting to open the specified file." << std::endl;
        exit(EXIT_FAILURE);
    }

    double temps[length];
    int currentNum = 0;
    while(file >> temps[currentNum++]);

    read_temperatures(temps, length);

    return 0;
}


/**
 * This method completes the functionality required for part B.
 * @param temperatures
 * @param length
 */
void read_temperatures(double temperatures[], int length) {
    int temp_interval[3] = {};

    for(int i = 0; i < length; i++) {
        std::cout << "Temperature " << i + 1 << ": " << temperatures[i] << "\n";
        if(temperatures[i] < 10) {
            temp_interval[0]++;
        } else if (temperatures[i] >= 10 && temperatures[i] <= 20) {
            temp_interval[1]++;
        } else {
            temp_interval[2]++;
        }
    }
    std::cout << "\nNumber of temperatures under 10: " << temp_interval[0] << "\n";
    std::cout << "Number of temperatures between 10 and 20: " << temp_interval[1] << "\n";
    std::cout << "Number of temperatures over 20: " << temp_interval[2] << std::endl;

}
