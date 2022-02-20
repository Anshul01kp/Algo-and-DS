#include <iostream>

class Node{
public:
    int data;
    Node *next;

    explicit Node(int value){
        data = value;
        next = nullptr;
    }
};

class LinkedListInsertion{

public:
    static Node *insertAtFront(Node *head, int value){
        Node *temp = new Node(value);

        temp->next = head;
        head = temp;

        return head;
    }

    static Node *insertAtLast(Node *head, int value){
        if(head == nullptr){
            return new Node(value);
        }

        Node *temp = new Node(value);
        Node *curr = head;

        while(curr->next != nullptr){
            curr = curr->next;
        }

        curr->next = temp;

        return head;
    }

    static Node *insertAfter(Node *head, int value, int position){
        Node *temp = new Node(value);
        Node *curr = head;

        for(int i = 1; i < position; i++){
            curr = curr->next;
        }

        temp->next = curr->next;
        curr->next = temp;

        return head;
    }

    static void displayLinkedList(Node *head){
        Node *curr = head;
        while(curr != nullptr){
            std::cout << curr->data << std::endl;
            curr = curr->next;
        }
    }
};

int main() {
    Node *head = nullptr;

    for(int i = 1; i <= 5; i++)
        head = LinkedListInsertion::insertAtLast(head, i);

    head = LinkedListInsertion::insertAtFront(head, 0);
    head = LinkedListInsertion::insertAtLast(head, 7);
    head = LinkedListInsertion::insertAfter(head, 6, 6);

    LinkedListInsertion::displayLinkedList(head);

    return 0;
}
