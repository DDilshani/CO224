#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//a linked list node named word
typedef struct word_t{
	char *name;
	int len;
	struct word_t *next;// to store the length of the word
} word;


int printed(char * w, word * head){
	word * current=head;
	while(current!=NULL){
		if(strcasecmp(current->name, w)==0) return 1;
		current=current->next;
	}
	return 0;
}

void add(char * w, word * head){
	word * current=head;
	while(current->next!=NULL){
		current=current->next;
	}

	current->next = malloc(sizeof(word));

	int i=0;
	while(w[i]!='\0'){
		current->next->name[i]=w[i];
		i++;
	}
}


// print the sorted linked list
void printText(word *i){
	word * current = i;
	char array[100][100];
	int count,j,k=0;
	for(count=30;count>0;--count){
		current = i;
		k=0;
		while (current != NULL){

			if(current->len == count){
					int p=0;
					for(j=0;j<100;j++){
						if(strcasecmp(array[j],current->name)==0){
							p=1;
							break;
						}
					}
					if(!p){
						printf("%s\n", current->name);
						strcpy(array[k],current->name);
						k++;
					}
					
						
			}
			current = current->next;
		}
	}
	
}

//read the input file and directing to the node
word* fileReader(FILE *file){
	word * i = malloc(sizeof(word));
	char para[255];
	int counter;
	int fileRead = fscanf(file,"%s",para);
	if ((para[strlen(para)-1]=='.')  || (para[strlen(para)-1]==',')){// to eliminate '.' and ','
		para[strlen(para)-1]= '\0';
	}

	if(fileRead != EOF){ 
	counter++;
        i->name = strdup(para);
	i->len = strlen(para);
        i->next = fileReader(file);
	
	}
	if(fileRead == EOF) {// if the linked list is empty
        return NULL;
	}
	return i;
}


int main(int argc, char** argv){ //command line input arguments
	FILE *fp = fopen(argv[1],"r"); // open the file
	word *i = fileReader(fp); 
	printText(i); //sort the linked list and print the sorted words
	fclose(fp); // closing the file
	return 0;
}
