/*
 * @Description: 二叉树递归遍历之先序遍历
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-06 20:41:29
 */
#include <iostream>

struct BtreeNode{
    int data;
    BtreeNode* left;
    BtreeNode* right;
};

class Solution{
public:
    
    void preorder(BtreeNode* root){
        if(root == nullptr)
            return;
        //先访问根节点
        std::cout << root->data<< " ";
        preorder(root->left);
        preorder(root->right);
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
    b.left = &e;
    Solution sl;
    sl.preorder(&root);
    std::cout << std::endl;
    return 0;
}