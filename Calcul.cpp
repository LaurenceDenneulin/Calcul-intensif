#include "Calcul.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <random>

Calcul::Calcul()
{
    taxmax=0;
}

void Calcul::LogMultinormalDefinition()
{
    std::mt19937 gen;
    gen.seed(1234);
    std::normal_distribution<double> nd(0.0,1.0);

    //On utilise le fait que si x suit une loi log-Normale, Y=log(x) suit une loi normale de même moyenne et matrice de covariance.
    //On utilise ensuite la décomposition de Cholesky pour générer X et Y puis on prend l'exponentielle.
 for (int i=0; i<Kmax; i++)
 {
    double Y1 = nd(gen);
    double Y2 = nd(gen);
    productivity[i]=exp(m1+s1*Y1);
    gamma[i]=exp(m2+s2*(r*Y1+sqrt(1.0-r*r*Y2)));
    std::cout<<productivity[i]<<" "<<gamma[i]<<std::endl;
  }
    return ;
}

Calcul::~Calcul()
{
    //dtor
}
