#include "decrypt.h" // Print header file
#include <ctype.h>
#include <stdio.h>

int characters; //globar variable characters
int key; //global variable key



void DecryptionWithKey(int fileSize, unsigned char* charBuffer)
{//start DecryptionWithKey

	for (characters = 0; characters < fileSize-1 ; characters++) //iterating through file
	{
		if (charBuffer[characters] == 99 && charBuffer[characters] != '\0' ) //if key = 99
		{
			key = KeylessDecryption(fileSize, charBuffer); //calling function
			printf("Key:%d\nMessage: ", key);  //print key value
		}
		else if (charBuffer[characters-1] == '\0' || characters == 0) //the character after null or first character in file
		{
			key = charBuffer[characters]; //set key
			printf("Key:%d \nMessage: ", key ); //print key value
		}
		else if (isprint(charBuffer[characters])) //printable characters
		{
			if (charBuffer[characters] - key < 'A') //if key subtraction goes past A ie 65
			{
				charBuffer[characters] = charBuffer[characters] +26; //stay between A and Z
			}
			printf("%c", charBuffer[characters] -(key)); //decrypted character print
		}
		else if (charBuffer[characters] == '\0') //new line for next message or end
		{
			printf("\n");
		}

	}
	printf("\n");
}// end DecryptionWithKey
