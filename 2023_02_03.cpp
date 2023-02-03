/**
 * @file 2023_02_03.cpp
 * @author Chitra Nayal
 * @brief 
 * @version 0.1
 * @date 2023-02-03
 * 
 * @copyright Copyright (c) 2023
 * 
 * 
 * Given a binary matrix of dimensions  with R rows and C columns. Start from cell(0, 0), moving in the right direction. Perform the following operations: 

If the value of matrix[i][j] is 0, then traverse in the same direction and check the next value.
If the value of matrix[i][j] is 1, then update matrix[i][j] to 0 and change the current direction clockwise. ie - up, right, down, or left directions change to right, down, left, and up respectively.
Find the index of the cell where you will be forced to exit the matrix while performing the given traversal. 

Example 1:

Input:
matrix[][] = {{0,1},
              {1,0}}
R=2
C=2
 
 Output: (1,1)

 Example 2:

Input: 
matrix[][] = {{0, 1, 1, 1, 0},
                   {1, 0, 1, 0, 1},
              {1, 1, 1, 0, 0}}
R=4
C=4

Output: (2,0)
Explanation: We will leave the grid after visiting the index (2,0).
 

Your Task:
You don't need to read input or print anything. Complete the function endPoints() which take  a 2D matrix[][] , an integer R and an integer C as  input parameter and returns the index of the last cell before exiting the matrix. 


 */

#include<bits/stdc++.h>
using namespace std;


pair<int,int> endPoint(vector<vector<int>> matrix, int row, int col){

    pair<int,int> ans;
    ans.first = 0, ans.second =0;
    int i = 0, j= 0;

    // right -> down->left->up->right
    string direction ="right";

    while (i >= 0 and j >= 0 and i < row && j < col)
    {
        ans.first = i, ans.second = j;

        if(direction == "right"){
            if(matrix[i][j] == 0){
                j++;
            }
            else{
                matrix[i][j] = 0;
                i++;
                direction="down";
            }
        }
        else if(direction == "down"){
            if(matrix[i][j] == 0){
                i++;
            }
            else{
                matrix[i][j] = 0;
                j--;
                direction="left";
            }
        }
        else if(direction == "left"){
            if(matrix[i][j] == 0){
                j--;
            }
            else{
                matrix[i][j] = 0;
                i--;
                direction="up";
            }
        }
        else if(direction == "up"){
            if(matrix[i][j] == 0){
                i--;
            }
            else{
                matrix[i][j] = 0;
                j++;
                direction = "right";
            }
        }
    }
    return ans;
    
}

int main(){

    cout <<"enter the rows: ";
    int row, col;
    cin >> row;
    cout <<"enter the cols : ";
    cin >> col;
    vector<vector<int>> matrix (row, vector<int>(col));
    for(int i = 0 ;i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> matrix[i][j];
        }
    }
    
    pair<int,int> p = endPoint(matrix, row, col);
    cout << p.first<<", "<< p.second<<endl;

    return 0;
}