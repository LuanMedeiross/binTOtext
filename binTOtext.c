#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

	int bits[8] = { 128, 64, 32, 16, 8, 4, 2, 1 };

	printf("\n");

	if (strcmp(argv[1], "-e")) { 

		char text[128];
		int bin = 0;

		for (int i = 1; i < argc; i++) {
			for (int c = 0; c <= 8; c++) {
				if (argv[i][c] == '1') {
					bin += bits[c];
				}
			} 

			text[i-1] = bin;
			bin = 0;
		}

		printf("Decimal: ");
		for (int i = 0; i < argc - 1; i++) {
			printf("%i ", text[i]);
		}

		printf("\nText: %s\n", text);
	
	} else {
		
		char byte[8];

		for (int arg = 2; arg < argc; arg++) {

			int sizeOfArg = strlen(argv[arg]);

			for (int chaR = 0; chaR < sizeOfArg; chaR++) {

				int decimal = argv[arg][chaR];
				
				for (int bit = 0; bit <= 8; bit++) {
					if (decimal >= bits[bit]) {
						decimal -= bits[bit];
						byte[bit] = '1';
					} else {
						byte[bit] = '0';
					}
				} printf("%s ", byte);
			} 
		} printf("\n");
	}
		
	printf("\n");

	return 0;
	
}
