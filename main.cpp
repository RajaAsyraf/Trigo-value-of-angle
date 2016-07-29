/******************************************** 
Course : TCP1101 Programming Fundamentals
Session: Trimester 1, 2013/14
Name: RAJA MOHAMAD ASYRAF BIN RAJA ABDUL RAHMAN
ID  : 1112703432
Lecture Section : TC102 
Tutorial Section: TC203 
Project: 01
Email: raja_asyraf@yahoo.com
Phone: 0177339914
********************************************/

#include <iostream>
using namespace std;

int factorial(int a) //a for any input
{
	int fac = 1; //fac stand for factorial
	int counter = 2;
	while (counter <= a)
	{
		fac = fac * counter;
		counter = counter + 1;
	}
	return fac; //show the result from fac
}

double power(double b, double c) // b is going to be replaced with angle and c replace with term later
{
	double pow = 1.0; //pow stand for power
	int counter = 0;
	while (counter < c) 
	{
		pow = pow * b; //b is the angle
		counter = counter + 1;
	}
	return pow;
}

double sin(double anglerad) //anglerad means Angle in RADIAN
{
	double anglesin; //anglesin is same with angle in radian
	anglesin = anglerad; 
	int maxterms = 11; 
	double sina = 0; //sina is used to differentiate with sin
	int term = 1;
	int negative = 1; //negative used to get plus and minus 
	while(term <= maxterms)
	{
		double powersin; //
		powersin = power(anglesin,term);
		double factorialsin;
		factorialsin = factorial(term);
		sina = sina + ((powersin/factorialsin)*negative);
		negative = negative * -1;
		term = term + 2;
	}
	return sina;
}

double cos(double anglerad)
{
	double anglecos;
	anglecos = anglerad;
	int maxterms = 12;
	double cosa = 1.0;
	int term = 2;
	int negative = -1;
	while(term <= maxterms)
	{
		double powercos;
		powercos = power(anglecos,term);
		double factorialcos;
		factorialcos = factorial(term);
		cosa = cosa + ((powercos/factorialcos)*negative);
		negative = negative * -1;
		term = term + 2;
	}
	return cosa;
}

int main()
{
	double angle, anglerad, angledeg, angleoriginal, angleradoriginal; //angle is the value that user insert
	double pi = 3.1416; //anglerad is angle in RADINA, angledeg is angle in DEGREE, angleoriginal is angle that more than 360 but not minus yet
	char res,res2; //angleradoriginal is angle in RADIAN that has not been minus if it is more than 360
	
	do
	{
		bool valid = true; //bool is used to repeat while action until change to false
		cout << endl;
		cout << "***** Trigonometry Program ********" << endl;
		cout << "Please enter an angle value => ";
		cin >> angle;
		cout << "Is the angle in Degree or Radian?" << endl;
		angleoriginal = angle; 
			
		while(valid)
		{
			cout << "    Type D if it is in Degree" << endl;
			cout << "    Type R if it is in Radian" << endl;
			cout << "Your response => ";
			cin >> res; //res is response
	
			if (res == 'D' || res == 'd') //within degree case 
			{
				if(angle==0)
				{
					cout << " ";
					angleradoriginal = 0; //this is special case on certain condition so that 0 will appear
					anglerad = 0;
				}
				else
				{
					angleradoriginal = angle * (pi/180); //angleradoriginal means angle radian from original angle before minus
					cout << "     " << angleoriginal << " Degree =        " << angleradoriginal << " Radian"; //showing the changes from degree to radian
				}	
				angledeg = angle;
					
				while(angledeg >= 360) //if angle in degree is more than 360, it need to be minus before convert it to trigo
				{
					angledeg = angledeg - 360;
				}
				anglerad = angledeg * (pi/180); //anglerad is the right value so that conversion to trigo can be done
				
				valid = false; //false to proceed with next step
			}
			else if(res == 'R' || res == 'r') //within radian case , no need to convert to radian anymore
			{
				if(angle==0) //angle equal to 0 is special case
				{
					cout << " ";
					angleradoriginal = 0;
					anglerad = 0;
					
				}
				else
				
				angleradoriginal = angle;
				anglerad = angle; 
				
				valid = false;
			}
		
			else	
			{
				cout << "Please insert correct input."<< endl; //if the input is incorrect, program will allow user to try again insert the input 
			}
		}
		
		
		
		
		double sina = sin(anglerad);
		double cosa = cos(anglerad);
		double tan;
		tan = (sina/cosa);
		
		if (angle == 90 || anglerad == pi/2) // this is also special angle 
		{
			cosa = 0; //if angle in 90 degree, cos will become 0
			cout << endl;
			cout << endl;
			cout << "             RESULTS        " << endl;
			cout << "============================" << endl;
			cout << "       x =       " << angleradoriginal << " Radian" << endl;
			cout << "  sin(x) =       " << sina << endl;
			cout << "  cos(x) =       " << cosa << endl;
			cout << "  tan(x) =       infinity" << endl; //tan going to be infinity
			cout << "============================" << endl << endl;
			cout << "Do you want to continue?" << endl;
			cout << "	Type Y to continue" << endl;
			cout << "	Type any other key to stop" << endl;
			cout << "Your response => ";
			cin >> res2;
		}
		else
		{
			
			cout << endl;
			cout << endl;
			cout << "             RESULTS        " << endl;
			cout << "============================" << endl;
			cout << "       x =       " << angleradoriginal << " Radian" << endl;
			cout << "  sin(x) =       " << sina << endl;
			cout << "  cos(x) =       " << cosa << endl;
			cout << "  tan(x) =       " << tan << endl;
			cout << "============================" << endl << endl;
			cout << "Do you want to continue?" << endl;
			cout << "	Type Y to continue" << endl;
			cout << "	Type any other key to stop" << endl;
			cout << "Your response => ";
			cin >> res2;
		}
	}	
		while(res2 == 'Y' || res2 == 'y');
		
		cout << "Thank you, good bye!!" << endl;
	
return 0;
}