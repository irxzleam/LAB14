#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

void findLocalMax(const double A[N][N], bool B[N][N]) 
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 || i == N - 1 || j == 0 || j == N - 1) {
                B[i][j] = false;
            }else{
                double chong = A[i][j];
                if (chong >= A[i-1][j] && chong >= A[i+1][j] && chong >= A[i][j-1] && chong >= A[i][j+1])  
                {
                    B[i][j] = true;
                }else{
                    B[i][j] = false;
                }
            }
        }
    }
}

void showMatrix(const bool M[N][N])
{
    for (int r = 0; r < N; r++) 
	{
        for (int c = 0; c < N; c++) 
		{
			if (M[r][c]==true) cout << "1";
            else cout << "0";
            cout << " ";
        }
        cout << "\n";
    }
}

void inputMatrix(double M[N][N])
{
	for (int r = 0; r < N; r++)
	{
	cout << "Row " << r + 1 << ": ";
	}
	for (int i = 0; i < N; i++) 
	{
        for (int j = 0; j < N; j++) 
		{
            cin >> M[i][j]; 
        }
		
	}
}	
