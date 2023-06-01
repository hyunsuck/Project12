#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct nd_0
{
	struct nd_0* prv_1;
	struct nd_0* nxt_1;
	int dta;
};
struct nd_0* head;
void Insert_first();
void Insert_last();
void Delete_first();
void Delete_last();
void Print_list();
void main()
{
	int choce = 0;
	while (choce != 8)
	{
		printf("\n=========   Menu   =========\n");
		printf("\n1.Insert First\n2.Insert Last\n3.Delete First\n4.Delete Last\n5.Print List\n6.Exit\n");
		printf("Enter the menu : ");
		scanf("\n%d", &choce);
		switch (choce)
		{
		case 1:
			Insert_first();
			break;
		case 2:
			Insert_last();
			break;
		case 3:
			Delete_first();
			break;
		case 4:
			Delete_last();
			break;
		case 5:
			Print_list();
			break;
		case 6:
			exit(0);
			break;
		default:
			printf("Select_entry_of_your_choicce..");
		}
	}
}
void Insert_first()
{
	struct nd_0* ptr_0, * temp_1;
	int item_0;
	ptr_0 = (struct nd_0*)malloc(sizeof(struct nd_0));
	if (ptr_0 == NULL)
	{
		printf("\nList_Overflow");
	}
	else
	{
		printf("Input a number : ");
		scanf("%d", &item_0);
		ptr_0->dta = item_0;
		if (head == NULL)
		{
			head = ptr_0;
			ptr_0->nxt_1 = head;
			ptr_0->prv_1 = head;
		}
		else
		{
			temp_1 = head;
			while (temp_1->nxt_1 != head)
			{
				temp_1 = temp_1->nxt_1;
			}
			temp_1->nxt_1 = ptr_0;
			ptr_0->prv_1 = temp_1;
			head->prv_1 = ptr_0;
			ptr_0->nxt_1 = head;
			head = ptr_0;
		}
	}
}
void Insert_last()
{
	struct nd_0* ptr_0, * temp_1;
	int itm_0;
	ptr_0 = (struct nd_0*)malloc(sizeof(struct nd_0));
	if (ptr_0 == NULL)
	{
		printf("\niList_overflow");
	}
	else
	{
		printf("Input a number : ");
		scanf("%d", &itm_0);
		ptr_0->dta = itm_0;
		if (head == NULL)
		{
			head = ptr_0;
			ptr_0->nxt_1 = head;
			ptr_0->prv_1 = head;
		}
		else
		{
			temp_1 = head;
			while (temp_1->nxt_1 != head)
			{
				temp_1 = temp_1->nxt_1;
			}
			temp_1->nxt_1 = ptr_0;
			ptr_0->prv_1 = temp_1;
			head->prv_1 = ptr_0;
			ptr_0->nxt_1 = head;
		}
	}
}
void Delete_first()
{
	struct nd_0* temp_1;
	if (head == NULL)
	{
		printf("\n List_UNDERFLOW");
	}
	else if (head->nxt_1 == head)
	{
		head = NULL;
		free(head);
		printf("\ndelete_node_at_beginning\n");
	}
	else
	{
		temp_1 = head;
		while (temp_1->nxt_1 != head)
		{
			temp_1 = temp_1->nxt_1;
		}
		temp_1->nxt_1 = head->nxt_1;
		head->nxt_1->prv_1 = temp_1;
		free(head);
		head = temp_1->nxt_1;
		printf("First Node has been deleted\n");
	}
}
void Delete_last()
{
	struct nd_0* ptr_1;
	if (head == NULL)
	{
		printf("\n List_Underflow");
	}
	else if (head->nxt_1 == head)
	{
		head = NULL;
		free(head);
		printf("\nDelete Node\n");
	}
	else
	{
		ptr_1 = head;
		if (ptr_1->nxt_1 != head)
		{
			ptr_1 = ptr_1->nxt_1;
		}
		ptr_1->prv_1->nxt_1 = head;
		head->prv_1 = ptr_1->prv_1;
		free(ptr_1);
		printf("Last Node has been deleted\n");
	}
}
void Print_list()
{
	struct nd_0* ptr_0;
	ptr_0 = head;
	if (head == NULL)
	{
		printf("\nnot_to_print_anything;;");
	}
	else
	{
		
		while (ptr_0->nxt_1 != head)
		{
			printf("%d->", ptr_0->dta);
			ptr_0 = ptr_0->nxt_1;
		}
		printf("%d->", ptr_0->dta);
	}
}
