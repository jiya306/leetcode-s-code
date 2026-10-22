#include <iostream>
using namespace std;

struct node {
    int val;
    node* next;

    node(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    node* mergeTwoLists(node* list1, node* list2) {
        if (list1 == NULL)
            return list2;

        if (list2 == NULL)
            return list1;

        node* head;

        if (list1->val <= list2->val) {
            head = list1;
            list1 = list1->next;
        }
        else {
            head = list2;
            list2 = list2->next;
        }

        node* curr = head;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            }
            else {
                curr->next = list2;
                list2 = list2->next;
            }

            curr = curr->next;
        }

        if (list1 != NULL)
            curr->next = list1;
        else
            curr->next = list2;

        return head;
    }
};