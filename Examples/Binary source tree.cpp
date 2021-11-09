#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

typedef struct n
{
	struct n *left;
	int data;
	struct n *right;
}node;
node *root;
node *iter;

void Insert()
{
	int inpdata;
	printf("Eklenecek veri: "); scanf("%d", &inpdata);
	if(root == NULL)
	{
		root = (node *)malloc(sizeof(node));
		root->data = inpdata;
		root->left = root->right = NULL;
	}
	else
	{
		iter = root;
		while(true)
		{
			if(inpdata > iter->data)
			{
				if(iter->right != NULL)
					iter = iter->right;
				else
				{
					iter->right = (node *)malloc(sizeof(node));
					iter = iter->right;
					iter->data = inpdata;
					iter->left = iter->right = NULL;
					break;
				}
			}
			else
			{
				if(iter->left != NULL)
					iter = iter->left;
				else
				{
					iter->left = (node *)malloc(sizeof(node));
					iter = iter->left;
					iter->data = inpdata;
					iter->left = iter->right = NULL;
					break;
				}
			}
		}
		printf("Veri eklendi.\n\n");
	}
}

void Inorder(node *L)
{
	if(L != NULL)
	{
		Inorder(L->left);
		printf("%d-", L->data);
		Inorder(L->right);
	}
}

void soru(node *L)
{
	if(L->left != NULL)
	{
		soru(L->left);
	}
	if(L->right != NULL)
	{
		soru(L->right);
		printf("%d-", L->data);
	}
}

node *Min(node *tree)
{
	if(tree != NULL)
	{
		while(tree->left != NULL)
			tree = tree->left;
	}
	return tree;
}

node *Max(node *tree)
{	
	if(tree != NULL)
	{
		while(tree->right != NULL)
			tree = tree->right;	
	}
	return tree;
}

node *Find(int inpdata)
{
	iter = root;
	while(iter != NULL)
	{
		if(iter->data == inpdata)
			break;
		else if(inpdata > iter->data)
		{
			if(iter->right != NULL)
				iter = iter->right;
			else
				iter = NULL;
			
		}
		else if(inpdata < iter->data)
		{
			if(iter->left != NULL)
				iter = iter->left;
			else
				iter = NULL;
		}
	}
	return iter;
}

void Delete()
{
	int inpdata;
	printf("Silinmek istenen veri: "); scanf("%d", &inpdata);
	node *temp = Find(inpdata);
	if(temp != NULL)
	{
		
		if(root == NULL)
			printf("Aðaçta veri yok !\n\n");
		else if(root->left != NULL || root->right != NULL)
		{
			if(temp->left == NULL && temp->right == NULL)
			{
				iter = root;
				while(temp != NULL)
				{
					if(iter->data < temp->data)
					{
						if(iter->right != temp)
							iter = iter->right;
						else
						{
							iter->right = NULL;
							free(temp);
							temp = NULL;
						}
					}
					else
					{
						if(iter->left != temp)
							iter = iter->left;
						else
						{
							iter->left = NULL;
							free(temp);
							temp = NULL;
						}
					}
				}
			}
			else if(temp->right != NULL)
			{
				node *min = Min(temp->right);
				temp->data = min->data;
				iter = temp->right;
				if(min != iter)
				{
					while(iter->left != min)
						iter = iter->left;
					iter->left = NULL;
					free(min);	
				}
				else
				{
					temp->right = NULL;
					free(min);	
				}
			}
			else
			{
				node *max = Max(temp->left);
				temp->data = max->data;
				iter = temp->left;
				if(max != iter)
				{
					while(iter->right != max)
						iter = iter->right;
					iter->right = NULL;
					free(max);	
				}
				else
				{
					temp->left = NULL;
					free(max);	
				}
			}
			printf("Veri aðaçtan silindi.\n\n");
		}
		else
		{
			free(root);
			root = iter = NULL;
			printf("Veri aðaçtan silindi.\n\n");
		}
	}
	else
		printf("Silinmek isteden veri aðaçta yok !\n\n");
}

int main()  
{
	setlocale(LC_ALL, "Turkish");
	root = iter = NULL;
	int selection;
	do
	{
		printf("Ekle[1]\nSil[2]\nDolaþ[3]\nMax[4]\nMin[5]\nSoru[6]\nÇýkýþ[7]\nSeçim: "); selection = getch() - '0';
		printf("%d\n", selection);
		switch(selection)
		{
			case 1:
				Insert();
				break;
			case 2:
				Delete();
				break;
			case 3:
				Inorder(root);
				printf("\n\n");
				break;
			case 4:
				iter = Max(root);
				printf("Maximum veri: %d\n\n", iter->data);
				break;
			case 5:
				iter = Min(root);
				printf("Minimum veri: %d\n\n", iter->data);
				break;
			case 6:
				soru(root);
				printf("\n\n");
				break;
			case 7:
				printf("Çýkýldý !");
				break;
			default:
				printf("Seçim geçerli deðil !\n\n");
				break;
		}
	}while(selection != 7);
	return 0;
}
