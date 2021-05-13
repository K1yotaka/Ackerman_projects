#include "linked.h"

LINKED_node* created_LINKED() {
    LINKED_node* HEAD = new LINKED_node;
    HEAD -> next = NULL;
    return HEAD;
}

void LINKED_Insert(LINKED_node* HEAD, LINKED_node* data_node) {
    // 采用头插法
    data_node->next = HEAD->next;
    HEAD->next = data_node;
}

void LINKED_Query(LINKED_node* HEAD, int* LINKED_Query) {
    cout << "开始查找：" << endl;
    LINKED_node * q;
    for (int i = 0;i < 10;i++) {
        q = HEAD;
        while ((q != NULL) && (q->index != LINKED_Query[i]))
            q = q->next;
        if (q != NULL)
            cout << LINKED_Query[i] << "的mac地址为：" << q->mac << endl;
        else
            cout << LINKED_Query[i] << "无记录" << endl;
    }
}

void LINKED_Delete(LINKED_node* HEAD, int* LINKED_Delete) {
    cout << "开始删除：" << endl;
    LINKED_node * q;
    LINKED_node * p;
    for(int i = 0; i < 10; i++){
        q = HEAD;
        while((q->next!= NULL) && (q->next->index!=LINKED_Delete[i]))
            q = q->next;
        if(q->next != NULL){
            p = q->next;
            cout << LINKED_Delete[i] << "的mac地址为：" << q->next->mac << endl;
            q->next = p->next;
            delete(p);
        }
        else if((q->next == NULL) && (q->index==LINKED_Delete[i]))
            delete(q);
        else
            cout << LINKED_Delete[i] << "无记录" << endl;

    }
}