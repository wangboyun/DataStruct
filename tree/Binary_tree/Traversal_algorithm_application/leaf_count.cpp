/*
 * @Description: 递归方法求叶子节点的个数(左 右节点都为空)
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-07 15:44:12
 */
#include <algorithm>
#include <iostream>

struct BtreeNode{
    int data;
    BtreeNode* left;
    BtreeNode* right;
};

class Solution{
public:
    int leaves(const BtreeNode* root){
        if(root == nullptr)
            return 0;
        if(root->left == nullptr && root->right == nullptr)
            return 1;
        int lcount = leaves(root->left);
        int rcount = leaves(root->right);
        return lcount + rcount;
    }
    
};

int main(){
    BtreeNode root{1,nullptr,nullptr};
    BtreeNode a{2,nullptr,nullptr};
    BtreeNode b{3,nullptr,nullptr};
    BtreeNode c{4,nullptr,nullptr};
    BtreeNode d{5,nullptr,nullptr};
    BtreeNode e{6,nullptr,nullptr};
    root.left = &a;
    root.right = &b;
    a.left = &c;
    a.right = &d;
    d.left = &e;
    Solution sl;
    std::cout << sl.leaves(&root)<< std::endl;
    return 0;
}