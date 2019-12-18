//  main.cpp
//  fibIter
//  Created by Dara Lim on 9/23/18.
//  Copyright © 2018 Dara Lim. All rights reserved.

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    int pre1 = 0;
    int pre2 = 1;
    int next;
    cout << "Enter the positive integer n ";
    cout << "and the program will find the fibonacci of n" <<endl;
    cin >> n;
    for(int i = 0; i <= n; i++)
    {
        if(i <= 1){
            next = i;
        }
        else{
            next = pre1 + pre2;
            pre1 = pre2;
            pre2 = next;
        }
    }
    cout << "The Fibonacci number is: " << next <<endl;
    return 0;
}
