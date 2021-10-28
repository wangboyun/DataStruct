/*
 * @Description: 希尔排序 O(NlogN ~ N2)
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-02 08:44:30
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    const vector<int>& shellsort(vector<int>& nums , vector<int>& d){
        int k = 0; int index = 0;
        while(k < d.size()){
            for(int i = 0 ; i < nums.size() ; i++){
                for(index = d[k] + i; index < nums.size(); index += d[k]){
                    int t = index;
                    while(t >  i){
                        if(nums[index] < nums[t - d[k]]){
                            t -= d[k];
                        }
                        else
                            break;
                    }
                    int temp = nums[index];
                    for(int j = index; j > t ; j -= d[k]){
                        nums[j] = nums[j - d[k]];
                    }
                    nums[t] = temp;
                }
            }
            k++;
        }  
        return nums;
    }
};

int main(){
    Solution sl;
    vector<int> nums{5,8,4,6,5,11,3,56,7,88,32,55};
    vector<int> d{7,5,3,1};
    nums = sl.shellsort(nums,d);
    for(auto i : nums)
        cout << i <<" ";
    cout << endl;
}
