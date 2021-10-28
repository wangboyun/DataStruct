/*
 * @Description: 后序遍历(递归)
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-07 19:34:39
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
        preorder(root->left);
        preorder(root->right);
        std::cout << root->data<< " ";
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