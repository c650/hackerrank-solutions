/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data) {       
    
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    
    if (head == NULL) {
        head = new_node;
        return head;
    }
    
    Node* curr = head;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
    return head;
}

