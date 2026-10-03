#include<iostream>
using namespace std;

void print(int arr[], int size){
    cout << endl;
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionArmSorter(int arr[], int size){
    int totalShifts = 0;
    for(int i = 1; i < size; i++){
        bool swapped = false;
        int shifts = 0;
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            swapped = true;
            shifts++;
            j--;
        }
        arr[j+1] = key;
        print(arr, size);
        cout << "No. of shifts for [" << key << "]: " << shifts << endl;
        if(!swapped){
            cout << "No shift required." << endl;
        }
        totalShifts += shifts;
    }
    cout << "\nTotal shifts: " << totalShifts << endl;
}

int main(){
	int arr[8] = {3, 6, 5, 4, 7, 2, 1, 8};
	int n = 8;
	insertionArmSorter(arr, n);
	return 0;
}
