#include"Calcul.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  srand(1234);
  Calcul C;
  C.r=0.01*(rand()%100);

  C.Set_Productivity_Gamma();
    std::cout<<C.r<<std::endl;
}
