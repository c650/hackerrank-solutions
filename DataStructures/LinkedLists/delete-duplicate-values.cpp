/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node *current = head->next, *last = head;
    
    while(current != NULL) {
        if (last->data == current->data) {
            Node* temp = current;
            
            last->next = current->next;
            current = last->next;
            
            delete [] temp;
        } else {
            last = current;
            current = current->next;
        }
    }
    
    return head;
}

