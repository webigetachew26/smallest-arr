#include <iostream>
using namespace std;

// Binary Search Implementation for Exponential Search
int binarySearch(int arr[], int low, int high, int target) 
{
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) 
        {
            return mid; // Target found
        } else if (arr[mid] < target) 
        {
            low = mid + 1; // Search right half
        } else {
            high = mid - 1; // Search left half
        }
    }
    return -1; // Target not found
}

// Exponential Search
int exponentialSearch(int arr[], int size, int target) 
{
    if (arr[0] == target) 
    {
        return 0; // If the target is the first element
    }

    int bound = 1;
    while (bound < size && arr[bound] < target) 
    {
        bound *= 2; // Double the bound
    }

    // Perform binary search between the found range
    int high = (bound < size) ? bound : size - 1;
    return binarySearch(arr, bound / 2, high, target);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = exponentialSearch(arr, size, target);
    if (result != -1) 
    {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}