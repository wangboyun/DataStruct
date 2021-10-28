/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-01 21:24:31
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashmap;
        vector<int> ans;
        for(int i = 0 ; i < nums.size() ; i++){
            hashmap[nums[i]] = i;
        }
        for(int i = 0 ; i < nums.size() ; i++){
            auto pos = hashmap.find(target - nums[i]);
            if( pos!= hashmap.end() && i != pos->second ){
                ans.push_back(i);
                ans.push_back(pos->second);
                return ans;
            }
            
        }
        return ans;
    }
};

int main(){
    vector<int> nums{2,7,11,15};
    vector<int> ans;
    Solution sl;
    ans = sl.twoSum(nums, 9);
    for(auto i : ans)
        cout<< i <<" ";
    cout<< endl;
    return 0;
}