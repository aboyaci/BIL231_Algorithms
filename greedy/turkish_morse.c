 /*
        Morse Code for Turkish Language
        -------------------------------

        Letter frequincy source
        http://letterfrequency.org/
 */

#include <stdio.h>
#include <stdlib.h>

char freq_ordered_letters[] = {'a', 'e', 'i', 'n', 'r', 'l', 'ý', 'd', 'k', 'm', 'u', 'y', 't', 's', 'b', 'o', 'ü', 'þ', 'z', 'g', 'ç', 'h', 'ð', 'v', 'c', 'ö', 'p', 'f', 'j'	};

/*
	Convert code to morse
	The trick is :

	z = 20 => .-..
		which is 10100 in binary 

	when we get ignore the first digit, and replace 0 with dot and 1 with dash we have the morse code! 
*/
int convert_to_morse(int code, char* buffer)
{
	unsigned int mask = 1 << 31;
	int count = 0;

	/* skip the leading zeros */
	while(!(code & mask))
	{
		mask >>= 1;
	}

	/* skip the first digit, so remaining digits can be directly converted to morse */
	mask >>= 1;

	while(mask)
	{
		if(code & mask)
		{
			buffer[count] = '-';
		}
		else
		{
			buffer[count] = '.';
		}

		mask >>= 1;
		count++;
	}

	buffer[count] = '\0';

	return count;
}

int main()
{
	int i;
	int code = 2; /* code starts from 2 to have a proper tree! */
	char buffer[10] = "";

	for (i=0; i<sizeof(freq_ordered_letters); i++)
	{
		convert_to_morse(code, buffer);
		printf("%c (%d) = %s\n", freq_ordered_letters[i], code, buffer);
		code++;
	}

	return EXIT_SUCCESS;
}