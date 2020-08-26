#include<iostream> 
#include <iomanip> 
#include<vector>
#include<fstream>
using namespace std; 

/*double fun1(double phi)
{
    double y = -1*phi;
    return y;
}

double fun2(double phi, double t)
{
    double y = -2*t*phi*phi;
    return y;
}*/

int main()
{
    //double err, tol;
    double del_t;
    cout << "Enter the time-step size:";
    cin >> del_t ;
    //double x = (1-(del_t/2))/(1+(del_t/2));
    int n = 20/del_t ;
    double phi[n], t[n];
    phi[0] = 1.0, t[0] = 0.0;
    //ofstream cnEuler("cnEuq2_0_1.txt",ios::trunc);
    //ofstream cnEuler("cnEuq2_0_6.txt",ios::trunc);
    ofstream cnEuler("cnEuq2_2_1.txt",ios::trunc);

    cnEuler << t[0] << "," << phi[0] << endl;

    for (int i = 0; i < n; i++)
    {
        t[i+1] = t[i] + del_t;
        double x = 1/(1+(2*t[i+1]*del_t*phi[i]));
        //phi[i+1]= phi[i] * x;
        phi[i+1]= (phi[i] * x) - ((t[i]*del_t*phi[i]*phi[i])*x) + ((t[i+1]*del_t*phi[i]*phi[i])*x);
        cnEuler << t[i+1] << "," << phi[i+1] << endl;
        //phi[i+1]= phi[i] - fun2(phi[i+1], t[i+1])*del_t;
    }

    cnEuler.close();
    

    return 0; 

}