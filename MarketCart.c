#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char nume[20];
	float pret;
	struct node* next;
};

float shopping_cart_balance = 0;
int politete = 0;
void clear(char prod[]) {
	prod = NULL;
}

void menu() {
	if (politete == 0)
	{
		printf("Bun venit!\n");
		printf("\nCosul dumneavoastra este gol.\n");
		politete = 1;
	}
	printf("----------------------------------\n");

	printf("Menu: \n");
	printf("1. Lactate \n");
	printf("2. Fructe \n");
	printf("3. Legume \n");
	printf("4. Carnuri \n");
	printf("5. Sterge produs \n");
	printf("6. Goleste cosul\n");
	printf("7. Plateste\n");
	printf("8. Iesire Magazin\n");


	printf("----------------------------------");

}

void readList(struct node* head) {
	
	struct  node* ptr = malloc(sizeof(struct node));
	ptr = head;
	int poz = 1;
	while(ptr!=NULL)
	{
		printf("%d:%s; pret:%.2f\n", poz, ptr->nume,ptr->pret);
		ptr = ptr->next;
		poz++;
	}
	printf("\nBalanta cosului:%.2f ", shopping_cart_balance);
}

void creareNod(struct node** head, float data, char nume_prod[]) {
	struct node* ptr = malloc(sizeof(struct node));
	strcpy(ptr->nume, nume_prod);
	ptr->pret = data;
	ptr->next = NULL;

	*head = ptr;
}

void insert_back(struct node** head, float data, char nume_produs[])
{
	struct node* ptr = *head;
	struct node* temp = malloc(sizeof(struct node));
	strcpy(temp->nume, nume_produs);
	temp->pret = data;
	temp->next = NULL;

	while (ptr->next!=NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = temp;
}

void del_pos(struct node** head, int pos) {

	struct node* ptr = *head;
	struct node* ptr2 = *head;
	if (*head == NULL)
	{
		printf("Cosul este deja gol.");
	}
	else if (pos == 1)
	{
		*head = ptr->next;
		shopping_cart_balance -= ptr->pret;
		free(ptr);
		ptr = NULL;
	}
	else
	{
		while (pos != 1) {

			ptr2 = ptr;
			ptr = ptr->next;
			pos--;
		}
		ptr2->next = ptr->next;
		shopping_cart_balance -= ptr->pret;
		free(ptr);
		ptr = NULL;
	}
}

struct node* del_List(struct node** head) {
	struct node* ptr = *head;

	while (ptr != NULL)
	{
		ptr = ptr->next;
		free(*head);
		*head = ptr;
	}
	return head;
}

int main() {
	struct node* head;
	menu();
	int primul_produs = 0;
	while (1)
	{
		char nume_produs[20];
		int optiune = 0;
		int produs_selectat = 0;
		printf("\n");
		scanf_s("%d", &optiune);
		switch (optiune)
		{
		case 1:
			printf("Ati selectat Lactate, ce doriti sa cumparati?\n");
			printf("1.Lapte, pret= 4.5 lei \n");
			printf("2.Branza, pret= 5.20 lei \n");
			printf("3.Oua, pret= 9.10 lei \n");
			printf("4.Unt, pret= 12.30 lei \n");
			printf("Atentie! Pentru o mai buna acuratete, selectarea se face dupa numarul din stanga produsului si apoi numele produsului! \n");
			scanf_s("%d", &produs_selectat);


			if (produs_selectat == 1)
			{
				if (primul_produs == 0)
				{
					scanf("%s", &nume_produs);
					printf("Ati selecat Lapte.\n");
					creareNod(&head, 4.5, nume_produs);
					shopping_cart_balance += head->next->pret;
					primul_produs = 1;
					printf("\nCos actualizat:\n");
					readList(head);
					clear(nume_produs);
					printf("\nAfisam meniul...\n");
					menu();
				}
				else
				{
					scanf("%s", &nume_produs);
					printf("Ati selecat Lapte.\n");
					insert_back(&head, 4.5, nume_produs);
					shopping_cart_balance += head->next->pret;
					printf("\nCos actualizat:\n");
					readList(head);
					clear(&nume_produs);
					printf("\nAfisam meniul...\n");
					menu();
				}
			}
			else if (produs_selectat == 2)
			{
				if (primul_produs == 0)
				{
					scanf("%s", &nume_produs);
					printf("Ati selecat Branza.\n");
					creareNod(&head, 5.20, nume_produs);
					shopping_cart_balance += head->next->pret;
					primul_produs = 1;
					printf("\nCos actualizat:\n");
					readList(head);
					printf("\nAfisam meniul...\n");
					menu();
				}
				else
				{
					scanf("%s", &nume_produs);
					printf("Ati selecat Branza.\n");
					insert_back(&head, 5.20, nume_produs);
					shopping_cart_balance += head->next->pret;
					printf("\nCos actualizat:\n");
					readList(head);
					printf("\nAfisam meniul...\n");
					menu();
				}

			}
			else if (produs_selectat == 3)
			{
				if (primul_produs == 0)
				{
					scanf("%s", &nume_produs);
					printf("Ati selecat Oua.\n");
					creareNod(&head, 9.30, nume_produs);
					shopping_cart_balance += head->next->pret;
					primul_produs = 1;
					printf("\nCos actualizat:\n");
					readList(head);
					clear(nume_produs);
					printf("\nAfisam meniul...\n");
					menu();
				}
				else
				{
					scanf("%s", &nume_produs);
					printf("Ati selecat Oua.\n");
					insert_back(&head, 9.30, nume_produs);
					shopping_cart_balance += head->next->pret;
					printf("\nCos actualizat:\n");
					readList(head);
					clear(&nume_produs);
					printf("\nAfisam meniul...\n");
					menu();
				}
			}
			else if (produs_selectat == 4)
			{
				if (primul_produs == 0)
				{
					scanf("%s", &nume_produs);
					printf("Ati selecat Unt.\n");
					creareNod(&head, 12.30, nume_produs);
					shopping_cart_balance += head->next->pret;
					primul_produs = 1;
					printf("\nCos actualizat:\n");
					readList(head);
					printf("\nAfisam meniul...\n");
					menu();
				}
				else
				{
					scanf("%s", &nume_produs);
					printf("Ati selecat Unt.\n");
					insert_back(&head, 12.30, nume_produs);
					shopping_cart_balance += head->next->pret;
					printf("\nCos actualizat:\n");
					readList(head);
					printf("\nAfisam meniul...\n");
					menu();
				}

			}
			break;
			case 2:
				printf("Ati selectat Fructe, ce doriti sa cumparati?\n");
				printf("1.Banane, pret= 4.9 lei/kg \n");
				printf("2.Kiwi, pret= 6.20 lei/kg \n");
				printf("3.Portocale, pret= 4.10 lei/kg \n");
				printf("4.Mere, pret= 3.20 lei/kg \n");
				printf("Atentie! Pentru o mai buna acuratete, selectarea se face dupa numarul din stanga produsului si apoi numele produsului! \n");
				scanf_s("%d", &produs_selectat);


				if (produs_selectat == 1)
				{
					if (primul_produs == 0)
					{
						scanf("%s", &nume_produs);
						printf("Ati selecat Banane.\n");
						creareNod(&head, 4.9, nume_produs);
						shopping_cart_balance += head->pret;
						primul_produs = 1;
						printf("\nCos actualizat:\n");
						readList(head);
						clear(nume_produs);
						printf("\nAfisam meniul...\n");
						menu();
					}
					else
					{
						scanf("%s", &nume_produs);
						printf("Ati selecat Banane.\n");
						insert_back(&head, 4.9, nume_produs);
						shopping_cart_balance += head->next->pret;
						printf("\nCos actualizat:\n");
						readList(head);
						clear(&nume_produs);
						printf("\nAfisam meniul...\n");
						menu();
					}
				}
				else if (produs_selectat == 2)
				{
					if (primul_produs == 0)
					{
						scanf("%s", &nume_produs);
						printf("Ati selecat Kiwi.\n");
						creareNod(&head, 6.20, nume_produs);
						shopping_cart_balance += head->pret;
						primul_produs = 1;
						printf("\nCos actualizat:\n");
						readList(head);
						printf("\nAfisam meniul...\n");
						menu();
					}
					else
					{
						scanf("%s", &nume_produs);
						printf("Ati selecat Kiwi.\n");
						insert_back(&head, 6.20, nume_produs);
						shopping_cart_balance += head->next->pret;
						printf("\nCos actualizat:\n");
						readList(head);
						printf("\nAfisam meniul...\n");
						menu();
					}

				}
				else if (produs_selectat == 3)
				{
					if (primul_produs == 0)
					{
						scanf("%s", &nume_produs);
						printf("Ati selecat Portocale.\n");
						creareNod(&head, 4.10, nume_produs);
						shopping_cart_balance += head->pret;
						primul_produs = 1;
						printf("\nCos actualizat:\n");
						readList(head);
						clear(nume_produs);
						printf("\nAfisam meniul...\n");
						menu();
					}
					else
					{
						scanf("%s", &nume_produs);
						printf("Ati selecat Portocale.\n");
						insert_back(&head, 4.10, nume_produs);
						shopping_cart_balance += head->pret;
						printf("\nCos actualizat:\n");
						readList(head);
						clear(&nume_produs);
						printf("\nAfisam meniul...\n");
						menu();
					}
				}
				else if (produs_selectat == 4)
				{
					if (primul_produs == 0)
					{
						scanf("%s", &nume_produs);
						printf("Ati selecat Mere.\n");
						creareNod(&head, 3.20, nume_produs);
						shopping_cart_balance += head->pret;
						primul_produs = 1;
						printf("\nCos actualizat:\n");
						readList(head);
						printf("\nAfisam meniul...\n");
						menu();
					}
					else
					{
						scanf("%s", &nume_produs);
						printf("Ati selecat Mere.\n");
						insert_back(&head, 3.20, nume_produs);
						shopping_cart_balance += head->next->pret;
						printf("\nCos actualizat:\n");
						readList(head);
						printf("\nAfisam meniul...\n");
						menu();
					}

				}
				break;
				case 3:
					printf("Ati selectat Legume, ce doriti sa cumparati?\n");
					printf("1.Ceapa, pret= 2.5 lei/kg \n");
					printf("2.Brocoli, pret= 5.25 lei/kg \n");
					printf("3.Ardei, pret= 3.45 lei/kg \n");
					printf("4.Cartofi, pret= 2.32 lei/kg \n");
					printf("Atentie! Pentru o mai buna acuratete, selectarea se face dupa numarul din stanga produsului si apoi numele produsului! \n");
					scanf_s("%d", &produs_selectat);


					if (produs_selectat == 1)
					{
						if (primul_produs == 0)
						{
							scanf("%s", &nume_produs);
							printf("Ati selecat Ceapa.\n");
							creareNod(&head, 2.5, nume_produs);
							shopping_cart_balance += head->pret;
							primul_produs = 1;
							printf("\nCos actualizat:\n");
							readList(head);
							clear(nume_produs);
							printf("\nAfisam meniul...\n");
							menu();
						}
						else
						{
							scanf("%s", &nume_produs);
							printf("Ati selecat Ceapa.\n");
							insert_back(&head, 2.5, nume_produs);
							shopping_cart_balance += head->next->pret;
							printf("\nCos actualizat:\n");
							readList(head);
							clear(&nume_produs);
							printf("\nAfisam meniul...\n");
							menu();
						}
					}
					else if (produs_selectat == 2)
					{
						if (primul_produs == 0)
						{
							scanf("%s", &nume_produs);
							printf("Ati selecat Brocoli.\n");
							creareNod(&head, 5.25, nume_produs);
							shopping_cart_balance += head->pret;
							primul_produs = 1;
							printf("\nCos actualizat:\n");
							readList(head);
							printf("\nAfisam meniul...\n");
							menu();
						}
						else
						{
							scanf("%s", &nume_produs);
							printf("Ati selecat Brocoli.\n");
							insert_back(&head, 5.25, nume_produs);
							shopping_cart_balance += head->next->pret;
							printf("\nCos actualizat:\n");
							readList(head);
							printf("\nAfisam meniul...\n");
							menu();
						}

					}
					else if (produs_selectat == 3)
					{
						if (primul_produs == 0)
						{
							scanf("%s", &nume_produs);
							printf("Ati selecat Ardei.\n");
							creareNod(&head, 3.45, nume_produs);
							shopping_cart_balance += head->next->pret;
							primul_produs = 1;
							printf("\nCos actualizat:\n");
							readList(head);
							clear(nume_produs);
							printf("\nAfisam meniul...\n");
							menu();
						}
						else
						{
							scanf("%s", &nume_produs);
							printf("Ati selecat Ardei.\n");
							insert_back(&head, 3.45, nume_produs);
							shopping_cart_balance += head->next->pret;
							printf("\nCos actualizat:\n");
							readList(head);
							clear(&nume_produs);
							printf("\nAfisam meniul...\n");
							menu();
						}
					}
					else if (produs_selectat == 4)
					{
						if (primul_produs == 0)
						{
							scanf("%s", &nume_produs);
							printf("Ati selecat Cartofi.\n");
							creareNod(&head, 2.32, nume_produs);
							shopping_cart_balance += head->next->pret;
							primul_produs = 1;
							printf("\nCos actualizat:\n");
							readList(head);
							printf("\nAfisam meniul...\n");
							menu();
						}
						else
						{
							scanf("%s", &nume_produs);
							printf("Ati selecat Cartofi.\n");
							insert_back(&head, 2.32, nume_produs);
							shopping_cart_balance += head->next->pret;
							printf("\nCos actualizat:\n");
							readList(head);
							printf("\nAfisam meniul...\n");
							menu();
						}

					}
					break;
					case 4:
						printf("Ati selectat Carnuri, ce doriti sa cumparati?\n");
						printf("1.Porc, pret= 11.52 lei \n");
						printf("2.Pui, pret= 10.21 lei \n");
						printf("3.Curcan, pret= 16.15 lei \n");
						printf("4.Vita, pret= 12.38 lei \n");
						printf("Atentie! Pentru o mai buna acuratete, selectarea se face dupa numarul din stanga produsului si apoi numele produsului! \n");
						scanf_s("%d", &produs_selectat);


						if (produs_selectat == 1)
						{
							if (primul_produs == 0)
							{
								scanf("%s", &nume_produs);
								printf("Ati selecat Porc.\n");
								creareNod(&head, 11.52, nume_produs);
								shopping_cart_balance += head->next->pret;
								primul_produs = 1;
								printf("\nCos actualizat:\n");
								readList(head);
								clear(nume_produs);
								printf("\nAfisam meniul...\n");
								menu();
							}
							else
							{
								scanf("%s", &nume_produs);
								printf("Ati selecat Porc.\n");
								insert_back(&head, 11.52, nume_produs);
								shopping_cart_balance += head->next->pret;
								printf("\nCos actualizat:\n");
								readList(head);
								clear(&nume_produs);
								printf("\nAfisam meniul...\n");
								menu();
							}
						}
						else if (produs_selectat == 2)
						{
							if (primul_produs == 0)
							{
								scanf("%s", &nume_produs);
								printf("Ati selecat Pui.\n");
								creareNod(&head, 10.21, nume_produs);
								shopping_cart_balance += head->next->pret;
								primul_produs = 1;
								printf("\nCos actualizat:\n");
								readList(head);
							}
							else
							{
								scanf("%s", &nume_produs);
								printf("Ati selecat Pui.\n");
								insert_back(&head, 10.21, nume_produs);
								shopping_cart_balance += head->next->pret;
								printf("\nCos actualizat:\n");
								readList(head);
								printf("/nAfisam meniul...\n");
								menu();
							}

						}
						else if (produs_selectat == 3)
						{
							if (primul_produs == 0)
							{
								scanf("%s", &nume_produs);
								printf("Ati selecat Curcan.\n");
								creareNod(&head, 16.15, nume_produs);
								shopping_cart_balance += head->next->pret;
								primul_produs = 1;
								printf("\nCos actualizat:\n");
								readList(head);
								clear(nume_produs);
								printf("\nAfisam meniul...\n");
								menu();
							}
							else
							{
								scanf("%s", &nume_produs);
								printf("Ati selecat Curcan.\n");
								insert_back(&head, 16.15, nume_produs);
								shopping_cart_balance += head->next->pret;
								printf("\nCos actualizat:\n");
								readList(head);
								clear(&nume_produs);
								printf("\nAfisam meniul...\n");
								menu();
							}
						}
						else if (produs_selectat == 4)
						{
							if (primul_produs == 0)
							{
								scanf("%s", &nume_produs);
								printf("Ati selecat Vita.\n");
								creareNod(&head, 12.38, nume_produs);
								shopping_cart_balance += head->next->pret;
								primul_produs = 1;
								printf("\nCos actualizat:\n");
								readList(head);
								printf("\nAfisam meniul...\n");
								menu();
							}
							else
							{
								scanf("%s", &nume_produs);
								printf("Ati selecat Vita.\n");
								insert_back(&head, 12.38, nume_produs);
								shopping_cart_balance += head->next->pret;
								printf("\nCos actualizat:\n");
								readList(head);
								printf("\nAfisam meniul...\n");
								menu();
							}

						}
						break;
						case 5:
							if (shopping_cart_balance>0)
							{
								int pozitie;
								printf("Produsul pe care doresti sa il stergi: ");
								scanf("%d", &pozitie);
								del_pos(&head, pozitie);
								printf("\nCos actualizat:\n");
								readList(head);
								printf("\nAfisam meniul...\n");
								menu();
							}
							else
							{
								printf("Cosul este deja gol.\n");
								printf("\nAfisam meniul...\n");
								menu();
							}
							break;
						case 6:
							if (shopping_cart_balance > 0)
							{
								del_List(&head);
								printf("Cosul este gol.\n");
								printf("/nAfisam meniul...\n");
								menu();
							}
							else
							{
								printf("Cosul este deja gol..\n");
								printf("\nAfisam meniul...\n");
								menu();
							}
							break;
						case 7:
							if (shopping_cart_balance > 0)
							{
								printf("Deoarece suntem online, plata se va face cu cardul.\n");
								printf("Procesare...\n");
								shopping_cart_balance -= shopping_cart_balance;
								del_List(&head);
								if (head == NULL)
								{
									printf("Cosul este gol.\n");
									printf("Balanta cosului este:% 2.0f lei\n", shopping_cart_balance);
								}
								printf("Tranzactie aprobata!\n");
								printf("O zi Buna! Si va mai asteptam pe la noi!\n");
								exit(0);
							}
							else
							{
								printf("Cosul este gol, nu ai ce sa platesti.");
							}
							break;

						case 8:
							if (shopping_cart_balance > 0)
							{
								printf("Ai uitat sa platesti.. Nu poti parasi magazinul.");
							}
							else
							{
								printf("O zi Buna! Si va mai asteptam pe la noi!\n");
								exit(0);
							}
							
								
							
							

							break;
		}
	}
	return 0;
}