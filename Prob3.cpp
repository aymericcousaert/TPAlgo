#include <stdio.h>


int main()
{
    int taille;
    int nombre;
    int resultat = 0;

    scanf("%d", &taille);
    int tab[taille];
    for (int i=0; i < taille; i++)
    {
        scanf("%d",&nombre);
        tab[i] = nombre;
    }
    
    int liste[taille];
    for (int i = 0; i < taille; i++)
    {
        liste[i]=1;
    }
    
    for (int i = 1; i < taille; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (tab[i]%tab[j] == 0 && liste[j]+1 > liste[i])
            {
                liste[i] = liste[j]+1;
            }
        }
    }
    
    for (int i = 0; i < taille; i++)
    {
        if (resultat < liste[i])
            resultat = liste[i];
    }
    
    printf("%d\r\n",resultat);
    
    return 0;
}
