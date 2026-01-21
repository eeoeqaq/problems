#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <type_traits>
#include <vector>

using namespace std;

// ==========================================================
// 这份文件的目标：用一份可运行的示例讲清三件事
// 1) 函数模板（Function Template）
// 2) 类模板（Class Template，含非类型模板参数 N）
// 3) 群体数据：STL 容器 + 迭代器 + 算法（algorithm/numeric）
// ==========================================================

// =======================
// 1) 函数模板
// =======================

// (1) 两个同名函数模板重载：一个比较“值”，一个比较“指针所指的值”
// 注意：你原来的写法 `template<class T*>` 不是合法 C++ 语法。

// 版本A：比较两个值（传入指针时，这个版本会比较“地址”，除非你传 *p）
template <class T>
const T& mymax(const T& a, const T& b) {
    return (a < b) ? b : a;
}

// 版本B：比较两个指针所指向的值（更“贴近直觉”，但需要保证指针有效）
// 这里加了空指针处理：如果其中一个为空，就返回另一个。
template <class T>
const T* mymax(const T* a, const T* b) {
    if (!a) return b;
    if (!b) return a;
    return (*a < *b) ? b : a;
}


template <typename It>
void print_range(It begin, It end, const string& sep = " ") {
    for (auto it = begin; it != end; ++it) {
        cout << *it;
        if (next(it) != end) cout << sep;
    }
}

// (2) 绝对值：只允许算术类型（int/double/long long...）
// 这里展示：模板 + 编译期约束（static_assert + if constexpr）。
template <typename T>
constexpr T my_abs(T x) {
    static_assert(is_arithmetic_v<T>, "my_abs<T>: T 必须是算术类型");
    if constexpr (is_signed_v<T>) {
        return x < 0 ? -x : x;
    } else {
        return x;
    }
}

// (3) 最大值：展示模板参数推导
template <typename T>
const T& my_max(const T& a, const T& b) {
    return (a < b) ? b : a;
}

// =======================
// 2) 类模板
// =======================

// (1) 一个简单的栈：T 是元素类型
template <typename T>
class SimpleStack {
public:
    void push(const T& x) { data_.push_back(x); }
    void pop() {
        if (!data_.empty()) data_.pop_back();
    }
    T& top() { return data_.back(); }
    const T& top() const { return data_.back(); }
    bool empty() const { return data_.empty(); }
    size_t size() const { return data_.size(); }

private:
    vector<T> data_;
};

// (2) 非类型模板参数：N 是编译期常量（容量固定）
template <typename T, size_t N>
class StaticArray {
public:
    constexpr size_t size() const { return N; }
    T& operator[](size_t i) { return a_[i]; }
    const T& operator[](size_t i) const { return a_[i]; }

    T* begin() { return a_.data(); }
    T* end() { return a_.data() + N; }
    const T* begin() const { return a_.data(); }
    const T* end() const { return a_.data() + N; }

private:
    array<T, N> a_{};
};

// =======================
// 3) 群体数据（容器/迭代器/算法）
// =======================

int main() {
    cout << "== 1) 函数模板 ==\n";
    cout << "my_abs(-7) = " << my_abs(-7) << "\n";
    cout << "my_abs(-3.5) = " << my_abs(-3.5) << "\n";
    cout << "my_max(2, 9) = " << my_max(2, 9) << "\n\n";

    cout << "== 1.1) 传入指针时选哪个 mymax? ==\n";
    int x = 3, y = 5;
    int* px = &x;
    int* py = &y;
    cout << "mymax(px, py) 默认选指针版本（比较 *px 和 *py），结果指向: " << *mymax(px, py) << "\n";
    cout << "想强制选‘值版本’并比较指针地址：mymax<int*>(px, py) 选中地址较大的那个\n";
    cout << "  是否返回 px? " << (mymax<int*>(px, py) == px ? "yes" : "no") << "\n";
    cout << "想比较指针所指的值但又用值版本：传 *px, *py 即可：mymax(*px, *py) = " << mymax(*px, *py) << "\n\n";

    cout << "== 2) 群体数据：vector + 算法 ==\n";
    vector<int> v{5, 1, 4, 1, 3, 9, 2};
    cout << "原始 v: ";
    print_range(v.begin(), v.end());
    cout << "\n";

    // sort：对 [begin,end) 排序（算法与容器解耦）
    sort(v.begin(), v.end());
    cout << "排序后 v: ";
    print_range(v.begin(), v.end());
    cout << "\n";

    // unique + erase：对“已排序”的序列去重（vector 里常见套路）
    v.erase(unique(v.begin(), v.end()), v.end());//!!!
    cout << "去重后 v: ";
    print_range(v.begin(), v.end());
    cout << "\n";

    // transform：把每个元素映射成另一个元素
    vector<int> squares(v.size());
    transform(v.begin(), v.end(), squares.begin(), [](int x) { return x * x; });
    cout << "平方 squares: ";
    print_range(squares.begin(), squares.end());
    cout << "\n";

    // accumulate：聚合统计（求和/求积/自定义聚合）
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "v 的元素和 sum = " << sum << "\n\n";

    cout << "== 3) 群体数据：set（自动排序 + 去重）==\n";
    set<int> s(v.begin(), v.end());
    cout << "set s: ";
    print_range(s.begin(), s.end());
    cout << "\n";
    cout << "s 是否包含 4? " << (s.count(4) ? "yes" : "no") << "\n\n";

    cout << "== 4) 群体数据：array / StaticArray（固定大小）==\n";
    array<string, 3> words{"cpp", "template", "stl"};
    cout << "std::array words: ";
    print_range(words.begin(), words.end(), ", ");
    cout << "\n";

    StaticArray<int, 5> sa;
    for (size_t i = 0; i < sa.size(); ++i) sa[i] = static_cast<int>(i * i);
    cout << "StaticArray<int,5>: ";
    print_range(sa.begin(), sa.end());
    cout << "\n\n";

    cout << "== 5) 类模板：SimpleStack<T> ==\n";
    SimpleStack<string> st;
    st.push("hello");
    st.push("templates");
    st.push("world");
    cout << "stack top = " << st.top() << ", size = " << st.size() << "\n";
    st.pop();
    cout << "pop 后 top = " << st.top() << ", size = " << st.size() << "\n";

    return 0;
}