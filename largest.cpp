include <iostream>
#include <limits.h> // For INT_MIN
using namespace std;

void findSecondAndThirdLargest(int arr[], int size, int &second, int &third) {
    if (size < 2) {
        cout << "Not enough elements for second or third largest" << endl;
        return;
    }

    int first = INT_MIN;
    second = INT_MIN;
    third = INT_MIN;

    for (int i = 0; i < size; i++) {
        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] < first) {
            third = second;
            second = arr[i];
        } else if (arr[i] > third && arr[i] < second) {
            third = arr[i];
        }
    }

    if (second == INT_MIN) 
        cout << "No second largest number found." << endl;
    else
        cout << "The second largest number is: " << second << endl;
    
    if (third == INT_MIN) 
        cout << "No third largest number found." << endl;
    else
        cout << "The third largest number is: " << third << endl;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50}; // Example array
    int size = sizeof(arr) / sizeof(arr[0]);

    int secondLargest, thirdLargest;
    findSecondAndThirdLargest(arr, size, secondLargest, thirdLargest);

    return 0;
}