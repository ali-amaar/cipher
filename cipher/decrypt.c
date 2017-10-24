#include "decrypt.h" // Print header file
#include <ctype.h>
#include <stdio.h>

int characters; //globar variable characters
int key; //global variable key

int KeylessDecryption(int fileSize, unsigned char* charBuffer)
{// start KeylessDecription

	int charactercount = 0;
	int mode;
	int modecount = 0;
	int possiblemode = 'A';
	int keys;
	int characterposition = characters;

	for ( keys = 1; keys <=  25; keys++) //iterating through possible keys
	{
		while (charBuffer[characterposition ] != '\0') //while valid character
		{
			if (charBuffer[characterposition ] == possiblemode) //matching characters
			{
				modecount++; 	//iterate mode count
			}
			characterposition ++; //move on to next letter
		}
		if (modecount > charactercount) //if mode is found
		{
			charactercount = modecount; //mode is highest occuring character
			mode = possiblemode;
		}
		possiblemode++; //next character
		modecount = 0; //reset counter for next character
		characterposition = characters;
	}
	if ( mode < 'E' )
	{
		key = mode - 'E' + 26;
	}
	else
	{
		key = mode - 'E';
	}
	return key;
}//end KeylessDecription

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
			if(charBuffer[characters] -(key) == '+'){
				charBuffer[characters] = charBuffer[characters] - 11;
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
