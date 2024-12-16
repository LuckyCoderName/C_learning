#include <iostream>
void First() { // самое длинное слово
	int max = 0;
	int bigWordStart = 0;
	char str[100] = " worldddd woord lol h";
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


void Second() { //  удалить двойные цифры
	char str[100] = "22 1154 22 123 22 2 13 1";

	for (int i = 0, j = 0; str[i] != '\0'; i++, j++) {
		if ((str[i] == ' ') || (str[i + 1] == '\0')) {
			if (str[i + 1] == '\0') {
				j++;
				i++;
			}
			if (j == 2) {
				/*str[i - 1] = ' ';
				str[i - 2] = ' ';*/
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

void Third() {
	int isPal = 0;
	char str[100] = "aaa DSW adda WSAD a"; // добавить |
	//printf("%i", len);

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
				//printf("%i", StrLen(str));
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
				/*puts(str);*/
				i += 2;
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
	int maxSum = 0;
	int matr[4][5] = { {1,2,3,4,5},
					{5,5,3,4,5},
					{5,5,3,4,5},
					{1,2,3,4,5}, };
	printf("Enter the size of the submatrix: ");
	scanf_s("%i", &podmatrizaSize);
	for (int i = 0; i < 4 - podmatrizaSize + 1; i++)
	{
		for (int j = 0; j < 5 - podmatrizaSize + 1; j++)
		{
			sumMatr = 0;
			for (int i1 = i; i1 < podmatrizaSize + i; i1++)
			{
				for (int j1 = j; j1 < podmatrizaSize + j; j1++)
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
	Four();
}
