#include <iostream>
#include <vector>
#include "myprofile.h"

using namespace std;

void rotate(vector<vector<int>>& matrix){
    int msize = matrix.size();
    if(msize == 1)
        return;
    // сколько слоёв
    int i;
    for(i=0;i<msize/2;++i){
        int rowsize = msize-2*i;
        for(int j=0;j<rowsize-1;++j){
            int reserve = matrix[i][i+j];
            matrix[i][i+j] = matrix[i+(rowsize-1)-j][i];
            matrix[i+(rowsize-1)-j][i] = matrix[i+(rowsize-1)][i+(rowsize-1)-j];
            matrix[i+(rowsize-1)][i+(rowsize-1)-j] = matrix[i+j][i+(rowsize-1)];
            matrix[i+j][i+(rowsize-1)] = reserve;
        }
    }
}


void PrintMatrix(const vector<vector<int>> &matrix){
    for(auto & vec: matrix){
        for(auto & el : vec){
            cout << el << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    vector<vector<int>> matrix = {{0,1,2,3,4},{5,6,7,8,9},{0,1,2,3,4},{5,6,7,8,9},{0,1,2,3,4}};
    PrintMatrix(matrix);
    cout << endl;
    rotate(matrix);
    PrintMatrix(matrix);
    return 0;
}
