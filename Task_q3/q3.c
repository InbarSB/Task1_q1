#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS 

int strCmpRec(char* s1, char* s2)
{
    char tmp1 = *s1, tmp2 = *s2;
    if (tmp1 < tmp2) 
        return -1;         // check if char of s1 less than char of s2
    if (tmp1 > tmp2) 
        return 1;          // check if char of s1 great than char of s2
    if (tmp1 == '\0') 
        return 0;         // check if char of s1 equal than char of s2
    return strCmpRec(s1 + 1, s2 + 1);   //move to the next char
}


void main() {
	char s1[] = "aabcdt", s2[] = "abcdef";
    char s3[] = "fdbc", s4[] = "abcdef";
    char s5[] = "abcdef", s6[] = "abcdef";
    int result = 0, res_strcmp = 0;
	result = strCmpRec(s1, s2);          //recursive call with s1 and s2
    printf("1st STR is: %s\n", s1);
    printf("2nd STR is: %s\n", s2);
    if (result == -1)                     //print if s1 is before s2
        printf("lexical order is:\ns1->%s\ns2->%s\n", s1, s2);
    else if (result == 1)                 //print if s2 is before s1
        printf("lexical order is:\ns2->%s\ns1->%s\n", s2, s1);
    else
        printf("s1 and s2 are equal\n");
    result = strCmpRec(s3, s4);         //recursive call with s3 and s4
    printf("1st STR is: %s\n", s3);
    printf("2nd STR is: %s\n", s4);
    if (result == -1)
        printf("lexical order is:\ns1->%s\ns2->%s\n", s3, s4);
    else if (result == 1)
        printf("lexical order is:\ns2->%s\ns1->%s\n", s4, s3);
    else
        printf("s1 and s2 are equal\n");
    result = strCmpRec(s5, s6);
    printf("1st STR is: %s\n", s5);
    printf("2nd STR is: %s\n", s6);
    if (result == -1)
        printf("lexical order is:\ns1->%s\ns2->%s\n", s5, s6);
    else if (result == 1)
        printf("lexical order is:\ns2->%s\ns1->%s\n", s6, s5);
    else
        printf("s1 and s2 are equal\n");
}