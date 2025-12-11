#include <iostream>
struct Node {
    int data;       // 节点数据
    Node* next;
    Node(int x, Node* n = nullptr) : data(x), next(n) {}    // 指向下一个节点的指针
};
int size(Node *head) {
    int count = 0;
    while (head != nullptr) {
        count++;
        head = head->next;  // 移动到下一个节点
    }
    return count;
}

int main(){
    Node b(2);
    Node a{1,&b};
    Node c{342,&a};
    std::cout<<size(&c)<<std::endl;
    Node *root = new Node(1);
    root->next = new Node{2,nullptr};
}