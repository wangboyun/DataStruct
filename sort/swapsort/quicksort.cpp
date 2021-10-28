/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-05 16:42:25
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    void quicksort(vector<int>& nums,int left , int right){
        if(left >= right)
            return;
        int i = left; int j = right;
        int temp = nums[left];
        while (i != j) {
            //先在右边找小于 temp 的值
            while(nums[j] >= temp && i < j)
                j--;
            //再在左边找大于 temp 的值
            while(nums[i] <= temp && i < j)
                i++;
            // 交换两者的顺序
            if(i < j){
                int tm = nums[j];
                nums[j] = nums[i];
                nums[i] = tm;
            }  
        
        }

        nums[left] = nums[i] ;
        nums[i] = temp;

        quicksort(nums,left,i-1);
        quicksort(nums,i+1,right);
       
    }
};

int main(){
    Solution sl;
    vector<int> nums{4,2,4,3,0,1,3,2};
    int left = 0;
    int right = nums.size() - 1;
    sl.quicksort(nums,left,right);
    for(auto i : nums)
        cout << i <<" ";
    cout << endl;
}