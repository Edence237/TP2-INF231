#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void append(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}


void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void deleteOccurrences(Node** head, int value) {
    Node* temp = *head;
    Node* prev = NULL;

    while (temp != NULL) {
        if (temp->data == value) {
            Node* toDelete = temp;
            if (prev == NULL) { 
                // Suppression en tête
                *head = temp->next;
            } else {
                prev->next = temp->next;
            }
            temp = temp->next;
            free(toDelete);
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

int main() {
    Node* head = NULL;
    int n, value, target;

    printf("Combien d'elements voulez-vous ajouter ? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Entrez la valeur %d : ", i + 1);
        scanf("%d", &value);
        append(&head, value);
    }

    printf("\nListe avant suppression :\n");
    display(head);

    printf("\nEntrez la valeur a supprimer : ");
    scanf("%d", &target);

    deleteOccurrences(&head, target);

    printf("\nListe apres suppression de %d :\n", target);
    display(head);

    return 0;
}