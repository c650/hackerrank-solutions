/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail) { 
    int displacement = 0;
    
    Node *current, *result;
    current = result = head;
    
    while (displacement < positionFromTail && current->next != NULL) {
        current = current->next;
        
        displacement++;
    }
    
    while (current->next != NULL) {
        current = current->next;
        result = result->next;
    }
    
    return result->data;
}
