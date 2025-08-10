// check wheater a string is palindrome or not.

#include <stdio.h>
#include <string.h>
 
int main()
{
    char s[1000];  
    int i, n, c = 0;
 
    printf("Enter  the string : ");
    gets(s);

    for(n = 0; s[n] != '\0'; n++);
 
    for(i = 0; i < n / 2; i++){
    	if(s[i] == s[n - i - 1])
    	c++;
 	}
 	if(c == i)
 	    printf("string is palindrome");
    else
        printf("string is not palindrome");
 
 	 
     
    return 0;
}