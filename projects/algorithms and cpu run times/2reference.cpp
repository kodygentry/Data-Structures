#include <iostream>

using namespace std;
void displyArray(char arr[],int size){
int i;
if(size>=20){
cout<<"\n";
for(i=0;i<size;i++){
cout<<arr[i]<<" ";
}
}else{
cout<<"array size is less than 20";
}
  
}

//sequential search using recursion
int searchNumber(char arr[],int start,int size,char c){
int noOfComparision=0;
int found=0;
if(start<size && found==0 ){
if(arr[start]=='c'){

found=1;
cout<<"no of Comaparistion is to search char(80) is ="<<noOfComparision;
}else{
noOfComparision=noOfComparision+1;
searchNumber(arr,start+1,size,c);//recursive call
}
}
return found;
  
}

int sectionsort(char arr[],int size){
  
int i, j, min_index,swapCount=0;
  
// One by one move boundary of unsorted subarray
for (i = 0; i < size; i++)
{
// Find the minimum element in unsorted array
min_index = i;
for (j = i+1; j < size; j++)
if (arr[j] < arr[min_index])
min_index = j;
  
// Swap the found minimum element with the first element
  
char temp=arr[min_index];
arr[min_index]=arr[i];
arr[i]=temp;

swapCount=swapCount+1;
}
cout<<"\n";
cout<<"sorting using selection sort ";
for(i=0;i<size;i++){
cout<<arr[i]<<" ";
}
return swapCount;
}


//insertion sorting
int insertionSort(char arr[], int arr_size){
int count=0;
int i;
//chechking the boundry
if(arr_size > 1){
int size = arr_size;
for(int i = 1; i < size; ++i){
int j = i - 1;
int key = arr[i];
//comparing
while(j >= 0 && arr[j] > key){
arr[j+1] = arr[j];
--j;
}
arr[j+1] = key;
count=count+1;//counting no of swaps
}
}
cout<<"\n";
cout<<"sorting using insertion sort ";
for(i=0;i<arr_size;i++){
cout<<arr[i]<<" ";
}
return count;
}



int partition(char a[], int l, int r)
{
int p, i, j, t;
p = l;
i = l;
j = r;
while(i<j)
{
while((a[ i ] <= a[ p ]) && (i<r))
{
i++;
}
while(a[ j ] > a[ p ])
{
j--;
}
if(i<j)
{
t=a[ i ];
a[ i ] = a[ j ];
a[ j ] = t;
}
}
t=a[ p ];
a[ p ] = a[ j ];
a[ j ] = t;
return j;
}
//partion for taking last elemtn as pivot element

int lastpartition(char a[],int l,int r)
{
int j,temp,i=l;

for(j=l;j<r-1;j++)
{
//swap values if a[j]<=a[r-1](i.e. pivot)
if(a[j]<=a[r-1])
{
temp=a[j];
a[j]=a[i];
a[i]=temp;
i++;
}
}
//place pivot at its position by swapping
temp=a[i];
a[i]=a[r-1];
a[r-1]=temp;
return i;
}
//quick sort for first element as a pivot element
void quicksortFirstpivot(char a[], int l, int r)
{ int i;
int s;
if(l < r)
{
s=partition(a,l,r);
quicksortFirstpivot(a, l, s-1);
quicksortFirstpivot(a, s+1, r);
}

  
}
//quick sort for last element as a pivot element
void quicksortlastpivot(char a[], int l, int r)
{ int i;
int s;
if(l < r)
{
s=lastpartition(a,l,r);
quicksortlastpivot(a, l, s-1);
quicksortlastpivot(a, s+1, r);
}

  
}



//Qucik sort for middle element as pivot element

int quicksortMiddle(char arr[],int low,int high)
{
if(low>=high)
return 0;

int mid=(low+high)/2;
int pivot=arr[mid];
int i=low,j=high;
int temp;
while(i<j)
{
if(arr[i]>=pivot && arr[j]<=pivot)
{
temp=arr[j];
arr[j]=arr[i];
arr[i]=temp;
i++;
j--;
}
else
{
i++;
}
}
quicksortMiddle(arr,low,mid);
quicksortMiddle(arr,mid+1,high);
}
int main()
{
int i,n;
int position=0;
int flag=0;
cout<<"Enter positive integer";
cin>>n; //reading input from user
char arr[n];
  
//generating random numbers and convert them into char
//store the charectors into arr[]
for (i = 0; i < n; i++) {
int num = (rand() % (126 - 33 + 1)) + 33;
char c=(char)num;
arr[i]=c;

}
//method for dispalying charectors in array
displyArray(arr,n);
//searching the element in the array
int res=searchNumber(arr,0,n,char(80));
if(res==0){
cout<<"\n"<<"char(80) not found";
}
  
//selection sorting array call
cout<<"\n"<<"swapCount in selection sort is= "<<sectionsort(arr,n);
  
//insertion corting call
cout<<"\n"<<"swapCount in insertion sort ="<<insertionSort(arr,n);
  
//Quick sort: 1st element as pivot element
quicksortFirstpivot(arr,0,n-1);
cout<<"\n";
cout<<"Quick sort: 1st element as pivot element ";
for(i=0;i<n;i++){
cout<<arr[i]<<" ";
}
//Qucik sort :last element as pivot value
quicksortlastpivot(arr,0,n-1);
cout<<"\n";
cout<<"Qucik sort :last element as pivot value ";
for(i=0;i<n;i++){
cout<<arr[i]<<" ";
}
//quicksort :Middle element as pivot element
quicksortMiddle(arr,0,n-1);
cout<<"\n";
cout<<"quicksort :Middle element as pivot element ";
for(i=0;i<n;i++){
cout<<arr[i]<<" ";
}
}