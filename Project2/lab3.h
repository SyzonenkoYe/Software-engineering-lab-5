#include <iostream>
#include <fstream>
#include <locale>
#include <math.h>
using namespace std;

//If user enter incorrect value, for example, character, then program should generate exception.
void checkValidInput()
{
    if (cin.fail())
    {
        throw "Incorrect input";
    }
}

//If user enter incorrect value for from, step or n; for example, the value of n is less than 3, then program should generate exception.
void checkValidParams(double from, double to, double step, int n)
{
    if (from >= to || step <= 0 || n < 3)
    {
        throw "Input correct data";
    }
}

//The function “Calculate” shows how to calculate value on definite range of expression from lab 2
double calculate(double from, double to, double step, double& x, int n)
{
    if (x < 0)
    {
        double y = 0;
        for (int i = 0; i <= n; i++)
        {
            double p = 1;
            for (int j = i; j <= n - 1; j++)
            {
                p *= (pow(i, i) + j);
            }
            y += p;
        }
        return y;
    }
    else
    {
        double y = 0;
        for (int i = 1; i <= n - 2; i++)
        {
            y += (i - x);
        }
        return y;
    }
}

//The “Main” function
int main()
{
    double from, to, step, x, y;
    int n;
    try
    {
        cout << "Enter from = ";
        cin >> from;
        cout << "Enter to = ";
        cin>>to;
        cout << "Enter step = ";
        cin>>step;
        cout << "Enter n = "; 
        cin >> n;
        checkValidInput();
        checkValidParams(from, to, step, n);

        //Write on file "result.txt" from, to, step and n
        ofstream fout("result.txt");
            fout << "from = " << from << endl;
            fout << "to = " << to << endl;
            fout << "step = " << step << endl;
            fout << "n = " << n << endl;
        for (x = from; x <= to; x += step)
        {
            cout << " x = " << x << "; " << "y = " << calculate(from, to, step, x, n) << endl;
            //Write on file "result.txt" the result of every step  
            fout << "x = " << x <<"; ";
            fout << "y = " << calculate(from, to, step, x, n) << " " << endl;
        }
    }
    catch (const char* ex)
    {
        cout << ex << endl;
        return -1;
    }
    catch (...)
    {
        cout << "Unknown error" << endl;
        return -2;
    }

}

