#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char letter;
    struct node *next;
} node;

// Returns number of nodes in the linkedList.
int length(node *head)
{
    int count = 0;
    while (head)
    {
        head = head->next;
        count++;
    }
    return count;
}

// parses the string in the linkedList
char *toCString(node *head)
{
    int l = length(head);
    char *str = (char *)malloc(sizeof(char) * (l + 1));
    struct node *tmp = head;
    int i = 0;
    while (head != NULL)
    {
        str[i] = head->letter;
        head = head->next;
        i += 1;
    }
    str[l] = '\0';
    return str;
}

// inserts character to the linkedlist
void insertChar(node **pHead, char c)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->letter = c;
    struct node *last = *pHead;
    new_node->next = NULL;
    if (*pHead == NULL)
    {
        *pHead = new_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
}

// deletes all nodes in the linkedList.
void deleteList(node **pHead)
{
    struct node *temp = *pHead;
    struct node *next;
    while (temp != NULL)
    {
        next = temp->next;
        free(temp);

        temp = next;
    }
    *pHead = NULL;
}

int main(void)
{
    int i, strLen, numInputs;
    node *head = NULL;
    char *str;
    char c;
    FILE *inFile = fopen("input.txt", "r");
    fscanf(inFile, " %d\n", &numInputs);
    while (numInputs-- > 0)
    {
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++)
        {
            fscanf(inFile, " %c", &c);
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