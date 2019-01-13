#include <stdio.h>

int main()
{
    int capaBus;
    int nbEleves;
    int anneeEleve;
    int pdsEleve;
    int If3[100];
    int If4[100];
    int suiv3 = 1;
    int suiv4 = 1;
    
    If3[0] = 0;
    If4[0] = 0;
    scanf("%d",&capaBus);
    scanf("%d",&nbEleves);
    for (int i = 0; i < nbEleves; i++)
    {
        scanf("%d %d",&pdsEleve,&anneeEleve);
        if (anneeEleve == 3)
            If3[suiv3++] = pdsEleve;
        else
            If4[suiv4++] = pdsEleve;
        
    }
    
    int tab3[suiv3][capaBus+1];
    for (int i = 1; i <= capaBus; i++) tab3[0][i] = 0;
    for (int i = 0; i < suiv3; i++) tab3[i][0] = 1;
    
    for (int j = 1; j <= capaBus; j++)
    {
        for (int i = 1; i < suiv3; i++)
        {
            if (tab3[i-1][j] || (j-If3[i-1] >= 0 && tab3[i-1][j-If3[i]]))
                tab3[i][j] = 1;
            else tab3[i][j] = 0;
        }
    }
    
    int tab4[suiv4][capaBus+1];
    for (int i = 1; i <= capaBus; i++) tab4[0][i] = 0;
    for (int i = 0; i < suiv4; i++) tab4[i][0] = 1;
        
    for (int j = 1; j <= capaBus; j++)
    {
        for (int i = 1; i < suiv4; i++)
        {
            if (tab4[i-1][j] || (j-If4[i-1] >= 0 && tab4[i-1][j-If4[i]]) )
                tab4[i][j] = 1;
            else tab4[i][j] = 0;
        }
    }
    
    int max3;
    int max4;
    
    for (int i = 0; i <= capaBus; i++)
    {
        if (tab3[suiv3-1][i] == 1) max3=i;
    }
    for (int i = 0; i <= capaBus; i++)
    {
        if (tab4[suiv4-1][i] == 1) max4=i;
    }
    if (max3 == max4)
        printf("3 4\r\n");
    else
    {
        int max = max3 < max4 ? 4 : 3;
        printf("%d\r\n",max);
    }
   
    
    return 0;
}
