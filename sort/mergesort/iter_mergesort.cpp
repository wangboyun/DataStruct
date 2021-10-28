/*
 * @Description:  单个无序数组使用递归 + 迭代的方法 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-05 10:36:12
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

    int cal_count(int size){
        int n = 0;
        while(size){
            n++;
            size = size /2;
        }
        return n;
    }

    int towpow(int size){
        int n = 1;
        if(size <= 0)
            return 0;
        while (size) {
            n *= 2;
            size--;
        }
        return n;
    }

    void Msort(vector<int>& nums , vector<int> temp ){
        /* 计算趟数 */
        int n = cal_count(nums.size());
        
        int index = 1;
        while (index <= n){
            for (int i = 0 ; i < nums.size() ; i += (towpow(index))){
                if(i + towpow(index) -1 < nums.size())
                    mergesort(nums,temp,i, i+((towpow(index)) -1)/2 +1 , i + (towpow(index)) -1);
                else
                    mergesort(nums,temp,i, i+((towpow(index)) -1)/2 +1 , nums.size()-1);;
            }
            index++;
        }
        
    }
};

int main(){
    Solution sl;
    vector<int> nums{5,2,6,88,32,14,65,77,5,77,88};
    vector<int> temp = nums;
    int left = 0;
    int right = nums.size() - 1 ;
    sl.Msort(nums,temp);
    for(auto i : nums)
        cout << i <<" ";
    cout << endl;
}