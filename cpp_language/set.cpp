#include <iostream>
#include <set>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::set;
using std::string;

// 教学目标：用一份可运行的示例讲清楚 C++ 标准库内置容器 std::set
// 结论先说：
// 1) std::set 是“有序 + 去重”的集合容器（默认从小到大）。
// 2) 底层通常是平衡二叉搜索树（如红黑树），因此插入/删除/查找一般为 O(log n)。
// 3) 迭代遍历时得到的是“排序后的”结果。

// 小工具：打印 set
template <class T>
void PrintSet(const set<T>& s, const string& name)
{
	cout << name << " (size=" << s.size() << "): ";
	for (const auto& x : s) {
		cout << x << ' ';
	}
	cout << "\n";
}

// 演示：set 的基本性质（有序、去重）
void DemoBasic()
{
	cout << "\n=== DemoBasic: 有序 + 去重 ===\n";

	set<int> s;
	std::vector<int> data = {5, 1, 7, 1, 3, 3, 10, 2};
	for (int x : data) {
		// insert 返回 pair<iterator, bool>
		// bool 表示“是否真的插入成功”（重复元素插入失败）
		auto [it, inserted] = s.insert(x);
		cout << "insert(" << x << ") -> " << (inserted ? "成功" : "失败(重复)")
			 << ", 当前元素位置是 " << *it << "\n";
	}

	PrintSet(s, "s");
	cout << "观察：输出是升序且不重复。\n";
}

// 演示：查找、计数、删除
void DemoFindErase()
{
	cout << "\n=== DemoFindErase: find / count / erase ===\n";

	set<int> s = {1, 2, 4, 8, 16};
	PrintSet(s, "s");

	int q1 = 8;
	auto it = s.find(q1);
	if (it != s.end()) {
		cout << "find(" << q1 << ") 找到：" << *it << "\n";
	} else {
		cout << "find(" << q1 << ") 未找到\n";
	}

	int q2 = 7;
	// set 去重，所以 count(x) 只会是 0 或 1
	cout << "count(" << q2 << ") = " << s.count(q2) << "\n";

	// erase(key) 返回删除了几个元素（set 里只可能 0 或 1）
	cout << "erase(4) 删除数量 = " << s.erase(4) << "\n";
	PrintSet(s, "s");
}

// 演示：lower_bound / upper_bound
// lower_bound(x): 第一个 >= x 的迭代器
// upper_bound(x): 第一个 >  x 的迭代器
void DemoBounds()
{
	cout << "\n=== DemoBounds: lower_bound / upper_bound ===\n";

	set<int> s = {10, 20, 30, 40, 50};
	PrintSet(s, "s");

	int x = 35;
	auto lb = s.lower_bound(x);
	auto ub = s.upper_bound(x);
    //默认用小于号排->数列从小到大排列->下界是大于等于x，上界是大于x。
	cout << "x=" << x << "\n";
	if (lb == s.end()) {
		cout << "lower_bound(x) = end (说明所有元素都 < x)\n";
	} else {
		cout << "lower_bound(x) 指向 " << *lb << " (第一个 >= x)\n";
	}

	if (ub == s.end()) {
		cout << "upper_bound(x) = end (说明没有元素 > x)\n";
	} else {
		cout << "upper_bound(x) 指向 " << *ub << " (第一个 > x)\n";
	}

	cout << "\n再试一个 x=40：\n";
	x = 40;
	lb = s.lower_bound(x);
	ub = s.upper_bound(x);
	cout << "lower_bound(40) -> " << (lb == s.end() ? -1 : *lb) << "\n";
	cout << "upper_bound(40) -> " << (ub == s.end() ? -1 : *ub) << "\n";
}

// 演示：自定义排序（降序）
void DemoCustomOrder()
{
	cout << "\n=== DemoCustomOrder: 自定义比较器(降序) ===\n";

	// set<int, std::greater<int>> 会按从大到小排序
	set<int, std::greater<int>> s = {3, 1, 4, 1, 5, 9, 2};
	cout << "s (降序, size=" << s.size() << "): ";
	for (int x : s) {
		cout << x << ' ';
	}
	cout << "\n";
}

// 补充说明（放在注释里就好）：
// - 如果你需要“允许重复元素”，用 std::multiset。
// - 如果你更在意平均 O(1) 查找且不需要有序性，用 std::unordered_set。
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);

	DemoBasic();
	DemoFindErase();
	DemoBounds();
	DemoCustomOrder();
    unsigned list;
	cout << "\n=== 小结 ===\n";
	cout << "1) set: 有序 + 去重，常用操作 O(log n)。\n";
	cout << "2) 常用 API: insert/find/count/erase/lower_bound/upper_bound。\n";
	cout << "3) 可传比较器改变排序规则。\n";

	return 0;
}

