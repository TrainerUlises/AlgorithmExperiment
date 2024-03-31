/********************************************/
/* Programmer: Ulises Romero                     */
/* Date: START - March 26, 2024  END - ______                  */
/* Purpose: Sorting Algorithms  -    */
/*       main file, includes all sorting algorithm functions */
/* Input: User chooses from sorting algorithm    */
/* Output:  Comparisons and swaps will be shown        */
/*         for a sorting algorithm  */
/********************************************/

#include <iostream>
#include <fstream>
using namespace std;

//Declaring Sorting Functions
void selectionSort(int a[], int length);
void insertionSort(int a[], int length);
void swap(int &x, int &y);

int comparisons = 0; // global variables
int swaps = 0;      // global variables 
const int SIZE = 128;   // size of first array 
const int SIZE2 = 1024; // size of second array

// Swap functionality to count all swaps done in Sorting algorithms
void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

//Selection Sort Algorithm
void selectionSort( int a[], int length )			
{			
    comparisons = 0;
    swaps = 0;

    int i,j,min;			
    for ( i = 0; i < length-1; i++ )			
    {			
         min = i;			
         for ( j = i+1; j < length; j++ )			
         {			
            comparisons++;
             if ( a[j] < a[min] ){	
                min = j;		
             }	
         }			
        swap ( a[min], a[i]);		
        swaps++;	
     }			

     cout << "Comparisons: " << comparisons << endl;
     cout << "Swaps: " << swaps << endl;
}			

//Insertion Sort Algorithm
void insertionSort(int a[], int length)
{
    comparisons = 0;
    swaps = 0;

    for (int i = 1; i < length; i++)
    {
        int j = i;
        while (j != 0 && a[j] < a[j - 1])
        {
            comparisons++;
            swap(a[j], a[j - 1]);
            swaps++;
            j--;
        }
    }

    // Print comparisons and swaps
    cout << "Insertion Sort Comparisons: " << comparisons << endl;
    cout << "Insertion Sort Swaps: " << swaps << endl;
}

//Merge Sort Function
void merge(int a[], int LF, int LL,  int RF, int RL){
    int save = LF;
    int* temp = new int[RL - LF + 1];
    int j = 0;

    while(LF <= LL &&  RF <= RL){
        if(a[LF] < a[RF])
            temp[j++] = a[LF++];
        else
            temp[j++] = a[RF++];
    }
    while(LF <= LL)
        temp[j++] = a[LF++];
    while(RF <= RL)
        temp[j++] =  a[RF++];
    for (int i = save, j = 0; i <= RL; i++, j++) {
        a[i] = temp[j];
    }

    delete  []temp;
}

// Reading data from ALL ARRAYS THAT CONTAIN 128 INTEGERS
int readDataFromFiles(const string& filename, int data[]) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "ERROR: Unable to open file." << endl;
        return 0;
    }

    int size = 0;
    int num;
    while (file >> num && size < SIZE) {
        data[size++] = num;
    }
    file.close();
    return size;
}

// Reading data from ALL ARRAYS THAT CONTAIN 1024 INTEGERS
int readDataFromFiles(const string& filename, int data[], int size) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "ERROR: Unable to open file." << endl;
        return 0;
    }

    int index = 0;
    int num;
    while (file >> num && index < size) {
        data[index++] = num;
    }
    file.close();
    return index; 
}

int main() {
    const string filename128 = "SortedArray_Ex10_128.txt"; // Changing name of 'filename128' to switch to a different txt file
    const string filename1024 = "SortedArray_Ex10_1024.txt"; // Changing name of 'filename1024' to switch to a different txt file
    int data[SIZE]; // SIZE REFERS TO 128 ARRAY
    int data2[SIZE2]; // SIZE2 REFERS TO 1024 ARRAY

    int size = readDataFromFiles(filename128, data, SIZE);
    int size2 = readDataFromFiles(filename1024, data2, SIZE2);

    // Base case
    if (size == 0 || size2 == 0) {
        return 1;
    }

    //selectionSort(data, size);
    //selectionSort(data2, size2);

    //insertionSort(data, size);
    //insertionSort(data2, size2);

    

    return 0;
}




