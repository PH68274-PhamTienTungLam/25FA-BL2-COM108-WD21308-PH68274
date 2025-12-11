#define  _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "chucNang2.h"
#include "chucNang1.h"
#include "chucNang3.h"



int main()
{
	int menu;
	do
	{
		printf("+-----------------------Menu------------------+\n");
		printf("|1. Thong Tin thu cung                        |\n");
		printf("|2. Tinh tong                                 |\n");
		printf("|3. Thong tin cua hang                        |\n");
		printf("|0. Thoat                                     |\n");
		printf("+---------------------------------------------+\n");
		printf("Moi ban chon chuc nang(0,1,2,3): ");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1://done 90%
			system("cls");
			chucNang1();
			break;
		case 2://done 90% 
			system("cls");
			chucNang2();
			break;
		case 3://done 90%
			system("cls");
			chucNang3();
			break;
		case 0:
			printf("\ncam on ban da su dung chuong trinh! chuc ban mot ngay tot lanh <3\n");
			break;
		default:
			system("cls");
			printf("\nban da nhap sai! xin vui long kiem tra lai ( dang quay lai menu trong 1s )\n");
			Sleep(1000);
			system("cls");
			break;
		}
	} while (menu != 0);

}
