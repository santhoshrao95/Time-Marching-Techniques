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
    float del_t;
    cout << "Enter the time-step size:";
    cin >> del_t ;
    //double x = 1+del_t;
    int n = 20/del_t ;
    double phi[n], t[n];
    phi[0] = 1.0, t[0] = 0.0;
    //ofstream implicitEuler("implicitEu2q2_0_1.txt",ios::trunc);
    //ofstream implicitEuler("implicitEu2q2_0_6.txt",ios::trunc);
    //ofstream implicitEuler("implicitEu2q2_2_1.txt",ios::trunc);
    ofstream implicitEuler("implicitEu2q2_4_1.txt",ios::trunc);
    implicitEuler << t[0] << "," << phi[0] << endl;

    for (int i = 0; i < n; i++)
    {
        t[i+1] = t[i] + del_t;
        //phi[i+1]= phi[i] / x;

        double x = 1.0/(1.0 + (4.0*t[i+1]*del_t*phi[i]));
        //phi[i+1]= (phi[i]*x) - (x*(2*t[i+1]*phi[i]*phi[i])) ;
       phi[i+1]= (phi[i]*x) - (x*(2*t[i+1]*phi[i]*phi[i])*del_t) ;
        implicitEuler << t[i+1] << "," << phi[i+1] << endl;
        //phi[i+1]= phi[i] - fun2(phi[i+1], t[i+1])*del_t;
    }

    implicitEuler.close();
    

    return 0; 

}