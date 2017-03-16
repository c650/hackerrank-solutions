/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
  
  1 2 3 4
*/
Node* Reverse(Node *head) {
    
    if (head == NULL || head->next == NULL) return head;
    
    Node* next_node = head->next; // hold place of second node
    
    head->next = NULL; // set the head to be the end of the list
        
    Node* new_head = Reverse(next_node);
    
    next_node->next = head; // make head the last term in list
    
    return new_head;
}

