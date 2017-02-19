/*
  Compare two linked lists A and B
  Return 1 if they are identical and 0 if they are not. 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int CompareLists(Node *headA, Node* headB) {
    if (headA == NULL && headB == NULL) return 1;
    if (headA == NULL || headB == NULL) return 0;
    if (headA->data != headB->data) return 0;
    
    int equal = 1;
    
    Node *currentA = headA, *currentB = headB;
    
    while(currentA->next != NULL && currentB->next != NULL) {
        
        if (currentA->data != currentB->data) {
            equal = 0;
            return equal;
        }
        
        currentA = currentA->next;
        currentB = currentB->next;
        
        if ((currentA->next == NULL && currentB->next != NULL)
           || (currentA->next != NULL && currentB->next == NULL)) {
            equal = 0;
            return equal;
        }

    }
    
    return equal;
}

