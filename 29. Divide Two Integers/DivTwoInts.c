long long helper(long long dividend, long long divisor, long long keeper){
    if(dividend < divisor) return keeper; 
    if(keeper == INT_MAX) return keeper; 
    
    long long sum = divisor; 
    long long count = 1; 
    
    long long tmpSum; 
    long long tmpCount = count;
    while(dividend > sum){
        // 30
        // 7    14  28
        // 1    2   4
        tmpSum = sum; 
        tmpCount = count; 
        
        sum = sum << 1; 
        count = count << 1; 
        
    }
    
    dividend -= tmpSum; 
    keeper += tmpCount; 
    
    return helper(dividend, divisor, keeper); 
    
}

int divide(int dividend, int divisor){
    
    if(divisor == 1) return dividend; 
    
    long long sign = 1; 
    if(dividend < 0 && divisor > 0) sign = -1; 
    else if(dividend > 0 && divisor < 0) sign = -1; 
    
    long long output = 1; 
    
    long long ll_dividend = dividend; 
    long long ll_divisor = divisor; 
    
    ll_dividend = llabs(ll_dividend); 
    ll_divisor = llabs(ll_divisor); 
    
    long long sum = divisor; 
    
    output = helper(ll_dividend, ll_divisor, 0); 
    if(sign < 0) output = -output; 
    
    int out = (int) output; 
    return  out; 

}
