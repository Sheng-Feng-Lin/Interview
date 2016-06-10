#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define u16 unsigned long
#define u8 unsigned short

void String_Reverse(char *s);
u16 String_Length(char *s); 
int String_Cmp(char *s, char *t);

int main()
{
	char s[] = "abcdefgbbbbbb";
	char t[] = "abcdefgbbbbbbb";
	int i = 0;
	char temp;
	
	printf("Original String is : %s\n",s);
	//String_Reverse(s);
	printf("String Length is %lu\n",String_Length(s));
	printf("String Compare is %d\n", String_Cmp(s,t));


	return 0;
}

void String_Reverse(char *s)
{
	char temp;
	u16 i = 0;
	for(i = 0; i < String_Length(s)/2; i++){
		temp = s[i];
		s[i] = s[String_Length(s)-i-1];
		s[String_Length(s)-i-1] = temp;
	}
	printf("Reverse String is : %s\n", s);

}

u16 String_Length(char *s)
{
	u16 length = 0;
	while(*s != '\0'){
		s++;
		length++;
	}
	return length;
}

int String_Cmp(char *s, char *t)
{
	do{
		if((*s-*t)!=0)
			break;
		else{
			s++;
			t++;
		}

	}while(((*s-*t)==0 && (*s != '\0' && *t != '\0')));
	return (*s-*t);
}


