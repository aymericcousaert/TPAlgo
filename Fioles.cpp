#include <stdio.h>

int main()
{
    int capaciteReservoir;
    int nbFioles;
    int capaciteFiole;
    int typeFiole;
    scanf("%d",&capaciteReservoir);
    scanf("%d",&nbFioles);
    int fioleA[20] = {0};
    int fioleB[20] = {0};
    int suivA = 1;
    int suivB = 1;
    for (int i = 0; i < nbFioles; i++)
    {
        scanf("%d %d",&capaciteFiole,&typeFiole);
        if (typeFiole==1)
            fioleA[suivA++] = capaciteFiole;
        else
            fioleB[suivB++] = capaciteFiole;
    }
    
    int possibiliteA[suivA][capaciteReservoir+1];
    int possibiliteB[suivB][capaciteReservoir+1];
    
    for (int i = 0; i < suivA; i++) possibiliteA[i][0] = 1;
    for (int i = 1; i <= capaciteReservoir; i++) possibiliteA[0][i] = 0;
    
    for (int i = 1; i < suivA; i++)
    {
        for (int j = 1; j <= capaciteReservoir; j++)
        {
            if (possibiliteA[i-1][j] || ((j-fioleA[i] >= 0) && possibiliteA[i-1][j-fioleA[i]]))
                    possibiliteA[i][j] = 1;
            else possibiliteA[i][j] = 0;
        }
    }
    
    for (int i = 0; i < suivB; i++) possibiliteB[i][0] = 1;
    for (int i = 1; i <= capaciteReservoir; i++) possibiliteB[0][i] = 0;
    
    for (int i = 1;i < suivB; i++)
    {
        for (int j = 1;j <= capaciteReservoir; j++)
        {
            if (possibiliteB[i-1][j] || ((j-fioleB[i] >= 0) && possibiliteB[i-1][j-fioleB[i]]))
                possibiliteB[i][j] = 1;
            else possibiliteB[i][j] = 0;
        }
    }
    
    int max = 0;
    for (int k = 0; k <= capaciteReservoir; k++)
    {
        for (int l = 0; l <= capaciteReservoir; l++)
        {
            if (possibiliteA[suivA-1][k] == 1 && possibiliteB[suivB-1][l] == 1 && k+l <= capaciteReservoir)
            {
                int produit = 2*(k < l ? k : l);
                max = produit > max ? produit : max ;
            }
        }
    }
    printf("%d\r\n",max);
    
    // Debug
    /*
    printf("fioles : ");
    for (int i =0; i < suivA; i++)
    {
        printf("%d ", fioleA[i]);
    }
    printf("\r\n");
        for (int i =0; i < suivB; i++)
    {
        printf("%d ", fioleB[i]);
    }
    printf("\r\n");

    for (int i=0; i < suivA; i++) {
        for (int j=0; j <= capaciteReservoir; j++) {
            
            printf("%d ", possibiliteA[i][j]);
        }
        printf("\r\n");
    }
    printf("\r\n");
    for (int i=0; i < suivB; i++) {
        for (int j=0; j <= capaciteReservoir; j++) {
            
            printf("%d ",possibiliteB[i][j]);
        }
        printf("\r\n");
    }
     */
    return 0;
}
