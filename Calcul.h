#ifndef CALCUL_H
#define CALCUL_H


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
        void LogMultinormalDefinition();
        double r;
    protected:
    private:
        double taxmax;
        double S [2][2];
        double productivity[Kmax];
        double gamma[Kmax];

};

#endif // CALCUL_H
