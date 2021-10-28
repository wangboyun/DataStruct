/*
 * @Description:  二叉树的深度
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-07 15:30:34
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
    int depth(const BtreeNode* root){
        if(root == nullptr)
            return 0;
        int ldepth = depth(root->left);
        int rdepth = depth(root->right);
        return 1 + std::max(ldepth , rdepth);
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
    std::cout << sl.depth(&root)<< std::endl;
    return 0;
}