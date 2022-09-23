#include <iostream>
#include "algorithms.h"
#include "offer.h"
#include "basic.h"


int main()
{
	/*****������֤**************************************************************************************/
	/*Basic bs;
	vector<int> vec{ 4,3,5,2,1,7,0,-1 };
	bs.bubbleSort(vec);
	for (auto s : vec)
	{
		cout << s << " ";
	}*/




	/*****��������֤************************************************************************************/

	/*vector<int> vec{1,2};
	Solution sl;*/

	// 1 
	/*vector<int> res;
	res = sl.twoSum(vec,9);
	for (auto s : res)
	{
		cout << s << endl;
	}*/

	//22 
	/*Solution sl;
	vector<string> res = sl.generateParenthesis(3);
	for (auto s : res)
	{
		cout << s << endl;
	}*/

	//34
	/*vector<int> vec{ 5,7,7,8,8,10 };
	Solution sl;
	vector<int> res = sl.searchRange(vec, 8);
	for (auto s : res)
	{
		cout << s << " ";
	}*/

	//53
	//vector<int> vec{ -2,1,-3,4,-1,2,1,-5,4 };
	//Solution sl;
	//int res = sl.maxSubArray(vec);
	//cout << res << endl;

	//69
	/*Solution sl;
	cout << sl.mySqrt(2147395599);*/

	//74
	//vector<vector<int>> matrix{ {2,3,1,2,4,3} };
	//Solution sl;
	//bool res = sl.searchMatrix(matrix, 0);
	//cout << res;

	//77
	/*vector<vector<int>> res;
	vector<int> vec{ 1,2,3 };
	Solution sl;
	res = sl.permute(vec);
	for (auto v : res)
	{
		for (auto num : v)
		{
			cout << num << ' ';
		}
		cout << endl;
	}*/


	//78
	/*vector<int> vec{ 1,2,2,2,3,4 };
	Solution sl;
	vector<vector<int>> res;
	res = sl.subsetsWithDup(vec);
	for (auto v : res)
	{
		for (auto num : v)
		{
			cout << num << ' ';
		}
		cout << endl;
	}*/

	//146
	//LRUCache lch(2);
	//lch.put(2, 1);
	//lch.put(2, 2);
	//cout << lch.get(2) << endl;
	//lch.put(1, 1);
	////cout << lch.get(2) << endl;
	//lch.put(4, 1);
	//cout << lch.get(2) << endl;

	//221
	//Solution sl;
	//vector<vector<char>> vec{ {'1','1'},{'1','1'} };// { {'1', '0', '1', '0', '0'}, { '1', '0', '1', '1', '1' }, { '1', '1', '1', '1', '1' }, { '1', '0', '0', '1', '0' }};
	//int res = sl.maximalSquare(vec);
	//cout << res << endl;

	//752
	//string target{ "8888" };
	////vector<string> vs{ "8887","8889","8878","8898","8788","8988","7888","9888" };
	//vector<string> vs{ "0001","0009","0010","0090","0100","0900","1000","9000" };
	//Solution sl;
	//cout << sl.openLock(vs, target) << endl;

	//162
	//vector<int> vec{ 3,4,3,2,1 };
	//Solution sl;
	//int res = sl.findPeakElement(vec);
	//cout << res;

	//209
	/*vector<int> vec{ 1,1,1,1,1,1,1,1 };
	Solution sl;
	int res = sl.minSubArrayLen(11, vec);
	cout << res;*/

	//215
	/*vector<int> vec{ 3,2,1,5,6,4 };
	Solution sl;
	int res = sl.findKthLargest(vec, 2);
	cout << res;*/

	// 881 
	//int res = 0;
	//res = sl.numRescueBoats(vec, 3);
	//cout << res << endl;
	
	//1456
	//string a{ "ibpbhixfiouhdljnjfflpapptrxgcomvnb" };
	//Solution sl;
	//int res = sl.maxVowels(a, 33);
	//cout << res;

	// Solution_of sl;
	// vector<string> mid{ "5","+","4","-","1","+","7" };
	// vector<string> res = sl.RPN(mid);
	// cout << sl.evalRPN(res) << endl;
	
	Solution sl;
	vector<int> prices{1,3,2,8,4,9};
	cout <<"final: "<<sl.maxProfit5(prices,2)<<endl;
	system("pause");
	return 0;

}




