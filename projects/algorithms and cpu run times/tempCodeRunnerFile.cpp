

/// clean and comment !
/// due at 11am

// the instructions say do not use dynamic arrays,
// yet static arrays require a constant size

// ex. i get an error when:
// int size = 0;
// cin >> size;
// char array[size]

// the only way to do this is with a dynamic array
// a lot of other students ran into this issue and either created a dynamic array (like me)
// or fixed the size of the array (both would result in a 0, according to the instructions)
// i emailed the professor about this issue and he didn't give much help
// if you (the grader/professor) could give some feedback, it would be much appreciated!

#include <iostream>
#include "time.h"
using namespace std;

void displayArray(char array[], int size);
int sequentialSearch(char array[], int size);
int selectionSort(char array[], int size);
int insertionSort(char array[], int size);
int quickSortMiddlePivot(char array[], int low, int high);
int quickSortFirstPivot(char array[], int low, int high);
int quickSortLastPivot(char array[], int low, int high);

int main(){
    // display menu
    clock_t start, end;                                    // vars for manual CPU clock
    double actualTime = 0.0;                              // var for actual CPU time

    int size = 0;
    cout << "Enter the size of the array: "; // get size of array from user
    cin  >> size;
    if(size <= 0){
        cout << "***Error - Invalid Input - Size must be > 0 ***\n"
             << "\n11/16/2020 - By Kody Gentry\nBenchmark Algorithm";
        return -1;
    }

    char array[size]; // create array with size from user
    for (int i = 0; i < size; i++)                      // fill each element with random char between 50 and 150
        array[i] = (char)(std::rand()%100+50);

    cout << "Array elements are: ";                   // display array
    displayArray(array,size);                        // output elements

    /// Sequential Search ------------------------------------------------
    cout << "\n\nSequential Search:";
    start = clock();                                     // using "time.h", record start time
    cout << "\nCPU start time: " << start;              // output CPU start time
    int comparisons = sequentialSearch(array, size);   // call search func and set comparisons
    end = clock();                                    // using "time.h", record end time
    cout << "CPU end time: " << end;                 // output CPU end time
    actualTime = (double)(end - start)/CLOCKS_PER_SEC; // Calculate actual CPU time
    cout << "\nActual CPU Clock Time: " << actualTime << " second(s) or " << actualTime * 1000 << " milliseconds\n";

    cout << "Total Number of Comparisons: " << comparisons << endl;
    cout << "Array elements are: ";                  // display array
    displayArray(array,size);                       // output elements

    /// Selection Sort ----------------------------------------------------
    char array2[size]; // create copy of array to sort
    for (int i = 0; i < size; i++)
        array2[i] = array[i];

    cout << "\n\nSelection Sort:";
    start = clock();                                     // using "time.h", record start time
    cout << "\nCPU start time: " << start;              // output CPU start time
    int swaps = selectionSort(array, size);            // call search func and set swaps
    end = clock();                                    // using "time.h", record end time
    cout << "\nCPU end time: " << end;               // output CPU end time
    actualTime = (double)(end - start)/CLOCKS_PER_SEC; // Calculate actual CPU time
    cout << "\nActual CPU Clock Time: " << actualTime << " second(s) or " << actualTime * 1000 << " milliseconds\n";
    cout << "Total Number of Swaps: " << swaps << endl;
    cout << "Sorted elements are: ";                  // display array
    displayArray(array,size);                       // output elements

    /// Insertion Sort ------------------------------------------------
    char array3[size]; // create copy of array to sort
    for (int i = 0; i < size; i++)
        array3[i] = array2[i];

    cout << "\n\nInsertion Sort";
    start = clock();                                     // using "time.h", record start time
    cout << "\nCPU start time: " << start;              // output CPU start time
    int InsComparisons = insertionSort(array2, size);  // call search func and set comparisons
    end = clock();                                    // using "time.h", record end time
    cout << "\nCPU end time: " << end;               // output CPU end time
    actualTime = (double)(end - start)/CLOCKS_PER_SEC; // Calculate actual CPU time
    cout << "\nActual CPU Clock Time: " << actualTime << " second(s) or " << actualTime * 1000 << " milliseconds\n";
    cout << "Total Number of Swaps: " << InsComparisons << endl;
    cout << "Sorted elements are: ";                  // display array
    displayArray(array2,size);                       // output elements

    /// Quick Sort Mid -------------------------------------------------
    char array4[size]; // create copy of array to sort
    for (int i = 0; i < size; i++)
        array4[i] = array3[i];

    cout << "\n\nQuick Sort - Next to the middle element as a pivot:\n";
    start = clock();                                   // using "time.h", record start time
    cout << "CPU start time: " << start;              // output CPU start time
    int recursions = quickSortMiddlePivot(array3, 0, size-1);   // call search func and set comparisons
    end = clock();                                    // using "time.h", record end time
    cout << "\nCPU end time: " << end;               // output CPU end time
    actualTime = (double)(end - start)/CLOCKS_PER_SEC; // Calculate actual CPU time
    cout << "\nActual CPU Clock Time: " << actualTime << " second(s) or " << actualTime * 1000 << " milliseconds\n";
    cout << "Total Number of Recursive Calls: " << recursions << endl;
    cout << "Sorted elements are: ";                  // display array
    displayArray(array3,size);                       // output elements

    /// Quick Sort First------------------------------------------------
    char array5[size]; // create copy of array to sort
    for (int i = 0; i < size; i++)
        array5[i] = array4[i];

    cout << "\n\nQuick Sort - First element as a pivot:\n";
    start = clock();                                   // using "time.h", record start time
    cout << "CPU start time: " << start;              // output CPU start time
    int recursions2 = quickSortFirstPivot(array4, 0, size-1);   // call search func and set comparisons
    end = clock();                                    // using "time.h", record end time
    cout << "\nCPU end time: " << end;               // output CPU end time
    actualTime = (double)(end - start)/CLOCKS_PER_SEC; // Calculate actual CPU time
    cout << "\nActual CPU Clock Time: " << actualTime << " second(s) or " << actualTime * 1000 << " milliseconds\n";
    cout << "Total Number of Recursive Calls: " << recursions2 << endl;
    cout << "Sorted elements are: ";                  // display array
    displayArray(array4,size);                       // output elements

    /// Quick Sort Last------------------------------------------------
    cout << "\n\nQuick Sort - Last element as a pivot:\n";
    start = clock();                                   // using "time.h", record start time
    cout << "CPU start time: " << start;              // output CPU start time
    int recursions3 = quickSortLastPivot(array5, 0, size-1);   // call search func and set comparisons
    end = clock();                                    // using "time.h", record end time
    cout << "\nCPU end time: " << end;               // output CPU end time
    actualTime = (double)(end - start)/CLOCKS_PER_SEC; // Calculate actual CPU time
    cout << "\nActual CPU Clock Time: " << actualTime << " second(s) or " << actualTime * 1000 << " milliseconds\n";
    cout << "Total Number of Recursive Calls: " << recursions3 << endl;
    cout << "Sorted elements are: ";                  // display array
    displayArray(array5,size);                       // output elements
    // ------------------------------------------------
    cout << "\n\n11/16/2020 - By Kody Gentry\nBenchmark Algorithm";

    return 0;
}

void displayArray(char array[], int size){
    if (size > 20)
        size = 20;
    for (int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
}

int sequentialSearch(char array[], int size){
    bool found = false;
    int count = 0;
    for (int i = 0; i < size; i++){
        if (array[i] == char(80)){
            found = true;
            break;
        }
        else{
            found = false;
            count++;
        }
    }
    cout << "\nSearching for 80\n";
    if(found)
        cout << "80 was found\n";
    else
        cout << "80 was not found\n";
    return count;
}

int selectionSort(char array[], int size){
    int i, j, minIndex, count = 0;
    char temp;
    for (int i = 0; i < size-1; i++){
        minIndex = i;
        for (j = i+1; j < size; j++){
            if(array[j] < array[minIndex]){
                count++;
                minIndex = j;
            }
        }
        temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }
    return count;
}

int insertionSort(char array[], int size){
    int i, j, count = 0;
    char key;
    for (int i = 0; i < size; i++){
        key = array[i];
        j = i-1;
        while (array[j] > key && j >= 0 ){
            count++;
            array[j+1] = array[j];
            j = j-1;
        }
        array[j+1] = key;
    }
    return count;
}

int quickSortMiddlePivot(char array[], int low, int high){
    int count = 0;
    count++;
    if(low >= high)
        return 0;

    int mid = (low + high)/2;
    int pivot = array[mid + 1];
    int i = low,j = high;
    int temp;
    while(i < j){
        if(array[i] >= pivot && array[j] <= pivot){
            temp = array[j];
            array[j] = array[i];
            array[i] = temp;
            i++;
            j--;
        }
        else{
            i++;
        }
    }
    quickSortMiddlePivot(array, low, mid);
    quickSortMiddlePivot(array,mid+1, high);
    return count;
}

int quickSortFirstPivot(char array[], int low, int high){
    int i, j, count = 0;
    char pivot = array[low], temp;
    i = low;
    j = high + 1;
    count ++;

    do{
        do
            i++;
        while(array[i] < pivot && i <= high);

        do
            j--;
        while(pivot < array[j]);

        if(i < j){
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }while(i < j);

    array[low] = array[j];
    array[j] = pivot;

    int partition = j;

    if (low < high){
        quickSortFirstPivot(array, low, partition - 1);
        quickSortFirstPivot(array, partition + 1, high);
    }
    return count;
}

int quickSortLastPivot(char array[], int low, int high){
    int i, j, count = 0;
    char pivot = array[high], temp;
    i = low;
    j = high + 1;
    count ++;

    do{
        do
            i++;
        while(array[i] < pivot && i <= high);

        do
            j--;
        while(pivot < array[j]);

        if(i < j){
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }while(i < j);

    array[low] = array[j];
    array[j] = pivot;

    int partition = j;

    if (low < high){
        quickSortFirstPivot(array, low, partition - 1);
        quickSortFirstPivot(array, partition + 1, high);
    }
    return count;
}