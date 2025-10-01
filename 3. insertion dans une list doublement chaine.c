#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertSorted(Node** head, int value) {
    Node* newNode = createNode(value);

    // Cas 1 : liste vide
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Cas 2 : insertion avant la tête
    if ((*head)->data >= value) {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    // Cas 3 : insertion au milieu ou à la fin
    Node* current = *head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}
void displayForward(Node* head) {
    Node* temp = head;
    printf("Liste avant : ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void displayBackward(Node* head) {
    Node* temp = head;

    // aller à la fin de la liste
    while (temp && temp->next != NULL) {
        temp = temp->next;
    }

    printf("Liste arrière : ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int n, value;

    printf("Combien de valeurs voulez-vous insérer dans la liste triée ? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Entrez la valeur %d : ", i + 1);
        scanf("%d", &value);
        insertSorted(&head, value);
        displayForward(head);
        displayBackward(head);
    }

    printf("\nListe finale triée :\n");
    displayForward(head);
    displayBackward(head);

    return 0;
}

