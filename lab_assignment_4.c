#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
    int counter = 0;
    if (head == NULL) {
        return counter;
    }
    while (head->next != NULL) {
        head = head->next;
        counter++;
    }
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
    int l = length(head), count=0;
    char stringy[length(head) + 1];
    stringy[l] = '\0';
    if (head == NULL) {
        return stringy;
    }
    for (count = 0; count < l; count++) {
        stringy[count] = head->letter;
        head = head->next;
    }
    return stringy;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
    node* new = (node*) malloc(sizeof(node));
    new->letter = c;
    node* current = *pHead;
    if (current == NULL) {
        *pHead = new;
        printf("%c\n", new->letter);
    } else {
        while (current->next != NULL){
            current = current->next;
        }
        current->next = new;
        printf("%c\n", new->letter);
    }
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}