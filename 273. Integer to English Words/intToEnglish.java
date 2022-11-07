class Solution {
    
    public String getWord(int num){
        
        String output = ""; 
        
        switch(num){
            case (1):
                output = "One"; 
                break; 
            case(2):
                output =  "Two"; 
                break; 
            case(3):
                output = "Three"; 
                break; 
            case(4):
                output = "Four";
                break; 
            case(5):
                output =  "Five";
                break; 
            case(6):
                output =  "Six"; 
                break;
            case(7):
                output = "Seven"; 
                break; 
            case(8):
                output = "Eight";
                break; 
            case(9):
                output =  "Nine"; 
                break; 
            case(10):
                output += "Ten"; 
                break;  
            case(11):
                output += "Eleven"; 
                break;
            case(12):
                output += "Twelve"; 
                break;  
            case(13):
                output += "Thirteen";
                break;  
            case(14):
                output += "Fourteen"; 
                break; 
            case(15):
                output += "Fifteen";
                break;
            case(16): 
                output += "Sixteen"; 
                break;
            case(17):
                output += "Seventeen"; 
                break; 
            case(18):
                output += "Eighteen"; 
                break;
            case(19):
                output += "Nineteen";
                break; 
        }
        
        return output; 
        
    }
    public String numberToWords(int num) {
        
        if(num == 0) return "Zero"; 
        
        String output = ""; 
        
        int B = 0; 
        
        while(num > 999999999){
            num -= 1000000000;
            B++; 
        }
        
        if(B < 10 && B > 0){
            output += getWord(B); 
            output += " Billion";
            if(num > 0) output += " ";
        }else if(B > 9){
            output += numberToWords(B) + " Billion"; 
            if(num > 0) output += " ";
        }
        
        int M = 0; 
        
        while(num > 999999){
            num -= 1000000; 
            M++; 
        }
        
        if(M < 10 && M > 0){
            output += getWord(M); 
            output += " Million"; 
            if(num > 0) output += " ";
        }else if(M > 9){
            output += numberToWords(M) + " Million"; 
            if(num > 0) output += " ";
        }
        
        int T = 0; 
        
        while(num > 999){
            num -= 1000; 
            T++; 
        }
        
        if(T < 10 && T > 0){
            output += getWord(T);
            output += " Thousand"; 
            if(num > 0) output += " ";
        }else if(T > 9){
            output += numberToWords(T) + " Thousand"; 
            if(num > 0) output += " ";
        }
        
        int H = 0; 
        
        while(num > 99){
            num -= 100; 
            H++; 
        }
        
        if(H < 10 && H > 0){
            output += getWord(H); 
            output += " Hundred"; 
            if(num > 0) output += " ";
        }else if(H > 9){
            output += numberToWords(H) + " Hundred"; 
            if(num > 0) output += " ";
        }
        
        if(num > 19){
            
            if(num > 89){
                num -= 90; 
                output += "Ninety"; 
                if(num > 0) output += " ";
            }else if(num < 90 && num > 79){
                num -= 80; 
                output += "Eighty"; 
                if(num > 0) output += " ";
            }else if(num < 80 && num > 69){
                num -= 70; 
                output += "Seventy"; 
                if(num > 0) output += " ";
            }else if(num < 70 && num > 59){
                num -= 60; 
                output += "Sixty"; 
                if(num > 0) output += " ";
            }else if(num < 60 && num > 49){
                num -= 50; 
                output += "Fifty";
                if(num > 0) output += " ";
            }else if(num < 60 && num > 39){
                num -= 40; 
                output += "Forty"; 
                if(num > 0) output += " ";
            }else if(num < 40 && num > 29){
                num -= 30; 
                output += "Thirty"; 
                if(num > 0) output += " ";
            }else if(num < 30 && num > 19){
                num -= 20; 
                output += "Twenty"; 
                if(num > 0) output += " ";
            }
            
            if(num != 0) output += getWord(num); 
            return output; 
            
        }else if(num > 9 && num < 20){
            output += getWord(num); 
            return output; 
            
        }else if(num < 10){
            output += getWord(num); 
            return output; 
        }
        
        return output; 
        
    }
}
