#include<iostream>
#include <cmath>
using namespace std;

int midpointSplitSearch(int arr[], int size, int target){
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            cout << "Error: Conveyor is unsorted. Search aborted." << endl;
            return -1;
        }
    }
    int low = 0;
    int high = size - 1;
    int steps = 0;
    int maxSteps = floor(log2(size)) + 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        cout << "Low: " << low << " | Mid: " << mid << " | High: " << high << endl;
        double space = ((double)(high - low + 1) / size) * 100;
        cout << "Remaining search percentage: " << space << endl;
        cout << "Steps taken: " << steps << " / Theoretical max steps: " << maxSteps << endl;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    // Test Case 1: Sorted Array
    int sortedConveyor[8] = {101, 204, 305, 412, 515, 620, 730, 840};
    int n = 8;
    int target = 620;

    cout << "--- Searching for " << target << " in Sorted Array ---" << endl;
    int index = midpointSplitSearch(sortedConveyor, n, target);
    if (index != -1) {
        cout << "Tracking number " << target << " found at index: " << index << endl;
    } else {
        cout << "Tracking number " << target << " not found." << endl;
    }

    cout << endl;

    // Test Case 2: Unsorted Array (Error Trigger)
    int unsortedConveyor[5] = {500, 100, 300, 200, 400};
    cout << "--- Searching in Unsorted Array ---" << endl;
    midpointSplitSearch(unsortedConveyor, 5, 300);

    return 0;
}
