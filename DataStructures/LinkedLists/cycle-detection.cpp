/*
  Detect loop in a linked list 
  List could be empty also
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
bool find(Node* cache[], int l, Node* q) {
    for (int i = 0; i < l; i++) {
        if (cache[i] == q)
            return true;
    }
    
    return false;
}
int HasCycle(Node* head) {
    if (head == NULL || head->next == NULL)
        return 0;
    
    Node* cache[100];
    int cache_idx = 0;
    
    for (int i = cache_idx; i < 100; i++)
        cache[i] = NULL;
    
    Node* tmp = head;
    
    while(tmp->next != NULL) {
        
        if (find(cache, cache_idx+1, tmp))
            return 1;
            
        cache[cache_idx] = tmp;
        cache_idx++;
        
        tmp = tmp->next;
    }
    
    return 0;
}

