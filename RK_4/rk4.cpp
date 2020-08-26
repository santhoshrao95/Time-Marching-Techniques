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
    double b1 = 1.0/2.0, t1 = del_t/2;
    int n = 10/del_t ;
    double phi[n], t[n];
    phi[0] = 1, t[0] = 0;
    
    //ofstream rk4("rk4Euq2_0_1.txt",ios::trunc);
    //ofstream rk4("rk4Euq2_0_6.txt",ios::trunc);
    ofstream rk4("rk4Euq2_2_1.txt",ios::trunc);

    rk4 << t[0] << "," << phi[0] << endl;

    for (int i = 0; i < n; i++)
    {
        double k1, k2, k3, k4;
        t[i+1] = t[i] + del_t;
        k1 = del_t*fun2(phi[i], t[i]);
        k2 = del_t*fun2((phi[i]+(b1*k1)), t[i]+t1);
        k3 = del_t*fun2((phi[i]+(b1*k2)), t[i]+t1);
        k4 = del_t*fun2(phi[i]+k3 , t[i]+del_t);
        phi[i+1] = phi[i] + (k1/6.0) + (k2/3.0) + (k3/3.0) + (k4/6.0);
        rk4 << t[i+1] << "," << phi[i+1] << endl;
        //phi[i+1]= phi[i] - fun2(phi[i+1], t[i+1])*del_t;
    }

    rk4.close();
    

    return 0; 

}