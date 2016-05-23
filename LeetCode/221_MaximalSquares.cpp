/**
 * Given a 2D binary matrix filled with 0's and 1's,
 * find the largest square containing all 1's and return its area
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    int max(int x,int y){
        if(x > y)
            return x;
        return y;
    }
    int min(int x, int y){
        if(x > y)
            return y;
        return x;
    }
    int maximalSquare(vector<vector<char> >& matrix){
        if(matrix.empty()) return 0;

        int maxArea = 0;
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < (matrix[0]).size(); ++j){
                if(matrix[i][j] == '0') matrix[i][j] = 0;
                else if(matrix[i][j] == '1') matrix[i][j] = 1;
                if(matrix[i][j] && i >=1 && j >= 1){
                    matrix[i][j] = min(min(matrix[i-1][j],matrix[i][j-1]),matrix[i-1][j-1]) + 1;
                    maxArea = max(matrix[i][j],maxArea);
                }else if(matrix[i][j]){
                    maxArea = max(matrix[i][j],maxArea);
                }
            }
        }

        return maxArea*maxArea;
    }
};

int main()
{
    Solution s;
    vector<char> v(1,'1');

    vector< vector<char> > vv;
    vector< vector<char> >::iterator it;
    it = vv.begin();
    vv.insert(it,v);

    cout << s.maximalSquare(vv);

    return 0;
}
