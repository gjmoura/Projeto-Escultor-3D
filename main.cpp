#include <cmath>
#include <iostream>
#include <cstdlib>
#include <string>
#include "sculptor.h"
#include <math.h>

using namespace std;

int main()
{
       Sculptor a(50,50,50);
       a.setColor(0,0,102,1);
       a.putSphere(25,25,25,25);


       a.writeOFF((char*)"arqOFF.off");
       return 0;
}
