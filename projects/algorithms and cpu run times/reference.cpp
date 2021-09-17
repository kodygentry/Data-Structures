#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "time.h"

using namespace std;

void display(char array[], int n)
{
cout<<endl;
if(n>20)
n=20;
for(int j=0;j<n;j++)
cout<<array[j]<<" ";
}

void search(char array1[],int n){
char temp=80;
int count =0,i;
for(i=0;i<n;i++){
if(array1[i]==temp)
break;
else
count++;
}
cout<<endl<<"number of comparisons: "<<count;
}

void insertion_sort(char array[], int n)
{
int i, j,count=0;
char key;
for (i = 1; i < n; i++)
{
//choose ith element as key
key = array[i];
j = i-1;
  
/* inserts key in the sorted left array, check the position where it should be inserted*/
while (array[j] > key && j >= 0 )
{
count++;
array[j+1] = array[j];
j = j-1;
}
//insert in right position
array[j+1] = key;
}
cout<<endl<<"number of comparisons: "<<count;
}

void selection_sort(char arr[], int n)
{
int i, j, index,count =0;
char temp;
  
// Outer loop to select ith element subarray
for (i = 0; i < n-1; i++)
{
// smallest element in rest of the array
index = i;
for (j = i+1; j < n; j++)
if (arr[j] < arr[index]){
count++;
index = j;
}
// Swap the minimum element with the ith element
temp = arr[index];
arr[index] = arr[i];
arr[i] = temp;
}
cout<<endl<<"number of comparisons: "<<count;
}

int partition (char arr[], int low, int high)
{
int mid= low+(high-low)/2,i,j;
char pivot = arr[mid+1],temp;
i=low;
j=high+1;
  
do
{
do
i++;
  
while(arr[i]<pivot&&i<=high);
  
do
j--;
while(pivot<arr[j]);
  
if(i<j)
{
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
}while(i<j);
  
arr[mid+1]=arr[j];
arr[j]=pivot;
  
return(j);
}
  
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quick_sort_mid(char arr[], int low, int high)
{
if (low < high)
{
/* pi is partitioning index, arr[p] is now
at right place */
int pi = partition(arr, low, high);
  
// Separately sort elements before
// partition and after partition
quick_sort_mid(arr, low, pi - 1);
quick_sort_mid(arr, pi + 1, high);
}
}

int partition2(char arr[], int low, int high)
{
  
char pivot = arr[high]; // pivot
int i = (low - 1); // Index of smaller element
char temp;
for (int j = low; j <= high- 1; j++)
{
// If current element is smaller than or
// equal to pivot
if (arr[j] <= pivot)
{
i++; // increment index of smaller element
temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}
}
//swap(&arr[i + 1], &arr[high]);
temp = arr[i+1];
arr[i+1] =arr[high];
arr[high] = temp;
return (i + 1);
}
  
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quick_sort_last(char arr[], int low, int high)
{
if (low < high)
{
/* pi is partitioning index, arr[p] is now
at right place */
int pi = partition2(arr, low, high);
  
// Separately sort elements before
// partition and after partition
quick_sort_last(arr, low, pi - 1);
quick_sort_last(arr, pi + 1, high);
}
}

//quick sort first
int partition3(char arr[], int low, int high)
{
  
char pivot = arr[low]; // pivot
int i,j;
char temp;
i=low;
j=high+1;
  
do
{
do
i++;
  
while(arr[i]<pivot&&i<=high);
  
do
j--;
while(pivot<arr[j]);
  
if(i<j)
{
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
}while(i<j);
  
arr[low]=arr[j];
arr[j]=pivot;
  
return(j);
}
  

void quick_sort_first(char arr[], int low, int high)
{
if (low < high)
{
// pi is partitioning index,
int pi = partition3(arr, low, high);
  
// Separately sort elements before
// partition and after partition
quick_sort_first(arr, low, pi - 1);
quick_sort_first(arr, pi + 1, high);
}
}
int main()
{

int i,n,l;
clock_t start, end;
double duration;
cout<<"Enter n";
cin>>n;
//create dynamic array
char *array1 = (char*)malloc(n*sizeof(char));
for(i=0;i<n;i++)
array1[i] = (char) (33 + rand() % 93);

//second function
cout<<endl<<"Before ";
display(array1,n);
//Record start of clock
start = clock();
cout<<endl<<"CPU start time: "<<start;
search(array1,n);
// Record the end of clock
end = clock();
cout<<endl<<"CPU end time: "<<end;
// Calculate duration
duration = (double)(end - start)/ CLOCKS_PER_SEC;
cout <<endl<< "Time taken by search is : "<< duration<< " sec " << endl;
//replicate new array
  
char *array2 = (char*)malloc(n*sizeof(char));
for(i=0;i<n;i++)
array2[i] = array1[i];
  
//Record start of clock
start = clock();
cout<<endl<<"CPU start time: "<<start;
selection_sort(array1,n);
// Record the end of clock
end = clock();
cout<<endl<<"CPU end time: "<<end;
// Calculate duration
duration = (double)(end - start)/ CLOCKS_PER_SEC;
cout <<endl<< "Time taken by selection sort is : "<< duration<< " sec " << endl;
//test code to check if sort works, display after sort
cout<<endl<<"After ";
display(array1,n);
//check with different sort functions everytime   

cout<<endl<<"Before ";
display(array2,n);
start = clock();
cout<<endl<<"CPU start time: "<<start;
char *array3 = (char*)malloc(n*sizeof(char));
for(i=0;i<n;i++)
array3[i] = array2[i];
insertion_sort(array2,n);
// Record the end of clock
end = clock();
cout<<endl<<"CPU end time: "<<end;
// Calculate duration
duration = (double)(end - start)/ CLOCKS_PER_SEC;
cout <<endl<< "Time taken by insertion sort is : "<< duration<< " sec " << endl;
//test code to check if sort works, display after sort
cout<<endl<<"After ";
display(array2,n);
  
  
//5 function
cout<<endl<<"Before ";
display(array3,n);
start = clock();
cout<<endl<<"CPU start time: "<<start;
char *array4 = (char*)malloc(n*sizeof(char));
for(i=0;i<n;i++)
array4[i] = array3[i];
quick_sort_mid(array3,0,n-1);
// Record the end of clock
end = clock();
cout<<endl<<"CPU end time: "<<end;
// Calculate duration
duration = (double)(end - start)/ CLOCKS_PER_SEC;
cout <<endl<< "Time taken by quick sort is : "<< duration<< " sec " << endl;
//test code to check if sort works, display after sort
cout<<endl<<"After ";
display(array3,n);
  
//6 function
cout<<endl<<"Before ";
display(array4,n);
start = clock();
cout<<endl<<"CPU start time: "<<start;
char *array5 = (char*)malloc(n*sizeof(char));
for(i=0;i<n;i++)
array5[i] = array4[i];
quick_sort_first(array4,0,n-1);
// Record the end of clock
end = clock();
cout<<endl<<"CPU end time: "<<end;
// Calculate duration
duration = (double)(end - start)/ CLOCKS_PER_SEC;
cout <<endl<< "Time taken by quick sort first is : "<< duration<< " sec " << endl;
//test code to check if sort works, display after sort
cout<<endl<<"After ";
display(array4,n);
  
//7 function
cout<<endl<<"Before ";
display(array5,n);
start = clock();
cout<<endl<<"CPU start time: "<<start;
  
quick_sort_last(array5,0,n-1);
// Record the end of clock
end = clock();
cout<<endl<<"CPU end time: "<<end;
// Calculate duration
duration = (double)(end - start)/ CLOCKS_PER_SEC;
cout <<endl<< "Time taken by quick sort last is : "<< duration<< " sec " << endl;
//test code to check if sort works, display after sort
cout<<endl<<"After ";
display(array5,n);
cin>>l;

}