#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<math.h>
int main(int argc, char** argv){
	int max=atoi(argv[1]); // width of the line = max
	char file[255],new; 
	int length; // length of the string
	int i,maximum=0;

	if ((argc<3)||(argc>3)){ // command line inputs should be equal to 3
		printf("Usage: ./prog <width> <input-file>\n");
	}

	FILE *fp; // file pointer
	fp=fopen(argv[2],"r"); // open the file for reading



	while(fscanf(fp,"%s%c",file,&new)!=EOF){ //reading file fp
		length=strlen(file); //length of the string
	}
	fclose(fp); // closing the file



	if (max<length+1){ // maximum width of the line should be greater than or eual to the maximum length of the string
		printf("Word length must be less than screen width\n");
		return 0;
	}



	if(max>pow(10,17)){ // when width>10^17 prints word line by line but not working :(
		printf("%s\n",file);
	}	

			 

	fp=fopen(argv[2],"r"); // open the file
	while(fscanf(fp,"%s%c",file,&new)!=EOF){ // reading the file
		length=strlen(file); // length of the string
		if(i+length<=max){ 
			i+=length+1;
		}else {
			printf("\n");
			i=length+1;
		}
		printf("%s ",file);
		if(new=='\n'){
			printf("\n");
			i=0;
		}
	}

	fclose(fp);	// closing the file
	return 0;
}
