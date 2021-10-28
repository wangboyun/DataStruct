/*
 * @Description: 两个升序数组归并排序 O(N)
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-03 20:55:46
 */
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

class Solution{
public:
    const vector<int> mergesort(vector<int>& nums , vector<int>& vect){
        vector<int> ans;
        auto nums_it = nums.begin();
        auto vect_it = vect.begin();
        while(nums_it != nums.end() && vect_it != vect.end()){
            if(*nums_it > *vect_it){
                ans.push_back(*vect_it);
                vect_it++;
            }
            else {
                ans.push_back(*nums_it);
                nums_it++;
            }
        }
        if(nums_it == nums.end()){
            for(; vect_it != vect.end(); vect_it++){
                ans.push_back(*vect_it);
            }
        }
        else {
            for(; nums_it != nums.end(); nums_it++){
                ans.push_back(*nums_it);
            }
        }
        return ans;
    }
};

int main(){
    Solution sl;
    vector<int> nums{4,5,6,11,32,55,77,88};
    vector<int> vect{6,9,44,222,434,555};
    nums = sl.mergesort(nums,vect);
    for(auto i : nums)
        cout << i <<" ";
    cout << endl;
}

