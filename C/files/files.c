#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MY_FILE "./test.txt"

int main(int argc, char* argv[])
{
	FILE *fp = NULL;

	fp = fopen(MY_FILE, "w");
	if (fp == NULL) {
		printf("Open file failed!!!\n");
		return -1;
	} else {
		printf("Open file successful!!!\n");
	}

	//Writing to file
	char *buf    = "File testing Part1 ";
	char *buf_w1 = "Code Product Price($)";
	char *buf_w2 = "0000 candies 10";
	char *buf_w3 = "0001 Butter  20";
	char *ptr = buf_w1;
	int index = 0, ret = 0, qtyData = 0;

	//write a quantity of a string to a file
	qtyData = 4;
	if (qtyData == fwrite(buf, sizeof(char), qtyData, fp)) {
		printf("fwrite function successful\n");

	}
	fputc('\n', fp);

	//write characters one by one to file
	while ((ptr != NULL) && (index < strlen(buf_w1))) {
		ret = fputc(*ptr, fp);
		if (ret == EOF) {
			//printf("fputc function error\n");
			return -1;
		}
		ptr = ptr + 1;
		index++;
		//printf("%d preious:%c, next:%c\n", index, ret, *ptr);
	}
	//new line
	fputc('\n', fp);

	//write string to file
	ret = fputs(buf_w3, fp);
	if (ret == EOF) {
		printf("fputc function error\n");
		return -1;
	}

	printf("current pos: %d\n", (int)ftell(fp));
	fseek(fp, -strlen(buf_w2), SEEK_END);
	printf("current pos: %d\n", (int)ftell(fp));
	ret = fputs(buf_w2, fp);
	if (ret == EOF) {
		printf("fputc function error\n");
		return -1;
	}
	fputc('\n', fp);
	printf("current pos: %d\n", (int)ftell(fp));

	ret = fputs(buf_w3, fp);
	if (ret == EOF) {
		printf("fputc function error\n");
		return -1;
	}
	fputc('\n', fp);

	fclose(fp);


	//Reading from file
	char *buf_r = malloc(sizeof(char) * 128);
	char *buf_tmp = malloc(32);
	if ((fp = fopen(MY_FILE, "r")) == NULL) {
		printf("open file for reading error\n");
		return -1;
	}

	index = 0;

	//Read file character by character
	ret = fgetc(fp);
	while(ret != '\n' ) {
		buf_r[index] = (char)ret;
		ret = fgetc(fp);
		index++;
	}

	//Read string from file
	memset(buf_tmp, 0, strlen(buf_tmp));
	fgets(buf_tmp, strlen(buf_w1) + 1, fp);
	strncat(buf_r, buf_tmp, strlen(buf_tmp));

	//Read file by block
	memset(buf_tmp, 0, strlen(buf_tmp));
	fread(buf_tmp, sizeof(char), strlen(buf_w2) + 1, fp);
	strncat(buf_r, buf_tmp, strlen(buf_tmp));

	memset(buf_tmp, 0, strlen(buf_tmp));
	char *prodID = malloc(16);
	char *prod = malloc(16);
	char *val = malloc(4);
	fscanf(fp, "%s %s %s", prodID, prod, val);
	sprintf(buf_tmp, "\n%s %s %s", prodID, prod, val);
	strncat(buf_r, buf_tmp, strlen(buf_tmp));
	printf("%s\n", buf_r);

	//reset the position of the file at the top
	rewind(fp);
	//display the content of the file
	printf("\nDisplay the content of the file all at once\n\n");
	index = 0;
	ret = fgetc(fp);
	while(ret != EOF) {
		printf("%c", ret);
		buf_r[index] = (char)ret;
		//printf("%c", buf_r[index]);
		ret = fgetc(fp);
		index++;
	}

	fclose(fp);
	
	return 0;
}
