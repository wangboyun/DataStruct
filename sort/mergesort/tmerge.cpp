/*
 * @Description: 单个无序数组使用递归 + 归并的方法 
 *  一种分治的思想
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-03 21:08:55
 */
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

class Solution{
public:
    void mergesort(vector<int>& nums , vector<int>& temp, int left , int mid , int right){
        int index = 0;
        vector<int> comp1;
        vector<int> comp2;
        
        index = left;
        for(int i = left; i < mid; i++)
            comp1.push_back(nums[i]);
        for(int i = mid; i <= right; i++)
            comp2.push_back(nums[i]);
        auto comp1_it = comp1.begin();
        auto comp2_it = comp2.begin();
        while(comp1_it != comp1.end() && comp2_it != comp2.end()){
            if(*comp1_it > *comp2_it){
                temp[index++]= *comp2_it;
                comp2_it++;
            }
            else {
                temp[index++]= *comp1_it;
                comp1_it++;
            }
        }
        if(comp1_it == comp1.end()){
            for(; comp2_it != comp2.end(); comp2_it++){
                temp[index++]= *comp2_it;
            }
        }
        else {
            for(; comp1_it != comp1.end(); comp1_it++){
                temp[index++]= *comp1_it;
            }
        }
        // 将temp 拷到 nums 对应位置
        for(int i = left ; i <= right ; i++){
            nums[i] = temp[i];
        }
    }

    void Msort(vector<int>& nums , vector<int> temp , int left , int right){
        //递归结束条件
        if(left >= right)
            return;
        int mid = (left + right) >> 1;
        Msort(nums, temp, left,mid);
        Msort(nums, temp, mid+1, right);
        mergesort(nums,temp,left,mid+1,right);
    }


};

int main(){
    Solution sl;
    vector<int> nums{5,2,6,88,32,14,65,77,3,1,4,7,8,99,90};
    vector<int> temp = nums;
    int left = 0;
    int right = nums.size() - 1 ;
    sl.Msort(nums,temp,left,right);
    for(auto i : nums)
        cout << i <<" ";
    cout << endl;
}
