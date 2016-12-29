#include "Calcul.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    double Sifters;
    double r;
    #pragma omp for
    for (int  i=0;i<=20;i++)
    {
        r=(i-10)/10.f;
        Calcul* c= new Calcul();
        c->Set_Productivity_Gamma(r);
        c->Set_Elasticity();
        c->Set_tPopt_tCopt();
        Sifters=(c->Kmax-c->ns)/c->Kmax*100;
        std::cout<<"r="<<r<<" Optimum : tP="<<c->tPopt<<"; tC="<<c->tCopt<<"; Sifters="<<Sifters<<"%."<<std::endl;
        delete c;

    }
}
