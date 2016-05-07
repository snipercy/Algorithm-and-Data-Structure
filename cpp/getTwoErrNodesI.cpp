/*
 * 一棵二叉树原本是搜索二叉树,但是其中有两个节点调换了位置,使得这棵二叉树不
 * 再是搜索二叉树,请找到这两个错误节点并返回。
 * 已知二叉树中所有节点的值都不一样, 给定二叉树的头节点 head, 返回一个长度为 2
 * 的二叉树节点类型的数组 errs, * errs[0]表示一 个错误节点,errs[1]表示另一个错误节点。
 */
// 只需遍历一遍

#include<stdio.h>
#include<assert.h>
#include<vector>
#include<stack>
#include<array>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;

    Node(int val){
        value = val;
        left = right = NULL;
    }
};


std::array<Node*, 2> getTwoErrNodes(Node* head) {
    assert(head);

    std::array<Node*, 2> res={0};
    std::stack<Node*> stk;
    Node* cur = head;
    Node* pre = NULL;

    // inOrder traverse
    while(!stk.empty() || cur != NULL) {
        if(cur != NULL) {
            stk.push(cur);
            cur = cur->left;
        } else {
            cur = stk.top();
            stk.pop();
            if(pre != NULL && pre->value > cur->value) {
                printf("pre:%d, cur:%d\n",pre->value, cur->value);
                res[0] = res[0] == NULL ? pre : res[0];
                res[1] = cur;
            }
            pre = cur;
            cur = cur->right;
        }
    }

    return res;
}

// for test
int main() {
    Node* p = new Node(4);
    p->left = new Node(2);
    p->left->left = new Node(3);
    p->left->right = new Node(1);
    p->right = new Node(5);
    auto err = getTwoErrNodes(p);

    printf("%d\n",err[0]->value);
    printf("%d\n",err[1]->value);

    return 0;
}
