                             //Returning the Middle Node of Linked List
//Time complexity: O(n)
//Space complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

public:
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int lengthofLL(Node* head) {
    int cnt = 0;
    Node* temp = head;
    while (temp) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

Node* middleNode(Node* head) {
    int len = lengthofLL(head);
    int mid = len / 2;

    Node* temp = head;
    while (mid--) {
        temp = temp->next;
    }
    return temp;
}

int main() {
    vector<int> arr = {3, 8, 2, 9};
    Node* head = convertArr2LL(arr);

    Node* middle = middleNode(head);
    cout << middle->data;
}
