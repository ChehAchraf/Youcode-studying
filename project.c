#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_BOOK 50
struct books{
    char book_name[MAX_BOOK];
    char book_author[MAX_BOOK];
    float price;
    int stock;
};
void display_menu();
void add_books(struct books b[],int *counter);
void show_books(struct books b[] , int *counter );
void search_book(struct books b[],int *counter);
void edit_book(struct books b[],int *counter);
void delete_book(struct books b[],int *counter);
int main ()
{
    struct books b[100];
    // defining our variables
    int choice = -1; 
    int counter = 0;

    // looping the all menu
    while (choice != 0)
    {
        display_menu();
        if(scanf("%d" , &choice) != 1){
            printf("\n entrer un valid nombre");
           while (getchar() != '\n');
    }
    scanf("%*[^\n]");
    getchar();
        
        // start the switch to maniplate the options
        switch(choice)
        {
            case 1 : 
                add_books( b , &counter );
            break;
            case 2 : 
                show_books(b ,&counter );
            break;
            case 3 : 
                search_book(b,&counter);
            break;
            case 4 :
                edit_book( b,&counter);
            break;
            case 5 :
                delete_book(b,&counter);
            break;
            default : 
                printf("\nEntrer un nombre valid\n");
            break;
        }
    } 

    return 0;
}
// function for menu display
void display_menu(){
    printf("\n---------------------------------------------------\n");
    printf("||\t \t  Bienvenue \t \t ||\n");
    printf("---------------------------------------------------");
    puts("\n1 - Ajouter un livre au stock.");
    puts("2 - Afficher tous les livres disponibles.");
    puts("3 - Rechercher un livre par son titre");
    puts("4 - Mettre a jour la quantite d'un livre.");
    puts("5 - Supprimer un livre du stock.");
    puts("6 - Afficher le nombre total de livres en stock.");
    puts("7 - Entret 0 pour quiter lapplication");
    printf("----> ");
}
// add books function 
void add_books(struct books b[],int *counter){
    int add_options;
    int i;
    printf("1 - Voulez-vous ajouter un livre ? \n 2 - Ou souhaitez-vous ajouter plusieurs livres ? \n");
    scanf("%d" , &add_options);
    if ( add_options == 1 ){
        printf("\n## entrer le nom de livre : ");
        scanf("%s" ,b[*counter].book_name);

        printf("## entrer le nom de lauteur : ");
        scanf("%s" ,b[*counter].book_author);
        AGAIN:
        printf("## entrer le prix de livre : ");
        if (scanf("%f" ,&b[*counter].price) != 1){
            getchar();
            goto AGAIN;
        }   
        printf("## entrer la quantite : ");
        scanf("%d" ,&b[*counter].stock);
        (*counter)++;
    }else if(add_options == 2){
        printf("Combien de fois souhaitez-vous saisir l'element?");
        scanf("%d", &i);
        for (int j = 0 ; j < i+1 ; j++){
            printf("\n ## entrer le nom de livre : ");
        scanf("%s" ,b[*counter].book_name);

        printf("## entrer le nom de lauteur : ");
        scanf("%s" ,b[*counter].book_author);

        printf("## entrer le prix de livre : ");
        scanf("%f" ,&b[*counter].price);

        printf("## entrer la quantite : ");
        scanf("%d" ,&b[*counter].stock);
        (*counter)++;
        }
    }
}
// function to loop through the item 
void show_books(struct books b[] , int *counter ){
    int tri_option;
    printf("\n### Voulez-vous ranger les livres :\n");
    printf(">1 - De A à z \n");
    printf("2- de Z à A\n");
    if (scanf("%d", &tri_option) != 1) {
        printf("Entrer un nombre valide.\n");
        // Clear invalid input from stdin
        while (getchar() != '\n');
    }
    scanf("%*[^\n]");
    getchar();

    isalnum(tri_option);
    // Check if the given input 
    // is numeric or not 
    if ( isdigit(tri_option) == 1){
        switch(tri_option){
        case 1 : 
            for(int i = 0 ; i < *counter ; i++)
            {
                for ( int j = 0 ; j < *counter-1 ; j++){
                    for (int c = 0 ; c < *counter -1 ; c++){
                        if (b[c].book_name[0] > b[c+1].book_name[0] ){
                        int temp = b[c].book_name[0];
                        b[c].book_name[0] = b[c+1].book_name[0];
                        b[c+1].book_name[0] = temp; 
                        }
                }
            }
    }
    for(int i = 0 ; i < *counter ; i++){
        printf("%s\n" , b[i].book_name );
    }
        break;
        case 2 : 
        for(int i = 0 ; i < *counter ; i++)
    {
        for ( int j = 0 ; j < *counter-1 ; j++){
            for (int c = 0 ; c > *counter -1 ; c++){
                if (b[c].book_name[0] > b[c+1].book_name[0] ){
                    int temp = b[c].book_name[0];
                    b[c].book_name[0] = b[c+1].book_name[0];
                    b[c+1].book_name[0] = temp; 
                }
            }
        }
    }
    for(int i = 0 ; i < *counter ; i++){
        printf("%s\n" , b[i].book_name );
    }
        break;
    }
    }else{
        printf("entrer un valid number ");
    }
}
// function to search for a book
void search_book(struct books b[],int *counter){
    char search_name[50];
    puts("voice d'abord notre list : ");
    for(int i = 0 ; i < *counter ; i++)
    {
        printf("\n ------------------------------------------------------------------------------------------------------------- \n");
        printf("\n|| le nom : %s \t || le auteur : %s \t || le prix : %.2f \t || le quantite : %d \n", b[i].book_name , b[i].book_author , b[i].price , b[i].stock);
        
    }
    printf("Entrer le nom que vous voulez rechercher : ");
    scanf(" %[^\n]" , search_name);
    for (int i = 0 ; i < *counter ; i++){
        if (strcmp(b[i].book_name , search_name ) == 0  ){
        printf("\n ------------------------------------------------------------------------------------------------------------- \n");
        printf("\n|| le nom : %s \t || le auteur : %s \t || le prix : %.2f \t || le quantite : %d \n", b[i].book_name , b[i].book_author , b[i].price , b[i].stock);       
        }
    }
}
// function to modify the books
void edit_book(struct books b[],int *counter)
{
    char search_name[50];
    char name_to_edit[50];
    int menu_to_edit;
    puts("ces notre list des livre disponible : ");
    for(int i = 0 ; i < *counter ; i++)
    {
        
        printf("\n ------------------------------------------------------------------------------------------------------------- \n");
        printf("\n|| le nom : %s \t || le auteur : %s \t || le prix : %.2f \t || le quantite : %d \n", b[i].book_name , b[i].book_author , b[i].price , b[i].stock);
        
    }
    printf("\n entrer le nom de livre que vous voulez modifier : ");
    scanf(" %[^\n]" , search_name );
    for(int i = 0 ; i < *counter ; i++){
        if (strcmp(b[i].book_name , search_name ) == 0  ){
        printf("\n Svp , vous voulez modifier qoi exactement ? :\n");
        printf("1 - Le nom de livre. \n 2 - lauteur de livre. \n 3 - le prix de livre. \n 4 - le stock.");
        printf("\n ---->");
        scanf("%d", &menu_to_edit);
        switch (menu_to_edit)
        {
        case 1:
            printf("\n entrer le nv nom de livre : ");
            scanf(" %[^\n]" , b[i].book_name);
            break;
        case 2 :
            printf("\n entrer le nv auteur de cette livre : ");
            scanf(" %[^\n]" , b[i].book_author);
            break;
        case 3 : 
            printf("\n entrer le nv  prix : ");
            scanf("%f" , &b[i].price);
            break;
        case 4 : 
            printf("\n entrer le nv stock : ");
            scanf("%d" , &b[i].stock);
            break;
        default:
            printf("\n there must be an error enter a valid number");
            break;
        }      
        }
    }
}
// function to delete books
void delete_book(struct books b[],int *counter){
    char del[40];
    if ( *counter == 0 ){
        printf("\nIl n'y a pas de livres actuellement, veuillez en ajouter quelques livres\n");
    }else{
        puts("ces notre pour ce moment : ");
    for(int i = 0 ; i < *counter ; i++)
    {
        
        printf("\n ------------------------------------------------------------------------------------------------------------- \n");
        printf("\n|| le nom : %s \t || le auteur : %s \t || le prix : %.2f \t || le quantite : %d \n", b[i].book_name , b[i].book_author , b[i].price , b[i].stock);
        
    }
        printf("\n entrer le nom de livre que vous voulez supprimer : ");
        scanf(" %[^\n]" , del);
        for(int i = 0 ; i < *counter ; i++){
            if (strcmp(b[i].book_name , del ) == 0  ){
                for(int j=i ; j < *counter -1; i++){
                    b[i] = b[i+1];
                    (*counter)--;
                }
            }
        }
        
    }

}

