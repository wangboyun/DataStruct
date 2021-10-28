/*
 * @Description: 中序遍历 (非递归形式)
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-07 16:57:23
 */

#include <iostream>
#include <stack>
#include <utility>

struct BtreeNode{
    int data;
    BtreeNode* left;
    BtreeNode* right;
};

class Solution{
public:
    void inorder(BtreeNode* root){
        // 申请一个栈
        std::stack<std::pair<BtreeNode* , int>> st;
        // 将根节点入栈
        st.push(std::pair<BtreeNode* , int> {root , 0});
        while(!st.empty()){
            std::pair<BtreeNode* , int>temp = st.top();
            st.pop();
            // 如果该节点的左右节点都为nullptr 或者 int 那个数据为 1 的之间访问
            if(temp.first->left == nullptr && temp.first->right == nullptr)
                // 访问节点
                std::cout << temp.first->data<<" ";
            else if(temp.second == 1)
                // 访问根节点
                std::cout << temp.first->data<<" ";
            else{
                temp.second = 1;
                if(temp.first->right != nullptr)
                    st.push(std::pair<BtreeNode* , int> {temp.first->right , 0});
                st.push(temp);
                if(temp.first->left != nullptr)
                    st.push(std::pair<BtreeNode* , int> {temp.first->left , 0}); 
            }
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
    sl.inorder(&root);
    std::cout << std::endl;
    return 0;
}