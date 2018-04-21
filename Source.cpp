#pragma warning(disable:4996)
#include<stdio.h>
#include<conio.h>
#include<wchar.h>
#include<fcntl.h>
#include<io.h>
#include<stdlib.h>
struct sinhvien
{
	wchar_t MSSV[10];
	wchar_t ten[30];
	wchar_t khoa[30];
	int khoahoc;
	wchar_t date[11];
	wchar_t hinhanh[12];
	wchar_t mota[1000];
	wchar_t sothich[10][1000];
	wchar_t email[21];
}; typedef sinhvien sv;
void xacdinhsoluongsv(int &n)
{
	wchar_t str[2000];
	FILE*p = _wfopen(L"danhsach1.csv", L"r,ccs=UTF-16LE");
	if (p == NULL)
	{
		wprintf(L"Không tìm ra file\n");
		return;
	}
	else
	{
		while (!feof(p))
		{
			fgetws(str, 2000, p);
			n++;
		};
	}
	fclose(p);
}
void docso(FILE *p, int &a)
{
	wchar_t ch;
	ch = fgetwc(p);
	if (ch == '"')
	{
		fwscanf(p, L"%d", &a);
		fseek(p, 2L, SEEK_CUR);
	}
	else
	{
		fseek(p, -1L, SEEK_CUR);
		fwscanf(p, L"%d", &a);
		fseek(p, 1L, SEEK_CUR);
	}
}
void docchuoi(FILE*p, wchar_t a[])
{
	int index = 0;
	wchar_t ch = fgetwc(p);
	if (ch == '"')
	{
		ch = fgetwc(p);
		while (1)
		{
			if (ch == '"' || ch == EOF)
			{
				break;
			}
			else
			{
				a[index] = ch;
				index++;
				ch = fgetwc(p);
			}
		}
		a[index] = '\0';
		fgetwc(p);
	}
	else
	{
		while (1)
		{
			if (ch == ',' || ch == '\n' || ch == EOF)
			{
				break;
			}
			else
			{
				a[index] = ch;
				index++;
				ch = fgetwc(p);
			}
		}
		a[index] = '\0';
	}
}
void doc1sinhvien(FILE *p, sv &a)
{
	docchuoi(p, a.MSSV);
	docchuoi(p, a.ten);
	docchuoi(p, a.khoa);
	docso(p,a.khoahoc);
	docchuoi(p, a.date);
	docchuoi(p, a.hinhanh);
	docchuoi(p, a.email);
	docchuoi(p, a.mota);
	docchuoi(p, a.sothich[0]);
	docchuoi(p, a.sothich[1]);
}
void doctatca(sv a[],int &index,int n)
{
	index = 0;
	FILE *p = _wfopen(L"danhsach1.csv", L"r,ccs=UTF-16LE");
	if (p == NULL)
	{
		wprintf(L"Không tìm ra file\n");
		return;
	}
	else
	{
		while (index < n-1)
		{
			doc1sinhvien(p, a[index]);
			index++;
		}
	}
	fclose(p);
}
void xuatmanhinh(sv a[], int index)
{

	for (int i = 0; i < index; i++)
	{
		wprintf(L"MSSV : %ls\n", a[i].MSSV);
		wprintf(L"Họ và tên : %ls\n", a[i].ten);
		wprintf(L"Khoa : %ls\n", a[i].khoa);
		wprintf(L"Khóa : %d\n", a[i].khoahoc);
		wprintf(L"Ngày sinh : %ls\n", a[i].date);
		wprintf(L"Hình ảnh : %ls\n", a[i].hinhanh);
		wprintf(L"Email : %ls\n", a[i].email);
		wprintf(L"Mô tả : %ls\n", a[i].mota);
		wprintf(L"Sở thích: %ls\n", a[i].sothich[0]);
		wprintf(L"Sở thích: %ls\n\n\n", a[i].sothich[1]);
	}
}
void xuat(sv a[], int index)
{
	wchar_t file[20];
	for (int i = 0; i < index; i++)
	{
		wcscpy(file, a[i].MSSV);
		wcscat(file, L".html");
		FILE *p = _wfopen(file, L"w,ccs=UTF-16LE");
		if (p == NULL)
		{
			printf("Khong tim thay tep\n");
		}
		else
		{
			fwprintf(p, L"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
			fwprintf(p, L"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n");
			fwprintf(p, L"	<head>\n");
			fwprintf(p, L"		<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n");
			fwprintf(p, L"		<link rel=\"stylesheet\" type=\"text/css\" href=\"personal.css\" />\n");
			fwprintf(p, L"		<title>HCMUS - %ls </title>\n", a[i].MSSV);
			fwprintf(p, L"	</head>\n");
			fwprintf(p, L"	<body>\n");
			fwprintf(p, L"		<div class=\"Layout_container\">\n");
			fwprintf(p, L"			<!-- Begin Layout Banner Region -->\n");
			fwprintf(p, L"			<div class=\"Layout_Banner\" >\n");
			fwprintf(p, L"				<div><img id=\"logo\" src=\"Images/logo.jpg\" height=\"105\" /></div>\n");
			fwprintf(p, L"				<div class=\"Header_Title\">TRƯỜNG ĐẠI HỌC KHOA HỌC TỰ NHIÊN</div>\n");
			fwprintf(p, L"			</div>\n");
			fwprintf(p, L"			<!-- End Layout Banner Region -->\n");
			fwprintf(p, L"			<!-- Begin Layout MainContents Region -->\n");
			fwprintf(p, L"			<div class=\"Layout_MainContents\">\n");
			fwprintf(p, L"				<!-- Begin Below Banner Region -->\n");
			fwprintf(p, L"				<div class=\"Personal_Main_Information\">\n");
			fwprintf(p, L"					<!-- Begin Thông tin cá nhân của sinh viên ------------------------------------------------------------------------------------------->\n");
			fwprintf(p, L"					<div class=\"Personal_Location\"> \n");
			fwprintf(p, L"						<img src=\"Images/LogoFooter.jpg\" width=\"27\" height=\"33\" />\n");
			fwprintf(p, L"						<span class=\"Personal_FullName\">%ls - %ls</span>\n", a[i].ten, a[i].MSSV);
			fwprintf(p, L"						<div class=\"Personal_Department\">KHOA CÔNG NGHỆ THÔNG TIN</div>\n");
			fwprintf(p, L"						<br />\n");
			fwprintf(p, L"						<div class=\"Personal_Department\">%ls</div>\n", a[i].email);
			fwprintf(p, L"						<br />\n");
			fwprintf(p, L"						<div class=\"Personal_Phone\">\n");
			fwprintf(p, L"						</div>\n");
			fwprintf(p, L"						<br />\n");
			fwprintf(p, L"						<br />\n");
			fwprintf(p, L"					</div>\n");
			fwprintf(p, L"					<!-- End Thông tin cá nhân của sinh viên ------------------------------------------------------------------------------------------->\n");
			fwprintf(p, L"					<div class=\"Personal_HinhcanhanKhung\">\n");
			fwprintf(p, L"						<img src=\"Images/%ls\" class=\"Personal_Hinhcanhan\" />\n", a[i].hinhanh);
			fwprintf(p, L"					</div>\n");
			fwprintf(p, L"				</div>\n");
			fwprintf(p, L"				<!-- End Below Banner Region -->\n");
			fwprintf(p, L"				<!-- Begin MainContents Region -->\n");
			fwprintf(p, L"				<div class=\"MainContain\">\n");
			fwprintf(p, L"\n");
			fwprintf(p, L"					<!-- Begin Top Region -->\n");
			fwprintf(p, L"					<div class=\"MainContain_Top\">\n");
			fwprintf(p, L"\n");
			fwprintf(p, L"						<div class=\"InfoGroup\">Thông tin cá nhân</div>\n");
			fwprintf(p, L"                       <div>\n");
			fwprintf(p, L"                            <ul class=\"TextInList\">\n");
			fwprintf(p, L"                              <li>Họ và tên: %ls </li>\n", a[i].ten);
			fwprintf(p, L"								 <li>MSSV: %ls </li>\n", a[i].MSSV);
			fwprintf(p, L"								 <li>Sinh viên khoa: %ls </li>\n", a[i].khoa);
			fwprintf(p, L"								 <li>Ngày sinh: %ls </li>\n", a[i].date);
			fwprintf(p, L"								 <li>Khóa học: %ld </li>\n", a[i].khoahoc);
			fwprintf(p, L"								 <li>Email: %ls </li>\n", a[i].email);
			fwprintf(p, L"							 </ul>\n");
			fwprintf(p, L"						</div>\n");
			fwprintf(p, L"                       <div class=\"InfoGroup\">Sở thích</div>\n");
			fwprintf(p, L"                       <div>\n");
			fwprintf(p, L"                            <ul class=\"TextInList\">\n");
			fwprintf(p, L"                              <li>%ls</li>\n", a[i].sothich[0]);
			fwprintf(p, L"                              <li>%ls</li>\n", a[i].sothich[1]);
			fwprintf(p, L"							 </ul>\n");
			fwprintf(p, L"						</div>\n");
			fwprintf(p, L"						<div class=\"InfoGroup\">Mô tả</div>\n");
			fwprintf(p, L"						<div class=\"Description\">\n");
			fwprintf(p, L"                            %ls.\n", a[i].mota);
			fwprintf(p, L"						</div>\n");
			fwprintf(p, L"\n");
			fwprintf(p, L"					</div>\n");
			fwprintf(p, L"				</div>\n");
			fwprintf(p, L"			</div>\n");
			fwprintf(p, L"\n");
			fwprintf(p, L"			<!-- Begin Layout Footer -->\n");
			fwprintf(p, L"			<div class=\"Layout_Footer\">\n");
			fwprintf(p, L"				<div class=\"divCopyright\">\n");
			fwprintf(p, L"					<br />\n");
			fwprintf(p, L"					<img src=\"Images/LogoFooter_gray.jpg\" width=\"34\" height=\"41\" /><br />\n");
			fwprintf(p, L"					<br />\n");
			fwprintf(p, L"				@2018</br>\n");
			fwprintf(p, L"				Đồ án giữa kì</br>\n");
			fwprintf(p, L"				Kỹ thuật lâp trình</br>\n");
			fwprintf(p, L"				TH2018/04</br>\n");
			fwprintf(p, L"				1712845 - Nguyễn Ngọc Trung</br>\n");
			fwprintf(p, L"				</div>\n");
			fwprintf(p, L"			</div>\n");
			fwprintf(p, L"			<!-- End Layout Footer -->\n");
			fwprintf(p, L"		</div>\n");
			fwprintf(p, L"	</body>\n");
			fwprintf(p, L"</html>");
			fclose(p);
		}
	}
}
int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	int index;
	int n = 0;
	sv *a;
	xacdinhsoluongsv(n);
	a = (sv*)malloc(n * sizeof(sv));
	doctatca(a, index,n);
	xuatmanhinh(a, index);
	xuat(a, index);
	wprintf(L"Hoàn Thành\n");
	getch();
	free(a);
	return 0;
}