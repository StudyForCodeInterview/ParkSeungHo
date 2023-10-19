#include <iostream>
#include <vector>
#include <cassert>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void PrintList(ListNode* head)
{
    while (head != nullptr)
    {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("\n");
}
ListNode* MakeList(int arr[], int size)
{
    if (size < 1)
        return nullptr;
    ListNode* head = nullptr;
    ListNode* cur = nullptr;
    for (int i = 0; i < size; i++)
    {
        if (head == nullptr)
        {
            head = new ListNode(arr[i]);
            cur = head;
        }
        else
        {
            cur->next = new ListNode(arr[i]);
            cur = cur->next;
        }
    }
    return head;
}

//class Solution {
//public:
//    void reorderList(ListNode* head) {
//        ListNode* arr[50000];
//        int listSize = 0;
//        ListNode* tmp = head;
//
//        while (tmp != nullptr)
//        {
//            arr[listSize] = tmp;
//            tmp = tmp->next;
//            arr[listSize]->next = nullptr;
//            listSize++;
//        }
//
//        if (listSize == 1)
//        {
//            head = arr[0];
//            return;
//        }
//
//        int startIndex = 0;
//        int lastIndex = listSize - 1;
//        head = arr[0];
//        ListNode* cur = nullptr;
//        for (int i = 0; i < listSize / 2 + 1; i++)
//        {
//            if (i > lastIndex)
//                break;
//            if (cur == nullptr)
//            {
//                cur = arr[i];
//                cur->next = arr[lastIndex--];
//                cur = cur->next;
//            }
//            else if (i == lastIndex)
//            {
//                cur->next = arr[i];
//            }
//            else
//            {
//                cur->next = arr[i];
//                cur = cur->next;
//                cur->next = arr[lastIndex--];
//                cur = cur->next;
//            }
//        }
//    }
//};
#include <stack>

class Solution {
public:
    void reorderList(ListNode* head) {
        std::stack<ListNode*> st;

        if (head->next == nullptr)
            return;

        int size = 0;
        ListNode* cur = head;
        while (cur != nullptr)
        {
            cur = cur->next;
            size++;
        }

        if (size % 2 == 0)
        {
            cur = head->next;
            while (cur->next != nullptr)
            {
                st.push(cur);
                cur = cur->next->next;
            }
            st.push(cur);

            cur = head;
            while (cur->next != nullptr)
            {
                ListNode* top = st.top();
                if (cur->val >= top->val)
                {
                    cur->next->next = nullptr;
                    break;
                }
                st.pop();
                top->next = cur->next;
                cur->next = top;
                cur = cur->next->next;
            }
        }
        else
        {

        }
    }
};

int main(void)
{
    Solution s;
    int arr1[] = { 1, 2, 3, 4 };
    int arr2[] = { 1, 2, 3, 4, 5 };
    int arr3[] = { 1 };
    int arr4[] = { 1, 2, 3, 4, 5, 6 };

    ListNode* head = MakeList(arr1, 4);
    PrintList(head);
    s.reorderList(head);
    PrintList(head);
    printf("-------------------------------\n");
    head = MakeList(arr2, 5);
    PrintList(head);
    s.reorderList(head);
    PrintList(head);
    printf("-------------------------------\n");
    head = MakeList(arr3, 1);
    PrintList(head);
    s.reorderList(head);
    PrintList(head);
    printf("-------------------------------\n");
    head = MakeList(arr4, 6);
    PrintList(head);
    s.reorderList(head);
    PrintList(head);
    return 0;
}