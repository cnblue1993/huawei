//
//  main.cpp
//  从单向链表中删除指定值的节点
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


int main(int argc, const char * argv[]) {
    int n, root;
    while(cin>>n>>root){
        ListNode *head = (ListNode *) malloc(sizeof(ListNode));
        head->m_nKey = root;
        head->m_pNext = NULL;
        
        ListNode *p = head;
        int x,y;
        while(--n){
            cin>>x>>y;
            for(p = head; p != NULL; p=p->m_pNext){
                if(p->m_nKey == y){
                    ListNode *q = (ListNode *) malloc(sizeof(ListNode));
                    q->m_nKey = x;
                    q->m_pNext = p->m_pNext;
                    p->m_pNext= q;
                    break;
                }
            }
        }
        
        int del;
        cin>>del;
        p = head;
        ListNode *result = head;
        if(head->m_nKey == del){
            result = head->m_pNext;
            free(head);
            if(result == NULL){
                
            }else{
                for(; result->m_pNext != NULL; result = result->m_pNext){
                    cout<<result->m_nKey<<" ";
                }
                cout<<result->m_nKey<<" "<<endl;
            }
            
        }else{
            for(; p!=NULL; p = p->m_pNext){
                if(p->m_nKey == del){
                    result->m_pNext = p->m_pNext;
                    free(p);
                    break;
                }else{
                    result = p;
                }
            }
            for(result = head; result != NULL; result = result->m_pNext){
                cout<<result->m_nKey<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
