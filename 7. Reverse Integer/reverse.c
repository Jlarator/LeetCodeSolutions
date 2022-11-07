

int reverse(int x){
    
    // 846 384 741 2 
    if(x==-2147483648) return 0;
    if(x == 0) return 0; 
    
    int mult = (x <0) ? -1 : 1; 
    
    x = (x >= 0) ? x : -x;
    int maxp = 0; 
    
    
    while(x > pow(10, maxp + 1) ){
         maxp++; 
     }
    
    int temp;
    int index = 0;
    int divisor = 0; 
    int output2 = 0; 
    int powStart = 0; 
    int adder = 0; 
    
    while(x > 0){
        divisor = (int) pow(10, maxp); 
        temp = x / divisor; 
        adder = pow(10, powStart) * temp;
        if (adder > (2147483648 - output2)) return 0; 
        output2 += adder; 
        x  = x % divisor; 
        maxp--;
        powStart++; 
    }
    
    if(output2 <=0) return 0; 
    
    while(output2 % 10 == 0){
        output2 =  output2 / 10; 
    }
     
    return output2 * mult; 
}
