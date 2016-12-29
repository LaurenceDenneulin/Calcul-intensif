#ifndef CALCUL_H
#define CALCUL_H
#include <iostream>
#include <vector>


const double m1 = 10.19357;
const double s1 = 0.3022616;
const double m2 = 11.795;
const double s2 = s1;

class Calcul
{
    public:
        Calcul();
        virtual ~Calcul();
        void Set_Productivity_Gamma(double r);
        void Set_Elasticity();
        void Set_Threshold();
        void Set_tax();
        void Set_tPopt_tCopt();
        void Set_ns();


        double Wtilde(const double g, const double e);

        const int Kmax = 10;
        double tPopt;
        double tCopt;
        double ns;
    protected:
    private:
        double tC;
        double tP;

        double taxmax;
        double tax;
        double gdp;

        std::vector<double> productivity;
        std::vector<double> gamma;
        std::vector<double> elasticity;
        std::vector<double> threshold;

};

#endif // CALCUL_H
