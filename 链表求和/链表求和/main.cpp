//
//  main.cpp
//  链表求和
//
//  Created by 满脸胡茬的怪蜀黍 on 2017/9/6.
//  Copyright © 2017年 满脸胡茬的怪蜀黍. All rights reserved.
//

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
    
    // 奇偶节点交换
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)    return NULL;
        ListNode *oddNode = head, *evenNode = head->next, *evenHead = evenNode;
        while (evenNode != NULL && evenNode->next != NULL) {
            oddNode->next = evenNode->next;
            oddNode = oddNode->next;
            evenNode->next = oddNode->next;
            evenNode = evenNode->next;
        }
        oddNode->next = evenHead;
        return head;
    }
    // 非递归的方式
    ListNode* reverse(ListNode *head) {
        if (head == NULL || head -> next == NULL) {
            return head;
        }
        ListNode *p = NULL, *q = NULL;
        while (head != NULL) {
            p = head->next;
            head->next = q;
            q = head;
            head = p;
        }
        return q;
    }
    // 递归的方式
    ListNode* reverse_Recursion(ListNode *head) {
        // 这块儿，大家可能有疑问，这里说明一下，第一个是异常判断，第二个是递归结束条件
        if (head == NULL || head -> next == NULL) {
            return head;
        }
        
        ListNode *newHead = reverse_Recursion(head->next);
        
        head->next->next = head;
        head->next = NULL;
        
        return newHead;
    }
    // 删除节点
    void deleteNode(ListNode *head,ListNode* node) {
        if (head == NULL && node == NULL) {
            return;
        }
        if (node -> next != NULL ) {   // 一般正常情况
            ListNode *nextNode = node ->next;
            node->val = nextNode->val;
            node->next = nextNode->next;
            
            delete nextNode;
            nextNode = NULL;
        } else if (head == node){    // 链表中只有一个节点
            delete node;
            node = NULL;
            head = NULL;
        } else {                        //          要删除的节点是尾节点
            ListNode *p = head;
            while (p->next != node) {
                p = p->next;
            }
            
            p->next = node->next;
            delete node;
            node = NULL;
        }
    }
//  链表中倒数第k个节点
    ListNode* FindKthToTail(ListNode* head, unsigned int k) {
        // 写一些简单算法的过程中，一定要注重代码的鲁棒性
        if (head == NULL || k == 0) {
            return NULL;
        }
        
        ListNode* pAhead = head;
        ListNode* pBehind = NULL;
        for (int i = 0; i < k-1; ++i) {
            if (pAhead -> next != NULL) {
                pAhead = pAhead->next;
            } else {
                return NULL;
            }
        }
        pBehind = head;
        while (pAhead->next != NULL) {
            pAhead = pAhead -> next;
            pBehind = pBehind -> next;
        }
        return pBehind;
    }
   // 直接在原链表上进行操作
//    ListNode* swapPairs(ListNode* head) {
//        ListNode *p = head->next, *s,*q,*ss;
//        while (p!= NULL && p->next != NULL ) {
//            if (p == head->next) {
//                s = p->next;
//                q = p->next->next;
//                p->next = s->next;
//                s->next = p;
//                head->next = s;
//                ss = p;
//                p = q;
//            } else {
//                s = p->next;
//                q = p->next->next;
//                p->next = s->next;
//                s->next = p;
//                ss->next = s;
//                ss = p;
//                p = q;
//            }
//        }
//        return head;
//    }

    // 新创建一个结点newHead
    ListNode* swapPairs(ListNode *head) {
        ListNode *newHead = new ListNode(0);
        newHead->next = head->next;
        ListNode *preNode = newHead, *curNode = head->next;
        while (curNode != NULL && curNode->next != NULL) {
            preNode->next = curNode->next;
            curNode->next = preNode->next->next;
            preNode->next->next = curNode;
            preNode = curNode;
            curNode = curNode->next;
        }
        
        head = newHead;
        delete newHead;
        return head;
    }
    
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
//        reverse(l1);
//        reverse(l2);
        int c = 0;
        int temp = 0;
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        while (l1 != NULL && l2 != NULL) {
            temp = l1->val + l2->val + c;
            c = temp/10;
            temp = temp%10;
            p->next = new ListNode(temp);
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL) {
            temp = l1->val + c;
            c = temp/10;
            temp = temp%10;
            p->next = new ListNode(temp);
            p = p->next;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            temp = l2->val + c;
            c = temp/10;
            temp = temp%10;
            p->next = new ListNode(temp);
            p = p->next;
            l2 = l2->next;
        }
        if (c != 0) {
            p->next = new ListNode(c);
        }
//        reverse(head->next);
        return head->next;
    }
};

ListNode *creat() {
    ListNode *head = NULL,*node;
    head = new ListNode(0);
    head->next = NULL;
    ListNode *p = head;
    int c;
    while (1) {
        cin >> c;
        if (c == -1) {
            break;
        } else {
            node = new ListNode(c);
            p->next = node;
            p = node;
        }
    }
    p->next = NULL;
    return head;
}

void print(ListNode *head) {
    ListNode *s;
    s = head->next;
    while (s != NULL) {
        cout << s->val;
        s= s->next;
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {

    ListNode *head1, *head2, *addList;
    head1 = creat();
//    head2 = creat();
    Solution solution;
//    addList = solution.addLists(head1, head2);
//    print(addList);
//    print(solution.swapPairs(addList));
    print(solution.oddEvenList(head1));
    return 0;
}


