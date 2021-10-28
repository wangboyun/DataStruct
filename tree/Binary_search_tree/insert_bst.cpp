/*
 * @Description: 二叉排序树插入
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-08 10:59:36
 */
#include <iostream>
#include <vector>

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

    BtreeNode* insert_bst(const int val , BtreeNode* root){
        
        if(root == nullptr){
            BtreeNode* node = new BtreeNode{val ,nullptr ,nullptr};
            root = node;
        }
        if(val > root->data)
            root->right = insert_bst(val,root->right);
        else if (val < root->data)
            root->left = insert_bst(val,root->left);

        return root;
    } 
    
};

int main(){
    std::vector<int> val{50,30,80,20,40,90,35,82,32,85};
    BtreeNode* root = nullptr;
    Solution sl;
    for(auto i : val){
        root = sl.insert_bst(i,root);
    }
    sl.inorder(root);
    std::cout<<std::endl;
    return 0;
}