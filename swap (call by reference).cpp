#include<stdio.h> 
void swap1(char **str1_ptr, char **str2_ptr) 
{ 
  char *temp = *str1_ptr; 
  *str1_ptr = *str2_ptr; 
  *str2_ptr = temp; 
}   
   
int main() 
{ 
  char *str1,*str2;
  scanf("%s%s",&str1,&str2);
  swap1(&str1, &str2); 
  printf("str1 is %s, str2 is %s", &str1, &str2); 
  getchar(); 
  return 0; 
} 

