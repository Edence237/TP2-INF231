

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = newNode->prev = NULL;
    return newNode;
}
void insertHead(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        newNode->next = newNode->prev = newNode;
        *head = newNode;
    } else {
        Node* tail = (*head)->prev;
        newNode->next = *head;
        newNode->prev = tail;
        tail->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    }
}
void insertTail(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        newNode->next = newNode->prev = newNode;
        *head = newNode;
    } else {
        Node* tail = (*head)->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = *head;
        (*head)->prev = newNode;
    }
}
void displayForward(Node* head) {
    if (!head) {
        printf("Liste vide\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(tête)\n");
}

// Affichage arrière (tail → head)
void displayBackward(Node* head) {
    if (!head) {
        printf("Liste vide\n");
        return;
    }
    Node* tail = head->prev;
    Node* temp = tail;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    } while (temp != tail);
    printf("(tête)\n");
}

int main() {
    Node* head = NULL;
    int choix, valeur;

    do {
        printf("\nMenu :\n");
        printf("1. Insertion en tête\n");
        printf("2. Insertion en queue\n");
        printf("3. Afficher liste avant\n");
        printf("4. Afficher liste arrière\n");
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
                printf("Liste avant : ");
                displayForward(head);
                break;
            case 4:
                printf("Liste arrière : ");
                displayBackward(head);
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