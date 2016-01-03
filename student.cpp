#include "student.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
//global variables
 FILE * fp;
 struct buf * top =NULL;
//functions declarations
//test done
enum bool_ is_in_list(int id,struct Node* head){
	if (head == NULL) return NO;
	while(head != NULL){
		if(head ->id == id)return YES;
		head = head ->next;
	}
	return NO;
}



/*function test cases
deletion at first ,end and mid
empty list
wrong id encountered*/
//test done
struct Node* del_student(struct Node * head, int value){
	struct Node* current,*prev;
	//keep track of prev and current node
	prev = head;
	current = head;
	if(head == NULL)
		{
		printf("Empty list:\n");
		return NULL;
	    }
	/*first node occurrence*/
	if(current->id == value)
	    {
		printf("Are you sure:(yes/no)");
	    if(getchar() == 'y'){
		head = head ->next;
		free(prev);
		fflush(stdin);
		}
		return head;
	    }
	/*traverse the list for find node*/
	/*exit condition is whether end of list and not found (current =NULL)
	or
	found already and not counter null at current node */
	else{
		do{
			if(current->id == value)
				{
					
					break;
				}
			prev=current;
			current = current->next;
			
		 }while((current != NULL));
	}
	if (current == NULL) 
	    {/*wrong id not found*/
		printf("===============: Wrong id :===============\n");
		return head;
	    }
	
	printf("Are you sure:(yes/no)");
	if(getchar() == 'y'){
		prev ->next = current->next;
		current ->next = NULL;
	    free(current);
		fflush(stdin);
	}
	return head;
}


//test done
struct Node * GenerateNode(){
	//int row,col;
	struct Node * head = (struct Node *) malloc(sizeof(struct Node));
	if (head == NULL) exit(EXIT_FAILURE);
	head->id =0;
	//=======================================================================
	head->arr1 = (int**)malloc(2*sizeof(int*));//array of int pointer
	if (head->arr1 == NULL){
		puts("\n Failure in allocate room for row pointer\n");
		exit(EXIT_FAILURE);
	}
	(head->arr1[0]) = (int *)malloc(11*sizeof(int));//day/month/year
	if (head->arr1[0] == NULL) exit(EXIT_FAILURE);

	(head->arr1[1]) = (int * )malloc(15*sizeof(int));//telephone
	if (head->arr1[1] == NULL) exit(EXIT_FAILURE);
	//======================================================================
	//nrows =6,ncols=15
	head ->arr2 = (char(*)[15])malloc(5*15*sizeof(char));//array of char pointer
	head ->address= (char *)malloc(50*sizeof(char));
	if (head->arr2 == NULL) exit(EXIT_FAILURE);

	//first name,last name,country,city,gender,address

	//===========initialize all to null========================
	/*for(row=0;row<6;row++){
		for(col=0;col<15;col++){
			head->arr2[row][col]=NULL;
		
		}
	}*/
	return head;
}


//test done
struct Node * CreateStudent(struct Node* head){
	struct Node * temp = GenerateNode();
	printf("Enter your id:\n");
	scanf("%d",&temp->id);
	fflush(stdin);
	//check for valid id
	while(is_in_list(temp->id,head)){
		printf("Already exist select another one:\n");
		scanf("%d",&temp->id);
		fflush(stdin);
	};
	
	
	printf("Enter First name:\n");
	fgets(temp->arr2[0],15,stdin);
	printf("Enter last name:\n");
	fgets(temp->arr2[1],15,stdin);

	printf("Enter your country:\n");
	fgets(temp->arr2[2],15,stdin);
	printf("Enter your city: \n");
	fgets(temp->arr2[3],15,stdin);

	printf("Enter your gender:\n");
	fgets(temp->arr2[4],15,stdin);

	printf("Enter your Address:\n");
	fgets(temp->address,50,stdin);
	fflush(stdin);
	printf("Enter date of birth: (day/month/year) \n");
	fgets((char*)temp->arr1[0],11,stdin);
	fflush(stdin);
	printf("Enter your phone:\n");
	fgets((char*)temp->arr1[1],15,stdin);

	temp ->next = head;
	return temp;

}



//print data of student given id
//test done
void print_id(struct Node* head,int id){
	if(is_in_list(id,head))
	{
			while(head -> id != id)
			head =head->next;
			printf("this %d id has the following info:\n \n",head->id);
			printf("First Name:%s \n",head->arr2[0]);
			printf("Last Name:%s \n",head->arr2[1]);
			printf("Country:%s \n",head->arr2[2]);
			printf("City:%s \n",head->arr2[3]);
			printf("Gender:%s \n",head->arr2[4]);
			printf("Address:%s \n",head->address);
			printf("Date_Of_Birth:%s \n",(char*)head->arr1[0]);
			printf("Telephone Number: %s\n",(char*)head->arr1[1]);
			
	}else
			printf("Not in list:\n");
}

//print all list
//test done
void print_all(struct Node * head){
	if(head == NULL)return;

	while(head != NULL){
		printf("this %d id has the following info:\n \n",head->id);
		printf("First Name:%s \n",head->arr2[0]);
		printf("Last Name:%s \n",head->arr2[1]);
		printf("Country:%s \n",head->arr2[2]);
		printf("City:%s \n",head->arr2[3]);
		printf("Gender:%s \n",head->arr2[4]);
		printf("Address:%s \n",head->address);
		printf("Date_Of_Birth:%s \n",(char*)head->arr1[0]);
		printf("Telephone Number: %s\n",(char*)head->arr1[1]);
		head = head ->next;
	}

}


//print to file
//test done
void print_to_DB(struct Node *head){
	
	    if(head == NULL) return;
		while(head != NULL)
		{
	    fprintf(fp,"ID is: %d\n",head->id);
		fprintf(fp,"First Name:%s \n",head->arr2[0]);
		fprintf(fp,"Last Name:%s \n",head->arr2[1]);
		fprintf(fp,"Country:%s \n",head->arr2[2]);
		fprintf(fp,"City:%s \n",head->arr2[3]);
		fprintf(fp,"Gender:%s \n",head->arr2[4]);
		fprintf(fp,"Address:%s \n",head->address);
		fprintf(fp,"Date_Of_Birth:%s \n",(char*)head->arr1[0]);
		fprintf(fp,"Telephone Number: %s\n",(char*)head->arr1[1]);
		head = head ->next;
		}

}


//open file to load data
//test done
void load_data (){
	if( (fp=fopen("DB_STUDENT.txt","a"))==NULL )
			exit(EXIT_FAILURE);
	
}

//test done
int length(struct Node* head)
{
    int count = 0;
    while(head != NULL)
        {
        count ++;
        head = head->next;
        }
    return count;

}


void push(char *A){
	/*this function act as buffer of visited value
	to eliminated duplication of value countining*/
	struct buf * temp =(struct buf*)malloc(sizeof(struct buf*));
	temp->address = A;
	temp->link=top;
	top=temp;

}


enum bool_ not_in_buff(char * data,struct buf* top){
	
	while(top != NULL){
		if(top ->address == data)return NO;
		top = top->link;
	}
	return YES;
	
}


void show_field_value(struct Node * head,int i){
	struct Node *  temp= head;
	int count =0 ;
	int j = 0;
	char *value;
	int max = length(head);//not in the for loop as it will updated every iteration
	if (head == NULL) return;
	for(j=0;j<max;j++)
	{
		value=head->arr2[i];
		if(not_in_buff(head->arr2[i],top ))
	    //if the node addreess in buffer it is already counted before
	    //so go update part along
		{
			while(head != NULL)
			{
				if( !(strcmp(head->arr2[i],value)) )
				{
					count++;
					push(head->arr2[i]);//every visited node pushed in buffer
					//using this technique instead devastate data by puting null for example
				}
			head = head->next;
			}
			printf("%s %d \n",value,count);
		}
			//next step initialization (update part)
			head = temp->next;
			temp = head;
			count =0;
		
	}
}


//test done
void search(struct Node* head,const char * str,int i){
	/*i value determine the field specifier
	  i=0 search by first name
	  i=1 search by last name
	  i=2 search by month of birth or any value of birth
	  i=3 search by telephone nnumber
	  i=4 search by month/year of birth
	  */
	int j = i -2;
	if (head == NULL){printf("Empty list \n");return;}
	if(i<2)//search for fist or last name
	{
		while (head != NULL)
		{
			if(! strcmp(str,head->arr2[i]))
			{
				break;		
			}
			head = head->next;
		}
	
	}else if(j == 0)
	{
		while(head != NULL)
		{
			if( ((char*)head->arr1[0])[3] == str[0] &&  ((char*)head->arr1[0])[4] == str[1])
				//month of birth
			{
			break;	
			}
		head = head->next;
		}	
	}else if(j == 1)
	{
		while(head != NULL)
		{
			if(! strcmp(str,(char*)head->arr1[1]))//telephone number
			{
				break;		
			}
		head = head->next;
		}	
	}else{
		while(head != NULL)
		{
			if( ((char*)head->arr1[0])[3] == str[0] && 
				((char*)head->arr1[0])[4] == str[1] &&
				((char*)head->arr1[0])[5] == str[2] &&
				((char*)head->arr1[0])[6] == str[3] &&
				((char*)head->arr1[0])[7] == str[4] &&
				((char*)head->arr1[0])[8] == str[5] &&
				((char*)head->arr1[0])[9] == str[6] )
				//month/year of birth
			{
			break;	
			}
		head = head->next;
		}	
	
	
	}
	if(head == NULL) 
		printf("NOT FOUND:\n");
	else
		print_id(head,head->id);
return ;		
}	