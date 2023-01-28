#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#define true 1

void main(){
    Post* temp2;
    username = (char*) malloc(100 * sizeof(char));
    Password = (char*) malloc(100 * sizeof(char));
    input = (char*) malloc(500 * sizeof(char));// mallocation of input
    char* order = (char*) malloc(10 * sizeof(char));// definition of the orders of UTtuti and mallocation them
    char* order1 = (char*) malloc(10 * sizeof(char));
    char* order2 = (char*) malloc(10 * sizeof(char));
    char* order3 = (char*) malloc(10 * sizeof(char));
    char* order4 = (char*) malloc(10 * sizeof(char));
    char* order5 = (char*) malloc(10 * sizeof(char));
    char* order6 = (char*) malloc(10 * sizeof(char));
    char* order7 = (char*) malloc(10 * sizeof(char));
    char* order8 = (char*) malloc(10 * sizeof(char));
    char* order9 = (char*) malloc(10 * sizeof(char));
    order1 = "signup";
    order2 = "login";
    order3 = "like";
    order4 = "logout";
    order5 = "delete";
    order6 = "info";
    order7 = "find_user";
    order8 = "post";
    order9 = "quit";
    head = (profile*) malloc(sizeof(profile));
    head->next = NULL;
    current = NULL;
    posts = fopen("posts.txt", "w");
    while(true){// put all of the program in  while
        printf("write your input command: ");
        gets(input);// input of the user
        order = strtok(input, " ");// take the order
        if(!strcmp(order, order1)){// if the order is signup
            input += 7;
            username = strtok(input, " ");// taking each order
            input += strlen(username) + 1 ;
            Password = input;
            signup();
        }
        else if(!strcmp(order, order2)){//if the order is login
            printf("%s", head->next->password);
            input += 6;
            username = strtok(input, " ");
            input += strlen(username) + 1;
            Password = input;
            login();
        }
        else if(!strcmp(order, order3)){// if the order is like
            input += 5;
            username = strtok(input, " ");
            input += strlen(username) + 1;
            postid = atoi(input);
            like();
        }
        else if(!strcmp(order, order4)){// if the order is logout
            logout();
        }
        else if(!strcmp(order, order5)){// if the order is delete of the post
            input += 7;
            postid = atoi(input);
            Delete();
        }
        else if(!strcmp(order, order6)){// if the order is info
            input += 5;
            info();
        }
        else if(!strcmp(order, order7)){// if the order is find user
            input += 10;
            username = strtok(input, " ");
            find_user();
        }
        else if(!strcmp(order, order8)){// if the order is post
            input += 5;
            Text = input;
            temp2 = current->posts->next;
            while(temp2){
                temp2 = temp2->next;
            }
            temp2->next = temp2;
            fprintf(posts, "%s %s %d\n", Text, current->user_name, temp2->like);

        }
        else if(!strcmp(order, order9)){// if you want to quit the game
            break;
        }
        else{// if you write incorrect order with every permission
            printf("write correct input"); 
        }
        free(input);
    } 

    
    accounts = fopen("accounts.txt", "w");
    profile* temp;

    while(temp){// when you quit we save all users info we do not save in the program because the info will change 
        fprintf(accounts, "%s %s %d\n", temp->user_name, temp->password, temp->num_of_post);
    }
}