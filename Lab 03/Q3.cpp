#include<iostream>
using namespace std;

void print(int arr[], int size){
    cout << endl;
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void minimalSwapCrane(int arr[], int size){
    int swaps = 0;
    int skipped = 0;
    for(int i = 0; i < size - 1; i++){
        int smallidx = i;
        for(int j = i + 1; j < size; j++){
            if (arr[j] < arr[smallidx]){
                smallidx = j;
            }
        }
            if(smallidx != i){
                swap(arr[i], arr[smallidx]);
                swaps++;
            }
            else{
                skipped++;
        }
    }
    cout << "\n---Sorted Array---";
    print(arr, size);
    int comparisions = size * (size - 1) / 2;
    double swap2compare = ((double)swaps / comparisions) * 100;
    cout << "Total actual swaps: " << swaps << endl;
    cout << "Total skipped swaps: " << skipped << endl;
    cout << "Swap to Comparision Ratio: " << swap2compare << endl;  
}

int main(){
	int arr[8] = {3, 6, 5, 4, 7, 2, 1, 8};
	int n = 8;
	minimalSwapCrane(arr, n);
	return 0;
}
