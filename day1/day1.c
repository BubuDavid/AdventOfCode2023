#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LINESIZE 500

int max(int, int);
bool checkNum1(char);
char *slice(char*, int);
char digitTransformation(char*);
char *checkNum2(char *);
int part1(char **, int);
int part2(char **, int);

int main() {
	FILE *filePointer = fopen("./input_puzzle.txt", "r"); 

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

	// // Printing the values
	// printf("Cases: \n");
	// for (int i = 0; i < maxLines; i++) {
	// 	printf("%s", cValues[i]);
	// }
	printf("=====================================\n");

	// printf("Answers: \n");
	int ans1 = part1(cValues, maxLines);
	int ans2 = part2(cValues, maxLines);

	printf("Part 1: %d\n", ans1);
	printf("Part 2: %d\n", ans2);
	printf("=====================================\n");

	fclose(filePointer);
	free(line);
	for (int i = 0; i < maxLines; i++) {
		free(cValues[i]);
	}

	return 0;
}

int part1(char **cValues, int maxLines) {
	int suma = 0;
	char *num = (char*)malloc(2 * sizeof(char));
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
	int suma = 0;
	char *num = (char*)malloc(2 * sizeof(char));
	for (int i = 0; i < maxLines; i++) {
		int lineLength = strlen(cValues[i]);
		bool firstTime = true;
		num[0] = '\0';
		for (int j = 0; j < lineLength - 1; j++) {
			char *currentChar = checkNum2(&cValues[i][j]);
			// printf("Current Char: %s \n", currentChar);
			if (strcmp(currentChar, "0") != 0) {
				if (firstTime) {
					num[0] = digitTransformation(currentChar);
					firstTime = false;
				}
				num[1] = digitTransformation(currentChar);
			}
		}
		// printf("%s\n", num);
		suma += atoi(num);
	}

	return suma;
}

char digitTransformation(char *str) {
	char *digits = "123456789";

	while (strcmp(digits, "\0") != 0) {
		if (strcmp(str, slice(digits, 1)) == 0) return digits[0];
		digits++;
	}

	char letters[9][6] = {
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine"
	};

	for (int i = 0; i < 9; i++) {
		if (strcmp(str, letters[i]) == 0) return i + 1 + '0';
	}

	return '0';
}

bool checkNum1(char c) {
	char *digits = "123456789";
	for (int i = 0; i < strlen(digits); i++) {
		if (c == digits[i]) return true;
	}

	return false;
}

char *slice(char *str, int len) {
	char *newStr = (char *)malloc(len * sizeof(char));
	for (int i = 0; i < len; i++) {
		newStr[i] = str[i];
	}
	newStr[len] = '\0';
	return newStr;
}

char *checkNum2(char *firstChar) {
	char *numbers = "1,2,3,4,5,6,7,8,9,one,two,three,four,five,six,seven,eight,nine,";
	char *currentNum = (char *)malloc(10 * sizeof(char));
	int currentNumIndex = 0;
	int currentNumLength = 0;

	for (int i = 0; i < strlen(numbers); i++) {
		if (numbers[i] == ',') {
			currentNum[currentNumIndex] = '\0';
			currentNumLength = currentNumIndex;
			currentNumIndex = 0;
			// printf("%s %s\n", slice(firstChar, strlen(currentNum)), currentNum);
			if (strcmp(currentNum, slice(firstChar, strlen(currentNum))) == 0) {
				// printf("Found: %s\n", currentNum);
				return currentNum;
			}
		} else {
			currentNum[currentNumIndex] = numbers[i];
			currentNumIndex++;
		}
	}

	return "0";
}

int max(int a, int b) {
	return a > b ? a : b;
}
