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
    void reverse(ListNode *head) {
        ListNode *p, *q;
        p = head->next;
        head->next = NULL;
        while (p) {
            q = p;
            p = p->next;
            q->next = head->next;
            head->next = q;
        }
    }
    
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        reverse(l1);
        reverse(l2);
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
        reverse(head->next);
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
        cout << s->val << endl;
        s= s->next;
    }
}

void reverse(ListNode *head) {
    ListNode *p, *q;
    p = head->next;
    head->next = NULL;
    while (p) {
        q = p;
        p = p->next;
        q->next = head->next;
        head->next = q;
    }
}

int main(int argc, const char * argv[]) {

    ListNode *head1, *head2, *addList;
    head1 = creat();
    head2 = creat();
    Solution solution;
    addList = solution.addLists(head1, head2);
    print(addList);
    return 0;
}


