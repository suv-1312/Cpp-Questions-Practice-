class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        
        for(int i = 0 ; i<numRows ;i++){
            if(i<2){
                vector<int> temp(i+1,1);
                ans.push_back(temp);
                continue;
            }
            else
            {
                vector<int> temp;
             for(int j = 0 ; j<=i ; j++)
             {
                 if(j == 0 || j==i)
                 {
                     temp.push_back(1);
                 } 
                 else
                 {
                    int t  = ans[i-1][j-1] + ans[i-1][j];
                     temp.push_back(t);
                 }
             }
                ans.push_back(temp);
            }
        }
        return ans;
        
    }
};