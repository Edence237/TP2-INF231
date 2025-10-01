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
void insertHead(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        newNode->next = newNode; // Seul nœud pointe sur lui-même
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next; // aller au dernier nœud
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode; // mettre à jour la tête
    }
}
void insertTail(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}
void display(Node* head) {
    if (head == NULL) {
        printf("Liste vide\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(tête)\n");
}

int main() {
    Node* head = NULL;
    int choix, valeur;

    do {
        printf("\nMenu :\n");
        printf("1. Insertion en tête\n");
        printf("2. Insertion en queue\n");
        printf("3. Afficher la liste\n");
        printf("0. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrez la valeur à insérer en tête : ");
                scanf("%d", &valeur);
                insertHead(&head, valeur);
                break;
            case 2:
                printf("Entrez la valeur à insérer en queue : ");
                scanf("%d", &valeur);
                insertTail(&head, valeur);
                break;
            case 3:
                printf("Liste circulaire : ");
                display(head);
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide\n");
        }
    } while (choix != 0);

    return 0;
}

