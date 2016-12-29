#include "Calcul.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    double Sifters;
    for (double r=-1.0;r<=1;r=r+0.1)
    {
        Calcul* c= new Calcul();
        c->Set_Productivity_Gamma(r);
        c->Set_Elasticity();
        c->Set_tPopt_tCopt();
        Sifters=(c->Kmax-c->ns)/c->Kmax*100;
        std::cout<<"r="<<r<<" Optimum : tP="<<c->tPopt<<"; tC="<<c->tCopt<<"; Sifters="<<Sifters<<"%."<<std::endl;
        delete c;

    }
}
