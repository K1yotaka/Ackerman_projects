// Lab2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <time.h>
//#include <windows.h>
#include "ultity.h"
#include "array.h"
#include "linked.h"
#include "RBTree.h"

using namespace std;


void acceptance_test()//实验验收函数，【无需修改，不要改动】，请仔细阅读代码，理解IO接口
{
    vector<struct CSVDATA> dataList = dataload();
    // Get the data from CSV File
    std::cout << "There are " << dataList.size() << " datas in the CSV file." << std::endl;

    /* 数组部分 （开始）*/
    // 生成数组
    ARRAY_node* data_ARRAY = new ARRAY_node[100000];
    int ARRAY_length = 0;
    for (int i = 0; i < 99900; i++) {
        ARRAY_node new_data;
        new_data.mac = dataList[i].mac;
        new_data.index = dataList[i].index;
        ARRAY_Insert(data_ARRAY, new_data, ARRAY_length);
        ARRAY_length++;
    }

    // ======= 插入 =======
//    LARGE_INTEGER t1, t2, tc;
//    QueryPerformanceFrequency(&tc);
//    QueryPerformanceCounter(&t1);
    clock_t ARRAY_insert_start, ARRAY_insert_finish;
    ARRAY_insert_start = clock();
    for (int i = 0; i < 100; i++) {
        ARRAY_node new_data;
        new_data.mac = dataList[i + 99900].mac;
        new_data.index = dataList[i + 99900].index;
        ARRAY_Insert(data_ARRAY, new_data, ARRAY_length);
        ARRAY_length++;
    }
    ARRAY_insert_finish = clock();

    //QueryPerformanceCounter(&t2);
    double ARRAY_insert_time = (double)(ARRAY_insert_finish - ARRAY_insert_start) / CLOCKS_PER_SEC;
    cout << "ARRAY_insert_time = " << ARRAY_insert_time << " s" << endl;  //输出时间（单位：ｓ）

    // ======= 查找 =======
    int* Query_index = new int[10]{10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 99999};
    clock_t ARRAY_query_start, ARRAY_query_finish;
    ARRAY_query_start = clock();
    //QueryPerformanceCounter(&t1);
    ARRAY_Query(data_ARRAY, Query_index, ARRAY_length);
    ARRAY_query_finish = clock();
    //QueryPerformanceCounter(&t2);
    double ARRAY_query_time = (double)(ARRAY_query_finish - ARRAY_query_start) / CLOCKS_PER_SEC;
    cout << "ARRAY_query_time = " << ARRAY_query_time << " s" << endl;  //输出时间（单位：ｓ）

    // ======= 删除 =======
    int* Delete_index = new int[10]{15000, 25000, 35000, 45000, 55000, 65000, 75000, 85000, 95000, 99999 };
    //QueryPerformanceCounter(&t1);
    clock_t ARRAY_delete_start, ARRAY_delete_finish;
    ARRAY_delete_start = clock();
    ARRAY_Delete(data_ARRAY, Delete_index, ARRAY_length);
    ARRAY_delete_finish = clock();
    //QueryPerformanceCounter(&t2);
    double ARRAY_delete_time = (double)(ARRAY_delete_finish - ARRAY_delete_start) / CLOCKS_PER_SEC;
    cout << "ARRAY_delete_time = " << ARRAY_delete_time << " s" << endl;  //输出时间（单位：ｓ）

    /* 数组部分（结束） */
    cout << endl;


    /* 链表部分 （开始）*/
    //生成链表头
    LINKED_node* HEAD = created_LINKED();

    for (int i = 0; i < 99900; i++) {
        LINKED_node* new_data = new LINKED_node;
        new_data->mac = dataList[i].mac;
        new_data->index = dataList[i].index;
        new_data->next = NULL;
        LINKED_Insert(HEAD, new_data);
    }

    // ======= 插入 =======
    clock_t LINKED_insert_start, LINKED_insert_finish;
    //QueryPerformanceCounter(&t1);
    LINKED_insert_start = clock();
    for (int i = 0; i < 100; i++) {
        LINKED_node* new_data = new LINKED_node;
        new_data->mac = dataList[i + 99900].mac;
        new_data->index = dataList[i + 99900].index;
        new_data->next = NULL;
        LINKED_Insert(HEAD, new_data);
    }
    //QueryPerformanceCounter(&t2);
    LINKED_insert_finish = clock();
    double LINKED_insert_time = (double)(LINKED_insert_finish - LINKED_insert_start) / CLOCKS_PER_SEC;
    cout << "LINKED_insert_time = " << LINKED_insert_time << " s" << endl;  //输出时间（单位：ｓ）

    // ======= 查找 =======
    clock_t LINKED_query_start, LINKED_query_finish;
    LINKED_query_start = clock();
    //QueryPerformanceCounter(&t1);
    LINKED_Query(HEAD, Query_index);
    LINKED_query_finish = clock();
    //QueryPerformanceCounter(&t2);
    double LINKED_query_time = (double)(LINKED_query_finish - LINKED_query_start) / CLOCKS_PER_SEC;
    cout << "LINKED_query_time = " << LINKED_query_time << " s" << endl;  //输出时间（单位：ｓ）

    // ======= 删除 =======
    clock_t LINKED_delete_start, LINKED_delete_finish;
    LINKED_delete_start = clock();
    //QueryPerformanceCounter(&t1);
    LINKED_Delete(HEAD, Delete_index);
    LINKED_delete_finish = clock();
    //QueryPerformanceCounter(&t2);
    double LINKED_Delete_time = (double)(LINKED_delete_finish - LINKED_delete_start) / CLOCKS_PER_SEC;
    cout << "LINKED_Delete_time = " << LINKED_Delete_time << " s" << endl;  //输出时间（单位：ｓ）;

    /* 链表部分 （结束）*/
    cout << endl;


    /*红黑树部分（开始）*/
    //生成红黑树
    RBTree* tree = new RBTree();
    for (int i = 0; i < 99900; i++)
        tree->insert(dataList[i].index, dataList[i].mac);

    // ======= 插入 =======
    clock_t RBTREE_insert_start, RBTREE_insert_finish;
    RBTREE_insert_start = clock();
//    QueryPerformanceCounter(&t1);
    for (int i = 99900; i < 100000; i++)
        tree->insert(dataList[i].index, dataList[i].mac);
    RBTREE_insert_finish = clock();
//    QueryPerformanceCounter(&t2);
    double RBTREE_insert_time = (double)(RBTREE_insert_finish - RBTREE_insert_start) / CLOCKS_PER_SEC;
    cout << "RBTREE_insert_time = " << RBTREE_insert_time << " s" << endl;  //输出时间（单位：ｓ）;

    // ======= 查找 =======
    clock_t RBTREE_query_start, RBTREE_query_finish;
    RBTREE_query_start = clock();
//    QueryPerformanceCounter(&t1);
    for (int i = 0; i < 10; i++)
        cout << Query_index[i] << " : " << tree->search(Query_index[i])->mac << endl;
    RBTREE_query_finish = clock();
//    QueryPerformanceCounter(&t2);
    double RBTREE_Query_time = (double)(RBTREE_query_finish - RBTREE_query_start) / CLOCKS_PER_SEC;
    cout << "RBTREE_Query_time = " << RBTREE_Query_time << " s" << endl;  //输出时间（单位：ｓ）;

    // ======= 删除 =======
    clock_t RBTREE_delete_start, RBTREE_delete_finish;
    RBTREE_delete_start = clock();
//    QueryPerformanceCounter(&t1);
    for (int i = 0; i < 10; i++)
        tree->remove(Delete_index[i]);
    RBTREE_delete_finish = clock();
//    QueryPerformanceCounter(&t2);
    double RBTREE_Delete_time = (double)(RBTREE_delete_finish - RBTREE_delete_start) / CLOCKS_PER_SEC;
    cout << "RBTREE_Delete_time = " << RBTREE_Delete_time << " s" << endl;  //输出时间（单位：ｓ）;

    /*红黑树部分（结束）*/
    cout << endl;
}

void RBTree_test()//红黑树测试函数，供同学在补全红黑树函数时测试正确性，验收时也会用此函数对红黑树代码正确性进行测试
{
    /*红黑树测试示例---检验所编写的红黑树函数正确性--【自行编码可随意修改嬉戏，验收前请还原测试示例】*/
    RBTree* test = new RBTree();
    cout << "RBTree test" << endl;
    test->insert(8, "I");
    test->print();
    test->insert(2, "L");
    test->print();
    test->insert(5, "O");
    test->print();
    test->insert(9, "V");
    test->print();
    test->insert(1, "E");
    test->print();
    test->insert(7, "U");
    test->print();
    test->insert(6, "S");
    test->print();
    test->insert(10, "T");
    test->print();
    test->insert(4, "C");
    test->print();
    test->remove(2);
    test->print();
    /*红黑树测试结束*/
    cout << endl;
}

int main()
{
    acceptance_test();//实验验收
    RBTree_test();//红黑树测试

    return 0;
}