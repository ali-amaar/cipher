#include <stdio.h>
#include <stdlib.h>
#include "decrypt.h"
#include <ctype.h>

int main(int argc, char **argv)
{//start main
	FILE *aFile = fopen(argv[1], "r"); //pointer to the file
	if (argc > 2) //if more than 2 arguments are entered
	{
		printf("Error, Too Many Arguments\n");
		return 0;
	}
	else if (argc != 2) //if arguments are not equal to 2 ie. (1 argument)
	{
		printf("Error, Not Enough Arguments\n");
		return 0;
	}
	else if (aFile == NULL) //if file entered does not existed
	{
		printf("File entered: %s\n", argv[1]);
		printf("Error, Could not read file\n");
		return 0;
	}

	fseek(aFile, 0, SEEK_END); //go to the end of the file
	long fileSize = ftell(aFile); //find out the size of the file
	rewind(aFile); //go back to the start of the file
	unsigned char *charBuffer = (unsigned char *) malloc(fileSize); //allocate memory for characters
	long read = fread((void *) charBuffer, 1, fileSize, aFile); //cast the buffer to void*
	if (read != fileSize) //check if right number was read
	{
		printf("Error, Could Not Read File");
		return 0;
	}
	printf("\n\nDecrypted Data\n\n");

	KeylessDecryption(fileSize, charBuffer);
	DecryptionWithKey(fileSize, charBuffer); //calling decypher function

	fclose(aFile); //close the file

	return 0;

}//end main
