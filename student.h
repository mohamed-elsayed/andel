
#ifndef __RECORD__H
#define __RECORD__H
#include <stdio.h>
/*variables declarations*/
struct Node{
    int id;
	int  **arr1;
	char (*arr2)[15];
	char *address;
	struct Node * next;
};

struct buf{
	char*address;
	struct buf*link;
};

enum bool_{NO,YES};
extern FILE * fp;
extern struct buf * top ;

/*function declarations*/
enum bool_ is_in_list(int id,struct Node* head);

struct Node* del_student(struct Node * head, int value);

struct Node * GenerateNode();

struct Node * CreateStudent(struct Node* head);

void print_id(struct Node* head,int id);

void print_all(struct Node * head);

void print_to_DB(struct Node *head);

void load_data ();

int length(struct Node* head);

void push(char *A);

enum bool_ not_in_buff(char * data,struct buf* top);

void show_field_value(struct Node * head,int i);

void search(struct Node* head,const char * str,int i);

#endif