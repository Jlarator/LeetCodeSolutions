

bool checkString(char * s){
    
    int b = 0; 
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == 'a'){
            if (b){
                return 0; 
            }
        }else{
            b = 1; 
        }
       
    }
    return 1; 
}
