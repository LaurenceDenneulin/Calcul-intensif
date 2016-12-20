#include"Calcul.h"

int main()
{
    // Déclaration des constante

    // Il faudra faire en parallèle :
    // le SeedRandim[1234]
    //printf ("First number: %d\n", rand()%100);
    srand (time(NULL));
    //printf ("Random number: %d\n", rand()%100);
    srand (1234);
    int r=rand() ;
    //printf ("Again the first number: %d\n", rand()%100);
    std::cout <<" r vaut :"<< r << std::endl;

    double S [2][2];
    S[0][0]=s1*s1;
    S[0][1]=r*s1*s2;
    S[1][0]=r*s1*s2;
    S[1][1]=s2*s2;

    std::cout << " S vaut :" << S<< std::endl;



}
