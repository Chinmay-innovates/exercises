/*dynamic output*/

#include <stdio.h>
#include <stdlib.h>

// Node structure for the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head != NULL) {
        newNode->next = *head;
        (*head)->prev = newNode;
    }

    *head = newNode;
}

// Function to delete a node with a specific key
void deleteNode(struct Node** head, int key) {
    struct Node* current = *head;

    // Traverse the list to find the node with the given key
    while (current != NULL) {
        if (current->data == key) {
            // Update pointers of the previous and next nodes
            if (current->prev != NULL)
                current->prev->next = current->next;
            else
                *head = current->next;

            if (current->next != NULL)
                current->next->prev = current->prev;
                printf("%d is deleted!",current->data);
            
            free(current);
            return;
        }
        current = current->next;
    }

    // Node with the given key not found
    printf("Node with key %d not found\n", key);
}

// Function to print the doubly linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d <=> ", node->data);
        node = node->next;
    }              
    printf("NULL\n");

}

// Function to free the memory occupied by the doubly linked list
void freeList(struct Node* head) {
    while (head != NULL) {
        struct Node* temp = head;
        head=head->next;
        free(temp);
    }

}

// Example usage with dynamic input
int main()
{
    struct Node* head = NULL;
    int choice, data;
    int isValidchoice=0; /* To Avoid infinity loop*/

    do {
        printf("\n1. Insert at the beginning\n");
        printf("2. Delete a node\n");
        printf("3. Print the list\n");
        printf("4. Exit\n");
        while (!isValidchoice)
        {
             printf("\nEnter your choice: ");

              if(scanf("%d",&choice)==1){
                if(choice==4)
                   break;

                switch (choice)
               {
                 case 1:
                  printf("Enter data to insert: ");
                  scanf("%d", &data);
                  insertAtBeginning(&head, data);
                  break;

                 case 2:
                  printf("Enter data to delete: ");
                  scanf("%d", &data);
                  
                  deleteNode(&head, data);
                  break;
                 case 3:
                  printf("\nDoubly linked list:\n");
                  printList(head);
                  break;
                 case 4: break;
                
                  default: printf("\ninvalid input!\n\n");break;
                }
            } else
                {
                    while (getchar()!='\n');
                        printf("\ninvalid input! enter integer\n");                    
                }      
        }
    }while (choice!=4); 
    freeList(head); 
    return 0;
}


            
               
        
  

     

           

          