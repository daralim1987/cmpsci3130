//Dara Lim
//This is the cs3130 project 2
//This project is to perform empirical analysis of 6 sorting algorithms as follow:
//I perform this project with 6 algorithms and 9 different data arrays by running each time with different
//array input from files. 

#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<ctime>

using namespace std::chrono;
using namespace std;

//Function selection sort
void selectionSort(vector<int>num) {
    //Start timing
    auto start1 = high_resolution_clock::now();
    int i, j, minIndex, tmp;
    for (i = 0; i < num.size() - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < num.size(); j++){
            if (num[j] < num[minIndex]){
                minIndex = j;
            }
        }
        if (minIndex != i) {
            tmp = num[i];
            num[i] = num[minIndex];
            num[minIndex] = tmp;
        }
    }
    //End timing
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(end1 - start1);
    cout << duration1.count() << " microseconds " <<endl;
   
}

//Function insertion sort
void insertionSort(vector<int>vecI){
    //Start timing
    auto start2 = high_resolution_clock::now();
    int i, key, j;
    for(i = 1; i < vecI.size(); i++){
        key = vecI[i];
        j = i - 1;
        while(j >= 0 && vecI[j] > key)
        {
            vecI[j+1] = vecI[j];
            j = j - 1;
        }
        vecI[j+1] = key;
    }
    //End timing
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(end2 - start2);
    cout << duration2.count() << " microseconds " <<endl;
}

//Bubble sort
void BubbleSort (vector<int>vecB)
{
    //Start timing
    auto start3 = high_resolution_clock::now();
    int i, j;
    for (i = 0; i < vecB.size(); ++i)
    {
        for (j = 0; j < vecB.size()-i-1; ++j)
        {
            if (vecB[j] > vecB[j+1])
            {
                vecB[j] = vecB[j]+vecB[j+1];
                vecB[j+1] = vecB[j]-vecB[j + 1];
                vecB[j] = vecB[j]-vecB[j + 1];
            }
        }
    }
    //End timing
    auto end3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(end3 - start3);
    cout << duration3.count() << " microseconds " <<endl;
}

//Functon bubble sort with swap counting
void BubbleSortWithCount (vector<int>vecBC)
{
    //Start timing
    auto start4 = high_resolution_clock::now();
    int i, j;
    int swapCount = 0;
    for (i = 0; i < vecBC.size(); ++i)
    {
        for (j = 0; j < vecBC.size()-i-1; ++j)
        {
            // Comparing consecutive data and switching values if value at j > j+1.
            if (vecBC[j] > vecBC[j+1])
            {
                vecBC[j] = vecBC[j]+vecBC[j+1];
                vecBC[j+1] = vecBC[j]-vecBC[j + 1];
                vecBC[j] = vecBC[j]-vecBC[j + 1];
                swapCount++;
            }
        }
    }
    //End timing
    auto end4 = high_resolution_clock::now();
    auto duration4 = duration_cast<microseconds>(end4 - start4);
    cout << duration4.count() << " microseconds " <<endl;
}

//Partition function
int partition(vector<int>& A, int p,int q)
{
    int x= A[p];
    int i=p;
    int j;
    
    for(j=p+1; j<q; j++)
    {
        if(A[j]<=x)
        {
            i=i+1;
            swap(A[i],A[j]);
        }
        
    }
    
    swap(A[i],A[p]);
    return i;
}

//Function quick sort
void quickSort(vector<int>& A, int p,int q)
{
    int r;
    if(p<q)
    {
        r=partition(A, p,q);
        quickSort(A,p,r);
        quickSort(A,r+1,q);
    }
}


// Function merge
void Merge(vector<int>a, int low, int high, int mid)
{
    // We have low to mid and mid+1 to high already sorted.
    int i, j, k, temp[high-low+1];
    i = low;
    k = 0;
    j = mid + 1;
    
    // Merge the two parts into temp[].
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
        }
    }
    
    // Insert all the remaining values from i to mid into temp[].
    while (i <= mid)
    {
        temp[k] = a[i];
        k++;
        i++;
    }
    
    // Insert all the remaining values from j to high into temp[].
    while (j <= high)
    {
        temp[k] = a[j];
        k++;
        j++;
    }
    
    
    // Assign sorted data stored in temp[] to a[].
    for (i = low; i <= high; i++)
    {
        a[i] = temp[i-low];
    }
}

// A function to split array into two parts.
void MergeSort(vector<int>a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        // Split the data into two half.
        MergeSort(a, low, mid);
        MergeSort(a, mid+1, high);
        
        // Merge them to get sorted output.
        Merge(a, low, high, mid);
    }
}

int main()
{
    vector<int>num1;
    int value1;
    ifstream File1;
    File1.open("Sorted10000.txt");
    while(File1 >> value1){
        num1.push_back(value1);
    }
    File1.close();
    int p1 = 0;
    int q1 = num1.size();
    int n1 = num1.size();
    
    //Call function selection sort
    cout << "Selection sort time: " <<endl;
    cout << "with 10000 elements sorted is: ";
    selectionSort(num1);

    //call function insertion sort
    cout << "Insertion sort time: "<<endl;
    cout << "with 10000 elements sorted is: ";
    insertionSort(num1);
    

    //call function bubble sort
    cout << "Bubble sort time: "<<endl;
    cout << "with 10000 elements sorted is: ";
    BubbleSort(num1);

    //call bubble sort with swap
    cout << "Bubble sort with swap counting time: "<<endl;
    cout << "with 10000 elements sorted is: ";
    BubbleSortWithCount(num1);

    // Call quick sort and start timing
    auto start5 = high_resolution_clock::now();
    quickSort(num1,p1,q1);
    //End timing
    auto end5 = high_resolution_clock::now();
    auto duration5 = duration_cast<microseconds>(end5 - start5);
    cout << "Time taken by quick sort with 10000 elements sorted is: " << duration5.count() << " microseconds " <<endl;


    //call merge sort
    //Start timing
    auto start14 = high_resolution_clock::now();
    MergeSort(num1, 0, n1-1);
    //End timing
    auto end14 = high_resolution_clock::now();
    auto duration14 = duration_cast<microseconds>(end14 - start14);
    cout << "Time taken by merge sort with 10000 element sorted is: " << duration14.count() << " microseconds " <<endl;

    return 0;
}
