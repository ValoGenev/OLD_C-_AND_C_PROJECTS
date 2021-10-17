#include <stdio.h>
#include <stdlib.h>

#include <windows.h>
#include <dir.h>

int main (void)
  {
    //char *dir = "papka";
    //CreateDirectory(dir,NULL); // za suzdavane
    //remove ("da.txt"); // za triene
    int main(void)
{
    struct dirent *de;  // Pointer for directory entry

    // opendir() returns a pointer of DIR type.
    DIR *dr = opendir(".");

    if (dr == NULL)  // opendir returns NULL if couldn't open directory
    {
        printf("Could not open current directory" );
        return 0;
    }

    // Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html
    // for readdir()
    while ((de = readdir(dr)) != NULL)
            printf("%s\n", de->d_name);

    closedir(dr);
    return 0;
}



      return 0;
  }
