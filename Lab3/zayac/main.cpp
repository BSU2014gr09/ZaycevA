#include <iostream>
#include <math.h>
using namespace std;
#define PI 3.14159265
struct triangle
{
private:
	float side1;
	float side2;
	float side3;
public:
	void get_param();
	void get_halfperim();
	void get_area();
	void get_angles();
};
void triangle::get_param()
{
	cout << "Enter the first side : "; cin >> side1;
	cout << "Enter 2-nd side : " ; cin >> side2;
	cout << "Enter 3-rd side : " ; cin >> side3;
	cout << "\n";
}
void triangle::get_halfperim()
{
	float p = (side1 + side2 + side3) / 2;
	cout << "Half of perimetr is equals " << p << "\n";
}
void triangle::get_area()
{
	double p = (side1 + side2 + side3) / 2;
	double area = sqrt(p*(p-side1)*(p-side2)*(p-side3));
	printf("Area of this triangle is equals %f \n", area);
	system("pause");
}
void triangle::get_angles()
{
	double ang = acos((pow(side1, 2) - pow(side2, 2) - pow(side3, 2)) / (2 * side1*side2))*180.0/PI;
	printf("One of angles is equals : %f \n", ang);
}
int main()
{
	triangle tr1;
	tr1.get_param();
	tr1.get_angles();
	tr1.get_halfperim();
	tr1.get_area();
	system("pause");
	return 0;
}