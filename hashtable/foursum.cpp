/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-02 11:19:39
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashmap;
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); i++){
            hashmap[nums[i]] = i;
        }
        for(int i = 0; i < nums.size()-3 ; i++){
            for(int j = i+1 ; j < nums.size()-2; j++){
                for(int k = j + 1; k < nums.size()-1; k++ ){
                    auto ptr = hashmap.find(target - nums[i] -nums[j] -nums[k]);
                    if( ptr != hashmap.end() && ptr->second > k){
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        v.push_back(ptr->first);
                        ans.push_back(v);
                        // 去重操作
                    }
                }
            }
        }
        return ans; 
    }
};

int main(){
    vector<int> nums{1,0,-1,0,2,-2};
    vector<vector<int>> ans;
    Solution sl;
    ans = sl.fourSum(nums, 0);
    for(auto i : ans){
        for(auto p : i)
            cout << p << " ";
    }
        
    cout<< endl;
    return 0;
}