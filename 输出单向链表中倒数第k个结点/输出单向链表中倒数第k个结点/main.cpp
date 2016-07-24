//
//  main.cpp
//  输出单向链表中倒数第k个结点
//
//  Created by anne on 16/7/10.
//  Copyright © 2016年 anne. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode
{
    int       m_nKey;
    ListNode* m_pNext;
};

ListNode* lastK(ListNode *head, int k,int n){
    if(head == NULL || k > n)
        return NULL;
    ListNode *p,*q;
    p = head;
    q = head;
    while(k--){
        q = q->m_pNext;
    }
    while (q->m_pNext) {
        p = p->m_pNext;
        q = q->m_pNext;
    }
    return p;
}

int main(int argc, const char * argv[]) {
    int n,k,x;
    while(cin>>n){
        int len = n;
        cin>>x;
        ListNode *head = (ListNode *)malloc(sizeof(ListNode));
        head->m_nKey = x;
        head->m_pNext = NULL;
        ListNode *p = head;
        while(--n){
            cin>>x;
            ListNode *q = (ListNode *)malloc(sizeof(ListNode));
            q->m_nKey = x;
            q->m_pNext = NULL;
            p->m_pNext = q;
            p = q;
        }
        cin>>k;
        ListNode *result = lastK(head,k,len);
        cout<<(result?result->m_nKey:0)<<endl;
    }
    return 0;
}
