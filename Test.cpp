#include "stdio.h"

void First() { // самое длинное слово
	int max = 0;
	int bigWordStart = 0;
	char str[100] = " worldddd woord lol h";
	for (int i=0,j = 0; str[i] != '\0'; i++, j++) {
		if ((str[i] == ' ')|| (str[i+1] == '\0')) {
			if (str[i + 1] == '\0') {
				j++;
				i++;
			}
			if (max < j) {
				
				max = j;
				bigWordStart = i - j;
			}
			j = -1;
		}
	}
	for (int i = bigWordStart; i < bigWordStart + max; i++)
	{
		printf("%c", str[i]);
	}
}


void Second() { //  удалить двойные цифры
	char str[100] = "111 23 22 1313 1 1";

	for (int i = 0, j = 0; str[i] != '\0'; i++, j++) {
		if ((str[i] == ' ') || (str[i + 1] == '\0')) {
			if (str[i + 1] == '\0') {
				j++;
				i++;
			}
			if (j == 3) {
				str[i-1] = ' ';
				str[i-2] = ' ';
			}
			j = 0;
		}

	}
	puts(str);
}

void Third() {
	int isPal = 0;
	char str[100] = " assda aaaaa dadd dss sds"; // добавить |
	

	for (int i = 0, j = 0; str[i] != '\0'; i++, j++)
	{
		if (((str[i] == ' ')) || (str[i + 1] == '\0'))
		{
			if ((i==0) && (str[i]==' '))
			{
				j = -1;
				continue;
			}
			if (str[i + 1] == '\0') 
			{
				j++;
				i++;
			}
			//printf("j = %i ", j);

			isPal = 1;

			for (int temp = 0; temp < j; temp++)
			{
				//printf("str = %c %c\n", str[i - 1 - temp], str[i + temp-j]);
				if (str[i - 1 - temp] != str[i + temp - j]) 
				{
					isPal = 0;
				}
			}
			if (isPal == 1) {
				str[i - j - 1] = '|';
				str[i] = '|';
			}
			j = -1;
			//printf("isPal = %i ", isPal);
		}
	}
	puts(str);
}

void Four() {// наибольшая сумма эл матриц 
	int indexi = 0;
	int indexj = 0;
	int podmatrizaSize;
	int sumMatr = 0;
	int maxSum=0;
	int matr[4][5] = {{1,2,3,4,5},
					{5,5,3,4,5},
					{5,5,3,4,5},
					{1,2,3,4,5},};
	scanf_s("%i", &podmatrizaSize);
	for (int i = 0; i < 4 - podmatrizaSize+1; i++)
	{
		for (int j = 0; j < 5 - podmatrizaSize+1; j++)
		{
			sumMatr = 0;
			for (int i1 = i; i1 < podmatrizaSize+i; i1++)
			{
				for (int j1 = j; j1 < podmatrizaSize+j; j1++)
				{
					sumMatr += matr[i1][j1];
					printf("%i ", matr[i1][j1]);
				}
				if (maxSum < sumMatr) {
					maxSum = sumMatr;
					indexi = i;
					indexj = j;
				}
				printf("\n");
			}
			printf("\n");
		}
	}
	printf("best matr\n");
	for (int i = indexi; i < indexi + podmatrizaSize; i++) {
		for (int j = indexj; j < indexj+podmatrizaSize; j++)
		{
			printf("%i ", matr[i][j]);
		}
		printf("\n");
	}

}

int main() {
	//First();
	//Second();
	Third();
	//Four();
}