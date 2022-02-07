#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

int calculateFactoriel(int value);
void findStringInterval(char letters[], char willFindIntervalValues[2]);
void findValuesForAchieveTheGoal();

int main() {
	setlocale(LC_ALL, "Turkish");

	int userChoice=0;
	

	
	while (userChoice!=4)
	{
		int value;
		char findLetters[2];
		char letters[100];
		printf("\n---Menu---\n\nYapmak istediðiniz iþlemi seçiniz.\n\n1)Faktoriyel Hesapla.\n2)Referans deðerler ile harflerin konumunu bul.\n3)Dizideki sayýlarla hedefe ulaþ\n4)PROGRAMI SONLANDIR\n");
		scanf_s("%d", &userChoice);
		switch (userChoice)
		{
		case 1:
			printf("Deðer giriniz:");
			scanf_s("%d", &value);
			printf("%d sayýsýnýn faktöriyeli = %d", value, calculateFactoriel(value));

			break;
		case 2:
			printf("\n");
			gets_s(letters, 99);

			printf("Baþlangýç deðeri: ");
			scanf_s("%c", &findLetters[0]);

			printf("Bitiþ deðeri: ");
			scanf_s("\n%c", &findLetters[1]);

			printf("\nAralýk sonucu: ");
			findStringInterval(letters, findLetters);

			break;
		case 3:
			findValuesForAchieveTheGoal();
			break;
		case 4:
			printf("PROGRAM SONLANDIRILDI!");
			break;
		default:
			printf("GEÇERSÝZ DEÐER.");
		}
	}
	
	return 0;
}

int calculateFactoriel(int value) {
	int answer = 1;
	for (int i = 1; i <= value; i++)
	{
		answer = answer * i;
	}

	return answer;
}

void findStringInterval(char letters[],char willFindIntervalValues[2]) {
	int firstValueLocation=0;
	int secondValueLocation=0;
	
	for (int i = 0; i <= strlen(letters); i++)
	{
		if (letters[i] == willFindIntervalValues[0])
		{
			firstValueLocation = i;
			for (i; i <= strlen(letters); i++)
			{
				if (letters[i] == willFindIntervalValues[1])
				{
					secondValueLocation = i;
					break;
				}
			}
		}
	}
	int k = 0;
	char findedInterval[999];
	int findedIntervalSize = secondValueLocation - firstValueLocation - 1;
	for (int i = firstValueLocation + 1; i < secondValueLocation; i++)
	{
		findedInterval[k]=letters[i];
		k++;
	}
	for (int j = 0; j < findedIntervalSize; j++)
	{
		printf("%c", findedInterval[j]);
	}
	printf("\n");
	
}

void findValuesForAchieveTheGoal() {

	int allValues[5];
	int arraySize = 5;
	int goalValue;
	bool isFind = false;
	
	for (int i = 0; i < 5; i++)
	{
		printf("%d. deðeri giriniz: ", i);
		scanf_s("%d", &allValues[i]);
	}

	int firstValue=0,secondValue=0;
	int *value1 = &firstValue;
	int *value2 = &secondValue;
	printf("Ulaþýlacak deðeri giriniz: "); scanf_s("%d", &goalValue);

	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			if (allValues[i] + allValues[j] == goalValue)
			{
				firstValue = i;
				secondValue = j;
				isFind = true;
				break;
			}
		}
	}

	if (isFind)
	{
		printf("%d sayýsýna ulaþmak için %d ve %d numaralý sayýlarý toplamamýz gerekmektedir.", goalValue, *value1, *value2);
	}
	else {
		printf("Dizinizde toplayýnca %d deðerine denk gelen iki sayý bulunamadý.", goalValue);
	}
}