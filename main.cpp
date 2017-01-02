#include "Calcul.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    double Sifters;
    int i = 0;
    #pragma omp parallel private(i)
    {
        #pragma omp for
        for (i=0;i<=20;i++)
        {
            double r=(i-10)/10.f;
            Calcul* c= new Calcul();
            c->Set_Productivity_Gamma(r);
            c->Set_Elasticity();
            c->Set_tPopt_tCopt();
            Sifters=((c->Kmax-c->ns)/c->Kmax)*100;
            #pragma omp critical
            std::cout<<"On thread "<<omp_get_thread_num()<<" : r="<<r<<" Optimum : tP="<<c->tPopt<<"; tC="<<c->tCopt<<"; Sifters="<<Sifters<<"%."<<std::endl;
            delete c;
        }
    }
}
