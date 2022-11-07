/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    
    if(list1 == NULL && list2 != NULL){
        return list2; 
    }else if(list1 != NULL && list2 == NULL){
        return list1; 
    }else if(list1 == NULL && list2 == NULL){
        return NULL; 
    }
    
    struct ListNode *output= malloc(sizeof(struct ListNode)); 
    
    if(list1->val < list2->val){
        *output = *list1; 
        list1 = list1->next; 
    }else{
        *output = *list2; 
        list2 = list2->next; 
    }
    
    struct ListNode *listpointer = output; 
    
    while(list1 != NULL && list2 !=NULL){
        if(list1->val < list2->val){
            listpointer->next = list1; 
            list1 = list1->next; 
        }else{
            listpointer->next = list2; 
            list2 = list2->next; 
        }
        listpointer = listpointer->next; 
    }
    
    while(list1 != NULL && list2 == NULL){
        listpointer->next = list1; 
        list1 = list1->next; 
        listpointer = listpointer->next; 
    }
    
    while(list1 == NULL && list2 != NULL){
        listpointer->next = list2; 
        list2 = list2->next; 
        listpointer = listpointer->next; 
    }
    
    return output; 

}
