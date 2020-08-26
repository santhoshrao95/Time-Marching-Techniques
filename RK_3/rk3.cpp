#include<iostream> 
#include <iomanip> 
//#include<vector>
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
    double b1 = 8.0/15.0, b2 = 0.25, b3 = 5.0/12.0, a1 = 8.0/15.0, a2 = 2.0/3.0, g1= 0.25, g3 = 0.75;
    int n = 10/del_t ;
    double phi[n], t[n];
    phi[0] = 1.0, t[0] = 0.0;
    
    ofstream rk3("rk3Euq2_0_1.txt",ios::trunc);
    //ofstream rk3("rk3Euq2_0_6.txt",ios::trunc);
    //ofstream rk3("rk3Euq2_2_1.txt",ios::trunc);

    rk3 << t[0] << "," << phi[0] << endl;

    for (int i = 0; i < n; i++)
    {
        double k1, k2, k3;
        t[i+1] = t[i] + del_t;
        k1 = del_t*fun2(phi[i], t[i]);
        k2 = del_t*fun2(phi[i]+(b1*k1), t[i]+(a1*del_t));
        k3 = del_t*fun2(phi[i]+(b2*k1)+(b3*k2), t[i]+(a2*del_t));
        phi[i+1] = phi[i] + (g1*k1) + (g3*k3);
        rk3 << t[i+1] << "," << phi[i+1] << endl;
        //phi[i+1]= phi[i] - fun2(phi[i+1], t[i+1])*del_t;
    }

    rk3.close();
    

    return 0; 

}