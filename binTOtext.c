#include <stdio.h>

int main(int argc, char *argv[]) {

	int bits[8] = { 128, 64, 32, 16, 8, 4, 2, 1 };

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
	
	return 0;
}
