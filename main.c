#include <stdio.h>
#include <string.h>
#include <dirent.h>

void print_tree(const char* path, int tabs){
  DIR *root = opendir(path);
  if (root == NULL) {
    perror("");
	return;
  }
  struct dirent *current = readdir(root);
  while (current != NULL) {
	if(strcmp(current->d_name, ".") == 0)  {current = readdir(root); continue;}
	if(strcmp(current->d_name, "..") == 0) {current = readdir(root); continue;}

	// print tabs
    for (int i = 0; i < tabs; i++) { fputs("--", stdout); }
	// print name
	printf("%s\n", current->d_name);

	if (current->d_type == DT_DIR) {
	  char current_path[strlen(path) + strlen(current->d_name) + 2];
      strcpy(current_path, path);
      strcat(current_path,"/");
      strcat(current_path,current->d_name);
      print_tree(current_path, tabs + 1);
	}

	current = readdir(root);
  }
  closedir(root);
}
	

int main(int argc, char *argv[]){
  const char *root_path = (argc <= 1) ? "." : argv[1];

  printf("%s:\n", root_path);
  print_tree(root_path, 1);
  
  return 0;
}
