/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL) return l2; 
    else if(l2  == NULL) return l1; 
    
    int carryOver = 0; 
    int nodeSize = sizeof(struct ListNode); 
    
    struct ListNode* output = l1;
    struct ListNode* itr; 
    struct ListNode* ptr; 
    struct ListNode* pt1; 
    struct ListNode* pt2; 
    
    while(l1 != NULL && l2 != NULL){
        
        int val = l1->val + l2->val + carryOver; 
        
        int current = val % 10; 
        carryOver = val / 10; 
        
        l1->val = current; 
        
        pt1 = l1; 
        
        l1 = l1->next; 
        l2 = l2->next; 
    }
    
    itr = pt1;;
    
    if(l1 == NULL && l2 != NULL){
        ptr = l2;
        pt1->next = ptr; 
    }else if(l1 != NULL && l2 == NULL){
        ptr = l1;
        pt1->next = ptr; 
    }else if(l1 == NULL && l2 == NULL){
        if(carryOver>0){
            struct ListNode *newNode = malloc(nodeSize);
            newNode->val = carryOver; 
            newNode->next = NULL; 
            itr->next = newNode; 
            
        }
        return output; 
    }
    
     
    
    while(ptr != NULL){
        
        int val = ptr->val + carryOver; 
        int current = val % 10; 
        carryOver = val / 10; 
        ptr->val = current; 
        
        itr = ptr; // do not touch
        ptr = ptr->next; 
    }
    
    while(carryOver > 0){
        
        int val = itr->val + carryOver; 
        int current = val % 10; 
        carryOver = val / 10; 
        
        struct ListNode *newNode = malloc(nodeSize); 
        newNode->val = current; 
        newNode->next = NULL; 
        itr->next = newNode; 
    }
    
    
    return output; 
    
}
