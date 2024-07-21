#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char *key;
    char *value;
    struct node *next;
};

void setNode(struct node *node, char *key, char *value)
{
    node->key = strdup(key);
    node->value = strdup(value);
    node->next = NULL;
}

struct hashMap
{
    int numOfElements, capacity;
    struct node **arr;
};

void initializeHashMap(struct hashMap *mp)
{
    mp->capacity = 100;
    mp->numOfElements = 0;
    mp->arr = malloc(mp->capacity * sizeof(struct node *));
    for (int i = 0; i < mp->capacity; ++i)
    {
        mp->arr[i] = NULL;
    }
}

int hashFunction(struct hashMap *mp, char *key)
{
    int bucketIndex;
    int sum = 0, factor = 31;
    for (int i = 0; i < strlen(key); i++)
    {
        sum = (sum + ((int)key[i] * factor) % mp->capacity) % mp->capacity;
        factor = (factor * 31) % __INT_MAX__; // Avoid overflow
    }
    bucketIndex = sum;
    return bucketIndex;
}

void insert(struct hashMap *mp, char *key, char *value)
{
    int bucketIndex = hashFunction(mp, key);
    struct node *newNode = malloc(sizeof(struct node));
    setNode(newNode, key, value);
    if (mp->arr[bucketIndex] == NULL)
    {
        mp->arr[bucketIndex] = newNode;
    }
    else
    {
        newNode->next = mp->arr[bucketIndex];
        mp->arr[bucketIndex] = newNode;
    }
}

void delete(struct hashMap *mp, char *key)
{
    int bucketIndex = hashFunction(mp, key);
    struct node *prevNode = NULL;
    struct node *currNode = mp->arr[bucketIndex];
    while (currNode != NULL)
    {
        if (strcmp(key, currNode->key) == 0)
        {
            if (prevNode == NULL)
            {
                mp->arr[bucketIndex] = currNode->next;
            }
            else
            {
                prevNode->next = currNode->next;
            }
            free(currNode->key);
            free(currNode->value);
            free(currNode);
            break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}

char *search(struct hashMap *mp, char *key)
{
    int bucketIndex = hashFunction(mp, key);
    struct node *bucketHead = mp->arr[bucketIndex];
    while (bucketHead != NULL)
    {
        if (strcmp(bucketHead->key, key) == 0)
        {
            return bucketHead->value;
        }
        bucketHead = bucketHead->next;
    }
    char *errorMssg = malloc(sizeof(char) * 25);
    strcpy(errorMssg, "Oops! No data found.\n");
    return errorMssg;
}

int main()
{
    struct hashMap *mp = malloc(sizeof(struct hashMap));
    initializeHashMap(mp);

    insert(mp, "Yogaholic", "Anjali");
    insert(mp, "pluto14", "Vartika");
    insert(mp, "elite_Programmer", "Manish");
    insert(mp, "GFG", "BITS");
    insert(mp, "decentBoy", "Mayank");

    printf("%s\n", search(mp, "elite_Programmer"));
    printf("%s\n", search(mp, "Yogaholic"));
    printf("%s\n", search(mp, "pluto14"));
    printf("%s\n", search(mp, "decentBoy"));
    printf("%s\n", search(mp, "GFG"));
    printf("%s\n", search(mp, "randomKey"));

    printf("\nAfter deletion : \n");
    delete (mp, "decentBoy");
    printf("%s\n", search(mp, "decentBoy"));

    // Free memory
    for (int i = 0; i < mp->capacity; ++i)
    {
        struct node *current = mp->arr[i];
        while (current != NULL)
        {
            struct node *next = current->next;
            free(current->key);
            free(current->value);
            free(current);
            current = next;
        }
    }
    free(mp->arr);
    free(mp);

    return 0;
}
