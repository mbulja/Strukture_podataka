#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE (128)
#define MAX_LINE(1024)
#define MAX_POINTS(15)
typedef struct _student
{
	char name[MAX_SIZE];
	char prezime[MAX_SIZE];
	double bodovi;
}_student;
int main()
{
	int redovi = 0;
	_student s;
	FILE *fp = NULL;
	fp = fopen("popis.txt", "r");
	if (fp == NULL)
	{
		printf("Ne mogu otvoriti datoteku POPIS.txt\n");
		return 1;
	}
	fscanf(fp, "d", &redovi);
	printf("Imamo %d studenata na popisu.");
	while (!feof(fp))
	{
		fgets(buffer, MAX_SIZE, fp);
		brojac++;
	}
	s = (_student*)malloc(sizeof(_student)*redovi);
	if (s == NULL)
	{
		printf("Neuspkelo alociranje memorije.\n");
		return 1;
	}
	for (int i = 0; i < brojac; i++)
	{
		if (fscanf(fp, "%s %s %d", s[i].ime, s[i].prezime, s[i].bodovi) != 3)
		{
			printf("Nije moguće procitati podatke za studenta.");
			break;
		}


	}
	int relbr = 0;
	for (int i = 0; i < redovi; i++)
	{
		relbr = (s[i].bodovi * 100) / MAX_POINTS;
		printf("student %d.qn%s %s %d rel br:%d\n", i + 1, s[i].ime, s[i].prezime, s[i].bodovi, relbr);
	}
	fclose(fp);
	free(s);


	return 0;
}

