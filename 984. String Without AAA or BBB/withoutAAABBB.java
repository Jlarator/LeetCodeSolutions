class Solution {
    public String strWithout3a3b(int a, int b) {
        int size = 3; 
 
        int total = a + b; 
        int len = size - 1;  
        
        String max, min; 
        int maxInt, minInt; 
        
        if(a > b){
            max = "a"; 
            min = "b";
            maxInt = a; 
            minInt = b; 
        }else{
            max = "b"; 
            min = "a"; 
            maxInt = b; 
            minInt = a; 
        }
        
        String output = ""; 
        
        while(total > 0){
            
            if(minInt == maxInt){
             len = 1; 
            }
            
            for(int i = 0; i < len; i++){
                if(maxInt > 0){
                    output += max; 
                    maxInt--; 
                    total--; 
                }
            }
            if(minInt > 0){
                output += min; 
                minInt--; 
                total--; 
            }
            
        }
        
        return output; 
    }
    
    
}
