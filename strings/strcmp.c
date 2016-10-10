/*
   String compare
*/

#include <stdio.h>

int my_strcmp(char* s1, char* s2)
{
	int i;

	for (i=0; s1[i] == s2[i]; i++)
	{
		if (s1[i] == '\0')
		{
			return 0;
		}
	}

	return ((s1[i] < s2[i])? -1:1);
}

int main()
{
	int i = my_strcmp("ali", "veli");

	if (i > 0)
	{
		printf("str1 > str2\n");
	}
	else if(i < 0)
	{
		printf("str1 < str2\n");
	}
	else
	{
		printf("str1 = str2\n");	
	}
}

