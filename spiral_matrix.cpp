class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(); //rows
        int n=matrix[0].size(); //columns
        int left=0;
        int right=n-1;
        int top=0;
        int bottom=m-1;
        vector <int> ans;
        while(top<=bottom && left<=right)
        {
            //printing the right part
            for(int i=left;i<=right;i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++;
            //printing from top to bottom

            for(int i=top;i<=bottom;i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;
            //printing from right to left
            if(top<=bottom){
            for(int i=right;i>=left;i--)
            {
                ans.push_back(matrix[bottom][i]);

            }
            bottom--;
            }
            //printing from bottom to top
            if(left<=right)
            {
            for(int i=bottom;i>=top;i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
            }

        }
        return ans;
        
    }
};