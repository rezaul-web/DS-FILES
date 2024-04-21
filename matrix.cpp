#include <iostream>
using namespace std;

int determinant(int **matrix,int n)
{
    if(n==1)
    return matrix[0][0];

    int det=0;
    int **submatrix=new int*[n-1];
    for(int i=0;i<n;i++)
    {
        submatrix[i]=new int[n-1];
    }

    for(int k=0;k<n;k++)
    {
        int subi=0;
        for(int i=0;i<n;i++)
        {
            int subj=0;
            for(int j=0;j<n;j++)
            {
                if(j!=k)
                {
                    submatrix[subi][subj++]=matrix[i][j];
                }
            }
            ++subi;
        }
        int sign=(k%2==0)?-1:1;
        det+=sign*matrix[0][k]*determinant(submatrix,n-1);
        return det;
    }
}
int main()
{
    int rows, cols;
    int **matrix;
    cout << "Enter rows and cols ";
    cin >> rows >> cols;
    matrix = new int*[rows];
    for (int i = 0; i < cols; i++)
        matrix[i] = new int[cols];
    cout << "Enter entries : " << endl;
   for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
       
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << "   ";
        }
        cout << endl;
    }

    cout<<determinant(matrix,rows)<<endl;
}