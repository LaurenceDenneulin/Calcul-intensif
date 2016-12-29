#ifndef CALCUL_H
#define CALCUL_H
#include <iostream>
#include <vector>


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
        void Set_Productivity_Gamma();
        void Set_Elasticity();
        double Wtilde(double g, double e);
        void Set_Threshold();
        void Set_tax();
        double r;
    protected:
    private:
        double tax;
        double gdp;
        double taxmax;
        double S [2][2];
        double tP=0.75;
        double tC=0.65;
        std::vector<double> productivity;
        std::vector<double> gamma;
        std::vector<double> elasticity;
        std::vector<double> threshold;

};

#endif // CALCUL_H
