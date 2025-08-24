/* 
CLI tool that scans the given file and looks for given word / sequence occurrencess.
The tool simply outputs the amount of occurrences of the word / sequence found in the file.
The tool does count occurrences, even if they're not separated from each other. For example, 
if you have an input "thing", and a file containing "thingthingthing", the tool counts 
three occurrences where "thing" appears. Another example, if you have "aa" as input, and 
"aaaaaa" in the file, the tool counts three aa's. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int searchFile(const char* fileName, const char* input) {
	FILE* file = fopen(fileName, "r");

	if (file == NULL) {
		printf("Error trying to read file.\n");
		return 0;
	}

	// get file size
	fseek(file, 0, SEEK_END);
	long fileSize = ftell(file);
	fseek(file, 0, SEEK_SET);

	// add space for null terminator
	char* fileContent = malloc(fileSize + 1);
	if (fileContent == NULL) {
		printf("Error trying to allocate memory.\n");
		fclose(file);
		return 0;
	}

	int readBytes = fread(fileContent, 1, fileSize, file);
	fileContent[readBytes] = '\0';

	int count = 0;

	int inputLength = strlen(input);
	if (inputLength == 0) {
		free(fileContent);
		fclose(file);
		return 0;
	}

	const char *pos = fileContent;
	while ((pos = strstr(pos, input)) != NULL) {
		count++;
		pos += inputLength;
	}

	free(fileContent);
	fclose(file);

	return count;
}

int main() {
	char fileBuffer[100];
	char searchBuffer[100];

	printf("Enter filename you wish to scan (max 100 characters): \n");
	scanf("%99s", fileBuffer);

	printf("Enter word or sequence (max 100 characters): \n");
	scanf("%99s", searchBuffer);

	int count = searchFile(fileBuffer, searchBuffer);
	printf("Amount of matches: %d\n", count);

	return 0;
}
