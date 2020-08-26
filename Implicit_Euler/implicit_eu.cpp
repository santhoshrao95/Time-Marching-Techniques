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
    double x = 1+del_t;
    int n = 10/del_t ;
    double phi[n], t[n];
    phi[0] = 1, t[0] = 0;
    ofstream implicitEuler("implicitEuq1_0_1.txt",ios::trunc);
    //ofstream implicitEuler("implicitEuq1_0_6.txt",ios::trunc);
    //ofstream implicitEuler("implicitEuq1_2_1.txt",ios::trunc);

    implicitEuler << t[0] << "," << phi[0] << endl;

    for (int i = 0; i < n; i++)
    {
        t[i+1] = t[i] + del_t;
        phi[i+1]= phi[i] / x;
        implicitEuler << t[i+1] << "," << phi[i+1] << endl;
        //phi[i+1]= phi[i] - fun2(phi[i+1], t[i+1])*del_t;
    }

    implicitEuler.close();
    

    return 0; 

}