#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class CompareNode {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, CompareNode> minHeap;

    for (int i = 0; i < (int)lists.size(); i++) {
        if (lists[i] != nullptr) {
            minHeap.push(lists[i]);
        }
    }
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (!minHeap.empty()) {

        ListNode* smallest = minHeap.top();
        minHeap.pop();

        tail->next = smallest;
        tail = tail->next;

        if (smallest->next != nullptr) {
            minHeap.push(smallest->next);
        }
    }

    return dummy.next;
}
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << endl;
}

int main() {
    
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

   
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode*> lists = {l1, l2, l3};
    ListNode* mergedHead = mergeKLists(lists);

    printList(mergedHead);
    return 0;
}