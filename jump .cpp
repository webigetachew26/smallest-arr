#include <iostream>
#include <cmath> // For sqrt
using namespace std;

// Jump Search
int jumpSearch(int arr[], int size, int target) 
{
    int step = sqrt(size); // Define block size
    int prev = 0;

    // Jump ahead to find the block where the target may be
    while (arr[min(step, size) - 1] < target) 
    {
        prev = step;
        step += sqrt(size);
        if (prev >= size) {
            return -1; // Target not found
        }
    }

    // Perform linear search within the block
    for (int i = prev; i < step && i < size; i++) 
    {
        if (arr[i] == target) {
            return i; // Target found
        }
    }

    return -1; // Target not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = jumpSearch(arr, size, target);
    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}