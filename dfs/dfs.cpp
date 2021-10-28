/*
 * @Description: 深度优先算法 dfs  -- 就是一条路走到黑之后在回溯
 * 输出 123 三个数字的排列组合数
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-08-23 20:57:47
 */

#include <iostream>
#include <ostream>

enum{MAX = 8}; int a[10]; int book[10] = {0};
void dfs(int step){
    if(step == MAX){
        for(int i = 0 ; i < MAX ; i++){
            std::cout<< a[i] << " ";
        }
        std::cout<<std::endl;
        return;
    }
    for(int i = 0 ; i < MAX ; i++){
        if(book[i] == 0){
            a[step] = i+1;
            book[i] = 1;
            dfs(step+1);
            book[i] = 0;
        }
    }
    return ;
}
int main(){
    dfs(0);
    return 0;
}