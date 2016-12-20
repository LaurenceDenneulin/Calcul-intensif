#include"Calcul.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <random>

int main()
{

    std::mt19937 gen(1234);
    std::cout<<gen()<<std::endl;
    std::normal_distribution<double> nd(0.0,1.0);
    std::cout<<gen()<<std::endl;
    double resultat = 0.001*nd(gen);
    std::cout<<"Le résultat est : "<<resultat<< std::endl;
    return 0;
}
