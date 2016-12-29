#include "Calcul.h"
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <random>
#include <algorithm>

Calcul::Calcul()
{
    taxmax=0;
}

void Calcul::Set_Productivity_Gamma()
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
    productivity.push_back(exp(m1+s1*Y1));
    gamma.push_back(exp(m2+s2*(r*Y1+sqrt(1.0-r*r*Y2))));
    std::cout<<productivity[i]<<" "<<gamma[i]<<std::endl;
  }
    return ;
}

void Calcul::Set_Elasticity()
{
    auto result=std::minmax_element(productivity.begin(), productivity.end());
    double wagemin=productivity[result.first-productivity.begin()];
    double wagemax=productivity[result.second-productivity.begin()];
    std::cout<<wagemin<<" "<<wagemax<<std::endl;
    for (int i=0;i<Kmax;i++)
    {
        elasticity.push_back((0.4/(wagemax-wagemin))*(productivity[i]-wagemin)+0.1);
    }
    return ;
}

double Calcul::Wtilde(double g, double e)
{
    return std::pow((((1+e)*g)/(std::pow(1-tC,1+e)-std::pow(1-tP,1+e))),1/(1+e));
}

void Calcul::Set_Threshold()
{
    for (int i=0;i<Kmax;i++)
    {
        threshold.push_back(Wtilde(gamma[i],elasticity[i]));
        std::cout<<threshold[i]<<std::endl;
    }
    return ;
}

void Calcul::Set_tax()
{
    double sum1=0;
    double sum2=0;
    for (int i=0; i<Kmax;i++)
    {
        if (productivity[i]<=threshold[i])
        {
            sum1=sum1+pow(1-tP,elasticity[i])*pow(productivity[i],1+elasticity[i]);
        }
        else
        {
            sum2=sum2+pow(1-tC,elasticity[i])*pow(productivity[i],1+elasticity[i]);
        }
    }
    tax=tP*sum1+tC*sum2;
    gdp=sum1+sum2;
    return;
}

Calcul::~Calcul()
{
    //dtor
}
