#include<iostream>
using namespace std;

void print(int arr[], int size){
    cout << endl;
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void diminishingDistanceScanner(int arr[], int size){
    for(int gap = size/2; gap > 0; gap /= 2){
        int swaps = 0;
        int comparisions = 0;
        for(int i = gap; i < size; i++){
            int key = arr[i];
            int j = i;
            while(j >= gap){
                comparisions++;
                if(arr[j-gap] > key){
                    arr[j] = arr[j-gap];
                    swaps++;
                    j -= gap;
                }
                else{
                    break;
                }
            }
            arr[j] = key;
        }
        double gap_pc = ((double)gap / size) * 100;
        cout << "Gap " << gap << " Stats" << endl;
        cout << "Total swaps: " << swaps << endl;
        cout << "Total comparisions: " << comparisions << endl;
        cout << "Gap percentage: " << gap_pc << endl;
    }
}

int main(){
	int arr[8] = {3, 6, 5, 4, 7, 2, 1, 8};
	int n = 8;
	diminishingDistanceScanner(arr, n);
    print(arr, n);
	return 0;
}
