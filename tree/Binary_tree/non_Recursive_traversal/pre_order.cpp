/*
 * @Description: 先序遍历 非递归方法
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-07 16:33:23
 */
#include <iostream>
#include <stack>

struct BtreeNode{
    int data;
    BtreeNode* left;
    BtreeNode* right;
};

class Solution{
public:
    
    void preorder(BtreeNode* root){
        // 申请栈
        std::stack<BtreeNode*> st;  
        // 将根节点加入栈
        st.push(root);
        while(!st.empty()){
            BtreeNode* temp = st.top();
            //先序先访问根节点
            std::cout << temp->data << " ";
            st.pop();
            // 先序遍历 应入栈右节点 (栈是先进后出的)
            if(temp->right)
                st.push(temp->right);
            if(temp->left)
                st.push(temp->left); 
        }
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