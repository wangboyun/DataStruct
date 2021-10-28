/*
 * @Description: 最大堆排序算法
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-09 17:22:47
 */
#include <iostream>
#include <vector>
using namespace std;

// struct BtreeNode{
//     int data;
//     int left;
//     int right;
//     int parent;
// };

// 完全二叉树按数组形式排序，第 i 位的左子树(2*i+1)， 右子树(2*i+2)

class Solution{
public:
    void swap(int& a, int& b){
        int temp = b;
        b = a;
        a = temp;
    }

    /* 堆调整 */
    void heapify(vector<int>& tree ,int size, int i){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        // int parent = (i - 1) / 2;

        // 左右子树不存在 
        if(left > size)
            return ;
        // 只存在左子树
        else if(left <= size && right > size){
            if(tree[i] < tree[left]){
                swap(tree[i], tree[left]);
            }
            return ;
        }
        
        // 既有左子树又有右子树
        else{
            // 找这三个的最大值交换[i] 与 [index]
            int max = i;
            if(tree[max] < tree[left])
                max = left;
            if(tree[max] < tree[right])
                max = right;
            swap(tree[i], tree[max]);
        }
        return ;
    }
    
    /* 创建一个堆 */
    vector<int> creat_heap(vector<int>& tree){
        int size = tree.size() - 1 ;
        int n = size / 2;
        while(n >= 0){
            heapify(tree,size,n);
            n--;
        }
        return tree;
    }

    vector<int> max_heap_sort(vector<int>& tree){
        vector<int> ans;
        while(tree.size()-1 > 0){
            vector<int> res = creat_heap(tree);
            ans.push_back(res.front());
            tree.erase(tree.begin());
        }
        // 最后一个元素直接加入就行了
        ans.push_back(*tree.begin());
        return ans;
    }
};

int main(){
    vector<int> tree{49,97,13,38,27,49,76,65,44,54,33};
    Solution sl;
    vector<int> res = sl.max_heap_sort(tree);
    for(auto i : res)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}