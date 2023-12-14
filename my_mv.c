#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char arxiu[50];
char arxiu_nou[50];
char buf[3000];
int fd,fd_2;

int main (){
        printf("Nom del arxiu: ");
        scanf("%s", arxiu);

        fd = open(arxiu,  O_RDONLY);
        if (fd == -1){
                printf("No existeix l'arxiu \n");
                return 1;
        }
        else{
                printf("Nom del nou arxiu: ");
                scanf("%s", arxiu_nou);

                fd_2 = open(arxiu_nou, O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU );
                if (fd_2 == -1){
                        printf("Error en la creació de l'arxiu \n");
                        close(fd);
                        return 1;
                }
                else{

                         while (read(fd, buf, 3000) > 0) {
                                 write(fd_2, buf, 3000);
                        }


                        unlink(arxiu);

                        printf("Arxiu mogut.\n");



                }
        close(fd);
        close(fd_2);
        }
        return 0;

}
