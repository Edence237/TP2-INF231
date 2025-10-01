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
void insertSorted(Node** head, int value) {
    Node* newNode = createNode(value);

    // Cas 1 : liste vide ou valeur plus petite que la tête
    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Cas 2 : insertion au milieu ou à la fin
    Node* current = *head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
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
        printf("Liste actuelle : ");
        display(head);
    }

    printf("\nListe finale triée :\n");
    display(head);

    return 0;
}
