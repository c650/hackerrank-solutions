/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB) {
    if (headA == NULL) {
        return headB;
    } else if (headB == NULL) {
        return headA;
    }
    
    Node *resultHead, *currentA = headA, *currentB = headB;
    
    if (headA && headB) {
        if (headA->data < headB->data) {
            resultHead = headA;
            currentA = currentA->next;
        } else {
            resultHead = headB;
            currentB = currentB->next;
        }
    } 
    
    resultHead->next = MergeLists(currentA, currentB);
    
    return resultHead;
}

