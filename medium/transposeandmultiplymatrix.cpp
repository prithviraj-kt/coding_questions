#include<iostream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;
vector<vector<int>> readMatrix(int row, int col)
{
    vector<vector<int>> mat (row, vector<int>(col));
    
    for(int i = 0; i<row; i++){
    string sent;
        getline(cin,sent);
        stringstream ss(sent);
        int nums;
        for(int j = 0; j<col; j++){
            ss>>nums;
            mat[i][j] = nums;
        }
    }
    
    
    
    return mat;
}



vector<vector<int>> transpose(vector<vector<int>> &mat, int row, int col)
{
    vector<vector<int>> trans(col, vector<int>(row));
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            trans[j][i] = mat[i][j];
        }
    }
    return trans;
}

vector<vector<int>> multiply(vector<vector<int>> mat1, vector<vector<int>> mat2, int r1, int c1, int r2, int c2)
{
    vector<vector<int>> result(r1, vector<int>(c2));
    for(int i = 0; i<r1; i++){
        for(int j = 0; j<c2; j++){
            for(int k = 0; k<c1; k++)
            {
                result[i][j]+=mat1[i][k]*mat2[k][j];
            }
        }
    }
    return result;
}

int main()
{
    int row, col;
    string rowandcol;
    getline(cin, rowandcol);
    stringstream ss(rowandcol);
    ss>>row>>col;
    
    
    
    vector<vector<int>> matrix =  readMatrix(row, col);

    
    
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    vector<vector<int>> trans = transpose(matrix, row, col);
    
    cout<<endl<<endl<<endl;
    for(int i = 0; i<col; i++){
        for(int j = 0; j<row; j++){
            cout<<trans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    vector<vector<int>> result = multiply(matrix, trans, row, col, col, row);
    
    for(int i = 0; i<row; i++){
        for(int j = 0; j<row; j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}