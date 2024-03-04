#include <stdio.h>
#include <stdlib.h>
int main() {
    if (mkdir("level1", 0777) == -1) {
        perror("Error creating level1 directory");
        exit(1);
    }
    if (chdir("level1") == -1) {
        perror("Error changing to level1 directory");
        exit(1);
    }
    if (mkdir("level2a", 0777) == -1) {
        perror("Error creating level2a directory");
        exit(1);
    }
    if (mkdir("level2b", 0777) == -1) {
        perror("Error creating level2b directory");
        exit(1);
    }
    FILE *file1 = fopen("file1.txt", "w");
    if (file1 == NULL) {
        perror("Error creating file1.txt");
        exit(1);
    }
    fprintf(file1, "This is file1.txt in level2a\n");
    fclose(file1);
    FILE *file2 = fopen("file2.txt", "w");
    if (file2 == NULL) {
        perror("Error creating file2.txt");
        exit(1);
    }
    fprintf(file2, "This is file2.txt in level2b\n");
    fclose(file2)
    printf("Contents of level1 directory:\n");
    system("ls");
    if (chdir("..") == -1) {
        perror("Error changing to parent directory");
        exit(1);
    }
    return 0;
}