/**
 * Given an index k, return the kth row of the Pascal's triangle.
 */

class Solution{
public:
    vector<int> getRow(int rowIndex){
        if(rowIndex < 0)  return vector<int>();

        vector<vector<int> > vvi;

        int count = 0;
        while(count <= rowIndex){
            vector<int> row(1,1);
            for(int i = 1; i <= count; ++i){
                if(i != count) row.push_back(vvi[count-1][i] + vvi[count-1][i-1]);
                else row.push_back(1);
            }
            vvi.push_back(row);
            ++count;
        }

        return vvi[rowIndex];
    }
};
