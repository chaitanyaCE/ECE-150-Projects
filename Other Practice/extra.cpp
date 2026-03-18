# include <iostream>
#include <cmath>

double calculateAverage(int arr[], int size) {
    if (size <= 0) return 0.0; // Handle edge case for non-positive size

    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum / size;
}

int main() {
    int data[] = {10, 20, 30, 40, 50};
    int size = sizeof(data) / sizeof(data[0]);
    
    double average = calculateAverage(data, size);
    std::cout << "Average: " << average << std::endl;

    return 0;
}