/*
 * @Description: AVL 树 平衡二叉树
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-10 09:49:27
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

struct AVLtreeNode{
    int data;
    int height;
    AVLtreeNode* left;
    AVLtreeNode* right;
};

class Solution{
public:
    void inorder(AVLtreeNode* root){
        if(root == nullptr)
            return;

        //先中序遍历左节点
        inorder(root->left);
        
        std::cout << root->data<< " ";
        inorder(root->right);
    }

    void levelorder(AVLtreeNode* root){
        std::queue< AVLtreeNode* > btque;
        btque.push(root);
        while(!btque.empty()){
            AVLtreeNode* temp = btque.front();
            btque.pop();
            std::cout << temp->data << " ";
            if(temp->left)
                btque.push(temp->left);
            if(temp->right)
                btque.push(temp->right);    
        }
    }

    /*求树的深度*/
    int get_height(AVLtreeNode* root){
        if(!root)
            return 0;
        return root->height;
    }

    /*更新树的深度*/
    int update_tree_height(AVLtreeNode* root){
        if(!root)
            return 0;
        return std::max(get_height(root->left) , get_height(root->right)) + 1;
    }

    /* LL型旋 */
    AVLtreeNode* LL_rotating(AVLtreeNode* root){
        AVLtreeNode* q = root;
        AVLtreeNode* temp = root->left->right;
        root = root->left;         // 将之前的根节点的左结点作为LL旋转之后的根节点
        //将之前的根节点的左结点的右子树，旋转之后成为原根节点的左子树
        root->right = q;
        q->left = temp;
        // 每次旋转之后多需要更新涉及变得的节点的高度
        q->height = update_tree_height(q);
        root->height = update_tree_height(root);
        return root;
    }

    /* RR型 旋*/
    AVLtreeNode* RR_rotating(AVLtreeNode* root){
        AVLtreeNode* q = root;
        AVLtreeNode* temp = root->right->left;
        root = root->right;         // 将之前的根节点的右结点作为LL旋转之后的根节点
        //将之前的根节点的右结点的左子树，旋转之后成为原根节点的右子树 
        root->left = q;
        q->right = temp;
        // 每次旋转之后多需要更新涉及变得的节点的高度
        q->height = update_tree_height(q);
        root->height = update_tree_height(root);
        return root;
    }

     /* RL型 旋 */
    AVLtreeNode* RL_rotating(AVLtreeNode* root){
        root->right = LL_rotating(root->right);
        root =  RR_rotating(root);
        return root;
    }

    /* LR型 旋 */
    AVLtreeNode* LR_rotating(AVLtreeNode* root){
        root->left = RR_rotating(root->left);
        root =  LL_rotating(root);
        return root;
    }

    /* 插入 */
    AVLtreeNode* insert_avltree(const int val , AVLtreeNode* root){
        if(root == nullptr){
            AVLtreeNode* node = new AVLtreeNode{val, 0 ,nullptr ,nullptr};
            root = node;
        }
        if(val > root->data){
            /* 向右插 (对应 RR RL 型旋转)*/
            root->right = insert_avltree(val,root->right); 
            if(get_height(root->left) - get_height(root->right) == -2){
                // 这一步作用是当递归回到这个root时，判断是哪一种旋转
                if(val > root->right->data)
                    // RR 旋转
                    root =  RR_rotating(root);
                else
                    // RL 旋转;
                    root = RL_rotating(root);
            }   
        }
            
        else if (val < root->data){
            /* 向左插 (只能有 LL LR旋转)*/
            root->left = insert_avltree(val,root->left);
            if(get_height(root->left) - get_height(root->right) == 2){
                if(val < root->left->data)
                    //LL 旋转
                    root = LL_rotating(root);
                else
                    //LR 旋转;
                    root = LR_rotating(root);
            }
            
        }
        root->height = update_tree_height(root);
        return root;
    }  
};

int main(){
    std::vector<int> val{50,40,20,80,60,90};
    AVLtreeNode* root = nullptr;
    Solution sl;
    for(auto i : val){
        root = sl.insert_avltree(i,root);
    }
    sl.levelorder(root);
    std::cout<<std::endl;
    return 0;
}