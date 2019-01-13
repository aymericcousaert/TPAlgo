#include <stdio.h>

int main() {
    int capaSac;
    int pdsObjet;
    int objets[100];
    int nbObjets = 1;
    
    objets[0] = 0;
    scanf("%d", &capaSac);
    scanf("%d", &pdsObjet);
    while (pdsObjet != -1)
    {
        objets[nbObjets]=pdsObjet;
        nbObjets++;
        scanf("%d",&pdsObjet);
    }
    
    int sol[nbObjets][capaSac+1];
    for (int i = 1; i <= capaSac; i++) sol[0][i] = 0;
    for (int i = 0; i < nbObjets; i++) sol[i][0] = 1;
    
    for (int i = 1; i < nbObjets; i++)
    {
        for (int j = 1; j <= capaSac; j++)
        {
            if (sol[i-1][j] == 1 || ((j-objets[i]) >= 0 && sol[i-1][j-objets[i]] == 1))
                sol[i][j]=1;
            else sol[i][j]=0;
        }
    }
    
    if (sol[nbObjets-1][capaSac] == 1)
        printf("OUI\r\n");
                
    else printf("NON\r\n");
    
    
    
    /*for (int i=0;i<nbObjets;i++) {
        for (int j=0; j<=capaSac; j++) {
            
            printf("%d ",sol[i][j]);
        }
        printf("\r\n");
    }*/
    
    return 0;
}
