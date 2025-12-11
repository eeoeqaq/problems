#include <iostream> // 用于输入输出
#include <string>   // 必须包含 <string> 头文件来使用 std::string
#include <vector>   // 用于 split 函数的返回值
#include <algorithm> // 用于 find, sort, transform 等算法
#include <sstream>   // 用于字符串和数字之间的转换
#include <cstring> 
// --- 辅助函数：打印字符串和其长度 ---
void print_string_info(const std::string& s, const std::string& name) {
    std::cout << "--- " << name << " ---" << std::endl;
    std::cout << "Value: \"" << s << "\"" << std::endl;
    std::cout << "Length (size()): " << s.size() << std::endl;
    std::cout << "Capacity: " << s.capacity() << std::endl; // 字符串实际分配的内存大小
    std::cout << "Is empty? " << (s.empty() ? "Yes" : "No") << std::endl;
    std::cout << std::endl;
}

// --- 辅助函数：模拟字符串分割 (std::string 没有内置的 split) ---
std::vector<std::string> split_string(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s); // 使用 istringstream 来解析字符串
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    std::cout << "===================== std::string 基础与构造 =====================" << std::endl;

    // 1. 默认构造：空字符串
    std::string s1;
    print_string_info(s1, "s1 (default constructed)");

    // 2. 使用 C 风格字符串（const char*）构造
    std::string s2 = "Hello, World!";
    print_string_info(s2, "s2 (from C-string)");

    // 3. 拷贝构造
    std::string s3 = s2; // 等价于 std::string s3(s2);
    print_string_info(s3, "s3 (copy of s2)");

    // 4. 从部分 C 风格字符串构造 (前n个字符)
    std::string s4("Partial", 4); // "Part"
    print_string_info(s4, "s4 (from partial C-string)");

    // 5. 用 n 个字符填充构造
    std::string s5(5, '*'); // "*****"
    print_string_info(s5, "s5 (5 asterisks)");

    // 6. 从另一个 std::string 的子串构造
    std::string s6 = s2.substr(7, 5); // 从索引7开始，取5个字符："World"
    print_string_info(s6, "s6 (substring of s2)");

    std::cout << "===================== 访问与修改字符 =====================" << std::endl;

    std::string editable_str = "C++ String";
    std::cout << "Original: " << editable_str << std::endl;

    // 1. 使用 operator[] 访问单个字符 (不进行边界检查)
    std::cout << "First char (editable_str[0]): " << editable_str[0] << std::endl;
    editable_str[0] = 'X'; // 修改字符
    std::cout << "After editable_str[0] = 'X': " << editable_str << std::endl;

    // 2. 使用 at() 访问单个字符 (进行边界检查，越界会抛出 std::out_of_range 异常)
    try {
        std::cout << "Second char (editable_str.at(1)): " << editable_str.at(1) << std::endl;
        // editable_str.at(100) = 'Y'; // 尝试越界，会抛出异常
    } catch (const std::out_of_range& e) {
        std::cerr << "Error accessing character at invalid index: " << e.what() << std::endl;
    }

    // 3. front() 和 back() 访问首尾字符 (C++11)
    if (!editable_str.empty()) {
        std::cout << "Front char: " << editable_str.front() << std::endl;
        std::cout << "Back char: " << editable_str.back() << std::endl;
    }

    std::cout << "===================== 字符串连接与赋值 =====================" << std::endl;

    std::string str_a = "Hello";
    std::string str_b = " World";
    std::string str_c = "!";
    std::string result;

    // 1. 使用 + 运算符连接
    result = str_a + str_b + str_c;
    print_string_info(result, "result (concatenation with +)");

    // 2. 使用 += 运算符追加
    result = "Start";
    result += " Middle";
    result += " End";
    print_string_info(result, "result (append with +=)");

    // 3. append() 函数
    std::string app_str = "Appending ";
    app_str.append("string.");
    app_str.append(3, '!'); // 追加3个'!'
    print_string_info(app_str, "app_str (using append)");

    // 4. assign() 函数：赋值
    std::string assign_str;
    assign_str.assign("New content.");
    print_string_info(assign_str, "assign_str (using assign)");
    assign_str.assign(s2); // 赋值另一个 std::string
    print_string_info(assign_str, "assign_str (assigned s2)");

    std::cout << "===================== 字符串比较 =====================" << std::endl;

    std::string s_comp1 = "apple";
    std::string s_comp2 = "banana";
    std::string s_comp3 = "apple";

    // 1. 使用 ==, !=, <, >, <=, >= 运算符
    std::cout << "s_comp1 == s_comp3: " << (s_comp1 == s_comp3 ? "true" : "false") << std::endl; // true
    std::cout << "s_comp1 != s_comp2: " << (s_comp1 != s_comp2 ? "true" : "false") << std::endl; // true
    std::cout << "s_comp1 < s_comp2: " << (s_comp1 < s_comp2 ? "true" : "false") << std::endl;   // true (按字典序)

    // 2. compare() 函数：返回 0 (相等), 负数 (this < other), 正数 (this > other)
    std::cout << "s_comp1.compare(s_comp3): " << s_comp1.compare(s_comp3) << std::endl; // 0
    std::cout << "s_comp1.compare(s_comp2): " << s_comp1.compare(s_comp2) << std::endl; // 负数
    std::cout << "s_comp2.compare(s_comp1): " << s_comp2.compare(s_comp1) << std::endl; // 正数

    std::cout << "===================== 查找与替换 =====================" << std::endl;

    std::string search_str = "This is a test string for searching.";
    std::string target = "test";
    std::string replace_with = "example";

    // 1. find()：查找子串或字符，返回第一次出现的索引，未找到返回 std::string::npos
    size_t pos = search_str.find(target);
    if (pos != std::string::npos) {
        std::cout << "'" << target << "' found at index: " << pos << std::endl;
    } else {
        std::cout << "'" << target << "' not found." << std::endl;
    }

    // 2. rfind()：从末尾开始查找，返回第一次出现的索引
    pos = search_str.rfind('s'); // 查找 's' 字符
    if (pos != std::string::npos) {
        std::cout << "'s' (rfind) found at index: " << pos << std::endl;
    }

    // 3. find_first_of(), find_last_of(), find_first_not_of(), find_last_not_of()
    // 这些用于查找字符串中第一个/最后一个是/不是指定字符集中的字符

    // 4. replace()：替换子串
    std::string repl_str = "The quick brown fox.";
    std::cout << "Original: " << repl_str << std::endl;
    repl_str.replace(4, 5, "slow green"); // 从索引4开始，替换5个字符 ("quick") 为 "slow green"
    std::cout << "After replace: " << repl_str << std::endl; // The slow green brown fox.

    // 5. erase()：删除子串或字符
    std::string erase_str = "Delete some characters here.";
    erase_str.erase(7, 5); // 从索引7开始，删除5个字符 ("some ")
    std::cout << "After erase: " << erase_str << std::endl; // Delete characters here.

    // 6. insert()：插入子串或字符
    std::string insert_str = "Hello World";
    insert_str.insert(5, ", Beautiful"); // 在索引5处插入 ", Beautiful"
    std::cout << "After insert: " << insert_str << std::endl; // Hello, Beautiful World

    std::cout << "===================== 子串与 C 风格字符串转换 =====================" << std::endl;

    std::string my_str = "Example String";

    // 1. substr()：获取子串
    std::string sub = my_str.substr(8, 6); // 从索引8开始，取6个字符："String"
    print_string_info(sub, "sub (from substr)");

    // 2. c_str()：获取 C 风格的 const char* 字符串 (只读)
    const char* c_str_ptr = my_str.c_str();
    std::cout << "C-style string (c_str()): " << c_str_ptr << std::endl;

    // 3. data()：获取指向字符串内部字符数组的指针 (C++11 起可用于修改，但需要小心)
    char* data_ptr = my_str.data(); // C++11 之前的 data() 是 const char*
    // *data_ptr = 'x'; // 示例：修改第一个字符（不推荐直接修改，除非知道后果）

    std::cout << "===================== 字符串与数字类型转换 =====================" << std::endl;

    // --- 数字转字符串 ---

    // 1. std::to_string (C++11 推荐)
    int num_int = 123;
    double num_double = 45.67;
    std::string s_int = std::to_string(num_int);
    std::string s_double = std::to_string(num_double);
    std::cout << "int to string: \"" << s_int << "\"" << std::endl;
    std::cout << "double to string: \"" << s_double << "\"" << std::endl;

    // 2. std::stringstream (所有 C++ 版本可用，更灵活)
    std::stringstream ss;
    ss << 789;
    std::string s_from_ss = ss.str();
    std::cout << "stringstream int to string: \"" << s_from_ss << "\"" << std::endl;
    ss.str(""); ss.clear(); // 清空并重置
    ss << 123.456 << " World"; // 可以组合多种类型
    std::string combined_ss = ss.str();
    std::cout << "stringstream combined: \"" << combined_ss << "\"" << std::endl;


    // --- 字符串转数字 ---

    // 1. std::stoi, std::stol, std::stoll, std::stof, std::stod, std::stold (C++11 推荐)
    std::string s_num_int = "12345";
    std::string s_num_double = "67.89";
    std::string s_invalid = "abc";

    try {
        int i = std::stoi(s_num_int);
        double d = std::stod(s_num_double);
        std::cout << "string to int: " << i << std::endl;
        std::cout << "string to double: " << d << std::endl;

        // 尝试转换非法字符串，会抛出 std::invalid_argument 异常
        // int invalid_i = std::stoi(s_invalid);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error converting string to number (invalid argument): " << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error converting string to number (out of range): " << e.what() << std::endl;
    }

    // 2. std::stringstream (所有 C++ 版本可用)
    std::string str_to_parse = "100.5";
    double parsed_double;
    std::stringstream parser_ss(str_to_parse);
    parser_ss >> parsed_double;
    if (!parser_ss.fail()) { // 检查转换是否成功
        std::cout << "stringstream string to double: " << parsed_double << std::endl;
    } else {
        std::cerr << "stringstream conversion failed." << std::endl;
    }

    std::cout << "===================== 实用功能与算法 =====================" << std::endl;

    std::string raw_str = "   Trim this string   ";
    std::cout << "Original raw_str: \"" << raw_str << "\"" << std::endl;

    // 1. trim (std::string 没有内置的 trim，需要手动实现或使用算法)
    // 简单地移除首尾空格
    size_t first_char = raw_str.find_first_not_of(" \t\n\r");
    size_t last_char = raw_str.find_last_not_of(" \t\n\r");
    if (first_char == std::string::npos || last_char == std::string::npos) {
        raw_str = ""; // 全是空格
    } else {
        raw_str = raw_str.substr(first_char, (last_char - first_char + 1));
    }
    std::cout << "Trimmed raw_str: \"" << raw_str << "\"" << std::endl;

    // 2. 转换为大小写 (使用 <algorithm> 和 <cctype>)
    std::string case_str = "MiXeD CaSe";
    std::cout << "Original case_str: " << case_str << std::endl;
    std::transform(case_str.begin(), case_str.end(), case_str.begin(), ::tolower);
    std::cout << "Lowercase: " << case_str << std::endl;
    std::transform(case_str.begin(), case_str.end(), case_str.begin(), ::toupper);
    std::cout << "Uppercase: " << case_str << std::endl;

    // 3. 字符串分割 (std::string 没有内置的 split，需要自定义函数)
    std::string sentence = "apple,banana,orange,grape";
    char delimiter = ',';
    std::vector<std::string> fruits = split_string(sentence, delimiter);

    std::cout << "Splitting \"" << sentence << "\" by '" << delimiter << "':" << std::endl;
    for (const auto& fruit : fruits) {
        std::cout << "- " << fruit << std::endl;
    }

    // 4. 清空字符串
    std::string clear_me = "I will be empty.";
    clear_me.clear();
    print_string_info(clear_me, "clear_me (after clear())");

    // 5. 调整大小
    std::string resize_str = "12345";
    resize_str.resize(3); // 截断为 "123"
    print_string_info(resize_str, "resize_str (resized to 3)");
    resize_str.resize(7, 'x'); // 扩展为 "123xxxx"
    print_string_info(resize_str, "resize_str (resized to 7 with 'x')");

    std::cout << "===================== 与 C 风格字符串的互操作 =====================" << std::endl;

    // 1. std::string 到 C 风格 char* (危险，除非知道后果)
    // std::string::data() 返回的 char* 在 C++11 后是可修改的，但直接修改可能导致 std::string 内部状态不一致。
    // c_str() 始终返回 const char*，不能修改。
    std::string mod_str = "Modify";
    char* mod_ptr = &mod_str[0]; // 获取可修改的 C 风格字符串指针
    mod_ptr[0] = 'M';
    mod_ptr[1] = 'O';
    std::cout << "Modified std::string via char* pointer: " << mod_str << std::endl;
    // 更好的做法是复制到一个 char 数组中进行修改
    char buffer[20];
    strcpy(buffer, mod_str.c_str()); // 复制到 buffer
    buffer[0] = 'A';
    std::cout << "Modified C-string buffer: " << buffer << std::endl;

    // 2. C 风格 char* 到 std::string
    const char* c_style_str = "From C-style.";
    std::string cpp_str = c_style_str; // 隐式转换
    print_string_info(cpp_str, "cpp_str (from C-style char*)");

    return 0;
}