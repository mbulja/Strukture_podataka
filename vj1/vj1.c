/*Napisati program koji prvo proèita koliko redaka ima datoteka, tj.koliko ima studenata
zapisanih u datoteci.Nakon toga potrebno je dinamièki alocirati prostor za niz struktura
studenata(ime, prezime, bodovi) i uèitati iz datoteke sve zapise.Na ekran ispisati ime,
prezime, apsolutni i relativni broj bodova.
Napomena: Svaki redak datoteke sadrži ime i prezime studenta, te broj bodova na kolokviju.
relatvan_br_bodova = br_bodova / max_br_bodova * 100*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct student {
	char ime[50];
	char prezime[50];
	int bodovi;
};

int main()
{
	FILE* datoteka;
	int brst = 0;
	datoteka = fopen("studenti.txt", "r");
	if (datoteka == NULL)
	{
		printf("Nije moguce otovoriti datoteku.\n");
		return 1;
	}
	struct student* studenti = (struct student*)malloc(sizeof(struct student));
	if (studenti == NULL) {
		printf("Greška pri alociranju memorije.\n");
		return 1;
	}
	while (fscanf(datoteka, "%s %s %d", studenti[brst].ime, studenti[brst].prezime, &studenti[brst].bodovi) == 3) {
		brst++;
		studenti = (struct student*)realloc(studenti, (brst + 1) * sizeof(struct student));
	}

	// Zatvorite datoteku
	fclose(datoteka);

	// Ispis podataka o studentima
	printf("Podaci o studentima:\n");
	for (int i = 0; i < brst; i++) {
		printf("Ime: %s\n", studenti[i].ime);
		printf("Prezime: %s\n", studenti[i].prezime);
		printf("Apsolutni broj bodova: %d\n", studenti[i].bodovi);
		float relativni_br_bodova = (float)studenti[i].bodovi / 100 * 100; // Pretpostavljamo da je max_br_bodova 100
		printf("Relativni broj bodova: %.2f%%\n", relativni_br_bodova);
		printf("\n");
	}

	// Oslobodite alociranu memoriju
	free(studenti);

	return 0;

}