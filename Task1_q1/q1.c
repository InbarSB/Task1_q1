#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

void generate(char* charSet, int charSetSize, char* phrase, int phraseLen)
{
	//halting condition
	if (phraseLen == 0)
	{
		printf("%s\n", phrase);
		return;
	}
	for (int i = 0; i < charSetSize; i++) {
		//create current string - with the next char we need to add to the string
		//call generate func again with phaseLen-- - until we reach the Len - phaseLen==0 - Base case
		phrase[phraseLen - 1] = charSet[i];		
		generate(charSet, charSetSize, phrase, phraseLen - 1);    
	}

}
int main()
{
	const int MAX_PHRASE_LEN = 3;
	char* phrase = calloc(MAX_PHRASE_LEN + 1, sizeof(*phrase));
	if (phrase == NULL)
		exit(1); char charSet[] = { 'a','#','*' };
	int charSetSize = sizeof(charSet) / sizeof(charSet[0]);
	for (int i = 1; i <= MAX_PHRASE_LEN; i++)
	{
		printf("all sequences of length %d:\n", i);
		printf("##########################\n");
		generate(charSet, charSetSize, phrase, i);
	}
	free(phrase);
	return 0;
}

