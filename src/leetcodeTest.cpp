#include "LC217.h"
#include "basic.h"
#include "offer.h"
#include "algorithms.h"

int main()
{
	//217
	//vector<int> nums{ 1,2,3,4 };
	//Solution sl;
	//cout << "result: " << sl.containsDuplicate(nums) << endl;
	//389
	//string s, t;
	//s = "ymbgaraibkfmvocpizdydugvalagaivdbfsfbepeyccqfepzvtpyxtbadkhmwmoswrcxnargtlswqemafandgkmydtimuzvjwxvlfwlhvkrgcsithaqlcvrihrwqkpjdhgfgreqoxzfvhjzojhghfwbvpfzectwwhexthbsndovxejsntmjihchaotbgcysfdaojkjldprwyrnischrgmtvjcorypvopfmegizfkvudubnejzfqffvgdoxohuinkyygbdzmshvyqyhsozwvlhevfepdvafgkqpkmcsikfyxczcovrmwqxxbnhfzcjjcpgzjjfateajnnvlbwhyppdleahgaypxidkpwmfqwqyofwdqgxhjaxvyrzupfwesmxbjszolgwqvfiozofncbohduqgiswuiyddmwlwubetyaummenkdfptjczxemryuotrrymrfdxtrebpbjtpnuhsbnovhectpjhfhahbqrfbyxggobsweefcwxpqsspyssrmdhuelkkvyjxswjwofngpwfxvknkjviiavorwyfzlnktmfwxkvwkrwdcxjfzikdyswsuxegmhtnxjraqrdchaauazfhtklxsksbhwgjphgbasfnlwqwukprgvihntsyymdrfovaszjywuqygpvjtvlsvvqbvzsmgweiayhlubnbsitvfxawhfmfiatxvqrcwjshvovxknnxnyyfexqycrlyksderlqarqhkxyaqwlwoqcribumrqjtelhwdvaiysgjlvksrfvjlcaiwrirtkkxbwgicyhvakxgdjwnwmubkiazdjkfmotglclqndqjxethoutvjchjbkoasnnfbgrnycucfpeovruguzumgmgddqwjgdvaujhyqsqtoexmnfuluaqbxoofvotvfoiexbnprrxptchmlctzgqtkivsilwgwgvpidpvasurraqfkcmxhdapjrlrnkbklwkrvoaziznlpor";
	//t = "qhxepbshlrhoecdaodgpousbzfcqjxulatciapuftffahhlmxbufgjuxstfjvljybfxnenlacmjqoymvamphpxnolwijwcecgwbcjhgdybfffwoygikvoecdggplfohemfypxfsvdrseyhmvkoovxhdvoavsqqbrsqrkqhbtmgwaurgisloqjixfwfvwtszcxwktkwesaxsmhsvlitegrlzkvfqoiiwxbzskzoewbkxtphapavbyvhzvgrrfriddnsrftfowhdanvhjvurhljmpxvpddxmzfgwwpkjrfgqptrmumoemhfpojnxzwlrxkcafvbhlwrapubhveattfifsmiounhqusvhywnxhwrgamgnesxmzliyzisqrwvkiyderyotxhwspqrrkeczjysfujvovsfcfouykcqyjoobfdgnlswfzjmyucaxuaslzwfnetekymrwbvponiaojdqnbmboldvvitamntwnyaeppjaohwkrisrlrgwcjqqgxeqerjrbapfzurcwxhcwzugcgnirkkrxdthtbmdqgvqxilllrsbwjhwqszrjtzyetwubdrlyakzxcveufvhqugyawvkivwonvmrgnchkzdysngqdibhkyboyftxcvvjoggecjsajbuqkjjxfvynrjsnvtfvgpgveycxidhhfauvjovmnbqgoxsafknluyimkczykwdgvqwlvvgdmufxdypwnajkncoynqticfetcdafvtqszuwfmrdggifokwmkgzuxnhncmnsstffqpqbplypapctctfhqpihavligbrutxmmygiyaklqtakdidvnvrjfteazeqmbgklrgrorudayokxptswwkcircwuhcavhdparjfkjypkyxhbgwxbkvpvrtzjaetahmxevmkhdfyidhrdeejapfbafwmdqjqszwnwzgclitdhlnkaiyldwkwwzvhyorgbysyjbxsspnjdewjxbhpsvj";
	//Solution sl;
	//cout << "result: " << sl.findTheDifference(s,t) << endl;
	//705
	//MyHashSet hs;
	//hs.add(89);
	//hs.add(29);
	//hs.add(19);
	//hs.add(89);
	//hs.add(49);
	//hs.add(99);
	//hs.add(49);
	//hs.remove(19);
	//cout << "1: " << hs.contains(19) << endl;
	////��������
	/*["MyHashSet", "remove", "add", "contains", "add", 
		"contains", "add", "add", "add", "add", 
		1
		"contains", "remove", "contains", "contains", "contains", 
		"add", "contains", "add", "remove", "add", 
		2
		"add", "remove", "contains", "add", "contains", 
		"add", "add", "add", "add", "remove", 
		3
		"add", "remove", "add", "remove", "contains", 
		"contains", "add", "add", "add", "add",
		4
		"add", "contains", "remove", "add", "add", 
		"add", "contains", "contains", "add", "add", 
		5
		"contains", "remove", "add", "contains", "add", 
		"remove", "remove", "add", "contains", "add", 
		6
		"add", "add", "add", "add", "remove", 
		"add", "add", "contains", "contains", "contains", 
		7
		"add", "add", "contains", "contains", "add", 
		"add", "add", "contains", "contains", "add", 
		8
		"add", "remove", "add", "add", "contains", 
		"add", "remove", "add", "contains", "contains", 
		9
		"remove", "remove", "add", "contains", "remove", 
		"contains", "add", "add", "contains", "add", 
	 
		"add"]
	[[], [28], [82], [82], [15], 
		[82], [33], [7], [93], [61], 
		1
		[93], [15], [33], [6], [15], 
		[7], [15], [89], [66], [16], 
		2
		[7], [81], [89], [98], [98], 
		[40], [88], [29], [81], [17], 
		3
		[83], [33], [44], [22], [82], 
		[82], [8], [63], [13], [19], 
		4
		[89], [41], [67], [37], [17], 
		[57], [41], [30], [23], [82], 
		5
		[23], [51], [80], [81], [15], 
		[95], [45], [49], [93], [7], 
		6
		[45], [86], [74], [85], [69], 
		[7], [2], [13], [92], [3], 
		7
		[40], [32], [29], [74], [37], 
		[66], [14], [91], [82], [99], 
		8
		[84], [87], [56], [49], [85], 
		[34], [32], [38], [76], [34], 
		9
		[19], [81], [83], [30], [15], 
		[41], [42], [5], [19], [26], 
		
		[33]]*/
	//94
	//vector<string> vec{ "1","2","3","4","5","6","null","8"};
	//BinTree bt;
	//bt.createTreefromstr(vec);
	/*vector<string> vec2{ "5" };
	BinTree bt_sub;
	bt_sub.createTreefromstr(vec2);*/
	/*Solution_L sl;
	vector<int> res;
	res = sl.levelorderTraversal(bt.root);
	cout << "result: " << endl;
	for (auto p : res)
	{
		cout << p << " ";
	}*/
	//Solution sl;
	//cout << sl.isBalanced(bt.root) << endl;

	//215
	/*vector<int> vec{ 3,2,1,5,6,4 };
	Solution sl;
	int res = sl.findKthLargest(vec, 2);
	cout << "res: " << res << endl;*/


	//vector<int> value{ 1,5,10,15 };
	//vector<int> weight{ 1,3,1,2 };
	//Basic bs;
	//cout << bs.pack_prob_01(value, weight, 4) << endl;

	vector<int> coins{ 2,3 };
	Solution sl;
	sl.change(11, coins);
}