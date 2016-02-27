#include<stdio.h>
#include<string>
#include<iostream>
#include<stack>
#include<assert.h>
#include<queue>
#include<deque>

class TreeNode
{
    public:
        char data;
        TreeNode* lchild;
        TreeNode* rchild;
        TreeNode(char d) : data(d), lchild(nullptr), rchild(nullptr) { }
};

class traverse
{
    public:

        traverse() : _root(NULL){ }

        void buildTree(int*, int);

        // 递归 前,中,后序遍历
        void preOrderRecur(TreeNode*);
        void inOrderRecur(TreeNode*);
        void postOrderRecur(TreeNode*);

        // 非递归 前,中,后序遍历
        void preOrder(TreeNode*);
        void inOrder(TreeNode*);
        void postOrder(TreeNode*);

        // 层次遍历
        void levelTraversal(TreeNode*);

        // 之字遍历
        void printZigZag(TreeNode*);

    public:
        TreeNode*_root;
};

// 建立二叉树
// eg: int a[] = {1,2,3,0,0,4,0,0,5}; 0 means null
//    1
//   / \
//  2   3
//     /
//    4
//     \
//     5
void traverse::
buildTree(int a[], int n)
{
    if (n<=0) {
        _root = NULL;
    }

    TreeNode **tree = new TreeNode*[n];

    for(int i=0; i<n; i++) {
        if (a[i]==0 ){
            tree[i] = NULL;
            continue;
        }
        tree[i] = new TreeNode(a[i]);
    }
    int pos=1;
    for(int i=0; i<n && pos<n; i++) {
        if (tree[i]){
            tree[i]->lchild = tree[pos++];
            if (pos<n){
                tree[i]->rchild = tree[pos++];
            }
        }
    }
    _root = tree[0];
}

/*
   void buildTree_1(TreeNode* &node, std::string& ss) {
// for debug
// std::cout << ss.str()<<std::endl;

char c;
static int idx = 0;

printf("idx: %d",idx);

if (idx >= ss.length() || (c = ss[idx++]) == '!')  {
return;
} else if (c == '#') {
node = NULL;
} else {
node = new TreeNode(c);
buildTree_1((node)->lchild, ss);
buildTree_1((node)->rchild, ss);
}
}
*/

// 递归-前序遍历
void traverse::
preOrderRecur(TreeNode* r) {
    if (r == NULL) {
        return;
    }
    printf("%d ",r->data);
    preOrderRecur(r->lchild);
    preOrderRecur(r->rchild);
}

// 递归-中序遍历
void traverse::
inOrderRecur(TreeNode* r) {
    if (r == NULL) {
        return;
    }
    inOrderRecur(r->lchild);
    printf("%d ", r->data);
    inOrderRecur(r->rchild);
}

// 递归-后序遍历
void traverse::
postOrderRecur(TreeNode* r) {
    if (r == NULL) {
        return;
    }
    postOrderRecur(r->lchild);
    postOrderRecur(r->rchild);
    printf("%d ", r->data);
}

// 非递归-前序遍历
void traverse::
preOrder(TreeNode* r) {
    assert(r != NULL);
    std::stack<TreeNode*> stk;
    stk.push(r);
    TreeNode* cur;
    while(!stk.empty()) {
        cur = stk.top();
        stk.pop();
        printf("%d ", cur->data);

        if(cur->rchild) {
            stk.push(cur->rchild);
        }
        if(cur->lchild) {
            stk.push(cur->lchild);
        }
    }

}

// 非递归-中序遍历
void traverse::
inOrder(TreeNode* r) {
    assert(r != NULL);
    std::stack<TreeNode*> stk;
    TreeNode* cur = r;
    while(!stk.empty() || cur != NULL) {
        if(cur != NULL) {
            stk.push(cur);
            cur = cur->lchild;
        } else {
            cur = stk.top();
            stk.pop();
            printf("%d ", cur->data);
            cur = cur->rchild;
        }
    }
    printf("\n");
}

// 非递归-后序遍历
void traverse::
postOrder(TreeNode* r) {
    assert(r != NULL);
    std::stack<TreeNode*> stk;
    stk.push(r);
    TreeNode* cur = NULL;
    // 记录最近访问过的节点
    TreeNode* pre = r;

    while(!stk.empty()) {
        cur = stk.top();
        if(cur->lchild != NULL && cur->lchild != pre && cur->rchild != pre) {
            stk.push(cur->lchild);
        } else if (cur->rchild != NULL && cur->rchild != pre){
            stk.push(cur->rchild);
        } else {
            cur = stk.top();
            stk.pop();
            printf("%d ", cur->data);
            pre = cur;
        }
    }
    printf("\n");
}

// 层次遍历,
//
// **遍历时需要输出层号**，输出格式：
// level 1 : 1
// level 2 : 2 3
// level 3 : 4
// level 4 : 5
//
// last 记录每一层最右节点,当访问的节点等于last时，
// 则需要换行.
// nlast 下一层的最右节点,即最新加入队列的节点，
// 用于更新last节点.
//
void traverse::
levelTraversal(TreeNode* r) {
    assert(r != NULL);
    std::queue<TreeNode*> Queue;
    Queue.push(r);
    TreeNode* cur;
    TreeNode* nlast;
    TreeNode* last = r;
    int level = 1;

    printf("level %d : ", level++);
    while(!Queue.empty()) {
        cur = Queue.front();
        Queue.pop();
        printf("%d ", cur->data);
        if(cur->lchild != NULL) {
            Queue.push(cur->lchild);
            nlast = cur->lchild;
        }
        if(cur->rchild != NULL) {
            Queue.push(cur->rchild);
            nlast = cur->rchild;
        }
        if(cur == last && !Queue.empty()){
            printf("\nlevel %d : ", level++);
            last = nlast;
        }
    }
    printf("\n");
}

// ZigZag Print
//
// 之字遍历,**遍历时需要输出层号**，输出格式：
// level 1 from left  to right : 1
// level 2 from right to left  : 3 2
// level 3 from left  to right : 4
// level 4 from right to left  : 5
//
// last: 记录每一层最后访问的节点,当访问的节点等于
// last时，则需要换行.
// nlast: 下一层的最后访问的节点,即第一个加入队列的节点，
// 与层次遍历中的nlast的意义正好相反.
//

static inline void PrintLevelAndOri(int level, bool lr) {
    printf("level %d ", level);
    if (lr) {
        printf("from left  to right : ");
    } else {
        printf("from right to left  : ");
    }
}

void traverse::
printZigZag(TreeNode* r) {
    assert(r != NULL);
    std::deque<TreeNode*> Deque;
    Deque.push_front(r);
    TreeNode* cur = NULL;
    TreeNode* last = r;
    TreeNode* nlast = NULL; // 下一行最后节点
    int level = 1;
    bool lr = true;         // lr：从左往右遍历

    PrintLevelAndOri(level++, lr);
    while(!Deque.empty()) {
        if (lr) {
            cur = Deque.front();
            Deque.pop_front();
            if (cur->lchild) {
                Deque.push_back(cur->lchild);
                nlast = nlast == NULL ? cur->lchild : nlast;
            }
            if (cur->rchild) {
                Deque.push_back(cur->rchild);
                nlast = nlast == NULL ? cur->rchild : nlast;
            }
        } else {
            cur = Deque.back();
            Deque.pop_back();
            if (cur->rchild) {
                Deque.push_front(cur->rchild);
                nlast = nlast == NULL ? cur->rchild : nlast;
            }
            if (cur->lchild) {
                Deque.push_front(cur->lchild);
                nlast = nlast == NULL ? cur->lchild : nlast;
            }
        }

        printf("%d ", cur->data);
        if (cur == last && !Deque.empty()) {
            lr = !lr;
            last = nlast;
            nlast = NULL;
            printf("\n");
            PrintLevelAndOri(level++, lr);
        }
    }
}

int main() {
    traverse t;
    //    1
    //   / \
    //  2   3
    //     /
    //    4
    //     \
    //     5
    int a[] = {1,2,3,0,0,4,0,0,5};
    t.buildTree(a, sizeof(a)/sizeof(int));

    t.printZigZag(t._root);

    return 0;
}

