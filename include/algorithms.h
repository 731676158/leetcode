#pragma once
#include <time.h>
#include <limits.h>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	
};

class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution
{
public:
	// 1 
	vector<int> twoSum(vector<int>& nums, int target) {
		//���ù�ϣ����ֱ�������Ƿ����target-sum��Ԫ��
		unordered_map<int, int> hashtable;
		vector<int> res(2);
		for (int i=0;i<nums.size();i++)
		{
			if (hashtable.find(target - nums[i]) != hashtable.end())
			{
				res[0] = hashtable[target - nums[i]];
				res[1] = i;
				break;
			}
			else
			{
				hashtable[nums[i]] = i;
			}
		}
		return res;
	}
	//22 ��������
	string s;
	vector<string> vs;
	vector<string> generateParenthesis(int n) {
		stringTraceBack(n, 0, 0);
		return vs;
	}
	void stringTraceBack(int n, int left, int right)
	{
		if (left == n)
		{
			string r = fillString(s, n);
			vs.push_back(r);
			return;
		}
		s.push_back('(');
		stringTraceBack(n, left + 1, right);
		s.pop_back();//pop�Ŀ�����һ�������ţ�
		if (right < left)
		{
			s.push_back(')');
			stringTraceBack(n, left, right + 1);//����γ���ѭ����
			s.pop_back();//������һ�䣬�Ϳ��Ա�֤���Ե�pop��Ӧ���Ǹ��Ե�����
		}
	}
	string fillString(string& s, int n)
	{
		string r = s;
		while (r.size() < (2 * n))
		{
			r.push_back(')');
		}
		return r;
	}
	//34
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res{ -1,-1 };
		int l = 0;
		int r = nums.size() - 1;
		int mid = 0;
		//���Ȳ������
		while (l <= r)
		{
			mid = l + (r - l) / 2;
			if (nums[mid] == target)
			{
				res[0] = mid;
				r = mid - 1;
			}
			else if (nums[mid] < target)
			{
				l = mid + 1;
			}
			else if (nums[mid] > target)
			{
				r = mid - 1;
			}
		}
		r = nums.size() - 1;
		while (res[0] != -1 && l <= r)
		{
			mid = l + (r - l) / 2;
			if (nums[mid] == target)
			{
				res[1] = mid;
				l = mid + 1;
			}
			else if (nums[mid] < target)
			{
				l = mid + 1;
			}
			else if (nums[mid] > target)
			{
				r = mid - 1;
			}
		}
		return res;
	}

	//35 ��������λ��
	int searchInsert(vector<int>& nums, int target) {
		int l = 0;
		int r = nums.size() - 1;
		int mid = 0;
		while (l <= r)
		{
			mid = l + (r - l) / 2;
			if (nums[mid] == target) return mid;
			else if (nums[mid] > target) r = mid - 1;
			else if (nums[mid] < target)
			{
				if ((mid + 1) == nums.size() || nums[mid + 1] > target)  //��ֹ����Խ��
				{
					return mid + 1;
				}
				l = mid + 1;
			}
		}
		return 0;
	}

	//45
	int jump(vector<int>& nums) {
		int jmp = 0;
		int len = 0;
		int thislen = 0;
		int i = 0;
		while (i < nums.size())
		{
			thislen = max(thislen, i + nums[i]);
			if (len == i)  //������len>i>=(nums.size()-1)������ˣ���Ϊ��ѭ�������һ��Ȼ�󷵻����յ�jmp
			{
				if (i != nums.size() - 1)
				{
					++jmp;
					len = thislen;
					//if (len >= nums.size() - 1) break;//���������һ�䣬���ܻ����
				}
				else break;
			}
			++i;
		}
		return jmp;
	}

	//46
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		permuteTraceBack(res, nums, 0);
		return res;
	}
	void permuteTraceBack(vector<vector<int>>& res, vector<int>& nums, int pos)
	{
		if (pos == (nums.size() - 1))
		{
			res.push_back(nums);
			return;
		}
		int j = pos + 1;
		while (j < nums.size())
		{
			swap(nums[pos], nums[j]);
			res.push_back(nums);
			permuteTraceBack(res, nums, pos + 1);
			swap(nums[pos], nums[j]);
			++j;
		}
		permuteTraceBack(res, nums, pos + 1);
	}

	//53 ����������
	/*int maxSubArray(vector<int>& nums) {
		return getMaxSubArray(nums, 0, nums.size() - 1).msum;
	}
	struct sums
	{
		int allsum;
		int lsum;
		int rsum;
		int msum;
	};
	sums getMaxSubArray(vector<int>& nums, int l, int r)
	{
		if (l == r)
		{
			sums a{ nums[l],nums[l],nums[l],nums[l] };
			return a;
		}
		int mid = (r + l) / 2;
		sums leftMax = getMaxSubArray(nums, l, mid);
		sums rightMax = getMaxSubArray(nums, mid + 1, r);
		sums res = combineSums(leftMax, rightMax);
		return res;
	}
	sums combineSums(sums& s1, sums& s2)
	{
		sums res;
		res.allsum = s1.allsum + s2.allsum;
		res.lsum = max(s1.lsum, s1.allsum + s2.lsum);
		res.rsum = max(s2.rsum, s2.allsum + s1.rsum);
		res.msum = max(max(s1.msum, s2.msum), s1.rsum + s2.lsum);
		return res;
	}*/
	//̰�ķ�
	// int maxSubArray(vector<int>& nums)
	// {
	// 	int res = INT_MIN;
	// 	int count = 0;
	// 	for (int i = 0; i < nums.size(); ++i)
	// 	{
	// 		count += nums[i];
	// 		if (count > res) res = count;
	// 		if (count < 0)
	// 		{
	// 			count = 0;
	// 		}
	// 	}
	// 	return res;
	// }
	//动态规划
	// int maxSubArray(vector<int>& nums) {
	// 	if (nums.size()==1) return nums[0];
    //     vector<int> dp(nums.size(),0);
	// 	dp[0]=nums[0];
	// 	int result=nums[0];
	// 	for(int i=1;i<nums.size();++i) {
	// 		dp[i]=max(dp[i-1]+nums[i],nums[i]);
	// 		result=(result<dp[i])?dp[i]:result;
	// 	}
	// 	return result;
    // }

	//55
	bool canJump(vector<int>& nums) {
		int len = nums[0];
		for (int i = 0; i < nums.size(); ++i)
		{
			if (i > len) return false;
			if ((i + nums[i]) > len) len = i + nums[i];
			if (len >= nums.size()) return true;
		}
		return false;
	}

	//63
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		vector<vector<int>> dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),0));
		return uniquePathsWithObstaclesRec(obstacleGrid, dp, obstacleGrid.size() - 1, obstacleGrid[0].size() - 1);
	}
	int uniquePathsWithObstaclesRec(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp, int m, int n)
	{
		if (m < 0 || n < 0 || obstacleGrid[m][n] == 1) return 0;
		else if (m == 0 && n == 0)
		{
			dp[0][0] = ~obstacleGrid[m][n];
			return ~obstacleGrid[m][n];
		}

		int up = 0;
		int left = 0;

		if ((m - 1) >= 0 && dp[m - 1][n] != 0)
		{
			up = dp[m - 1][n];
		}
		else up = uniquePathsWithObstaclesRec(obstacleGrid, dp, m - 1, n);
		if ((n - 1) >= 0 && dp[m][n - 1] != 0)
		{
			left = dp[m][n - 1];
		}
		else left = uniquePathsWithObstaclesRec(obstacleGrid, dp, m, n - 1);
		
		dp[m][n] = left + up;
		return dp[m][n];
	}

	//64
	int uniquePaths(int m, int n) {
		vector<vector<int>> pathres(m, vector<int>(n));
		return uniquePathsRecur(pathres, m - 1, n - 1);
	}
	//��ͨ����ݹ�
	int uniquePathsRecur(vector<vector<int>>& pathres, int m, int n)
	{
		if (m == 0 || n == 0)
		{
			pathres[m][n] = 1;
			return 1;
		}
		int resm = (pathres[m][n - 1] == 0) ? uniquePathsRecur(pathres, m, n - 1) : pathres[m][n - 1];
		int resn = (pathres[m - 1][n] == 0) ? uniquePathsRecur(pathres, m - 1, n) : pathres[m - 1][n];
		pathres[m][n] = resm + resn;
		return resm+resn;
	}

	//69
	int mySqrt(int x) {
		int l = 0;
		int r = x;
		int mid = 0;
		while (l <= r)
		{
			mid = l + (r - l) / 2;
			if (mid * mid == x || (mid * mid<x && (mid + 1) * (mid + 1)>x)) return mid;
			else if (mid * mid < x) l = mid + 1;
			else if (mid * mid > x) r = mid - 1;
		}
		return l;
		
	}

	//70
	//int climbStairs(int n) {
	//	//����ͨ��쳲��������еݹ鷽��
	//	/*if (n == 1) return 1;
	//	else if (n == 2) return 2;
	//	return climbStairs(n - 1) + climbStairs(n - 2);*/
	//	//���ӱ�����
	//	int r1 = 1;
	//	int r2 = 2;
	//	int r3 = r1;
	//	if (n == 2) r3 = r2;
	//	for (; n >= 3; --n)
	//	{
	//		r3 = r1 + r2;
	//		r1 = r2;
	//		r2 = r3;
	//	}
	//	return r3;
	//}

	//����
	int climbStairs(int n) {

		/*
		* �����Ҫ���߼������Ե���¥��
			�����ڷ��߹��Ĳ���
			res[j]=min(res[j],res[j-value[i]]+1);
		
		*/
		vector<int> res(n + 1, 0);
		res[0] = 1;
		for (int i = 0; i <= n; ++i)
		{
			//���Ҫ���߼������Ե���¥��
			/*if (i >= 1) res[i] = res[i - 1] + 1;
			if (i >= 2) res[i] = min(res[i], res[i - 2] + 1);*/
			//�󷽰���
			if (i >= 1) res[i] += res[i - 1];
			if (i >= 2) res[i] += res[i - 2];
		}
		return res[n];
	}


	//74 ������ά����
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		//���ֲ��ҷ�
		//int hei = matrix.size();
		//int wid = matrix[0].size();
		//if (matrix.empty() || matrix[0].empty()) return false;
		////
		//pair<int, int> lco{ 0,0 };
		//pair<int, int> rco{ hei - 1,wid - 1 };
		//pair<int, int> mid{ 0,0 };
		//while (lco.first < rco.first || (lco.first == rco.first && lco.second <= rco.second))
		//{
		//	mid.first = (((rco.first * wid + rco.second) + (lco.first * wid + lco.second)) / 2) / wid;
		//	mid.second = (((rco.first * wid + rco.second) + (lco.first * wid + lco.second)) / 2) % wid;
		//	if (matrix[mid.first][mid.second] == target)
		//		return true;
		//	else if (matrix[mid.first][mid.second] < target)
		//	{
		//		lco = mid;
		//		if (lco.second == (wid - 1))
		//		{
		//			lco.second = 0;
		//			++lco.first;
		//		}
		//		else
		//		{
		//			++lco.second;
		//		}
		//	}
		//	else if (matrix[mid.first][mid.second] > target)
		//	{
		//		rco = mid;
		//		if (rco.second == 0)
		//		{
		//			rco.second = (wid - 1);
		//			--rco.first;
		//		}
		//		else
		//		{
		//			--rco.second;
		//		}
		//	}
		//}
		//return false;

		//����������
		/*if (matrix.empty()) return false;
		pair<int, int> head;
		head.first = 0;
		head.second = matrix[0].size() - 1;
		while (head.first < matrix.size() && head.second >= 0)
		{
			if (matrix[head.first][head.second] == target) return true;
			else if (matrix[head.first][head.second] < target)
			{
				++head.first;
			}
			else if (matrix[head.first][head.second] > target)
			{
				--head.second;
			}
		}
		return false;*/

		//���в��ҷ�  ����  [[1]] 0
		/*if (matrix.empty()) return false;
		pair<int, int> pos{ 0,0};
		
		while (pos.first<matrix.size())
		{
			if (matrix[pos.first][0] > target) return false;
			else if ((pos.first + 1) >= matrix.size() || matrix[pos.first + 1][0] > target) break;
			else ++pos.first;
		}
		while (pos.second < matrix[0].size())
		{
			if (matrix[pos.first][pos.second] > target) return false;
			else if (matrix[pos.first][pos.second] == target) return true;
			else ++pos.second;
		}
		return false;*/

		//�������в��ҷ�
		if (matrix.empty()) return false;
		pair<int, int> pos{ 0,0 };
		int l = 0;
		int r = matrix.size() - 1;
		int mid = 0;
		while (l <= r)
		{
			mid = (l + r) / 2;
			if (matrix[mid][0] <= target && ((mid + 1) >= matrix.size() || matrix[mid + 1][0] > target))
			{
				pos.first = mid;
				l = 0;
				r = matrix[0].size() - 1;
				while (l <= r)
				{
					mid = (l + r) / 2;
					if (matrix[pos.first][mid] == target) return true;
					else if (matrix[pos.first][mid] > target) r = mid - 1;
					else if (matrix[pos.first][mid] < target) l = mid + 1;
				}
				return false;
			}
			else if (matrix[mid][0] > target)  //��ʵû��Ҫ��(mid - 1) >= 0����Ϊ��������Ѿ���������l<=r��
			{
				r = mid - 1;
			}
			else if ((mid + 1) < matrix.size() && matrix[mid + 1][0] <= target)  
			{
				l = mid + 1;
			}
		}
		return false;
	}

	//77
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		vector<int> path;
		combineTraceBack(res, path, n, k, 1);
		return res;
	}
	void combineTraceBack(vector<vector<int>>& res, vector<int>& path, int n, int k, int pos)
	{
		if (path.size() == k)
		{
			res.push_back(path);
			return;
		}
		if (pos > n) return;
		path.push_back(pos);
		combineTraceBack(res, path, n, k, pos + 1);
		path.pop_back();
		combineTraceBack(res, path, n, k, pos + 1);
	}

	//78 �Ӽ�
	//�ݹ鷽ʽ
	vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<vector<int>> res;
		vector<int> path;
		myTraceBack(res, nums, path, 0);
		return res;
	}
	//�ٷ��� �ݹ�
	// vector<int> v;
	//vector<vector<int>> vs;
	//void traceBack(vector<int>& nums, int n)
	//{
	//	if (n == nums.size())
	//	{
	//		vs.push_back(v);
	//		return;
	//	}
	//	v.push_back(nums[n]);
	//	traceBack(nums, n + 1);//����൱�ڵ�һ�γ���
	//	v.pop_back();
	//	traceBack(nums, n + 1);//pop��ȥ֮������൱�ڶ���һ��Ԫ�ؽ��г���
	//}
	void myTraceBack(vector<vector<int>>& res, vector<int>& nums, vector<int> p, int start)
	{
		if (start == nums.size()) return;
		//������+����
		while (start < nums.size())  //����ʹ�ô��ڵ�����Ϊ�˷����һ��Ԫ�ؽ�p֮���л��������һ�ݹ��traceback,Ȼ����if�������أ�������ŵĻ������һ��Ԫ����Զ���ֲ�����
		{
			p.push_back(nums[start]);
			//�����������˳��һ��ע�⣬��Ȼʹ�������÷�ʽ������p��Ԫ���Ǵ��������ģ����ֻ����traceback����֮ǰpush
			res.push_back(p);
			myTraceBack(res, nums, p, ++start);

			p.pop_back();
		}
	}
	//�Լ�д��
	/*vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> path;
		res.push_back(path);
		for (int i = 0; i < nums.size(); ++i)
		{
			traceBack(res, nums, path, i);
		}
		return res;
	}
	void traceBack(vector<vector<int>>& res, vector<int>& nums, vector<int> p, int start)
	{
		if (start == nums.size()) return;
		p.push_back(nums[start]);
		res.push_back(p);
		++start;
		while (start != nums.size())
		{
			traceBack(res, nums, p, start);
			++start;
		}
		return;
	}*/
	//90
	//vector<int> v;
	//vector<vector<int>> vs;
	//vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	//	sort(nums.begin(), nums.end());
	//	traceBackWithDup(false, nums, 0);
	//	return vs;
	//}
	//void traceBackWithDup(bool dup, vector<int>& nums, int start)
	//{
	//	if (start == nums.size())
	//	{
	//		vs.push_back(v);
	//		return;
	//	}
	//	v.push_back(nums[start]);
	//	traceBackWithDup(false, nums, ++start);//��ȱ���//Ϊ�������ʹ��start���������++��������start+1
	//	v.pop_back();
	//	//Ӧ���ҵ���һ�����ظ�Ԫ���ٵݹ飬���´������� 2223�У�startָ���һ��2ʱ��������start+1û���жϵ�3���˳���
	//	/*if (!((start + 1) < nums.size() && nums[start] == nums[start + 1]))
	//	{
	//		traceBackWithDup(true, nums, start + 1);
	//	}*/
	//	while (start < nums.size() && nums[start - 1] == nums[start])
	//	{
	//		++start;
	//	}
	//	//����ѭ���������������һ�����Ѿ��������˲��ظ���Ԫ�أ���һ�����Ѿ�������������ĩβ��û�в��ظ���Ԫ�أ����������������ֱ�ӽ�����һ�εݹ飬�ڶ�����������һ�������󷵻أ���һ�����������ݹ�
	//	traceBackWithDup(true, nums, start);
	//}
	
	//�ٷ���
	vector<int> t;
	vector<vector<int>> ans;
	void dfs(bool choosePre, int cur, vector<int>& nums) {
		if (cur == nums.size()) {
			ans.push_back(t);
			return;
		}
		dfs(false, cur + 1, nums);
		if (!choosePre && cur > 0 && nums[cur - 1] == nums[cur]) {
			return;
		}
		t.push_back(nums[cur]);
		dfs(true, cur + 1, nums);
		t.pop_back();
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		dfs(false, 0, nums);
		return ans;
	}

	//100
	//����
	/*bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr) return true;
		else if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)) return false;
		else if (p->val != q->val) return false;
		if (isSameTree(p->left, q->left) && isSameTree(q->right, p->right)) return true;
		else return false;
	}*/
	//�ݹ�
	bool isSameTree(TreeNode* p, TreeNode* q) {
		stack<TreeNode*> stk;
		stk.push(p);
		stk.push(q);
		while (!stk.empty())
		{
			q = stk.top();
			stk.pop();
			p = stk.top();
			stk.pop();
			if (p == nullptr && q == nullptr) continue;
			else if (p == nullptr || q == nullptr || q->val != p->val) return false;
			stk.push(p->left);
			stk.push(q->left);
			stk.push(p->right);
			stk.push(q->right);
		}
		return true;
	}

	//101
	//������
	/*bool isSymmetric(TreeNode* root) {
		if (root == nullptr) return true;
 		return isSymmetricRec(root->left, root->right);
	}
	bool isSymmetricRec(TreeNode* left, TreeNode* right)
	{
		if (left == nullptr && right == nullptr) return true;
		else if ((left != nullptr && right == nullptr) || (left == nullptr && right != nullptr)) return false;
		else if (left->val != right->val) return false;
		if (isSymmetricRec(left->right, right->left) && isSymmetricRec(left->left, right->right)) return true;
		else return false;
	}*/
	bool isSymmetric(TreeNode* root)
	{
		stack<TreeNode*> stk;
		stk.push(root->left);
		stk.push(root->right);
		while (!stk.empty())
		{
			TreeNode* lnode = stk.top();
			stk.pop();
			TreeNode* rnode = stk.top();
			stk.pop();
			if (lnode == nullptr && rnode == nullptr) continue;
			else if (lnode == nullptr || rnode == nullptr || lnode->val != rnode->val) return false;
			stk.push(lnode->left);
			stk.push(rnode->right);
			stk.push(lnode->right);
			stk.push(rnode->left);
		}
		return true;
	}

	//102
	vector<vector<int>> levelOrder(TreeNode* root) {
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

	//104
	
	int maxDepth(TreeNode* root) {
		//����ݹ�
		/*if (root == nullptr) return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;*/
		queue<TreeNode*> que;
		if (root != nullptr) que.push(root);
		int dep = 0;
		while (!que.empty())
		{
			int sz = que.size();
			++dep;
			for (; sz > 0; --sz)
			{
				root = que.front();
				que.pop();
				if (root->left) que.push(root->left);
				if (root->right) que.push(root->right);
			}
		}
		return dep;
	}

	//107
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		if (root == nullptr) return vector<vector<int>>();
		queue<TreeNode*> que;
		que.push(root);
		vector<vector<int>> res;
		levelOrderBottomRec(res, que);
		return res;
	}
	void levelOrderBottomRec(vector<vector<int>>& res, queue<TreeNode*>& q)
	{
		if (q.empty()) return;
		TreeNode* pnode;
		vector<int> levelres;
		int sz = q.size();
		for (int i = 0; i < sz; ++i)
		{
			pnode = q.front();
			q.pop();
			levelres.push_back(pnode->val);
			if (pnode->left != nullptr) q.push(pnode->left);
			if (pnode->right != nullptr) q.push(pnode->right);
		}
		levelOrderBottomRec(res, q);
		res.push_back(levelres);
	}

	//110
	bool isBalanced(TreeNode* root) {
		if (root == nullptr) return true;
		
		/*
			���������������������һ������ƽ��������ֱ�ӷ���false
			�������������߶�
			����߶Ȳ����1����false
			����߶Ȳ�С��1����true��
		*/

		if (!isBalanced(root->left) || !isBalanced(root->right)) return false;
		int leftdep = countmaxDepBlcd(root->left);
		int rightdep = countmaxDepBlcd(root->right);
		if (abs(leftdep - rightdep) > 1) return false;
		else return true;
	}
	int countmaxDepBlcd(TreeNode* root)
	{
		if (root == nullptr) return 0;
		else return max(countmaxDepBlcd(root->left), countmaxDepBlcd(root->right)) + 1;
	}
	

	//111
	/*int minDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		queue<TreeNode*> que;
		que.push(root);
		int size = 0;
		int minlevel = 0;
		while (!que.empty())
		{
			++minlevel;
			size = que.size();
			for (int i = 0; i < size; ++i)
			{
				root = que.front();
				que.pop();
				if (root->left == nullptr && root->right == nullptr) return minlevel;
				if (root->left != nullptr) que.push(root->left);
				if (root->right != nullptr) que.push(root->right);
			}
		}
		return minlevel;
	}*/
	//�ݹ�
	int minDepth(TreeNode* root)
	{
		if (root == nullptr) return 0;
		if (root->right == nullptr && root->left == nullptr) return 1;
		else if (root->left == nullptr) return minDepth(root->right) + 1;
		else if (root->right == nullptr) return minDepth(root->left) + 1;
		else return min(minDepth(root->left), minDepth(root->right)) + 1;
	}

	//112
	//�ݹ�
	bool hasPathSum(TreeNode* root, int targetSum)
	{
		return hasPathSumRec(root, 0, targetSum);
	}
	bool hasPathSumRec(TreeNode* nnode, int sum, int targetSum)
	{
		if (nnode == nullptr) return false;
		sum += nnode->val;
		if ((!nnode->left && !nnode->right) && sum == targetSum)return true;

		if (hasPathSumRec(nnode->left, sum, targetSum)) return true;
		if (hasPathSumRec(nnode->right, sum, targetSum)) return true;
		return false;
	}
	//����
	/*bool hasPathSum(TreeNode* root, int targetSum) {
		if (root == nullptr) return false;
		stack<pair<TreeNode*, int>> stk;
		stk.push({root,root->val});
		int res = 0;
		while (!stk.empty())
		{
			pair<TreeNode*, int> nnode = stk.top();
			stk.pop();
			if (nnode != pair<TreeNode*, int>{nullptr, 0})
			{
				if (nnode.first->right) stk.push({ nnode.first->right,nnode.second + nnode.first->right->val });
				if (nnode.first->left) stk.push({ nnode.first->left,nnode.second + nnode.first->left->val });
				stk.push(nnode);
				stk.push({ nullptr,0 });
			}
			else
			{
				nnode = stk.top();
				stk.pop();
				
				if ((nnode.first->left == nullptr && nnode.first->right == nullptr) && nnode.second == targetSum) return true;
			}
		}
		return false;
	}*/

	//113
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		vector<vector<int>> res;
		pathSumRec(res, vector<int>(), root, 0, targetSum);
		return res;
	}
	void pathSumRec(vector<vector<int>>& res, vector<int> path, TreeNode* nnode, int sum, int targetSum)
	{
		if (nnode == nullptr) return;
		sum += nnode->val;
		path.push_back(nnode->val);
		if ((!nnode->left&&!nnode->right)&&sum == targetSum)
		{
			res.push_back(path);
			return;
		}

		pathSumRec(res, path, nnode->left, sum, targetSum);
		pathSumRec(res, path, nnode->right, sum, targetSum);
		return;
	}

	//121
	int maxProfit(vector<int>& prices) {
		vector<int> buy(prices.size());
		vector<int> sell(prices.size());
		buy[0] = -prices[0];
		int i = 1;
		for (; i < prices.size(); ++i)
		{
			buy[i] = max(buy[i - 1], 0 - prices[i]);  ///��ʵ����������Сֵ
			sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
		}
		return sell.back();
	}
	
	//122
	int maxProfit2(vector<int>& prices) {
		int res = 0;
		int i = 1;
		while (i < prices.size())
		{
			if ((prices[i] - prices[i - 1]) > 0)
			{
				res += (prices[i] - prices[i - 1]);
			}
			++i;
		}
		return res;
	}

	//139
	/*
	* �����ڴ�ŵģ�true/false
	* �ַ�������Ϊiʱ���Ƿ����װ���ַ���
	* ����ʽ��
	*	res[i]=res[i]||(res[i-str[j].size()]&&comp(s[i-str[j].size()],s[i],str[j]));
	* ��ʼ����
	*	res[0]=true;����Ϊfalse
	*/
	bool wordBreak(string s, vector<string>& wordDict) {
		vector<bool> res(s.size() + 1, false);
		for (int i = 0; i <= s.size(); ++i)
		{
			for (int j = 0; j < wordDict.size(); ++j)
			{
				if (i >= wordDict[j].size())
				{
					res[i] = res[i] || (res[i - wordDict[j].size()] && compStrwithDic(s, i - wordDict[j].size() + 1, i + 1, wordDict[j]));
				}
			}
		}
		return res[s.size()];
	}
	bool compStrwithDic(string& s, int begin, int end, string& dic)
	{
		if ((end - begin) != dic.size()) return false;
		for (int i = 0; i < (end - begin); ++i)
		{
			if (s[begin + i] != dic[i]) return false;
		}
		return true;
	}

	//141 ��������
	//����ָ�뷽��
	/*bool hasCycle(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return false;
		ListNode* snode = head;
		ListNode* fnode = head->next;
		while (fnode!=snode)
		{
			if (fnode->next == nullptr|| fnode->next->next == nullptr) return false;
			snode = snode->next;
			fnode = fnode->next->next;
		}
		return true;
	}*/
	//��ϣ������
	bool hasCycle(ListNode* head)
	{
		if (head == nullptr) return false;
		unordered_set<ListNode*>  hash;
		while (hash.count(head))
		{
			hash.insert(head);
			if (head->next == nullptr) return false;
			head = head->next;
		}
		return true;
	}
	//142
	ListNode* detectCycle(ListNode* head) {
		if (head == nullptr) return nullptr;
		if (head->next == nullptr) return nullptr;
		//�������ָ���ȷ���
		ListNode* slow = head;
		ListNode* fast = head;
		char flag = 0;
		while (flag == 0 || slow != fast)
		{
			flag = 1;
			if (fast == nullptr) return nullptr;

			slow = slow->next;
			if (fast->next == nullptr) return nullptr;
			else fast = fast->next->next;
		}
		slow = head;
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}

	//162 Ѱ�ҷ�ֵ
	int findPeakElement(vector<int>& nums) {
		//int n = nums.size();
		//if (n == 1) return 0;

		//// �������������
		//if (nums[0] > nums[1]) return 0;
		//if (nums[n - 1] > nums[n - 2]) return n - 1;

		//int l = 0, r = n - 1;
		//while (l <= r) {
		//	int mid = (l + r) / 2;

		//	// ��ǰΪ��ֵ
		//	if (mid >= 1 && mid < n - 1 && nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
		//		return mid;
		//	}
		//	else if (mid >= 1 && nums[mid] < nums[mid - 1]) {
		//		// ��ֵ�� mid ���
		//		r = mid - 1;
		//	}
		//	else if (mid < n - 1 && nums[mid] < nums[mid + 1]) {
		//		// ��ֵ�� mid �Ҳ�
		//		l = mid + 1;
		//	}
		//}
		//return -1;

		
		if (nums.size() == 1) return 0;
		if (nums[1] < nums[0]) return 0;
		if (nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1;
		int l = 0;
		int r = nums.size() - 1;
		return findPeakRecursively(nums, l, r);
	}
	int findPeakRecursively(vector<int>& nums, int l, int r)
	{
		if (l > r) return 0;
		int mid = l + (r - l) / 2;
		int res = 0;

		if (mid > 0 && mid < nums.size() - 1 && nums[mid - 1]<nums[mid] && nums[mid]>nums[mid + 1])
		{
			return mid;
		}
		else if (mid > 0 && nums[mid - 1] > nums[mid])//��ֵһ�������
		{
			res = findPeakRecursively(nums, l, mid - 1);
			if (res) return res;
		}
		else if (mid < nums.size() - 1 && nums[mid] < nums[mid + 1])
		{
			res = findPeakRecursively(nums, mid + 1, r);
			if (res) return res;
		}
		return -1;
	}
	//169 ����Ԫ��
	int majorityElement(vector<int>& nums) {
		return findMajority(nums, 0, nums.size() - 1);
	}
	int findMajority(vector<int>& nums, int l, int r)
	{
		if (l == r) return nums[l];
		int mid = (l + r) / 2;
		int leftMaj = findMajority(nums, l, mid);
		int rightMaj = findMajority(nums, mid + 1, r);
		if (countMaj(nums, leftMaj, l, r) > (r - l) / 2) return leftMaj;
		else if (countMaj(nums, rightMaj, l, r) > (r - l) / 2) return rightMaj;
		return -1;//������������ڣ�����������Ƕ�������������Ƕ���Ҳ�����������䣬���Կ��Է��Ĵ󵨵ط���-1
		
	}
	int countMaj(vector<int>& nums, int target, int l, int r)
	{
		int count = 0;
		for (; l <= r; l++)
		{
			if (nums[l] == target) ++count;
		}
		return count;
	}

	//198
	int rob(vector<int>& nums) {
		if (nums.size()==1) return nums[0];
		if (nums.size()==2) return max(nums[0],nums[1]);
		vector<int> dp(nums.size()+1, 0);
		dp[1] = nums[0];
		dp[2] = max(nums[0],nums[1]);
		for(int i = 3;i<=nums.size();++i) {
			dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
		}
		return dp[nums.size()];
	} 

	//200
	//�������
	//int numIslands(vector<vector<char>>& grid) {
	//	int res = 0;
	//	for (int i = 0; i < grid.size(); i++)
	//	{
	//		for (int j = 0; j < grid[0].size(); j++)
	//		{
	//			if (grid[i][j] == '1')
	//			{
	//				++res;
	//				isIsland(grid, i, j);
	//			}
	//		}
	//	}
	//	return res;
	//}
	//void isIsland(vector<vector<char>>& grid, int a1, int a2)
	//{
	//	if (a1 >= grid.size() || a2 >= grid[0].size())
	//	{
	//		return;
	//	}
	//	grid[a1][a2] = '0';

	//	if (a1 > 0 && grid[a1 - 1][a2] == '1') isIsland(grid, a1 - 1, a2);  //up  
	//	if (a2 > 0 && grid[a1][a2 - 1] == '1') isIsland(grid, a1, a2 - 1);  //left
	//	if (a1 < grid.size() - 1 && grid[a1 + 1][a2] == '1') isIsland(grid, a1 + 1, a2); //down
	//	if (a2 < grid[0].size() - 1 && grid[a1][a2 + 1] == '1') isIsland(grid, a1, a2 + 1);  //right
	//	return;
	//}
	//���鼯
	int numIslands(vector<vector<char>>& grid)
	{

	}

	//206 ��ת����
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}
		ListNode* newHead = reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;
		return newHead;
	}
	//209 ������С��������
	int minSubArrayLen(int target, vector<int>& nums) {
		if (nums.empty()) return 0;
		int l = 0; int r = 0;
		int sum = 0; int min_l = nums.size() + 1;
		while (r < nums.size())
		{
			sum += nums[r];
			while (sum >= target)
			{
				sum -= nums[l];
				min_l = min(min_l, r - l + 1);
				++l;
			}
			++r;
		}
		return (min_l == (nums.size() + 1)) ? 0 : min_l;

		//̫�����
		/*vector<int>::iterator it1 = nums.begin();
		vector<int>::iterator it2 = nums.begin();
		int len = 1;
		int sum = 0;
		int min = nums.size() + 1;
		while (it1 != (nums.end() - 1))
		{
			while (it2 != nums.end() && sum < target)
			{
				sum += (*it2);
				++it2;
				++len;
			}
			while (sum >= target)
			{
				sum -= (*it1);
				++it1;
				--len;
				min = (len < min) ? len : min;
			}
		}
		return (min == (nums.size() + 1)) ? 0 : min;*/
	}

	//213
	int rob2(vector<int>& nums) {
		if (nums.size()==1) return nums[0];
		if (nums.size()==2) return max(nums[0],nums[1]);
		vector<vector<int>> dp(2,vector<int>(nums.size()+1, 0));
		dp[0][1]=nums[0];
		dp[1][2]=nums[1];
		for(int i=0;i<2;++i) {
			for(int j = 2+i; j<=(nums.size() - 1 + i); ++j) {
				dp[i][j]=max(dp[i][j-1],dp[i][j-2]+nums[j-1]);
			}
		}
		return max(dp[0][nums.size()-1],dp[1][nums.size()]);
	}

	//215
	int findKthLargest(vector<int>& nums, int k) {
		//���η��鲢����
		vector<int> res = sortNums(nums, 0, nums.size() - 1);
		return res[k - 1];
	}
	//�鲢����
	vector<int> sortNums(vector<int>& nums, int l, int r)
	{
		if (l == r) return vector<int>{nums[l]};
		int mid = (l + r) / 2;
		vector<int> leftNums = sortNums(nums, l, mid);
		vector<int> rightNums = sortNums(nums, mid + 1, r);
		vector<int> res;
		int ll = 0;
		int rl = 0;
		while (!(ll >= leftNums.size() && rl >= rightNums.size()))
		{
			if ((ll < leftNums.size())&&(rl >= rightNums.size()|| (leftNums[ll] >= rightNums[rl])))  //��������¶���Ҫ����ߵ��������������ڲ�
			{
				res.push_back(leftNums[ll]);
				++ll;
			}
			else
			{
				res.push_back(rightNums[rl]);
				++rl;
			}
		}
		return res;
	}

	//221
	int maximalSquare(vector<vector<char>>& matrix) {
		char maxSquare = 0;
		vector<vector<char>> dp(matrix.size(), vector<char>(matrix[0].size(), 0));// matrix���Ƿ������������С��ʱ��Ҫע�⣡
		//���������и�ֵ
		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int j = 0; j < matrix[0].size(); ++j)
			{
				if (i == 0 || j == 0)
				{
					dp[i][j] = (matrix[i][j] == '0') ? 0 : 1;
					maxSquare = max(maxSquare, dp[i][j]);
				}
				else if (matrix[i][j] == '0')
				{
					dp[i][j] = 0;
				}
				else
				{
					dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
					maxSquare = max(maxSquare, dp[i][j]);
				}
			}
		}
		return maxSquare * maxSquare;
	}

	//222
	int countNodes(TreeNode* root) {
		/*if (root == nullptr) return 0;
		if (root->left == nullptr && root->right == nullptr) return 1;
		else if (root->left == nullptr) return countNodes(root->right) + 1;
		else if (root->right == nullptr) return countNodes(root->left) + 1;
		else return countNodes(root->left) + countNodes(root->right) + 1;*/
		//
		if (root == nullptr) return 0;
		int leftdep = 0;
		int rightdep = 0;
		TreeNode* leftnode = root->left;
		TreeNode* rightnode = root->right;
		while (leftnode)
		{
			leftnode = leftnode->left;
			++leftdep;
		}
		while (rightnode)
		{
			rightnode = rightnode->right;
			++rightdep;
		}
		if (leftdep == rightdep) return (2 << leftdep) - 1;
		else
		{
			return countNodes(root->left) + countNodes(root->right) + 1;
		}
	}

	//226  ��ת������
	//�ݹ�
	/*TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr) return nullptr;
		swap(root->left, root->right);
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}*/
	//�ݹ�����������Ҫע��ĵ㣺
	/*TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr) return nullptr;
		invertTree(root->left);
		swap(root->left, root->right);
		invertTree(root->left);
		return root;
	}*/
	//����
	/*TreeNode* invertTree(TreeNode* root)
	{
		stack<TreeNode*> stk;
		if (root != nullptr) stk.push(root);
		TreeNode* nnode = root;
		while (!stk.empty())
		{
			nnode = stk.top();
			stk.pop();
			if (nnode != nullptr)
			{
				if (nnode->right) stk.push(nnode->right);
				if (nnode->left) stk.push(nnode->left);
				stk.push(nnode);
				stk.push(nullptr);
			}
			else
			{
				nnode = stk.top();
				stk.pop();
				swap(nnode->left, nnode->right);
			}
		}
		return root;
	}*/
	//BFS
	TreeNode* invertTree(TreeNode* root)
	{
		queue<TreeNode*> que;
		if (root != nullptr) que.push(root);
		TreeNode* nnode = root;
		while (!que.empty())
		{
			int sz = que.size();
			for (int i = 0; i < sz; ++i)
			{
				nnode = que.front();
				que.pop();
				swap(nnode->left, nnode->right);
				if (nnode->left) que.push(nnode->left);
				if (nnode->right) que.push(nnode->right);
			}
		}
		return root;
	}

	//257
	//�ݹ�
	/*vector<string> binaryTreePaths(TreeNode* root) {
		if (root->left == nullptr && root->right == nullptr) return vector<string> {to_string(root->val)};
		if (root->left == nullptr)
		{
			vector<string> lft = binaryTreePaths(root->right);
			for (auto s : lft)
			{
				s = to_string(root->val) + string{ "->" } + s;
			}
			return lft;
		}
		else if (root->right == nullptr)
		{
			vector<string> rt = binaryTreePaths(root->left);
			for (auto t : rt)
			{
				t = to_string(root->val) + string{ "->" } + t;
			}
			return rt;
		}
		else
		{
			vector<string> lft = binaryTreePaths(root->right);
			vector<string> rt = binaryTreePaths(root->left);
			for (auto s : rt) lft.push_back(s);
			for(auto s:lft) s = to_string(root->val) + string{ "->" } + s;
			return lft;
		}
	}*/
	

	//279
	//�����������Ӷȹ���
	/*int numSquares(int n) {
		return numSquaresRec(n);
	}
	int numSquaresRec(int j)
	{
		if (j == 0) return 0;
		int minlen = INT_MAX;
		for (int i = 1; (i * i) <= j; ++i)
		{
			minlen = min(minlen, numSquaresRec(j - (i * i)));
		}
		return minlen + 1;
	}*/
	//������¼
	/*int numSquares(int n) {
		vector<int> res(n + 1);
		return numSquaresRec(res, n);
	}
	int numSquaresRec(vector<int>& res, int j)
	{
		if (j == 0) return 0;
		int minlen = INT_MAX;
		for (int i = 1; (i * i) <= j; ++i)
		{
			minlen = min(minlen, ((res[j - (i * i)] == 0) ? numSquaresRec(res, j - (i * i)) : res[j - (i * i)]));
		}
		res[j] = minlen + 1;
		return minlen + 1;
	}*/
	int numSquares(int n)
	{
		/*
		* �����ڴ��Ԫ�أ�Ҫ��������Ϊj�ı����ռ䣬������Ҫ������ȫƽ������
		* ����ʽ��
		*	res[j]=min(res[j],res[j-(i*i)]+1);
		* ��ʼ����
		*	res[0]=0;����Ķ�����Ϊһ����ֵ
		*/
		vector<int> res(n + 1, INT_MAX);
		res[0] = 0;
		for (int i = 0; i <= n; ++i)    //�ȱ�������
		{
			for (int j = 1; (j * j) <= n; ++j)        //�ٱ���Ԫ�أ�������ƽ��С��n����ȫƽ����
			{
				if (i >= (j * j))
				{
					res[i] = min(res[i], res[i - (j * j)] + 1);
				}
			}
		}
		return res[n];
	}
	
	//300
	int lengthOfLIs(vector<int>& nums) {
		if (nums.size()==1) return 1;
		vector<int> dp(nums.size(), 1);
		int result = 0;
		for(int i =1;i<nums.size();++i) {
			for(int j=0;j<i;++j) {
				if (nums[i]>nums[j]) dp[i] = max(dp[i], dp[j]+1);
			}
			if (dp[i]>result) result=dp[i];
		}
		return result;
	}

	//322
	int coinChange(vector<int>& coins, int amount) {
		/*
			�����ڴ�ŵ�Ԫ�أ��ճɽ��j����Ҫ�����ٵ�Ӳ�Ҹ�����
			����ʽ��
				�ճɽ��j��������ٵ�Ӳ�Ҹ���=min{�������¼��������ʱ�򣬴ճ�j����Ҫ�����ٵ�Ӳ������
											�����¼������������һöӲ��ǰ����Ҫ�����ٵ�Ӳ����+1}
			��ʼ����
				�ص��ǶԵ�һ�����ı�����ʼ��������dp[0]=0����Ϊ�ճ����Ϊ0��Ӳ�Ҹ���Ϊ0����Σ�jΪcoins[i]�ı�����ʱ��
		
		
		
		*/
		vector<int> res(amount + 1, (amount + 2));
		res[0] = 0;
		for (int i = 0; i < coins.size(); ++i)
		{
			for (int j = coins[i]; j <= amount; ++j)
			{
				res[j] = min(res[j], res[j - coins[i]] + 1);
			}
		}
		return (res[amount] == (amount + 2)) ? -1 : res[amount];
	}
	
	//337
	int rob(TreeNode* root) {
		// 迭代方法写二叉树遍历
		// stack<TreeNode*> stack;
		// if (!root) return 0;
		// else stack.emplace(root);
		// while(!stack.empty()) {
		// 	TreeNode* nnode = stack.top();
		// 	if (nnode!=nullptr) {
		// 		stack.emplace(nullptr);
		// 		if (nnode->right) stack.emplace(nnode->right);
		// 		if (nnode->left) stack.emplace(nnode->left);
		// 	} else {
		// 		stack.pop();
		// 		nnode=stack.top();
		// 		stack.pop();
		//      //一些处理
		// 	}
		// }

		// 递归
		vector<int> res = robRecursive(root);
		return max(res[0],res[1]);
	}
	vector<int> robRecursive(TreeNode* root) {
		if (root==nullptr) return {0, 0};
		vector<int> dp_l = robRecursive(root->left);
		vector<int> dp_r = robRecursive(root->right);
		vector<int> dp(2,0);
		dp[0] = max(dp_l[0],dp_l[1])+max(dp_r[0],dp_r[1]);
		dp[1] = root->val+dp_l[0]+dp_r[0];
		return dp;
	}

	//343
	int integerBreak(int n) {
		vector<int> dp(n + 1);
		return integerBreakRec(dp, n);
	}
	int integerBreakRec(vector<int>& dp, int n)
	{
		if (n == 2) return 1;

		int maxthis = 0;
		for (int i = 1; i < n; ++i)
		{
			if (dp[n - i] == 0)
			{
				maxthis = max(maxthis, max((i * (n - i)), (i * integerBreakRec(dp,n-i))));
			}
			else
			{
				maxthis = max(maxthis, max((i * (n - i)), (i * dp[n - i])));
			}
		}
		dp[n] = maxthis;
		return maxthis;
	}

	//344 ��ת�ַ���
	void reverseString(vector<char>& s) {
		int l = 0;
		int r = s.size() - 1;
		if (s.empty()) return;
		swapLeftRight(s, l, r);
	}
	void swapLeftRight(vector<char>& s, int l, int r)
	{
		if (l >= r) return;
		swapLeftRight(s, l + 1, r - 1);
		swap(s[l], s[r]);
		return;
	}

	//367
	bool isPerfectSquare(int num) {
		if (num == 1) return true;
		int l = 1;
		int r = num / 2;
		long long mid = 0;
		while (l <= r)
		{
			mid = l + (r - l) / 2;
			if (mid * mid == num) return true;
			else if (mid * mid < num) l = mid + 1;
			else if (mid * mid > num) r = mid - 1;
		}
		return false;
	}

	//376
	int wiggleMaxLength(vector<int>& nums) {
		int len = nums.size();
		int flag = 0;//��������½�
		for (int i = 0; i < nums.size(); ++i)
		{
			if (flag == -1)//�½�
			{
				if (nums[i] > nums[i - 1]) flag = 1;
				else
				{
					--len;
				}
			}
			else if (flag == 1) //����
			{
				if (nums[i] < nums[i - 1]) flag = -1;
				else
				{
					--len;
				}
			}
			else if (i > 0)
			{
				flag = (nums[i] > nums[i - 1]) ? 1 : (nums[i]<nums[i-1])?-1:(0,--len);
			}
		}
		return len;
	}

	//377
	int combinationSum4(vector<int>& nums, int target) {
		vector<int> res(target + 1, 0);
		res[0] = 1;
		for (int i = 0; i <= target; ++i)
		{
			for (int j = 0; j < nums.size(); ++j)
			{
				if (i >= nums[j])
				{
					res[i] += res[i - nums[j]];
				}
			}
		}
		return res[target];
	}

	//404
	int sumOfLeftLeaves(TreeNode* root) {
		stack<TreeNode*> stk;
		if (!root->left && !root->right) return 0;
		stk.push(root);
		int res = 0;
		while (!stk.empty())
		{
			root = stk.top();
			stk.pop();
			if (root != nullptr)
			{
				if (root->right) stk.push(root->right);
				if (root->left) stk.push(root->left);
				stk.push(root); stk.push(nullptr);
			}
			else
			{
				root = stk.top();
				stk.pop();
				//����
				if (root->left && (!root->left && !root->right))
				{
					res += root->left->val;
				}
			}
		}
		return res;
	}

	//416
	bool canPartition(vector<int>& nums) {
		int sum_all = 0;
		for (auto a : nums) sum_all += a;
		//return canParRec(nums, 0, 0, sum_all);

		//����
		if (sum_all % 2 == 1) return false;
		int tgt = sum_all / 2;
		vector<int> res(tgt + 1, 0);
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = tgt; j >= 0; --j)
			{
				if (i == 0)
				{
					if (j >= nums[i])
					{
						res[j] = nums[0];
					}
				}
				else
				{
					if (j >= nums[i])
					{
						res[j] = max(res[j], res[j - nums[i]] + nums[i]);
					}
				}
				if (res[tgt] == tgt) return true;
			}
		}
		return false;
	}
	//��ͨ���ݷ� ��ʱ
	bool canParRec(vector<int>& nums, int idx, int sum, int sum_all)
	{
		if (idx >= nums.size()) return false;
		int ts = nums[idx];
		sum += nums[idx];
		if ((sum * 2) == sum_all) return true;
		for(int i=1;i<(nums.size()-idx);++i)
		{
			if (canParRec(nums, idx + i, sum, sum_all)) return true;
		}
		if (canParRec(nums, idx + 1, sum - ts, sum_all)) return true;
		return false;
	}


	//455
	int findContentChildren(vector<int>& g, vector<int>& s) {
		if (s.size() == 0) return 0;
		sort(g.begin(), g.end()); sort(s.begin(), s.end());
		int res = 0;
		int cook = 0;
		for (int i = 0; i < g.size(); ++i)
		{
			while (cook < s.size() || s[cook] < g[i])
			{
				++cook;
			}
			if (cook = s.size()) return res;
			++res; ++cook;
		}
		return res;
	}

	//474
	int findMaxForm(vector<string>& strs, int m, int n) {
		vector<vector<int>> res(m + 1, vector<int>(n + 1, 0));
		for (int i = 0; i < strs.size(); ++i)
		{
			pair<int, int> p = countMNfromStr(strs[i]);
			//���㵹�������ά����
			for (int j = m; j >= 0; --j)
			{
				for (int k = n; k >= 0; --k)
				{
					if (i == 0)
					{
						if (j >= p.first && k >= p.second)
						{
							res[j][k] = 1;
						}
					}
					else
					{
						if (j >= p.first && k >= p.second)
						{
							res[j][k] = max(res[j][k], res[j - p.first][k - p.second] + 1);
						}
					}
				}
			}
		}
		return res[m][n];
	}
	pair<int, int> countMNfromStr(const string& s)
	{
		pair<int, int> p{ 0,0 };
		for (auto c : s)
		{
			if (c == '0') ++p.first;
			else if (c == '1') ++p.second;
		}
		return p;
	}

	//494
	/*****************************************************************************************************************************************************************************/
	int findTargetSumWays(vector<int>& nums, int target) {
		int sum = 0;
		for (auto s : nums)sum += s;
		if ((target + sum) % 2 == 1) return 0;
		if (abs(target) > sum) return 0;
		int tgt = (target + sum) / 2;
		vector<int> res(tgt + 1, 0);
		res[0] = 1;
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = tgt; j >= nums[i]; --j)  //���������nums[i]
			{
				res[j] += res[j - nums[i]];
			}
		}
		return res[tgt];
	}

	//509 
	/*int fib(int n) {
		if (n < 2)
		{
			return (n == 0) ? 0 : 1;
		}
		return fib(n - 1) + fib(n - 2);
	}*/
	
	//513
	int findBottomLeftValue(TreeNode* root) {
		queue<TreeNode*> que;
		que.push(root);
		int res = 0;
		while (!que.empty())
		{
			res = que.front()->val;
			int sz = que.size();
			for (; sz > 0; --sz)
			{
				root = que.front();
				que.pop();
				if (root->left) que.push(root->left);
				if (root->right) que.push(root->right);

			}
		}
		return res;
	}

	//518
	int change(int amount, vector<int>& coins) {
		
		vector<int> res(amount + 1, 0);
		res[0] = 1;
		for (int i = 0; i < coins.size(); ++i)
		{
			for (int j = coins[i]; j <= amount; ++j)
			{
				res[j] += res[j - coins[i]];
			}
		}
		return res[amount];
	}

	//572
	bool isSubtree(TreeNode* root, TreeNode* subRoot) {
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty())
		{
			int sz = que.size();
			for (; sz > 0; --sz)
			{
				root = que.front();
				que.pop();
				if ((root->val == subRoot->val) && isSubtreeItr(root, subRoot)) return true;
				if (root->left) que.push(root->left);
				if (root->right) que.push(root->right);
			}
		}
		return false;
	}
	bool isSubtreeItr(TreeNode* l, TreeNode* r)
	{
		queue<TreeNode*> que;
		que.push(l);
		que.push(r);
		while (!que.empty())
		{
			l = que.front();
			que.pop();
			r = que.front();
			que.pop();
			if (l == nullptr && r == nullptr) continue;
			else if (l == nullptr || r == nullptr || l->val != r->val) return false;
			que.push(l->left);
			que.push(r->left);
			que.push(l->right);
			que.push(r->right);
		}
		return true;
	}

	//559
	int maxDepth(Node* root) {
		//�ݹ�
		/*if (root == nullptr) return 0;
		int maxdep = 0;
		for (int i = 0; i < root->children.size(); ++i)
		{
			maxdep = max(maxdep, maxDepth(root->children[i]));
		}
		return maxdep + 1;*/
		//�ǵݹ�
		queue<Node*> que;
		if (root != nullptr) que.push(root);
		int dep = 0;
		while (!que.empty())
		{
			int sz = que.size();
			++dep;
			for (; sz > 0; --sz)
			{
				root = que.front();
				que.pop();
				for (int j = 0; j < root->children.size(); ++j)
				{
					if (root->children[j]) que.push(root->children[j]);
				}
			}
		}
		return dep;
	}

	//589 N����
	vector<int> preorder(Node* root) {
		stack<Node*> stk;
		if (root != nullptr) stk.push(root);
		vector<int> res;
		while (!stk.empty())
		{
			root = stk.top();
			stk.pop();
			if (root != nullptr)
			{
				for (int i = root->children.size() - 1; i >= 0; --i)
				{
					stk.push(root->children[i]);
				}
				stk.push(root);
				stk.push(nullptr);
			}
			else
			{
				root = stk.top();
				stk.pop();
				res.push_back(root->val);
			}
		}
		return res;
	}

	//590
	vector<int> postorder(Node* root) {
		stack<Node*> stk;
		if (root != nullptr) stk.push(root);
		vector<int> res;
		while (!stk.empty())
		{
			root = stk.top();
			stk.pop();
			if (root != nullptr)
			{
				stk.push(root);
				stk.push(nullptr);
				for (int i = root->children.size() - 1; i >= 0; --i)
				{
					stk.push(root->children[i]);
				}
			}
			else
			{
				root = stk.top();
				stk.pop();
				res.push_back(root->val);
			}
		}
		return res;
	}

	//674
	int findLengthOfLCIS(vector<int>& nums) {
		if (nums.size()==1) return 1;
		vector<int> dp(nums.size(), 1);
		int result=0;
		for(int i=1;i<nums.size();++i) {
			if (nums[i]>nums[i-1]) dp[i]=dp[i-1]+1;
			if (dp[i]>result) result=dp[i];
		}
		return result;
    }

	//704 ���ֲ���
	int search(vector<int>& nums, int target) {
		int l = 0;
		int r = nums.size() - 1;
		int mid = -1;
		while (l <= r)
		{
			mid = l + (r - l) / 2;
			if (nums[mid] == target)
			{
				return mid;
			}
			else if (nums[mid] > target)
			{
				r = mid - 1;
			}
			else if (nums[mid] < target)
			{
				l = mid + 1;
			}
			
		}
		return -1;


		//int l = 0;
		//int r = nums.size() - 1;
		//while (l <= r)
		//{
		//	//���������䷶Χ��
		//	if (nums[l] < target && target < nums[r])
		//	{
		//		if (nums[l + (r - l) / 2] > target)  //˵�����м��ǩ�����
		//		{
		//			r = l + (r - l) / 2;
		//		}
		//		else if (nums[l + (r - l) / 2] < target)
		//		{
		//			l += (r - l) / 2;
		//		}
		//		else return l + (r - l) / 2;
		//	}
		//	else if (target > nums[r] || target < nums[l])
		//	{
		//		return -1;
		//	}
		//	else
		//	{
		//		return (nums[l] == target) ? l : r;
		//	}
		//}
		//return -1;
	}

	//714
	int maxProfit5(vector<int>& prices, int fee) {
		vector<vector<int>> dp(prices.size(), vector<int> (2, 0));
		dp[0][0]=-prices[0];
		for(int i=1;i<prices.size();++i) {
			dp[i][0]=max(dp[i-1][0],dp[i-1][1]-prices[i]);
			dp[i][1]=max(dp[i-1][1], dp[i-1][0]+prices[i]-fee);
		}
		return dp[prices.size()-1][1];
	}

	//718
	int findLength(vector<int>& nums1, vector<int>& nums2) {
		vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));
		int result=0;
		for(int i=1;i<=nums1.size();++i) {
			for(int j=1;j<=nums2.size();++j) {
				if (nums1[i-1]==nums2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
				if (dp[i][j]>result) result=dp[i][j];
			}
		}
		return result;
    }

	//746
	int minCostClimbingStairs(vector<int>& cost) {
		mCCSdp.resize(cost.size() + 1);
		return minCostClimbingStairsRec(cost, cost.size());
	}
	vector<int> mCCSdp;
	int minCostClimbingStairsRec(vector<int>& cost, int i)
	{
		if (i < 0) return 0;
		else if (i == 0) return cost[0];
		else if (i == 1) return cost[1];
		
		int minl = 0;
		int minll = 0;

		if (i >= 1 && mCCSdp[i - 1]) minl = mCCSdp[i - 1];
		else minl = minCostClimbingStairsRec(cost, i - 1);

		if (i >= 2 && mCCSdp[i - 2]) minll = mCCSdp[i - 2];
		else minll = minCostClimbingStairsRec(cost, i - 2);

		if (i == cost.size()) mCCSdp[i] = min(minl, minll);
		else mCCSdp[i] = min(minl, minll) + cost[i];

		return mCCSdp[i];
	}


	//752
	int openLock(vector<string>& deadends, string target) {
		string start{ "0000" };
		if (start == target) return 0;
		queue<string> poss;
		int times = 0;
		poss.push(start);
		unordered_set<string> deads;
		unordered_set<string> visited;
		for (auto s : deadends)
		{
			deads.insert(s);
		}
		if (deads.count(start)) return -1;
		while (!poss.empty())
		{
			++times;
			int sz = poss.size();
			for (int i = 0; i < sz; ++i)
			{
				start = poss.front();
				poss.pop();
				if (visited.count(start))
				{
					if (poss.empty()) break;  //������еĽڵ㶼�ѷ��ʹ��������½ڵ�ɷ��ʣ������ѭ��
					else continue;    //���ʹ��˽ڵ㣬��������ѭ����ֱ�ӽ�����һ�֣�
				}
				visited.insert(start);
				for (int i = 0; i < 4; ++i)
				{
					string resp = upward(start, i);
					string resm = downward(start, i);
					if (resp == target || resm == target) return times;
					if (!(deads.count(resp) || visited.count(resp)))
					{
						poss.push(resp);
					}
					if (!(deads.count(resm) || visited.count(resm)))
					{
						poss.push(resm);
					}
				}
			}
		}
		return -1;
	}
	string upward(string& s, int pos)
	{
		string r = s;
		if (r[pos] == '9') r[pos] = '0';
		else ++r[pos];
		return r;
	}
	string downward(string& s, int pos)
	{
		string r = s;
		if (r[pos] == '0') r[pos] = '9';
		else --r[pos];
		return r;
	}


	//881 ����ͧ
	int numRescueBoats(vector<int>& people, int limit) {
		sort(people.begin(), people.end());
		int boats = 0;
		int left = 0;
		int right = people.size() - 1;
		while (left <= right)
		{
			if ((people[left] + people[right]) <= limit)
			{
				++left;
			}
			++boats;
			--right;
		}
		return boats;
	}

	//938
	//�ݹ�
	int rangeSumBST(TreeNode* root, int low, int high) {
		int res = recursivelySum(root, low, high);
		return res;
	}
	int recursivelySum(TreeNode* root, int low, int high)
	{
		if (root == nullptr)	return 0;
		int sumBST = 0;
		sumBST += recursivelySum(root->left, low, high);
		if (root->val >= low && root->val <= high)
		{
			sumBST += root->val;
		}
		sumBST += recursivelySum(root->right, low, high);
		return sumBST;
	}

	//1005
	//��õķ������ù�ϣ����
	int largestSumAfterKNegations(vector<int>& nums, int k) {
		int res = 0;
		for (; k >= 0; --k)
		{
			int min_index = 0;
			if (k == 0)
			{
				for (int i = 0; i < nums.size(); ++i) res += nums[i];
				break;
			}
			
			for (int i = 0; i < nums.size(); ++i)
			{
				min_index = (nums[min_index] > nums[i]) ? i : min_index;
			}
			nums[min_index] = -nums[min_index];
		}
		return res;
	}

	//1049
	int lastStoneWeightII(vector<int>& stones) {
		int sum = 0;
		for (auto s : stones) sum += s;
		int tgt = sum / 2;
		vector<int> res(tgt + 1, 0);
		for (int i = 0; i < stones.size(); ++i)
		{
			for (int j = tgt; j >= 0; --j)
			{
				if (i == 0)
				{
					if (j >= stones[i])
					{
						res[j] = stones[i];
					}
				}
				else
				{
					if (j >= stones[i])
					{
						res[j] = max(res[j], res[j - stones[i]] + stones[i]);
					}
				}
			}
		}
		return sum - 2 * (res[tgt]);
	}

	//1143
	int longestCommonSubsequence(string text1, string text2) {
		vector<vector<int>> dp(text1.size()+1, vector<int> (text2.size()+1,0));
		int result = 0;
		for(int i=1;i<=text1.size();++i) {
			for(int j=1;j<=text2.size();++j) {
				if (text1[i-1]==text2[j-1]) {
					dp[i][j]=dp[i-1][j-1]+1;
					if (dp[i][j]>result) result=dp[i][j];
				} else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
		return result;
    }

	//1456
	int maxVowels(string s, int k) {
		int max_len = 0;
		int len = 0;
		int l = 0;
		int r = 0;
		//�߳�һ����������
		do {
			if (s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u')
			{
				++len;
			}
			r++;
		} while (r < k);
		max_len = max(max_len, len);
		//��ʱl��r�ľ����Ѿ���Ϊ��k
		while (r < s.size())
		{
			if (s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u')
			{
				++len;
			}
			if (s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u')
			{
				--len;
			}
			max_len = max(max_len, len);
			++l;
			++r;
		}
		return max_len;
	}
};

//146
class LRUCache {
public:
	struct biListNode
	{
		int val, key;
		biListNode* prev;
		biListNode* next;
		biListNode():val(0),key(0), prev(nullptr), next(nullptr) {}
		biListNode(int x,int k) :val(x),key(k), prev(nullptr), next(nullptr) {}
		biListNode(int x,int k, biListNode* p,biListNode* n):val(x),key(k),prev(p),next(n){}
	};
	
	LRUCache(int capacity) {
		size = capacity;
		head = new biListNode();
		tail = new biListNode();
		head->next = tail;
		tail->prev = head;
	}

	int get(int key) {
		if (hashlist.find(key) == hashlist.end()) return -1;
		else
		{
			biListNode* nnode = hashlist[key];
			nnode->next->prev = nnode->prev;
			nnode->prev->next = nnode->next;
			head->next->prev = nnode;
			nnode->next = head->next;
			head->next = nnode;
			nnode->prev = head;
			return nnode->val;
		}
	}
	//Ҫ��ɹ����� ���ж��Ƿ��Ѿ����ڶ�Ӧ��ֵ������Ѿ����ھͽ���λ���ᵽͷ�����޸ļ�ֵ
	//��������ж��Ƿ񳬳�����������������������������������µĽڵ㵽��ͷ
	void put(int key, int value) {
		if (hashlist.find(key) != hashlist.end()) //�ҵ���
		{
			//�޸ļ�ֵ
			hashlist[key]->val = value;
			//���ڵ��ᵽ����
			biListNode* nnode = hashlist[key];
			nnode->prev->next = nnode->next;
			nnode->next->prev = nnode->prev;
			head->next->prev = nnode;
			nnode->next = head->next;
			head->next = nnode;
			nnode->prev = head;
		}
		else
		{
			if (hashlist.size() == size)   //û�ҵ�������Խ����
			{
				//�������
				hashlist.erase(hashlist.find(tail->prev->key));
				biListNode* nnode = tail->prev;
				tail->prev = tail->prev->prev;
				tail->prev->next = tail;
				delete nnode;
				nnode = nullptr;
			}
			//ֱ���ڶ��״����½ڵ�
			biListNode* nnode = new biListNode(value, key, head, head->next);
			head->next->prev = nnode;
			head->next = nnode;
			hashlist[key] = nnode;
		}
	}
public:
	int size = 0;
	biListNode* head;
	biListNode* tail;
	unordered_map<int, biListNode*> hashlist;
};