/**
 * Given numRows, generate the first numRows of Pascal's triangle.
 */

class Solution{
private:
    vector<vector<int> > vvi;
public:
    vector<vector<int> > generate(int numRows){
        if(numRows == 0) return vvi;

        int count = 0;
        while(count < numRows){
            vector<int> vi(1,1);
            //if(count == 1) vi.push_back(1);
            for(int i = 1; i <= count; ++i){
                if(i != count) vi.push_back(vvi[count-1][i] + vvi[count-1][i-1]);
                else vi.push_back(1);
            }
            vvi.push_back(vi);
            //vi.clear();
            ++count;
        }

        return vvi;
    }
};
