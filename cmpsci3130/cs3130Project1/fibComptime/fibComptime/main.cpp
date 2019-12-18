
//  main.cpp
//  fibComptime
//  Created by Dara Lim on 9/23/18.
//  Copyright © 2018 Dara Lim. All rights reserved.

#include <iostream>
#include <ctime>
using namespace std;
using namespace std::chrono;

//Fibonacci function with recursion definition
int RecFib(int n)
{
    if(n <= 1){
        return n;
    }
    else{
        return RecFib(n-1) + RecFib(n-2);
    }
}

//Fibonacci function with iteration method
int ItFibo(int n){
    int first = 0;
    int second = 1;
    int next;
    for(int i = 0; i <= n; i++){
        if(i <= 1){
            next = i;
        }
        else{
            next = first + second;
            first = second;
            second = next;
        }
    }
    return next;
}

int main(int argc, const char * argv[]) {
    int N;
    cout << "Enter the positive integer N and the programm will find ";
    cout << "the fibonacci number and the time to execution "<<endl;
    cin >> N;
    
    //Start timing the fibonacci function definition
    auto start = high_resolution_clock::now();
    cout << "The fibonacci number of " << N << " is: " << RecFib(N) <<endl;
    //End timing the fibonacci function definition and calculate the duration
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Time taken by recursion definition is: " << duration.count() << " microseconds " <<endl;
    
    //Start timing the fibonacci function iteration
    auto start1 = high_resolution_clock::now();
    cout << "The fibonacci number of " << N << " is: " << ItFibo(N) << endl;
    //End timing the fibonacci function definition and calculate the duration
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(end1 - start1);
    cout << "Time taken by iteration method is: " << duration1.count() << " microseconds " << endl;
    
    return 0;
}
