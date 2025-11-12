#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int counter = 0;
        int last_smaller = INT_MIN;
        int max_counter = 0; // to store longest sequence

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == last_smaller) {
                // skip duplicates
                continue;
            }
            if(nums[i] - 1 == last_smaller) {
                counter++;
            } else {
                counter = 1;
            }
            last_smaller = nums[i];
            if(counter > max_counter) max_counter = counter;
        }
        return max_counter;
    }
};
