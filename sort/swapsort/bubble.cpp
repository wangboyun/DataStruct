/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-05 15:49:58
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    const vector<int>& bubblesort(vector<int>& nums){
        for(int i = 0 ; i < nums.size()-1 ; i++){       // 需要的趟数，最多需要size-1 趟
        // 两两之间比较次数，每一趟选出一个最大值，就少比一次(即 第几次就少比较几个 )
            for(int j = 0; j < nums.size()-1-i ; j++){  
                if(nums[j] > nums[j+1]){
                    int temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                }
            }
        }
        return nums;
    }
};

int main(){
    Solution sl;
    vector<int> nums{5,8,4,6,5,11,3,56,7,88,32,55};
    nums = sl.bubblesort(nums);
    for(auto i : nums)
        cout << i <<" ";
    cout << endl;
}