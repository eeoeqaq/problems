#include<vector>
#include<iostream>
using namespace std;

struct DoublyLinkedList{
    int val;
    DoublyLinkedList *pre,*next;
    DoublyLinkedList(int x):val(x),pre(NULL),next(NULL){};
};

DoublyLinkedList* make(const vector<int>& arr){
    if(arr.size()==0){
        return nullptr;
    }
    DoublyLinkedList* head= new DoublyLinkedList(arr[0]);
    DoublyLinkedList* curr=head;
    for(int i=1;i<arr.size();i++){
        curr->next=new DoublyLinkedList(arr[i]);
        curr->next->pre=curr;
        curr=curr->next;  
    }
    return head;
}
int main(){
    DoublyLinkedList* tail=make({1,2,3,4,5});
    DoublyLinkedList* head=tail;
    //print 
    while(tail->next!=nullptr){
        std::cout<<tail->val<<std::endl;
        tail=tail->next;
    }
    std::cout<<tail->val<<std::endl;
    /*
    for (ListNode* p = head; p != nullptr; p = p->next) {
        std::cout << p->val << std::endl;
    }
    */
    //头部增
    DoublyLinkedList* newhead=new DoublyLinkedList(0);
    newhead->next=head;
    head->pre=newhead;
    head=newhead;

    //头部减
    head=head->next;
    //尾部增
    DoublyLinkedList *b=head;
    while(b->next!=nullptr){
        b=b->next;}
    b->next=new DoublyLinkedList(0);
    //尾部减
    DoublyLinkedList *b=head;
    while(b->next->next!=nullptr){
        b=b->next;
    }
    b->next=nullptr;
    //中间添加
     DoublyLinkedList *b=head;
    for(int i=0;i<3;i++){
        b=b->next;
        DoublyLinkedList*c= new DoublyLinkedList(666);
        c->next=b->next;
        b->next=c;
    }
    }