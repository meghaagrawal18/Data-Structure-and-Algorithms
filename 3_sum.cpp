//BRUTE FORCE APPROACH
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>>st;
        int n=nums.size();
        //using pointer in this , 2 static and one is movinf that is the kth one
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    if(nums[i]+nums[j]+nums[k]==0)
                    {
                        vector<int> temp={nums[i],nums[j],nums[k]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        for (auto triplet : st)
            ans.push_back(triplet);
            
        return ans;


        
    }
    
};
//better solution --> done usinh hashmap
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            //if i is incremened , hashset is again formed
            set<int> hashset;
            for (int j = i + 1; j < n; j++) {
                int third = -(nums[i] + nums[j]);
                if (hashset.find(third) != hashset.end()) {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                //inser the jth element in the hashset
                hashset.insert(nums[j]);
            }
        }

        for (auto triple : st) {
            ans.push_back(triple);
        }

        return ans;
    }
};

//optimal approach
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       int n=nums.size();
       vector <vector<int>> ans;
       sort(nums.begin(),nums.end());
       for(int i=0;i<n;i++)
       {
        if(i>0 && nums[i]==nums[i-1]) continue;
        int j=i+1;
        int k=n-1;
        while(j<k)
        {
            int sum=nums[i]+nums[j]+nums[k];
            if(sum>0)
            {
                k--;

            }
            else if(sum<0)
            {
                j++;

            }
            else
            {
                vector<int> temp={nums[i],nums[j],nums[k]};
                ans.push_back(temp);
                j++;
                k--;

            }
        }
       }
       
        return ans;
    }
   
};
