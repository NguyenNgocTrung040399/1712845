#pragma warning(disable:4996)
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct sinhvien
{
	char MSSV[1];
	char Hoten[30];
	char Khoa[30];
	char khoa[4];
	char ngaysinh[10];
	char hinhanh[12];
	char mota[1000];
	char sothich[1000];
}; typedef sinhvien SV;
void demsoluongsv(int &n)  // Đếm số lượng sinh viên
{
	FILE *p = fopen("Doan.csv", "rt");
	if (p == NULL)
	{
		printf("Khong mo duoc tep\n");
	}
	else
	{
		while (!feof(p))
		{
			char str[255];
			fgets(str, 255, p);
			n++;
		}
	}
	printf("%d", n);
	fclose(p);
}
// Đọc thông tin 1 sinh viên
void doc(SV &a)
{
	FILE *p = fopen("Doan.csv", "rt");
	if (p == NULL)
	{
		printf("Khong mo duoc tep");
	}
	else
	{

		fscanf(p, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", &a.MSSV, &a.Hoten, &a.Khoa, &a.khoa, &a.ngaysinh, &a.hinhanh, &a.mota, &a.sothich);
	}
	fclose(p);
}
// Xuất thông tin 1 sinh viên 
void xuat(SV a)
{
	FILE *p = fopen("output.txt", "wt");
	if (p == NULL)
	{
		printf("Khong tim thay tep\n");
	}
	else
	{

		fprintf(p, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", a.MSSV, a.Hoten, a.Khoa, a.khoa, a.ngaysinh, a.hinhanh, a.mota, a.sothich);
	}
	fclose(p);
}
int main()
{
	int n = 0;
	char str[255];
	demsoluongsv(n);
	SV a;
	doc(a);
	xuat(a);
	getch();
	return 0;
}