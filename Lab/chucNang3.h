#pragma once
int checkSoNguyen(double n) {
	if (n == (int)n) {
		return 1;
	}
	else {
		return 0;
	}
}
void chucNang3() {
	int n, i = 0, dem = 0, check = 0, viTri = 0;
	double array[100], max = 0, tong = 0, checkN;
	printf("Moi ban nhap so thu cung: ");
	scanf("%lf", &checkN);
	while (checkSoNguyen(checkN) == 0) {
		check++;
		if (check > 3) {
			printf("ban da nhap sai qua 3 lan!\n");
			return;
		}
		printf("So thu cung bat buoc la so nguyen(sai lan %d)! Vui long nhap lai: ", check);
		scanf("%lf", &checkN);
	}
	n = (int)checkN;
	for (i = 0; i < n; i++)
	{
		printf("Moi ban nhap can luong cua thu cung %d: ", i + 1);
		scanf("%lf", &array[i]);
	}

	printf("Bang cung nag cua thu cung la: \n");
	for (i = 0; i < n; i++)
	{
		printf("Thu cung thu %d co can nang la %.2lf\n", i + 1, array[i]);
	}
	for (i = 0; i < n; i++) {
		dem++;
		tong = tong + array[i];
	}
	double canNangTrungBinh = tong / dem;
	printf("can luong trung binh la: %.2lf\n", canNangTrungBinh);
	dem = 0;
	max = array[0];
	for (i = 0; i < n; i++) {
		if (array[i] < max) {
			max = array[i];
			viTri = i;
		}
		if (array[i] < canNangTrungBinh) {
			dem++;
		}
	}
	printf("can nang thap nhat la: %.2lf thuoc ve thu cung thu %d\n", max, viTri + 1);
	printf("So thu cung co can nang duoi can nang trung binh(%.2lf) la: %d\n", canNangTrungBinh, dem);

}