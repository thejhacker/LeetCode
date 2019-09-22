struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int flag = 0, nodeSum = 0, freeflag = 0;
    struct ListNode *ret,*now,*high,*freeBegin,*freeEnd;
    for(ret = l1, now = l1, high = l2, freeBegin = l2;l1  || l2  || flag ;) {  
        if (l1 == NULL && l2 == NULL) {
              now->next = high;
              now = now->next;
              freeBegin = now->next;
        }
        nodeSum = ( l1  ? l1->val : 0 ) + (l2 ? l2->val : 0) + flag;  
        now->val = nodeSum % 10;    
        flag =  nodeSum / 10; 
        l1 ? l1 = (l1->next ? l1->next : NULL) : NULL;
        if(l1 == NULL && 0 == freeflag && l2) {
            freeEnd = l2;
            freeflag = 1;
        }
        l2 ? l2 = (l2->next ? l2->next : NULL) : NULL;
        now->next = ( l1 ? l1 : (l2 ?  l2 : NULL) );
        now->next ? now = now->next : NULL;
    }
    l2 = freeBegin;
    freeEnd->next = NULL;
    return ret;
}

//作者：XiaoO
//链接：https://leetcode-cn.com/problems/add-two-numbers/solution/0e-wai-kong-jian-by-15885445/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。