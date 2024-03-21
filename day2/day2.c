#include <stdio.h>
#include <stdlib.h>

int max(int, int);
int stringLength(char *);
char *stringStrip(char *);
char **stringSplit(char *, char);

int main(int argc, char *argv[]) {
	FILE *file = fopen("./test_input.txt", "r");

	int maxLines = 0, maxLineSize = 500;
	char *line = (char*)malloc(maxLineSize * sizeof(char));

	while (fgets(line, maxLineSize, file)) {
		maxLines++;
		maxLineSize = max(maxLineSize, stringLength(line));
	}

	if (maxLineSize != 500){
		printf("Max Line Size Excedeed!");
		exit(1);
	}

	fclose(file);
	free(line);
	return 0;
}

int stringLength(char *str){
	int ans = 0;

	while (*str != '\0') {
		str++;
		ans++;
	}

	return ans;
}

char *stringStrip(char *str) {
	int len = stringLength(str);
	char *ans = (char*)malloc(len * sizeof(char));
	int i = 0;

	while (*str != '\0') {
		if (*str != '\n') {
			ans[i] = *str;
			i++;
		}
		str++;
	}

	return ans;
}

char **stringSplit(char *str, char deli) {
	char **ans (char**)malloc(len * sizeof(char*));
}


int max(int a, int b) { 
	return a > b ? a : b;
}
