#pragma once
void chucNang2() {
	int n, i, tong = 0, check = 1;
	printf("moi ban nhap so(n>3): "); scanf("%d", &n);
	while (n <= 3) {
		if (check >= 3) {
			printf("ban nhap sai qua 3 lan!\n");
			return;
		}
		printf("ban da nhap sai! so nhap phai lon hon 3! Xin vui long nhap lai(sai lan %d): ", check);
		scanf("%d", &n);
		check++;
	}
	for (i = 0; i <= n; i++) {
		tong = tong + i;
	}
	printf("\ntong cac so tu 1 den %d la: %d\n", n, tong);
	if (n % 5 == 0) {
		printf("So %d chia het cho 5\n", n);
	}
	else {
		printf("So %d khong chia het cho 5\n", n);
	}
}