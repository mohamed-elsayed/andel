#include "student.h"
#include <stdlib.h>

	
int main(){
	//printf("%u %u %u %u ",sizeof(struct Node),sizeof(struct Node*),sizeof(int **),sizeof(char (*)[]));
	load_data();
	struct Node * head = NULL;
	int select,id;
	int i;
	char *str;
	str=(char *)malloc(15*sizeof(char));
        printf(" Enter 1 to add student: \n");
	printf(" Enter 2 to delete student with id: \n ");
        printf(" Enter 3 to get search for student by (First name(0),family name(1),telephone(2),monthofbirth(3)): \n ");
	printf(" Enter 4 to save all data to a file: \n");
        printf(" Enter 5 to Load data from a file: \n");
	printf(" Enter 6 to display total info of s student given ID:\n");
	printf(" Enter 7 to show different values of a certain field (First name(0),family name(1),telephone(2),monthofbirth(3)): \n  ");
	printf(" Enter 8 to exit:\n");

do
{
  printf("============== Enter your selection =================\n");
  scanf("%d",&select);
  fflush(stdin);
 switch(select)
 {
 case 1 :
    head = CreateStudent(head);
    print_to_DB(head);
    break;
 case 2 :
	 printf("Enter the ID:");
	 scanf("%d",&id);
	 fflush(stdin);
     head=del_student( head,id);
	 print_all(head);
	 break;
 case 3 :
	 /*i value determine the field specifier
	  i=0 search by first name
	  i=1 search by last name
	  i=3 search by telephone nnumber
	  i=2 search by month of birth or any value of birth*/
	printf("Enter the value to look for and id:\n(id value)");
	fgets(str,15,stdin);
	
	scanf("%d",&i);
	
    search(head,str,i);
    break;
 case 4 :
     print_to_DB(head);
     break;
 case 5 :
     load_data ();
     break;
 case 6 :
	 printf("Enter the ID:");
	 scanf("%d",&id);
	 fflush(stdin);
     print_id(head,id);
     break;

case 7 :
	/*i value determine the field specifier
	  i=0 search by first name
	  i=1 search by last name
	  i=2 search by 
	  */
	 printf("Enter the field to look for:\n");
	 scanf("%d",&i);
     show_field_value(head, i);
     break;
case 8 :
     exit(EXIT_SUCCESS);
     break;
 }


}while(select>= 1 && select<=8);
return 0;
}
