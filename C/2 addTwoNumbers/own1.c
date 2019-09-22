/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int res = 0;
    long sum = 0;
    int i = 0;
    struct ListNode * resultNode = (struct ListNode *)malloc(sizeof(struct ListNode ));
    struct ListNode * firstNode = resultNode;
    while(l1!=NULL||l2!=NULL){
        int n1 = l1!=NULL?(*l1).val:0;
        int n2 = l2!=NULL?(*l2).val:0;
        int temp = n1+n2+res;
        res = temp/10;
        temp = temp%10;
        
        if(l1)
            l1 = l1->next;
        if(l2)
            l2 = l2->next;
        
        struct ListNode * nextNode = (struct ListNode *)malloc(sizeof(struct ListNode ));
        resultNode->val = temp;
        if(l1!=NULL||l2!=NULL){
            resultNode->next = nextNode;
            resultNode = nextNode;
        }else{
            resultNode->next =NULL;
        }
        i++;
    }
    if(res != 0){
        struct ListNode * nextNode = (struct ListNode *)malloc(sizeof(struct ListNode ));
        nextNode->val = res;
        nextNode->next =NULL;
        resultNode->next = nextNode;
        
    }
    
    return firstNode;

}

