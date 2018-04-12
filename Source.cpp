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
	wchar_t sothich[1000];
	wchar_t email[21];
}; typedef sinhvien sv;
void Doc1sinhvien(sv a[], int &index)
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	index = 0;
	wchar_t **b = (wchar_t**)malloc(50 * sizeof(wchar_t*));
	FILE *p = _wfopen(L"danhsach1.csv", L"r,ccs=UTF-16LE");
	if (p == NULL)
	{
		printf("Khong mo duoc tep");
	}
	else
	{
		while (!feof(p))
		{
			*(b + index) = (wchar_t*)malloc(5 * sizeof(wchar_t));
			fwscanf(p, L"%[^,],", &a[index].MSSV);
			fwscanf(p, L"%[^,],%[^,],", &a[index].ten, &a[index].khoa);
			fwscanf(p, L"%[^,],", *(b + index));
			a[index].khoahoc = _wtoi(b[index]);
			fwscanf(p, L"%[^,],", &a[index].date);
			fwscanf(p, L"%[^,],", &a[index].hinhanh);
			fwscanf(p, L"%[^,],", &a[index].email);
			fwscanf(p, L"%[^,],%[^\n]\n", &a[index].mota, &a[index].sothich);
			index++;
		}
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
			fwprintf(p, L"                              <li>%ls</li>\n", a[i].sothich);
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
	sv a[50];
	int index;
	Doc1sinhvien(a, index);
	xuat(a, index);
	wprintf(L"Hoàn Thành\n");
	getch();
	return 0;
}