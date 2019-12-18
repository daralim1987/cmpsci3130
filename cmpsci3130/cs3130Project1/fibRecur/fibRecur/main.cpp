//  main.cpp
//  fibRecur
//  Created by Dara Lim on 9/23/18.
//  Copyright © 2018 Dara Lim. All rights reserved.

#include <iostream>
using namespace std;

long long fib(long long n)
{
    if (n <= 1)
        return n;
    return fib(n-1)+fib(n-2);
}

int main(int argc, const char * argv[]) {
    long long N;
    cout << "Enter the positive number " << "";
    cout << "and the programm will find its Fibonacci number: " <<endl;
    cin >> N;
    cout << "The Fibonacci number of positive integer "<< N << " is: " << fib(N) <<endl;
    
    return 0;
}
