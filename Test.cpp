#include <stdio.h>
#include <stdlib.h>

void First() { // самое длинное слово
	int max = 0;
	int bigWordStart = 0;
	char str[100] = "worldddd woord lol h";
	puts(str);

	for (int i = 0, j = 0; str[i] != '\0'; i++, j++) {
		if ((str[i] == ' ') || (str[i + 1] == '\0')) {
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

void Second() { //  удалить двузначные числа
	char str[100] = "22 1154 22 123 22 2 13 1";
	puts(str);

	for (int i = 0, j = 0; str[i] != '\0'; i++, j++) {
		if ((str[i] == ' ') || (str[i + 1] == '\0')) {
			if (str[i + 1] == '\0') {
				j++;
				i++;
			}
			if (j == 2) {
				for (int k = i-2; str[k]!='\0'; k++)
				{
					str[k] = str[k+3];
				}
				i -= 2;
				j = 0;
			}
			
			if (j != 0) 
			{
				j = -1;
			}
		}
	}
	puts(str);
}

int StrLen(char* str) { //длинна строки
	int len = 0;
	for (; str[len] != '\0'; len++);
	return len;
}

void Third() { // добавить символ | слева и справа от слов палиндромов
	int isPal = 0;
	char str[100] = "aaa dsw adda wsad a"; 
	puts(str);
	for (int i = 0, j = 0; str[i] != '\0'; i++, j++)
	{
		if (((str[i] == ' ')) || (str[i + 1] == '\0'))
		{
			if ((i == 0) && (str[i] == ' '))
			{
				j = -1;
				continue;
			}
			if (str[i + 1] == '\0')
			{
				j++;
				i++;
			}

			isPal = 1;

			for (int temp = 0; temp < j; temp++)
			{
				if (str[i - 1 - temp] != str[i + temp - j])
				{
					isPal = 0;
				}
			}
			if (isPal == 1) {
				for (int k = StrLen(str)+2; k!=-1; k--)
				{
					
					if (k >i+1)
					{
						str[k] = str[k - 2]; 
					}
					else if (k == i + 1) {
						str[k] = '|';
					}
					else if((k < i + 1)&&(k>i-j)) {
						str[k] = str[k - 1];
					}
					else if (k == i - j){
						str[k] = '|';
					}
				}
				i += 2;
			}
			j = -1;
		}
	}
	puts(str);
}

void Four() {// найти квадратную подматрицу с максимальной суммой элементов
	int indexi = 0;
	int indexj = 0;
	int podmatrizaSize;
	int sumMatr = 0;
	int maxSum = 0;
	int matr[4][5] = { {1,2,3,4,5},
					{5,5,3,4,5},
					{5,5,3,4,5},
					{1,2,3,4,5}, };

	printf("your matrix:\n");
	for (int i = 0; i < 4; i++) { //вывод данной матрицы
		for (int j = 0; j <5; j++)
		{
			printf("%i ", matr[i][j]);
		}
		printf("\n");
	}

	printf("Enter the size of the submatrix: "); 
	scanf_s("%i", &podmatrizaSize);

	for (int i = 0; i < 4 - podmatrizaSize + 1; i++) // нахождение подматрицы
	{
		for (int j = 0; j < 5 - podmatrizaSize + 1; j++)
		{
			sumMatr = 0;
			for (int i1 = i; i1 < podmatrizaSize + i; i1++)
			{
				for (int j1 = j; j1 < podmatrizaSize + j; j1++)
				{
					sumMatr += matr[i1][j1];
				}
				if (maxSum < sumMatr) {
					maxSum = sumMatr;
					indexi = i;
					indexj = j;
				}
				
			}
			
		}
	}

	printf("best matr\n");
	for (int i = indexi; i < indexi + podmatrizaSize; i++) { //вывод лучшей матрицы
		for (int j = indexj; j < indexj + podmatrizaSize; j++)
		{
			printf("%i ", matr[i][j]);
		}
		printf("\n");
	}

}

int main() {
	//First();
	//Second();
	//Third();
	//Four();
}
