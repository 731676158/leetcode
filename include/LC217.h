#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <utility> //pair
#include <unordered_set>
#include <unordered_map>
#include "algorithms.h"
using namespace std;

//������
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};

class BinTree
{
public:
    void createTreefromint(vector<int>& vec)
    {
        queue<TreeNode*> que;
        //������ڵ� 
        TreeNode* nnode = new TreeNode(vec[0]);
        root = nnode;
        if (vec.size() == 1) return;
        que.push(nnode);
        for (int i = 1; i < vec.size(); i+=2)
        {
            nnode = que.front();
            que.pop();
            TreeNode* leftnode = new TreeNode(vec[i]);
            nnode->left = leftnode;
            que.push(leftnode);
            if ((i + 1) < vec.size())
            {
                TreeNode* rightnode = new TreeNode(vec[i + 1]);
                nnode->right = rightnode;
                que.push(rightnode);
            }
        }
    }
    void createTreefromstr(vector<string>& vec)
    {
        queue<TreeNode*> que;
        //������ڵ� 
        TreeNode* nnode = createTreeNode(vec[0]);
        TreeNode* prenode = nullptr;
        root = nnode;
        if (vec.size() == 1) return;
        que.push(nnode);
        for (int i = 1; i < vec.size(); ++i)
        {
            while (que.front() == nullptr)
            {
                que.pop();
            }
            nnode = que.front();


            TreeNode* lnode = createTreeNode(vec[i]);
            if (prenode != nnode)
            {
                nnode->left = lnode;
                que.push(lnode);
                prenode = nnode;
            }
            else
            {
                nnode->right = lnode;
                que.push(lnode);
                prenode = nullptr;
                que.pop();
            }
        }
    }
    TreeNode* createTreeNode(string& s)
    {
        if (s == "nullptr" || s == "null" || s == "NULL") return nullptr;
        return new TreeNode(atoi(s.c_str()));
    }
public:
    TreeNode* root;
};

void buildHeap(vector<int>& nums);
void deleteHeap(vector<int>& nums);

class Solution_L {
public:
    //94 �������
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        TreeNode* nnode = root;
        while(nnode != nullptr)
        {
            while (nnode->left != nullptr)
            {
                if (nnode->right != nullptr)
                {
                    stk.push(nnode->right);
                }
                stk.push(nnode);
                nnode = nnode->left;
            }
            res.push_back(nnode->val);

            //�ж�Ҷ�ӽڵ���ұ��Ƿ����Һ���
            if (nnode->right != nullptr)
            {
                nnode = nnode->right;
                continue;
            }
            else if (!stk.empty ())
            {
                do
                {
                    nnode = stk.top();
                    stk.pop();
                    res.push_back(nnode->val);
                    if (stk.empty()) break;
                } while (nnode->right == nullptr);
            }
            //�жϲ��ϵ����Ľڵ�����Ƿ����Һ���
            if (nnode->right != nullptr)
            {
                nnode = stk.top();
                stk.pop();
                continue;
            }
            else break;
        }
        return res;
    }
    //94 �� ������
    /*vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }*/

    //144 ǰ�����
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        TreeNode* nnode = root;
        do
        {
            if (nnode != nullptr)
            {
                res.push_back(nnode->val);
                //�ұ�
                if (nnode->right != nullptr)
                {
                    stk.push(nnode->right);
                }
                //���
                if (nnode->left != nullptr)
                {
                    nnode = nnode->left;
                }
                else if (!stk.empty())
                {
                    nnode = stk.top();
                    stk.pop();
                }
                else break;
            }
            else return res;
        }         while (true);
        return res;
    }

    //145 �������
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        TreeNode* nnode = root;
        TreeNode* prev = nullptr;
        while (nnode != nullptr || !stk.empty())
        {
            while (nnode != nullptr)
            {
                stk.push(nnode);
                nnode = nnode->left;
            }
            nnode = stk.top();
            stk.pop();
            
            if (nnode->right == nullptr || nnode->right == prev)
            {
                res.push_back(nnode->val);
                prev = nnode;
                nnode = nullptr;//��һ��ֱ���ߵ���һ��ѭ��while��ĩβ
            }
            else
            {
                stk.push(nnode);
                nnode = nnode->right;
            }
        }
        return res;
    }

    //�������
    vector<int> levelorderTraversal(TreeNode* root)
    {
        queue<TreeNode*> que;
        vector<int> res;
        if (root != nullptr) que.push(root);
        while (!que.empty())
        {
            int sz = que.size();
            for (; sz > 0; --sz)
            {
                root = que.front();
                que.pop();
                res.push_back(root->val);
                if (root->left) que.push(root->left);
                if (root->right) que.push(root->right);
            }
        }
        return res;
    }
    //215 
    int findKthLargest(vector<int>& nums, int k) {
        int res = 0;
        buildHeap(nums);
        for (; k > 0; k--)
        {
            res = nums[0];
            deleteHeap(nums);
        }
        return res;
    }

    //217
    bool containsDuplicate(vector<int>& nums) {
        //vector<int>::iterator it1, it2;
        //it1 = nums.begin();
        //it2 = nums.end();
        //unordered_set<int> hashcount(it1, it2);
        if (nums.empty()) return false;
        unordered_set<int> hashcount;
        for (auto num : nums)
        {
            if (hashcount.find(num) == hashcount.end())
            {
                hashcount.insert(num);
            }
            else
            {
                return true;
            }
        }
        return false;
    }
    //389
    char findTheDifference(string s, string t) {
        unordered_multiset<char> s_str(s.begin(), s.end());
        for (char ele : t)
        {
            
            unordered_multiset<char>::iterator it = s_str.find(ele);
            if (it == s_str.end())
            {
                return ele;
            }
            else
            {
                s_str.erase(it);
            }
        }
        return ' ';
    }
    //496
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> tab;
        unordered_map<int, int> hashtb;
        vector<int> res;
        for (int i = nums2.size() - 1; i >= 0; --i)
        {
            while (!tab.empty() && nums2[i] > tab.top())
            {
                tab.pop();
            }

/*            if (tab.empty() || nums2[i] < tab.top())
            {  */              
                hashtb[nums2[i]] = (tab.empty()) ? -1 : tab.top();
                tab.push(nums2[i]);
            //}
        }
        for (int ele : nums1)
        {
            res.push_back(hashtb[ele]);
        }
        return res;
    }
    //692
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> map;
        for (auto& w : words)
        {
            ++map[w];
        }
        //����С����
        //auto cmp = [](pair<string, int>& p1, pair<string, int>& p2)->bool {return (p1.second == p2.second) ? (p1.first < p2.first) : (p1.second > p2.second); };
        //priority_queue < pair<string, int>, vector<pair<string, int>>, decltype(cmp)> heap(cmp);
        ////����дdecltype�ķ�ʽ
        ///*struct comp
        //{
        //    bool operator() (pair<string, int>& a, pair<string, int>& b)
        //    {
        //        return (a.second == b.second) ? (a.first < b.first) : (a.second > b.second);
        //    }
        //};
        //priority_queue < pair<string, int>, vector<pair<string, int>>, comp> heap;*/
        //for (auto& p : map)
        //{
        //    heap.push(p);
        //    //��������
        //    if (heap.size() > k)
        //    {
        //        heap.pop();
        //    }
        //}
        //vector<string> res(k);
        //for (int i = k - 1; i >= 0; i--)
        //{
        //
        //    res[i] = heap.top().first;
        //    heap.pop();
        //}
        //return res;

    }
};

//705
//ע�����ӽڵ�ʱҪȥ�أ�*****************
//����дһ���⼸������
class MyHashSet {
public:
    MyHashSet(): len(10) {
        nums.resize(len);
    }

    void add(int key) {
        int index = key % len;
        if (nums[index] == nullptr)
        {
            Node* pnode = new Node();
            pnode->key = key;
            nums[index] = pnode;
        }
        else
        {
            //�������ڵ�
            //��Ҫ����ȥ�ؼ��ж�
            Node* pnode = nums[index];
            while (pnode->next != nullptr)
            {
                if (pnode->key == key) return;
                else
                {
                    pnode = pnode->next;
                }
            }
            if (pnode->key == key) return;
            else
            {
                Node* nnode = new Node();
                nnode->key = key;
                pnode->next = nnode;
            }
        }
    }

    //Ӧ�ôӺ���ǰɾ���ڵ�(����)
    //��ǰ��������Ĺ����У�Ҫ�жϵ�ǰ�ڵ��ŵ������Ƿ���Ҫɾ����keyֵ
    //��Ϊlen=10ʱ��6��76�����ͬһ��������
    void remove(int key) {
        int index = key % len;
        if (nums[index] != nullptr)
        {
            if (nums[index]->key == key)
            {
                Node* dnode = nums[index];
                nums[index] = dnode->next;
                delete dnode;
                dnode = nullptr;
            }
            else
            {
                if (nums[index]->next != nullptr)
                {
                    Node* pnode = nums[index];
                    Node* dnode = nums[index]->next;
                    while (dnode != nullptr && dnode->key != key)//�ǵ������˳���ж��Ƿ�Ϊ�յ�Ҫ��ǰ
                    {
                        pnode = dnode;
                        dnode = dnode->next;
                    }
                    //if (dnode->key == key)
                    if (dnode != nullptr)  //��Ҫ�ж������Ƿ��ǿ�ָ�룬����ǿ�ָ�����ܽ��м�ֵ���еȲ��������߲�ȡ��һ��while���ж�����д��������������һ��д
                    {
                        pnode->next = dnode->next;
                        delete dnode;
                        dnode = nullptr;
                    }
                }
            }
        }
        return;
    }

    bool contains(int key) {
        int index = key % len;
        Node* qnode = nums[index];
        while (qnode != nullptr)
        {
            if (qnode->key == key) return true;
            qnode = qnode->next;
        }
        return false;
    }

    struct Node
    {
        int key;
        Node* next;
    };

public:
    int len;
    vector<Node*> nums;
};

void maxHeapify(vector<int>& vec, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < vec.size() && vec[i] < vec[left])
    {
        largest = left;
    }
    if (right < vec.size() && vec[largest] < vec[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(vec[i], vec[largest]);
        maxHeapify(vec, largest);
    }
    
}

void buildHeap(vector<int>& vec)
{
    int len = vec.size();
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        maxHeapify(vec, i);
    }
}

void deleteHeap(vector<int>& vec)
{
    if (vec.size() > 1) vec[0] = vec[(vec.size() - 1)];
    vec.pop_back();
    if (vec.empty()) return;
    maxHeapify(vec, 0);
    return;
}