#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

typedef struct a
{
	int data;
	struct a *next;
	struct a *prev;
}node;

node *root;
node *iter;

void sonaGit()
{
	while(iter->next != NULL)
	{
		iter = iter->next;
	}	
}

void sonaEkle()
{
	if(root == NULL)
	{
		root = (node *)malloc(sizeof(node));
		root->next = root->prev = NULL;
		printf("Eklenecek veri: ");
		scanf("%d",&root->data);
		iter = root;
		printf("Ekleme Baþarýlý!\n");	
	}
	else
	{
		sonaGit();
		iter->next = (node *)malloc(sizeof(node));
		iter->next->prev = iter;
		iter = iter->next;
		printf("Eklenecek veri: ");
		scanf("%d",&iter->data);
		iter->next = NULL;
		printf("Ekleme Baþarýlý!\n");
	}	
}

void arayaEkle(int sira)
{
	int boyut = 1;
	while(iter->next != NULL)
	{
		iter = iter->next;
		boyut++;
	}
	if(sira == 1)
	{
		iter = root;
		iter->prev = (node *)malloc(sizeof(node));
		root = iter->prev;
		root->next = iter;
		root->prev = NULL;
		printf("Eklenecek veri: ");
		scanf("%d", &root->data);
	}
	else if(sira > 0 && sira <= boyut)
	{
		int i;
		node *temp;
		iter = root;
		for(i = 0; i < (sira-1); i++)
			iter = iter->next;
		iter->prev->next = (node *)malloc(sizeof(node));
		iter->prev->next->prev = iter->prev;
		iter->prev = iter->prev->next;
		iter->prev->next = iter;
		printf("Eklenecek veri: ");
		scanf("%d", &iter->prev->data);
		
	}
	else if(sira == boyut + 1)
		sonaEkle();
	else
		printf("Ýstenilen kadar veri yok !\n\n");
}

node *ara(int aranan)
{
	if(root == NULL)
		printf("Liste Boþ !\n\n");
	else
	{
		iter = root;
		while(iter != NULL)
		{
			if(iter->data == aranan)
			{
				iter = root;
				return iter;
			}
			iter = iter->next;
		}
	}
	iter = root;
	return NULL;
}

void sil()
{
	int aranan;
	printf("Silinmek istenen veri: ");
	scanf("%d", &aranan);
	iter = ara(aranan);
	if(iter == root)
	{
		root = root->next;
		free(root->prev);
		root->prev = NULL;
		iter = root;
		printf("Silindi !\n\n");
	}
	else if(iter != NULL)
	{
		iter->next->prev = iter->prev;
		iter->prev->next = iter->next;
		iter->next = NULL;
		iter->prev = NULL;
		free(iter);
		printf("Silindi !\n\n");
		iter = root;
		sonaGit();
	}
	else
		printf("Listede böyle bir veri yok !\n");
}

void goster()
{
	iter = root; int i = 1;
	while(iter != NULL)
	{
		printf("%d.Veri: %d\n", i++, iter->data);
		iter = iter->next;
	}
	iter = root;
}

int main()
{
	setlocale(LC_ALL, "Turkish");
	root = NULL;
	int secim; int sira; int aranan;
	do
	{
		printf("Sona Ekle[1]\nAraya Ekle[2]\nSil[3]\nGöster[4]\nAra[5]\nÇýkýþ[6]\nSeçim: ");
		secim = getch() - '0';
		printf("%d\n", secim);
		switch(secim)
		{
			case 1:
				sonaEkle();
				break;
			case 2:
				printf("Kaçýncý sýraya eklenecek: ");
				scanf("%d", &sira);
				arayaEkle(sira);
				break;
			case 3:
				sil();
				break;
			case 4:
				goster();
				break;
			case 5:
				printf("Aranacak deðer: ");
				scanf("%d", &aranan);
				iter = ara(aranan);
				if(iter != NULL)
					printf("Bulundu !!!\n\n");
				else
					printf("Bulunamadý !!!\n\n");
				break;
		}
	}while(secim != 6);
	
	return 0;
}
