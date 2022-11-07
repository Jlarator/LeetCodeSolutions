bool isPalindrome(int x){
    if(x < 0) return 0; 
    char nums[32]; 
    
    int base = 10; 
    int power = 1; 
    int index = 31; 
    int right = 31; 
    
    while(x > 0){
        
        int newNum = x % 10; 
        nums[index] = newNum; 
        x = x / 10; 
        power++; 
        index--; 
    }
    printf("\n"); 
    index++; 
    while(index < right){
        if(nums[index] != nums[right]){
            return 0; 
        }
        index++; 
        right--; 
        
    }
    
    return 1; 
}
