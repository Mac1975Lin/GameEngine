#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fptr = fopen(argv[1], "rb");
	if(!fptr)
	{
		printf("Usage: bin2c infile\n");
		return -1;
	}

	fseek(fptr, 0, SEEK_END);
	int flength = ftell(fptr);
	fseek(fptr, 0, SEEK_SET);

	int idx = 0;
	for(int i=0; i<flength; i++)
	{
		unsigned char ch;
		fread(&ch, 1, 1, fptr);
		printf("0x%02X, ", ch);
		idx++;
		if(idx==16)
		{
			printf("\n");
			idx= 0;
		}
	}

	fclose(fptr);

	return 0;
}