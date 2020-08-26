#include<iostream> 
#include <iomanip> 
#include<vector>
#include<fstream>
using namespace std; 

double fun1(double phi, double t)
{
    double y = -1*phi;
    return y;
}

double fun2(double phi, double t)
{
    double y = -2*t*phi*phi;
    return y;
}

int main()
{
    //double err, tol;
    float del_t;
    cout << "Enter the time-step size:";
    cin >> del_t ;
    int n = 10/del_t ;
    double phi[n], t[n];
    phi[0] = 1, t[0] = 0;
    //ofstream explicitEuler("explicitEuq2_0_1.txt",ios::trunc);
    //ofstream explicitEuler("explicitEuq2_0_6.txt",ios::trunc);
    ofstream explicitEuler("explicitEuq2_2_1.txt",ios::trunc);

    explicitEuler << t[0] << "," << phi[0] << endl;

    for (int i = 0; i < n; i++)
    {
        t[i+1] = t[i] + del_t;
        //phi[i+1]= phi[i] + fun1(phi[i])*del_t;
        phi[i+1]= phi[i] + fun2(phi[i], t[i])*del_t;
        explicitEuler << t[i+1] << "," << phi[i+1] << endl;
    }

    explicitEuler.close();
    

    return 0; 

}