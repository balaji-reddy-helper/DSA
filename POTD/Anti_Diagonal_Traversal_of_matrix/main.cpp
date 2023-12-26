/*Give a N*N square matrix, return an array of its anti-diagonals in top-leftmost to bottom-rightmost order. 
In an element of a anti-diagonal (i, j), surrounding elements will be (i+1, j-1) and (i-1, j+1). 
Look at the examples for more clarity.

Input:
N = 3
matrix[][] = 3 2 3
            4 5 1
            7 8 9
Output:
3 2 4 3 5 7 1 8 9

*/

#include <bits/stdc++.h>
using namespace std;


vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
{
    vector<int> ans;
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<m;i++)
    {
        int j=i,k=0;
        while(k<n && j>=0)
            ans.push_back(matrix[k++][j--]);
    }
    
    for(int i=1;i<n;i++)
    {
        int j=m-1,k=i;
        while(k<n && j>=0)
            ans.push_back(matrix[k++][j--]);
    }
    return ans;
}



int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        vector<int> ans = antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
