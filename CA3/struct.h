
typedef struct user_profile profile;
typedef struct  post_profile Post;


struct user_profile{// definition of our structures
    char* user_name;
    char* password;
    int num_of_post;
    Post* posts;
    profile* next;
};


struct post_profile{
    char* text;
    int like;
    int post_id;
    Post* next;
};
