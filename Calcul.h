#ifndef CALCUL_H
#define CALCUL_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random.h>
#include <cmath>

const int Kmax = 1000;
const double m1 = 10.19357;
const double s1 = 0.3022616;
const double m2 = 11.795;
const double s2 = s1;

class Calcul
{
    public:
        Calcul();
        virtual ~Calcul();
        void LogMultinormalDefinition(const double mu[2],const double Sigma[2][2]);
    protected:
    private:
    double taxmax;
    double S [2][2];
    double distribution[2][2];

};

#endif // CALCUL_H
