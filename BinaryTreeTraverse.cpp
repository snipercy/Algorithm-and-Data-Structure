#include<stdio.h>


class TreeNode
{
	int data;
	TreeNode* lchild;
	TreeNode* rchild;

	TreeNode(int d) : data(d), lchild(nullptr), rchild(nullptr) { }
};

class traverse
{
private:
	TreeNode* root;

public:
	// 递归遍历
	void preOrderRecur(TreeNode* r);
	void inOrderRecur(TreeNode* r);
	void postOrderRecur(TreeNode* r);

	// 非递归遍历
	void preOrder(TreeNode* r);
	void inOrder(TreeNode* r);
	void postOrder(TreeNode* r);

};

// 递归-前序遍历
void traverse::preOrderRecur(TreeNode* r) {
}

// 递归-中序遍历
void traverse::inOrderRecur(TreeNode* r) {
}

// 递归-后序遍历
void traverse::postOrderRecur(TreeNode* r) {
}

// 非递归-前序遍历
void traverse::preOrder(TreeNode* r) {
}

// 非递归-中序遍历
void traverse::inOrder(TreeNode* r) {
}

// 非递归-后序遍历
void traverse::postOrder(TreeNode* r) {
	printf("postOrder\n");
}


int main(){

	// test
	traverse t;
	t.postOrder(nullptr);

	return 0;
}
