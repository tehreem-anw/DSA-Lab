#include<iostream>
using namespace std;

void adjacentSwapper(int arr[], int size){
    int swapCount = 0;
    int compareCount = 0;
    int passCount = 0;
    for(int i=0; i<size; i++){
        bool isSwapped = false;
        passCount++;
        for(int j=0; j<size-i-1; j++){
            compareCount++;
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSwapped = true;
                swapCount++;
            }
        }
        if(isSwapped == false){
            break;
        }
    }
    cout << "Passes saved: " << size - 1 - passCount << endl;
    cout << "No of swaps: " << swapCount << endl;
    cout << "No of comparisons: " << compareCount << endl;
    cout << "Actual vs. Theoretical Worst-Case: " << compareCount << " / " << size * (size - 1) / 2 << endl;
}

void print(int arr[], int n){
	cout << "{";
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << "}" << endl;
}

int main(){
	int arr[8] = {3, 6, 5, 4, 7, 2, 1, 8};
	int n = 8;
	adjacentSwapper(arr, n);
	print(arr, n);
	return 0;
}
