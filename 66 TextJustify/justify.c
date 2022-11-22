/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void stringCopy(char* target, char* new ){
  int len = strlen(new);

  for(int i = 0; i < len; i++){
    target[i] = new[i]; 
  }  
}

void checkSpaces(char* target, int maxWidth){
  printf("Checking spaces\n"); 

  int gaps = 0;
  int spaces = 0;
  char prev = '0' ; 
  for(int i = 0; i < maxWidth; i++){

    if(prev == ' ' && target[i] != ' ') gaps++; 
    if(target[i] == ' ') spaces++;
    prev = target[i]; 
    printf(" %c ", target[i]); 

  }

  // redistribute spaces per gaps
  int spacesPerGap = 0;
  int extra = 0; 
  if(gaps != 0){
    spacesPerGap = spaces / gaps;
    extra = spaces % gaps; 
    //    extra =(extra == 1) ? 0 :extra;     
  }

  printf("Space count = %d | Gaps: %d | Extra: %d\n", spaces, gaps, extra);
    
  char temp[maxWidth];
  int tempIndex = 0;

  for(int i = 0; i < maxWidth; i++){
    if(target[i] != ' '){
      temp[tempIndex] = target[i];
      tempIndex++; 
    }else{
      if(gaps == 0){
	temp[tempIndex] = target[i];	
	tempIndex++; 
      }else{
	
	for(int k = 0; k < spacesPerGap; k++){
	  if(tempIndex == maxWidth - 1) break;
	  if(spaces == 0) break; 
	  temp[tempIndex] = ' ' ;
	  tempIndex++;
	  spaces--;
	
	  if(extra > 0){
	    temp[tempIndex] = ' ';
	    tempIndex++;
	    extra--;
	    spaces--;
	  }	
	}
	
      }
    }    
  }

  for(int i = 0; i < maxWidth; i++){
    target[i] = temp[i]; 
    
  }
  printf("\n"); 
  
}

char ** fullJustify(char ** words, int wordsSize, int maxWidth, int* returnSize){   
     printf("INIt return size %d\n", *returnSize); 
    int charCount = 0;      
    int rowCount = 0;     
    int wordCount = 0;      
    
    for(int i = 0; i < wordsSize; i++){               
      charCount += strlen(words[i]);       
      if(i + 1 < wordsSize){          
          if( (charCount += strlen(words[i+1]) + 1) >= maxWidth){  
              rowCount++;  
              charCount = 0;        
          }       
      }    
    } 
    
    char** output;   
    output = (char**)malloc(sizeof(char*) * rowCount);   
    for(int ir = 0; ir < rowCount; ir++){        
      output[ir] = (char*)malloc(sizeof(char) * (maxWidth + 1));  
      for(int m = 0; m < maxWidth; m++){    
	    output[ir][m] = ' ';    
      }
      output[ir][maxWidth] = '\0';
	
    }      
    int arrIndex = 0;   
    int start = 0;    
    int end = 0;
    int st;
    
    for(int i = 0; i < rowCount; i++){   
      printf("\nROW: %d\n", i);  
      int charCount = 0;    
      int wordNum = 0; 
      int charMarker = 0;

      
      while((charCount < maxWidth) && (end < wordsSize)){
	
	if((charCount) + strlen(words[end]) >= maxWidth){

	  int st = start;
	  int nd = end - 1;
	  int side = 0;
	  int leftIndex = 0;
	  int rightIndex = maxWidth -1;
	  
	  //	  printf("%s ... %s\n", words[start], words[end - 1]);
	  charMarker = 0;
	  ///	  printf("Words to be placed: %d\n", (end - start));

	  
	  /* while(st <= nd){ */
	  /*   stringCopy(&output[i][leftIndex], words[st]); */
	  /*   leftIndex += strlen(words[st]);  */
	  /*   output[i][leftIndex] = ' '; */
	  /*   leftIndex ++; */
	  /*   st++;  */
	  /* } */
	  while(st <= nd){
	    if(side % 2 == 0){
	      //	      printf("|l%d %s |", leftIndex, words[st]);
	      stringCopy(&output[i][leftIndex], words[st]);
	      /* strcpy(&output[i][leftIndex], words[st]);	       */
	      leftIndex += strlen(words[st]);
	      output[i][leftIndex] = ' ' ;
	      leftIndex++;
	      st++;
	    }else{
	      rightIndex -= strlen(words[nd]) - 1;
	      //	      printf("|r%d %s |", rightIndex, words[nd]);
	      stringCopy(&output[i][rightIndex], words[nd]);
	      
	      nd--;
	    }
	    side++;
	  }
	  printf("\n");

	  if(i < rowCount - 1) checkSpaces(output[i], maxWidth);
	  printf(" %s ", output[i]); 
	  
	  start = end;   
	  break;       
	}else if (end == wordsSize - 1){  
	  printf("MID %s ... %s\n", words[start], words[end]);
	  printf("Words to be placed: %d\n", (end - start)); 

	  int st = start;
	  int nd = end;
	  int side = 0;
	  int leftIndex = 0;
	  int rightIndex = maxWidth -1;

	  while(st <= nd){
	    stringCopy(&output[i][leftIndex], words[st]);
	    leftIndex += strlen(words[st]); 
	    output[i][leftIndex] = ' ';
	    leftIndex ++;
	    st++; 
	  }
	  /* while(st <= nd){ */
	    
	  /*   if(side % 2 == 0){ */
	  /*     printf("|r%d %s |", leftIndex, words[nd]); */
	  /*     stringCopy(&output[i][leftIndex], words[st]); */
	  /*     leftIndex += strlen(words[st]); */
	  /*     output[i][leftIndex] = ' '; */
	  /*     leftIndex++; */
	  /*     st++; */
	  /*   }else{ */
	  /*     rightIndex -= strlen(words[nd]) - 1; */
	  /*     printf("|r%d %s |", rightIndex, words[nd]); */
	  /*     stringCopy(&output[i][rightIndex], words[nd]); */
	  /*     nd--; */
	      
	  	  /*   } */
	  /*   side++;  */
	  /* } */
	  printf("\n");

	  if(i < rowCount - 1) checkSpaces(output[i], maxWidth); 
	  printf(" %s ", output[i]); 
	  break; 
	}else{                        
	  charCount += strlen(words[end]) + (wordNum / 2);   
	  wordNum++;            
	  end++;        
	}                
      }              
    }                  
 
    *returnSize = rowCount; 
    printf("\nReturn size assigned to %d\n", *returnSize); 
    return output; 

}
      
int main(int argc, char *argv[]){
  //  char *arr[] = {"This", "is", "an", "example", "of", "text", "justification."}; // 15 -> 7
  //  char *arr[] = {"What", "must", "be", "acknowledgement", "shall", "be"}; // 16
  char *arr[] = {"Science","is","what", "we", "understand", "well", "enough",
    "to","explain","to","a","computer.","Art","is","everything", "else", "we","do"}; // 20
  int maxWidth = 20; 
  
  int size = -1;

  char **output = fullJustify(arr, 8, maxWidth, &size);
  printf("Size is %d\n", size);
  
  for(int i = 0; i < size; i++){
    printf("|%s|\n", output[i]); 
  }
  
  for(int i = 0; i < size; i++){
    free(output[i]); 
  }
  free(output); 
  return 0;
  
}
