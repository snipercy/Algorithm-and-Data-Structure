//
// Created by cy on 16/1/30.
//
// reverse list

#include<stdio.h>
#include<vector>
#include<array>

// list node
struct node{
    int addr_;
    int data_;
    int next_;
    node(int addr, int data, int next){
        addr_ = addr;
        data_ = data;
        next_ = next;
    }
};

static std::vector<node> vec;

// for get input data
inline void getInput() 
{
    static int addr = 0;
    static int list_length = 0;
    static int N = 0; // 在list中，每N个节点为一组,组内进行链表的反转

    scanf("%d %d %d", &addr, &list_length, &N);

    // for debug
    printf("addr=%d, list_length=%d, N=%d", addr, list_length, N);

    static int val;
    static int next;
    while(list_length-- > 0) {
        scanf("%d %d %d",&addr,&val,&next);

        // for debug
        printf("addr=(%d),val=(%d),next=(%d)",addr,val,next);

        node* cur = new node(addr,val,next);
        vec.push_back()
    }
    
}

void reverse(std::vector<int>::iterator start,
             std::vector<int>::iterator end)
{
    
    return;
}

int main() {

    return 0;
}
