/*Author: John G. Toland, Project 3 CS4352
Recursive function for printing the path and contents from a given directroy*/
#include <dirent.h> 
#include <stdio.h> 
#include <string.h>

#define NORMAL_COLOR  "\x1b[0m"
#define GREEN  		  "\x1b[32m"
#define BLUE  		  "\x1b[34m"
#define RED     	  "\x1b[31m"
#define YELLOW  	  "\x1b[33m"
#define MAGENTA 	  "\x1b[35m"
#define CYAN    	  "\x1b[36m"
#define RESET   	  "\x1b[0m"

int x = 0;
int files = 0;
int folders = 0;
int error = 0;

char folder_name[255];
/* let us make a recursive function to print the content of a given folder */

void show_dir_content(char * path){
	// open the path
	DIR * d = opendir(path);
	// delcareing a char pointer to the . that appears infront of hidden files
	char * hidden = ".";

	// for the directory entries
	struct dirent * dir; 
	// if we were able to read somehting from the directory
	while (1) { 
			dir = readdir(d);
			if(!dir){
				//decrement depth of folders cause we have backed out of a dir
				x--;
				break;
			}
			// char pointer for the substring compare (seeing if file is a hidden file)
			char * temp = dir ->d_name;
			// if the type is not directory just print it with blue (if hidden file then ignore it)
			if(dir-> d_type != DT_DIR && (temp[0] != hidden[0])){
				// print the folder that contains the file in green		
				for(int i =0; i<x; i++){
					printf("%s| ",GREEN);
				}
				files++;
				printf("%s|-/",GREEN);
				// file in blue
				printf("%s%s\n",BLUE, dir->d_name);
			}else{
				 // if it is a directory
				if(dir -> d_type == DT_DIR && strcmp(dir->d_name,".")!=0 && strcmp(dir->d_name,"..")!=0 ){
					// print its name in green
					//printf("%s%s/%s\n",GREEN, path, dir->d_name);
					for(int i =0; i<x; i++){
						printf("%s| ",GREEN);
					} 
					printf("%s|-%s/\n",GREEN, dir->d_name);
					//increment depth of folders
					x++;
					folders++;
					// delcare a char variable for the path
					char d_path[255]; 
					// here I am using sprintf which is safer than strcat
					sprintf(d_path, "%s/%s", path, dir->d_name);
					// recall with the new path
					show_dir_content(d_path);
				}
			}
		}
		closedir(d); // finally close the directory
}

int main(int argc, char **argv){
	// prints a new line in normal color
	printf("%s\n", NORMAL_COLOR);
	// if agrument is empty use this directroy as default
	if(!argv[1]){
		// set argument to . (this directory)
		argv[1] = ".";
	}
	//check if directory exists
	DIR * d = opendir(argv[1]);
	if(d==NULL) {
		// print error statement since directory does not exist
		printf("%s[ello]: ERROR! ...no such directory exists.\n",RED);
	}else{
		// print root directory
		printf("%s%s\n", CYAN, argv[1]);
		// call to recursive function to display the contents of given directory
		show_dir_content(argv[1]);
		// print finito when the program is finished
		printf("\n%s[finito]: bottom of hierarchy\n\n", MAGENTA);
		printf("%sNumber of folders: %d\nNumber of files: %d", CYAN, folders, files);
	}
	// setting the text color to normal
	printf("%s\n", NORMAL_COLOR);
	// return from main with 0
	return(0);
}