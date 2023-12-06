#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LINESIZE 500

int max(int, int);
bool checkNum1(char);
int part1(char **, int);
int part2(char **, int);

int main() {
	FILE *filePointer = fopen("./input_test.txt", "r"); 

	char *line = malloc(LINESIZE * sizeof(char));
	int maxLines = 0;
	int maxLineSize = 0;

	while (fgets(line, LINESIZE, filePointer)) {
		maxLines++;
		maxLineSize = max(maxLineSize, strlen(line));
	}

	char **cValues = (char **)malloc(maxLines * sizeof(char *));

	for (int i = 0; i < maxLines; i++) {
		cValues[i] = (char *)malloc(maxLineSize * sizeof(char));
	}

	int nLine = 0;
	fseek(filePointer, 0, SEEK_SET);
	while (fgets(line, LINESIZE, filePointer)) {
		strcpy(cValues[nLine], line);
		nLine++;
	}

	// Printing the values
	printf("Cases: \n");
	for (int i = 0; i < maxLines; i++) {
		printf("%s", cValues[i]);
	}

	printf("Answers: \n");
	int ans1 = part1(cValues, maxLines);
	int ans2 = part2(cValues, maxLines);

	printf("Part 1: %d\n", ans1);
	printf("Part 2: %d\n", ans2);

	fclose(filePointer);
	free(line);
	for (int i = 0; i < maxLines; i++) {
		free(cValues[i]);
	}

	return 0;
}

int part1(char **cValues, int maxLines) {
	int suma = 0;
	char *num = (char*)malloc(LINESIZE * sizeof(char));
	for (int lineNumber = 0; lineNumber < maxLines; lineNumber++) {
		int lineLength = strlen(cValues[lineNumber]);
		bool firstTime = true;
		num[0] = '\0';
		for (int i = 0; i < lineLength; i++) {
			if (checkNum1(cValues[lineNumber][i]) && firstTime) {
				num[0] = cValues[lineNumber][i];
				firstTime = false;
			}
			if (checkNum1(cValues[lineNumber][i]))
				num[1] = cValues[lineNumber][i];
		}
		suma += atoi(num);
	}

	return suma; 
}

int part2(char **cValues, int maxLines) {
	return 0;
}


bool checkNum1(char c) {
	if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0') {
		return true;
	}

	return false;
}

bool checkNum2(char c) {
	if (checkNum1(c)) return true;
	if (c == 'o' || c == 't' || c == 'f' || 's' || 'e' || 'n') return true;
	return false;
}

bool checkNumSpelled(char *c) {
	if (strcmp(c, "one") == 0) return true;
	if (strcmp(c, "two") == 0) return true;
	if (strcmp(c, "three") == 0) return true;
	if (strcmp(c, "four") == 0) return true;
	if (strcmp(c, "five") == 0) return true;
	if (strcmp(c, "six") == 0) return true;
	if (strcmp(c, "seven") == 0) return true;
	if (strcmp(c, "eight") == 0) return true;
	if (strcmp(c, "nine") == 0) return true;
}

int max(int a, int b) {
	return a > b ? a : b;
	// si a > b entonces regresa a, sino b
}
