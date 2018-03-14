//
//  main.cpp
//  旋转链表
//
//  Created by 满脸胡茬的怪蜀黍 on 2018/3/14.
//  Copyright © 2018年 Puqin.Chen. All rights reserved.
//
/// 旋转链表
/// 题目描述：给定一个列表，将链表旋转到右边的k个位置，其中k是非负的。

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k < 0) {
            return NULL;
        }
        ListNode *phead = head ,*pNode = head;
        for (int i = 0; i < k; i++) {
            pNode = pNode->next;
        }
        while (pNode->next != NULL) {
            pNode = pNode->next;
            phead = phead->next;
        }
        pNode->next = head->next;
        head->next = phead->next;
        phead->next = NULL;
        return head;
    }
};

int main(int argc, const char * argv[]) {
    ListNode *head;
    head = creat();
    int k = 0;
    cin >> k;
    Solution solution;
    print(solution.rotateRight(head, k));
    return 0;
}
