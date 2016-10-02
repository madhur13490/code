#include<bits/stdc++.h>

using namespace std;


class node
{
        public:
                node *next;
                int data;
};

node* createNode(int a)
{
        node* n = new node;
        n->next = NULL;
        n->data = a;
        return n;
}

void printLL(node* head)
{
        while(head != NULL) {
                cout << head->data << " ";
                head = head->next;
        }
}

node* createLL(std::initializer_list<int> l)
{
        node *last = NULL, *head = NULL, *n;

        for (auto i : l) {
                n = createNode(i);
                if (last == NULL) {
                        head = n;
                        last = n;
                } else {
                        last->next = n;
                        last = n;
                }
        }

        cout << "printing ll";
        printLL(head);
        return head;
}

int main()
{
        std::initializer_list<int> l = {1, 2, 3, 4, 5};
        createLL(l);
        return 0;
}
