/*
 * @Description: 直接插入排序 O(N2)
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-01 17:13:44
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    vector<int>& strinsort(vector<int>& nums)const{
        int j ,index;
        for(int i = 1 ; i < nums.size(); i++){ 
            /*找到合适的位置 */
            for( index = 0 ; index < i ; index++){
                if(nums[index] > nums[i])
                    break;
            }
            int temp = nums[i];
            /* 向后移位 */
            for(j = i ; j > index ; j--){
                nums[j] = nums[j-1];
            }
            nums[j] = temp;
        }
        return nums;
    }
};

int main(){
    Solution sl;
    vector<int> nums{5,8,4,6,5,11,3,56,7,88,32,55};
    nums = sl.strinsort(nums);
    for(auto i : nums)
        cout << i <<" ";
    cout << endl;
}