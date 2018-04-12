//
//  main.cpp
//  BinarySortTree
//
//  Created by 满脸胡茬的怪蜀黍 on 2018/4/12.
//  Copyright © 2018年 Puqin.Chen. All rights reserved.
//

// 二叉排序树，又称二叉查找树，它或者是一棵空树，或者是具有以下性质的树：
//      若它的左子树不空，则左子树上所有的结点的值均小于它的根结构的值；
//      若它的右子树不空，则右子树上所有结点的值均均大于它的根结点的值；

#include <iostream>
using namespace std;
typedef struct BiTNode {
    int data; // 结点数据
    struct BiTNode *lchild, *rchild; //左右孩子指针
}BiTNode, *BiTree;

bool SearchBST(BiTree T, int key, BiTree f, BiTree *p) {
    if (!T) {
        *p = f;
        return false;
    } else if (key == T->data) {
        *p = T;
        return true;
    } else if(key < T->data){
        return SearchBST(T->lchild, key, T, p); // 在左子树继续查找
    } else {
        return SearchBST(T->rchild, key, T, p); // 在右子树继续查找
    }
}

bool InsertBST(BiTree *T, int key) {
    BiTree p, s;
    if (!SearchBST(*T, key,  NULL, &p)) { // 查找不成功
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild = NULL; // 插入s为新的根结点
        if (!p) {
            *T = s;
        } else if( key < p->data) { // 插入 s 为左子树
            p->lchild = s;
        } else {    //  插入 s 为右子树
            p->rchild = s;
        }
        return true;
    }
    else
        return false;
}

bool Delete(BiTree *p) {
    BiTree q, s;
    if ((*p)->rchild == NULL) { //如果只有左子树，就重接左子树就可以
        q = *p;
        *p = (*p)->lchild;
        free(q);
    } else if ((*p)->lchild == NULL) { // 如果只有右子树，只需重接右子树就可以
        q = *p;
        *p = (*p)->rchild;
        free(q);
    } else { // 左右子树均不为空
        q = *p;
        s = (*p)->lchild; // 转到左子树
        while (s->rchild) { // 然后向右，找到左子树的最大的树
            q = s;
            s = s->rchild;
        }
        (*p)->data = s->data; // s 指向被删节点的直接前驱
        if (q != *p) {
            q->rchild = s->lchild; //如果p 不等于 q,就重接右子树
        } else {
            q->lchild = s->lchild;
        }
        free(s);
    }
    return true;
}

bool DeleteBST(BiTree *T, int key) {
    if (!*T) {
        return false;
    } else {
        if (key == (*T)->data) {
            return Delete(T);
        } else if (key < (*T)->data) {
            return DeleteBST(&(*T)->lchild, key);
        } else {
            return DeleteBST(&(*T)->rchild, key);
        }
    }
}

int main(int argc, const char * argv[]) {
    int a[10] = {62, 88, 58, 47, 35, 73, 51, 99, 37, 93};
    BiTree T = NULL, p;
    for (int i = 0; i < 10; i++) {
        InsertBST(&T, a[i]);
    }
    int key = 0;
    cin >> key;
    cout  << SearchBST(T, key, NULL, &p);
    return 0;
}
