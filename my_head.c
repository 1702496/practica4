#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char arxiu[50];
char buf[3000];
int fd,fd_2,linies,comptador;


int main (){
        printf("Nom del arxiu: ");
        scanf("%s", arxiu);

        fd = open(arxiu,  O_RDONLY);
        if (fd == -1){
                printf("No existeix l'arxiu \n");
                return 1;
        }
        else{
                printf("Nombre de linies a mostrar: ");
                scanf("%d", &linies);

                if (linies <= 0){
                        printf("Nombre de línies incorrecte\n");
                        return 1;
                }
                else{
                        while(read(fd,buf,3000) != 0){
                                for (int i = 0; i<3000;i++){
                                        if(buf[i] == 10){comptador++;}
                                        if (comptador == linies){
                                                buf[i] = '\0';
                                                break;
                                        }
                                }
                        printf("%s \n",buf);
                        break;
                        }
                }

        close(fd);
        }
        return 0;

}
