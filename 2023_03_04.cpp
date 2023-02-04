/**
 * @file 2023_03_04.cpp
 * @author Chitra Nayal 
 * @brief 
 * @version 0.1
 * @date 2023-02-04
 * 
 * @copyright Copyright (c) 2023
 * 


Given an array Arr of size N containing positive integers. Find the maximum sum of a subsequence such that no two numbers in the sequence should be adjacent in the array.

Example 1:

Input:
N = 6
Arr[] = {5, 5, 10, 100, 10, 5}
Output: 110
Explanation: If you take indices 0, 3
and 5, then Arr[0]+Arr[3]+Arr[5] =
5+100+5 = 110.
 

Example 2:

Input:
N = 4
Arr[] = {3, 2, 7, 10}
Output: 13
Explanation: 3 and 10 forms a non
continuous  subsequence with maximum
sum.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function findMaxSum() which takes the array of integers arr and n as parameters and returns an integer denoting the answer. It is guaranteed that your answer will always fit in the 32-bit integer.

 

 */


#include<bits/stdc++.h>
using namespace std;

int findMax(int * arr, int n){

    int dp[n+1]={0};
    dp[0] = 0;
    dp[1] = max(arr[0],arr[1]);
    for(int i=2; i <n; i++){
        dp[i] = max(arr[i], max(dp[i-1],dp[i-2]+arr[i]));
    }
    return dp[n-1];
}

int main(){
    int n = 4 ;
    int arr[n] = {3,2,7,10};
    cout << findMax(arr, n);
}