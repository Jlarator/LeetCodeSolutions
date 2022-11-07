class Solution {
    public int romanToInt(String s) {
        
        int output = 0; 
        String[] romanNums = s.split(""); 
        
        int len = romanNums.length;
        Integer[] list = new Integer[len]; 
        
        for(int i = 0; i < len ; i++){
            
            int currentVal = 0; 
            
            switch(romanNums[i]){
                case "I":
                    currentVal = 1; 
                    break; 
                case "V":
                    currentVal = 5; 
                    break; 
                case "X":
                    currentVal = 10; 
                    break; 
                case "L":
                    currentVal = 50; 
                    break; 
                case "C":
                    currentVal = 100; 
                    break; 
                case "D": 
                    currentVal = 500; 
                    break; 
                case "M":
                    currentVal = 1000; 
                    break; 
            }
            
            list[i] = currentVal;  
            
        }
        
        // XIV
        // X > I -> output = X = 10 
        // I < V -> output += V - 1 -> 14
        
        if(len == 1) return  list[0]; 
        
        for(int i = 0; i < len; i++){
            
           int next = i + 1; 
            if(next < len){
                if(list[i] < list[next]){
                    output += list[next] - list[i];
                    i++; 
                }else{
                    output += list[i]; 
                }
            }else{
                output += list[i]; 
            }
            
        }
       
        return output; 
    }
}
