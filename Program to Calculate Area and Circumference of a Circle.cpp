#include <stdio.h>

int main() {

int r, lingkaran;
float pi, luas, keliling;

printf("Pilih (1:Find the Area of ​​a Circle 2:Calculating the Circumference of a Circle)");
	scanf("%d", &lingkaran);

	switch (lingkaran)
	{
	    case 1:
		printf("Enter the radius of the circle:");
		scanf("%d", &r);
		pi = 3.14;
		luas = pi * (r * r);
		printf("Circle area:%f \n", luas);
		break;

        case 2:
		printf("Enter the radius of the circle:");
		scanf("%d", &r);
		pi = 3.14;
		keliling = 2 * pi * r;
		printf("Circumference:%f \n", keliling);
		break;}

	printf("Program Finish");
	return 0;
}
