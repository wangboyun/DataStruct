/*
 * @Description: 简单选择排序 O(N2)
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-03 20:11:00
 */

#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    const int find_min_index(vector<int>& nums, int index){
        int min = nums[index]; 
        for(int i = index; i < nums.size(); i++){
            if(min > nums[i]){
                min = nums[i];
                index = i;
            }
        }
        return index;
    }

    const vector<int>& smp_selectsort(vector<int>& nums){
        int index = 0;
        for(int i = 0; i < nums.size(); i++){
            index = find_min_index(nums, i);
            if(index != i){
                int temp = nums[index];
                nums[index] = nums[i];
                nums[i] = temp;
            }
        }
        return nums;
    }
};

int main(){
    Solution sl;
    vector<int> nums{5,8,4,6,5,11,3,56,7,88,32,55};
    nums = sl.smp_selectsort(nums);
    for(auto i : nums)
        cout << i <<" ";
    cout << endl;
}