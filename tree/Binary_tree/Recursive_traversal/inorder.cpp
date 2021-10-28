/*
 * @Description: 二叉树递归遍历之中序遍历
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-06 21:31:05
 */
#include <iostream>

struct BtreeNode{
    int data;
    BtreeNode* left;
    BtreeNode* right;
};

class Solution{
public:
    
    void inorder(BtreeNode* root){
        if(root == nullptr)
            return;

        //先中序遍历左节点
        inorder(root->left);
        
        std::cout << root->data<< " ";
        inorder(root->right);
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
    sl.inorder(&root);
    std::cout << std::endl;
    return 0;
}