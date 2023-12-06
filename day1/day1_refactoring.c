
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LINESIZE 500

bool checkNum1(char c) {
	if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0') {
		return true;
	}

	return false;
}

int main() {
	FILE *filePointer = fopen("./input_puzzle.txt", "r"); 

	if (filePointer == NULL) {
		printf("Failed opening the file\n");
		exit(1);
	}

	char *line = (char*)malloc(LINESIZE * sizeof(char));
	char **cValues = (char**)malloc()
	char *num = (char*)malloc(LINESIZE * sizeof(char));
	int counter = 0;
	int suma = 0;

	while (fgets(line, 500, filePointer)) {
		int lineLength = strlen(line);
		bool firstTime = true;
		num[0] = '\0';

		for (int i = 0; i < lineLength; i++) {
			if (checkNum1(line[i]) && firstTime) {
				num[0] = line[i];
				firstTime = false;
			}
			if (checkNum1(line[i]))
				num[1] = line[i];
		}
		counter++;
		suma += atoi(num);
	}

	printf("%d\n", suma);


	fclose(filePointer);
	free(line);
	free(num);

	return 0;
}
