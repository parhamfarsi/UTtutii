#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
#define debug 0

char* username;
char* Password;
profile* head;
profile* current;
int postid;
char* post;
char* Text;
char* input;
FILE* accounts;
FILE* posts;


void signup(void){
    profile* temp;
    temp = head->next;
    if(strlen(username) < 1){
        printf("incorrect username");
    }
    if(strlen(Password) < 1){
        printf("too easy password");
    }
    while(temp){// finding NULL structure
        if(!strcmp(temp->user_name, username)){// if the username token before you take it
            printf("this username is token\n");
            return;
        }
        temp = temp->next;
    }

    temp = (profile*) malloc(sizeof(profile));// put the username and password in structure
    temp->user_name = username;
    temp->password = Password;
    Post* temp2 = (Post*) malloc(sizeof(Post));
    temp->posts = temp2;
    temp->posts->next = NULL;
    temp->next = head->next;// put this structure in your head list
    head->next = temp;
    printf("user succesfully signed up\n");
} 
void login(void){
    current = head->next;
    if(!current){// when anyone do not sign up
        printf("no user signup\n");
        return;
    }
    while(current){// find the structure and redefinition current
        if(!strcmp(Password, current->password)){
            if(!strcmp(username, current->user_name)){// when we find that structure
                printf("you login succesfully\n");
                return;
            }
        }
        current = current->next;
    }
    printf("username or password is incorrect\n");// when we do not find that structre so user write incorrect password
    return;
}
void like(void){
    profile* temp;
    int x = 0;
    temp = head->next;
    while(temp != NULL){// find the username that we want to like his post
        if(strcmp(temp->user_name, username)){
            x = 1;
            break;
        }
    }
    if(temp = NULL) printf("information is incorrect");// if you do not find that username
    if(x = 1){// if we find
        Post* temp2 = temp->posts->next;
        while(temp2 != NULL){// find NULL post
            if(temp2->post_id == postid){
                temp2->like ++;
                printf("like succesfully finished");
                break;
            }
            temp2 = temp2->next;
        }
        if(temp2 == NULL){
            printf("wrong postid");
        }
    }

}
void logout(void){
    current = head;// put your current in head
}

void Delete(void){
    if(current == head){// if you do not login
        printf("login first");
        return;
    }
    Post *Temp= current->posts;
    while(Temp){// find that post id
        if(Temp->next->post_id == postid){
            Temp->next = Temp->next->next;        
            printf("Post deleted succesfully\n");
            return;
        }
        Temp = Temp->next;
    }
    printf("post not found\n");
    return;
}
void info(void){
    if(current = head){// if we do not login
        printf("login first\n");
        return;
    }
    printf("username: %s\n", current->user_name);
    printf("password: %s\n", current->password);
    Post* temp = current->posts->next;
    while(temp != NULL){
        printf("postid: %d\n", temp->post_id);
        printf("post: %s\n", temp->text);
        printf("like: %d", temp->like);
        temp = temp->next;
    }
    return;
}

void find_user(void){
    profile* temp = head->next;
    while(temp != NULL){
        if(strcmp(temp->user_name, username)){
            printf("username: %s\n", temp->user_name);
            printf("password: %s\n", temp->password);
            Post* temp2 = temp->posts->next;
            while(temp2 != NULL){
                temp2 = temp2->next;
            }
            temp2->next = temp2;
            printf("postid: %d\n", temp2->post_id);
            printf("post: %s\n", temp2->text);
            printf("like: %d\n", temp2->like);
            return;
        }
    }
    if(temp == NULL){
        printf("incorrect username");
    }
}
void posting(void){
    if(current = head){
        printf("please login first");
    }
    Post* temp = current->posts->next; 
    while(temp){
        temp = temp->next;
    }
    current->num_of_post ++;
    temp->text = Text;
    free(Text);
}
