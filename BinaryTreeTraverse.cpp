#include<stdio.h>
#include<string>
#include<sstream>
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
private:
	TreeNode* root;

public:
	// 建立二叉树
	// point data points to std::array<int,size>
	void buildTree(TreeNode* &root, std::string& ss);

	// 递归 前,中,后序遍历
	void preOrderRecur(TreeNode* r);
	void inOrderRecur(TreeNode* r);
	void postOrderRecur(TreeNode* r);

	// 非递归 前,中,后序遍历
	void preOrder(TreeNode* r);
	void inOrder(TreeNode* r);
	void postOrder(TreeNode* r);

	// 层次遍历
	void levelTraversal(TreeNode* r);

	// "之"字形遍历
	void zhiTraversal(TreeNode* r);

};

// 建立二叉树
// hhhh
void traverse::
buildTree(TreeNode* &node, std::string& ss) {
	// for debug
	// std::cout << ss.str()<<std::endl;

	char c;
	static int idx = 0;

#ifdef DEBUG
	printf("idx: %*d",idx);
#endif

	if (idx >= ss.length() || (c = ss[idx++]) == '!')  {
		return;
	} else if (c == '#') {
		node = NULL;
	} else {
		node = new TreeNode(c);
		printf("data:%c\n", (node)->data);
		buildTree((node)->lchild, ss);
		buildTree((node)->rchild, ss);
	}
}

// 递归-前序遍历
void traverse::
preOrderRecur(TreeNode* r) {
	if (r == NULL) return;
	printf("%c ",r->data);
	preOrderRecur(r->lchild);
	preOrderRecur(r->rchild);
}

// 递归-中序遍历
void traverse::
inOrderRecur(TreeNode* r) {
}

// 递归-后序遍历
void traverse::
postOrderRecur(TreeNode* r) {
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
	printf("postOrder\n");
}

// 层次遍历
void traverse::
levelTraversal(TreeNode* r) {

}

// "之"字形遍历
void traverse::
zhiTraversal(TreeNode* r) {

}

int main(){

	// test
	traverse t;
	std::string s("1#284#5!");
	TreeNode* root = NULL;
	t.buildTree(root, s);
	printf("start traverse.\n");
	t.preOrderRecur(root);

	printf("done\n");
	return 0;
}
