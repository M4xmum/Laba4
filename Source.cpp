#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <locale.h>



struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};
int n = 0;

struct Node* root;

struct Node* CreateTree(struct Node* root, struct Node* r, int data)
{
	if (r == NULL)
	{
		r = (struct Node*)malloc(sizeof(struct Node));
		if (r == NULL)
		{
			printf("Ошибка выделения памяти");
			exit(0);
		}

		r->left = NULL;
		r->right = NULL;
		r->data = data;
		if (root == NULL)
			return r;

		if (data > root->data)
			root->right = r;
		else
			root->left = r;
		return r;
	}

	if (data > r->data)
		CreateTree(r, r->right, data);
	else
		CreateTree(r, r->left, data);

	return root;
}


void print_tree(struct Node* r, int l)
{

	if (r == NULL)
	{
		return;
	}

	print_tree(r->right, l + 1);
	for (int i = 0; i < l; i++)
	{
		printf(" ");
	}

	printf("%d\n", r->data);
	print_tree(r->left, l + 1);
}


void preOrderTravers(Node* root, int d) {
	if (root) {
		if (d == root->data)
			n++;
		preOrderTravers(root->left, d);
		preOrderTravers(root->right, d);
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	int D, start = 1, k;
	int serc = 0;
	root = NULL;

	while (1) {
		printf("\nВведите номер операции:\n1)Добавить эл. в дерево   2)Поиск эл. в дереве   3)Просмотреть эл. дерева    4)Посмотреть кол-во входов эл.    5)Выйти\n");
		scanf_s("%d", &k);
		switch (k) {
		case 1:
			start = 1;
			printf("-1 - окончание построения дерева\n");
			while (start)
			{
				printf("Введите число: ");
				scanf_s("%d", &D);
				if (D == -1)
				{
					start = 0;
				}
				else {
					preOrderTravers(root, D);
					if (n == 0)
						root = CreateTree(root, root, D);
					else {
						printf("Ошибка! Введите неповторяющееся число: ");
						n = 0;
						break;
					}
				}
			}
			break;
		case 2:
			if (root != NULL) {
				printf("Введите номер нужного элемента\n");
				scanf_s("%d", &serc);
				preOrderTravers(root, serc);
				if (n > 0) {
					printf("Элемент есть в дереве");
					n = 0;
					break;
				}
				else {
					printf("Элемента нет в дереве");
					break;
				}
				break;
			}
			else
				printf("Нет элементов в дереве");

			break;
		case 3:
			if (root != NULL) {
				print_tree(root, 3);
				break;
			}
			else
				printf("Нет элементов в дереве");
			break;
		case 4:
			if (root != NULL) {
				printf("Введите номер нужного элемента\n");
				scanf_s("%d", &serc);
				preOrderTravers(root, serc);
				printf("Кол-во вхождений элемента - %d", n);
				n = 0;
				break;
			}
			else
				printf("Нет элементов в дереве");
			break;
		case 5:
			return 0;
		}
	}
}
