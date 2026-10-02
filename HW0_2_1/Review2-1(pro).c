#include <stdio.h>
#include <string.h>
void print_reverse(char *str, int end) 
{
       char tmp;
     
       printf("%c", str[end]);

       if (end == 0) 
		   return;
	   else
          print_reverse(str, --end);
}

int main()
{
     char str[100];

     printf("Enter any string:");
     scanf("%s", str); 

     printf("Reversed String is: ");
     print_reverse(str, strlen(str) - 1);
     return 0;
}
