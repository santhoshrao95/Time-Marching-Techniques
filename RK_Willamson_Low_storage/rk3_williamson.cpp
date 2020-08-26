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
    double t1 = del_t/3;
    double b1 = -5.0/9.0;
    double t2 = (15.0/16.0)*del_t;
    double t3= (3.0/4.0)*del_t;
    double c1 = -153.0/128.0;
    double t4 = (8.0/15.0)*del_t;
    int n = 10/del_t ;
    double phi[n], t[n];
    phi[0] = 1.0, t[0] = 0.0;
    
    //ofstream rk3Williamson("rk3WilliamsonEuq1_0_1.txt",ios::trunc);
    //ofstream rk3Williamson("rk3WilliamsonEuq1_0_6.txt",ios::trunc);
    ofstream rk3Williamson("rk3WilliamsonEuq2_2_1.txt",ios::trunc);

    rk3Williamson << t[0] << "," << phi[0] << endl;

    for (int i = 0; i < n; i++)
    {
        double k1, phi_star;
        phi_star = phi[i];
        t[i+1] = t[i] + del_t;
        k1 = fun2(phi_star, t[i]);

        phi_star = phi_star + (t1 * k1);
        k1 = (b1*k1) + fun2(phi_star, t[i]+t1);

        phi_star = phi_star + (t2*k1);
        k1 = (c1*k1) + fun2(phi_star, t[i]+t3);

        
        /*k1 = fun2(phi_star, t[i]);

        phi_star = phi_star + (t1 * k1);
        k1 = (b1*k1) + fun2(phi_star, t[i]+t1);

        phi_star = phi_star + (t2*k1);
        k1 = (c1*k1) + fun2(phi_star, t[i]+t3);*/

        phi[i+1] = phi_star + (t4*k1);

        rk3Williamson << t[i+1] << "," << phi[i+1] << endl;
        //phi[i+1]= phi[i] - fun2(phi[i+1], t[i+1])*del_t;
    }

    rk3Williamson.close();
    

    return 0; 

}