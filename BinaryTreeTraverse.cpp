#include<stdio.h>
#include<string>
#include<iostream>

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
	TreeNode* root;

public:
	traverse() {
		root = NULL;
	}
	// 建立二叉树
	// point data points to std::array<int,size>
	//TreeNode* buildTree(int*, int);
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

	// "之"字形遍历
	void zhiTraversal(TreeNode*);

};

// 建立二叉树
// 通过字符串建立二叉树,eg:"123##67!",'#' means null
//      1
//     / \
//    2   3
//       / \
//      6  7
// hhhh
void traverse::
buildTree(int a[], int n)
{
	if (n<=0) {
		root = NULL;
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
	root = tree[0];
	printf("root:%p\n", root);

}

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
}

// 非递归-中序遍历
void traverse::
inOrder(TreeNode* r) {
}

// 非递归-后序遍历
void traverse::
postOrder(TreeNode* r) {
}

// 层次遍历
void traverse::
levelTraversal(TreeNode* r) {

}

// "之"字形遍历
void traverse::
zhiTraversal(TreeNode* r) {

}

int main() {

	//    1
	//   / \
	//  2   3
	//     /
	//    4
	//     \
	//     5
	int a[] = {1,2,3,0,0,4,0,0,5};

	traverse t;
	t.buildTree(a, sizeof(a)/sizeof(int));

	t.preOrderRecur(t.root);
	printf("\n");

	t.inOrderRecur(t.root);
	printf("\n");

	t.postOrderRecur(t.root);
	printf("\n");

	return 0;
}
