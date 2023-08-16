#include <iostream>

void find_intervals(int length);

int main() {
    const int length = 5;
    find_intervals(length);

    return 0;
}

/**
 * This method completes the requirements for part A of the first exercise.
 * @param length
 */
void find_intervals(int length) {
    std::cout << "Enter 5 temperatures.\n";
    double temperatures[length];
    int temp_interval[3] = {};

    for(int i = 0; i < length; i++) {
        std::cout << "Temperature " << i + 1 << ": ";
        std::cin >> temperatures[i];
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