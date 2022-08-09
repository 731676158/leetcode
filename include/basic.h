#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "algorithms.h"

using namespace std;

class Basic {
public:

	/***************����������*********************/
	//�ǵݹ�
	//ǰ��
	/*vector<int> preOrder(TreeNode* root)
	{
		vector<int> res;
		stack<TreeNode*> stk;
		if (root == nullptr) return {};
		stk.push(root);
		while (!stk.empty())
		{
			root = stk.top();
			stk.pop();
			res.push_back(root->val);
			if (root->right) stk.push(root->right);
			if (root->left) stk.push(root->left);
		}
		return res;
	}*/
	//����
	//vector<int> inOrder(TreeNode* root)
	//{
	//	vector<int> res;
	//	stack<TreeNode*> stk;
	//	while (root != nullptr || !stk.empty())
	//	{
	//		while (root != nullptr)
	//		{
	//			stk.push(root);
	//			root = root->left;
	//		}
	//		root = stk.top();
	//		stk.pop();
	//		res.push_back(root->val);
	//		root = root->right;        //��������if (root->right)����������ΪĿ�ľ���Ϊ�����û���Һ��ӽڵ�Ļ���rootΪ�գ��´�ѭ������ֱ�ӷ���ջ���ڵ�
 // 		}
	//	return res;
	//}
	//����
	/*vector<int> postOrder(TreeNode* root)
	{
		vector<int> res;
		stack<TreeNode*> stk;
		TreeNode* pre = root;
		while (root != nullptr || !stk.empty())
		{
			while (root != nullptr)
			{
				stk.push(root);
				root = root->left;
			}
			root = stk.top();
			if (root->right!=nullptr&&pre!=root->right)
			{
				root = root->right;
				continue;
			}
			else
			{
				res.push_back(root->val);
				pre = root;
				stk.pop();
				root = nullptr;
			}
		}
		return res;
	}*/
	//ͳһ����ǰ�к���
	//ǰ��
	vector<int> preOrder(TreeNode* root)
	{
		vector<int> res;
		stack<TreeNode*> stk;
		if (root == nullptr) return{};
		stk.push(root);
		while (!stk.empty())
		{
			root = stk.top();
			if (root != nullptr)
			{
				stk.pop();
				if (root->right) stk.push(root->right);
				if (root->left) stk.push(root->left);
				stk.push(root);
				stk.push(nullptr);
			}
			else
			{
				stk.pop();
				root = stk.top();
				stk.pop();
				res.push_back(root->val);
			}
		}
		return res;
	}
	//����
	vector<int> inOrder(TreeNode* root)
	{
		vector<int> res;
		stack<TreeNode*> stk;
		if (root) stk.push(root);
		while (!stk.empty())
		{
			root = stk.top();
			if (root != nullptr)
			{
				stk.pop();
				if (root->right) stk.push(root->right);
				stk.push(root);
				stk.push(nullptr);
				if (root->left) stk.push(root->left);
			}
			else
			{
				stk.pop();
				root = stk.top();
				stk.pop();
				res.push_back(root->val);
			}
		}
		return res;
	}
	//����
	vector<int> postOrder(TreeNode* root)
	{
		vector<int> res;
		stack<TreeNode*> stk;
		if (root) stk.push(root);
		while (!stk.empty())
		{
			root = stk.top();
			if (root != nullptr)
			{
				stk.push(nullptr);
				if (root->right) stk.push(root->right);
				if (root->left) stk.push(root->left);
			}
			else
			{
				stk.pop();
				root = stk.top();
				stk.pop();
				res.push_back(root->val);
			}
		}
		return res;
	}

	//BFS����
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> res;
		queue<TreeNode*> que;
		if (root) que.push(root);
		while (!que.empty())
		{
			vector<int> r1;
			int size = que.size();
			for (int i = 0; i < size; ++i)
			{
				root = que.front();
				r1.push_back(root->val);
				que.pop();
				if (root->right) que.push(root->right);
				if (root->left) que.push(root->left);
			}
			res.push_back(r1);
		}
		return res;
	}


	int pack_prob_01(vector<int>& value,vector<int>& weight,int bagweight)
	{
		vector<vector<int>> res(weight.size(), vector<int>(bagweight + 1, 0));
		for (int i = 0; i < weight.size(); ++i)
		{
			for (int j = 0; j <= bagweight; ++j)
			{
				if (i == 0)
				{
					if (j >= weight[0])
					{
						res[0][j] = value[0];
					}
				}
				else if (j < weight[i])
				{
					res[i][j] = res[i - 1][j];
				}
				else
				{
					//res[j - weight[i]]������ǰһ����Ʒ�Ŀ������£���˳���ڳ��㹻�Ŀռ�������Ʒ�Ž�ȥ���ڵ�ʱ����ܰ���һ���Լ�Ҳ�ڳ�ȥ��Ҳ���ܰ��Ϻü������ڳ�ȥ
					res[i][j] = max(res[i - 1][j], res[i - 1][j - weight[i]] + value[i]);
				}
			}
		}
		return res[weight.size() - 1][bagweight];
	}
	int pack_prob_01_compression(vector<int>& value, vector<int>& weight, int bagweight)
	{
		vector<int> res(bagweight + 1, 0);
		for (int i = 0; i < weight.size(); ++i)
		{
			for (int j = bagweight; j < 0; --j)
			{
				if (i == 0)
				{
					if (j >= weight[0]) res[j] = value[0];
				}
				else
				{

					//res[j - weight[i]]
					if (j >= weight[i]) res[j] = max(res[j], res[j - weight[i]] + value[i]);
				}
			}
		}
		return res[bagweight];
	}


	void bubbleSort(vector<int>& vec)
	{
		for (int i = 0; i < vec.size(); ++i)
		{
			for (int j = 0; j < (vec.size() - i - 1); ++j)
			{
				if (vec[j] > vec[j + 1])
				{
					swap(vec[j], vec[j + 1]);
				}
			}
		}
	}
};