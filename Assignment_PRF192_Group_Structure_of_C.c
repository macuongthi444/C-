#include <stdio.h>
#include <string.h>

//Struct
struct Student {
	char ID[999];
	char name[31];
	char sex[7]; //Max = female (6 character)??
	float PT;
	float As;
	float Ws;
	float PE;
	float FE;
	float result; //Khong thay doi
	char status[12]; //Max = incompleted (11 character)??
} sv;

//Nguyen mau ham
void mainMenu();
int getInt(int min, int max);
float getFloat(float min, float max);
void inputNewList(struct Student sv[999], int n);
void outputStruct(struct Student sv[999], int n);
void insertStruct(struct Student sv[999], int i);
void updateStruct(struct Student sv[999], int n, char updateID[9]);
void findStruct(struct Student sv[999], int n, char findID[9]);
void Intro();
//Chuong trinh chinh
int main() {
	struct Student sv[999];
	int n = 0; //so luong sinh vien mac dinh = 0
	int a; //User selection
	do {
		mainMenu();
		a = getInt(1, 7);
		switch(a) {
			case 1:
				printf("\nBan da chon so mot!");
				printf("\nNhap so luong sinh vien: ");
				n = getInt(1, 999);
				inputNewList(sv, n);
				break;
			case 2:
				printf("\nBan da chon so hai!");
				if (n < 1) printf("\nKhong co sinh vien nao de in ra");
				else outputStruct(sv, n);
				break;
			case 3:
				printf("\nBan da chon so ba!");
				if (n < 1) printf("\nKhong co danh sach nao de them");
				else {
					insertStruct(sv, n);
					n++;
				}
				break;
			case 4:
				printf("\nBan da chon so bon!");
				if (n < 1) printf("\nKhong co sinh vien nao de xoa");
				else {
					printf("\nNhap ID sinh vien ban muon xoa: ");
					char delID[9];
					fflush(stdin);
					gets(delID);
					int i, j = -1;
					for (i = 0; i < n; i++)
						if (strcmp(delID, sv[i].ID) == 0) {
							j = i;
							break;
						}
					if (j == -1) {
						printf("\n");
						printf("------------------------------------\n");
						printf("|     Student Have Not Founded     |\n");
						printf("------------------------------------\n\n");
					} else {
						if (j < n) {
							for (j; j < n; j++) {
								strcpy(sv[j].ID, sv[j + 1].ID);
								strcpy(sv[j].name, sv[j + 1].name);
								strcpy(sv[j].status, sv[j + 1].status);
								strcpy(sv[j].sex, sv[j + 1].sex);
								sv[j].As = sv[j + 1].As;
								sv[j].PT = sv[j + 1].PT;
								sv[j].Ws = sv[j + 1].Ws;
								sv[j].PE = sv[j + 1].PE;
								sv[j].FE = sv[j + 1].FE;
								sv[j].result = sv[j + 1].result;
							}
						}
						printf("\nBan da xoa sinh vien co ID la %s thanh cong!", delID);
						n = n - 1;
					}
				}
				break;
			case 5:
				printf("\nBan da chon so nam!");
				if (n < 1) printf("\nKhong co sinh vien nao de cap nhat thong tin");
				else {
					printf("\nNhap ma so sinh vien ban muon cap nhat thong tin: ");
					char updateID[9];
					fflush(stdin);
					gets(updateID);
					updateStruct(sv, n, updateID);
				}
				break;
			case 6:
				printf("\nBan da chon so sau!");
				if (n < 1) printf("\nKhong co sinh vien nao de tim kiem");
				else {
					printf("\nNhap ID sinh vien ban muon tra cuu thong tin: ");
					char findID[9];
					fflush(stdin);
					gets(findID);
					findStruct(sv, n, findID);
				}
				break;
			case 7:
				printf("\n\nBan da chon so seven!\n");
				printf("------------------------------------\n");
				printf("|           Exit program!          |\n");
				printf("------------------------------------\n\n");
				break;
		}
	} while (a != 7);
	return 0;
}
void Intro(void){
	printf ("\n\t\t\t\t*****************************************************************"); 
	printf ("\n\t\t\t\t*                             GROUP 3                     \t*");
    printf ("\n\t\t\t\t*                    Date       :       30/10/2022        \t*");
    printf ("\n\t\t\t\t*Students Name:   Tran Van Hoang|\tStudents Id:   HE160642\t*");
    printf ("\n\t\t\t\t*Students Name:   Luu Huy Hoang |\tStudents Id:   HE160522\t*");
    printf ("\n\t\t\t\t*Students Name: Nguyen Nhat Minh|\tStudents Id:   HE161060\t*");
    printf ("\n\t\t\t\t*Students Name:   Vuong Van Tuan|\tStudents Id:   HE161238\t*");
    printf ("\n\t\t\t\t*Students Name:  Hoang Tien Viet|\tStudents Id:   HE161001\t*");
    printf ("\n\t\t\t\t*****************************************************************"); 
 }
//Ham con
void mainMenu() {
	printf("\n\n");
	printf("*****************************************************\n");
	printf("*           Chuong trinh quan ly sinh vien          *\n");
	printf("*               [1]. Nhap danh sach                 *\n");
	printf("*               [2]. In danh sach                   *\n");
	printf("*               [3]. Them danh sach                 *\n");
	printf("*               [4]. Xoa danh sach                  *\n");
	printf("*               [5]. Cap nhat sinh vien             *\n");
	printf("*               [6]. Tim Kiem sinh vien             *\n");
	printf("*               [7]. Thoat                          *\n");
	printf("*****************************************************\n");
	printf("Enter a number to process: ");
}

int getInt(int min, int max) {
	int a, b, c = 1;
	char d;
	do {
		a = scanf("%d%c", &b, &d);
		if (a == 0) {
			printf("------------------------------------\n");
			printf("|   Wrong input, please re-enter!  |\n");
			printf("------------------------------------\n\n");
			fflush(stdin);
		} else if (d != '\n') {
			printf("------------------------------------\n");
			printf("|   Wrong input, please re-enter!  |\n");
			printf("------------------------------------\n\n");
			fflush(stdin);
		} else if (b < min || b > max) {
			printf("------------------------------------\n");
			printf("|  Out of Range, please re-enter!  |\n");
			printf("------------------------------------\n\n");
			fflush(stdin);
		} else c = 0;
	} while (c == 1);
	return b;
}

float getFloat(float min, float max) {
	int a, b = 1;
	float c;
	do {
		a = scanf("%f", &c);
		if (a == 0) {
			printf("------------------------------------\n");
			printf("|   Wrong input, please re-enter!  |\n");
			printf("------------------------------------\n\n");
			fflush(stdin);
		} else if (c < min || c > max) {
			printf("------------------------------------\n");
			printf("|  Out of Range, please re-enter!  |\n");
			printf("------------------------------------\n\n");
			fflush(stdin);
		} else b = 0;
	} while (b == 1);
	return c;
}

void inputNewList(struct Student sv[999], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("\nNhap sinh vien [%d/%d]", i + 1, n);
		printf("\nNhap ma so sinh vien: ");
		fflush(stdin);
		gets(sv[i].ID);
		printf("\nNhap ten sinh vien: ");
		fflush(stdin);
		gets(sv[i].name);
		printf("\nNhap gioi tinh: ");
		fflush(stdin);
		gets(sv[i].sex);
		printf("\nNhap diem assignment: ");
		fflush(stdin);
		sv[i].As = getFloat(0.0, 10.0);
		printf("\nNhap diem progress test: ");
		fflush(stdin);
		sv[i].PT = getFloat(0.0, 10.0);
		printf("\nNhap diem workshop: ");
		fflush(stdin);
		sv[i].Ws = getFloat(0.0, 10.0);
		printf("\nNhap Pratical Exam: ");
		fflush(stdin);
		sv[i].PE = getFloat(0.0, 10.0);
		printf("\nNhap Final Exam: ");
		fflush(stdin);
		sv[i].FE = getFloat(0.0, 10.0);
		sv[i].result = (sv[i].PT + sv[i].As + sv[i].Ws) * 0.1
		               + sv[i].PE * 0.4 + sv[i].FE * 0.3;
		if (sv[i].PT <= 0 || sv[i].As <= 0 || sv[i].Ws <= 0
		        || sv[i].PE <= 0 || sv[i].FE < 4 || sv[i].result < 5)
			strcpy(sv[i].status, "Incompleted");
		else strcpy(sv[i].status, "Completed");
	}
}

void outputStruct(struct Student sv[999], int n) {
	printf("\n------------+---------------------------------+--------+------THONG TIN SINH VIEN---+----------+----------------+-----------+--------+-------------+");
	printf("\n Student ID |            Full Name            | Gender | Assignment | Progress Test | Workshop | Practical Exam | Final Exam| Result |    Status   |");
	printf("\n------------+---------------------------------+--------+------------+---------------+----------+----------------+-----------+--------+-------------+");
	int i;
	for(i = 0; i < n; i++) printf("\n   %8s | %31s | %6s |    %.2f    |     %.2f      |   %.2f   |      %.2f      |    %.2f   |  %.2f  | %11s |", sv[i].ID, sv[i].name, sv[i].sex, sv[i].As, sv[i].PT, sv[i].Ws, sv[i].PE, sv[i].FE, sv[i].result, sv[i].status);
	printf("\n------------+---------------------------------+--------+------------+---------------+----------+----------------+-----------+--------+-------------+");
}

void insertStruct(struct Student sv[999], int i) {
	printf("\nNhap ma so sinh vien: ");
	fflush(stdin);
	gets(sv[i].ID);
	printf("\nNhap ten sinh vien: ");
	fflush(stdin);
	gets(sv[i].name);
	printf("\nNhap gioi tinh: ");
	fflush(stdin);
	gets(sv[i].sex);
	printf("\nNhap diem assignment: ");
	fflush(stdin);
	sv[i].As = getFloat(-0.0, 10.0);
	printf("\nNhap diem progress test: ");
	fflush(stdin);
	sv[i].PT = getFloat(-0.0, 10.0);
	printf("\nNhap diem workshop: ");
	fflush(stdin);
	sv[i].Ws = getFloat(-0.0, 10.0);
	printf("\nNhap Pratical Exam: ");
	fflush(stdin);
	sv[i].PE = getFloat(-0.0, 10.0);
	printf("\nNhap Final Exam: ");
	fflush(stdin);
	sv[i].FE = getFloat(-0.0, 10.0);
	sv[i].result = (sv[i].PT + sv[i].As + sv[i].Ws) * 0.1
	               + sv[i].PE * 0.4 + sv[i].FE * 0.3;
	if (sv[i].PT <= 0 || sv[i].As <= 0 || sv[i].Ws <= 0
	        || sv[i].PE <= 0 || sv[i].FE < 4 || sv[i].result < 5)
		strcpy(sv[i].status, "Incompleted");
	else strcpy(sv[i].status, "Completed");
}

void updateStruct(struct Student sv[999], int n, char updateID[9]) {
	int i = -1, j;
	for (j = 0; j < n; j++) {
		if (strcmp(updateID, sv[j].ID) == 0) {
			i = j;
			break;
		}
	}
	if (i == -1) {
		printf("\n");
		printf("------------------------------------\n");
		printf("|     Student Have Not Founded     |\n");
		printf("------------------------------------\n\n");
	} else {
		printf("\nNhap ma so sinh vien: ");
		fflush(stdin);
		gets(sv[i].ID);
		printf("\nNhap ten sinh vien: ");
		fflush(stdin);
		gets(sv[i].name);
		printf("\nNhap gioi tinh: ");
		fflush(stdin);
		gets(sv[i].sex);
		printf("\nNhap diem assignment: ");
		fflush(stdin);
		sv[i].As = getFloat(-0.0, 10.0);
		printf("\nNhap diem progress test: ");
		fflush(stdin);
		sv[i].PT = getFloat(-0.0, 10.0);
		printf("\nNhap diem workshop: ");
		fflush(stdin);
		sv[i].Ws = getFloat(-0.0, 10.0);
		printf("\nNhap Pratical Exam: ");
		fflush(stdin);
		sv[i].PE = getFloat(-0.0, 10.0);
		printf("\nNhap Final Exam: ");
		fflush(stdin);
		sv[i].FE = getFloat(-0.0, 10.0);
		sv[i].result = (sv[i].PT + sv[i].As + sv[i].Ws) * 0.1
		               + sv[i].PE * 0.4 + sv[i].FE * 0.3;
		if (sv[i].PT <= 0 || sv[i].As <= 0 || sv[i].Ws <= 0
		        || sv[i].PE <= 0 || sv[i].FE < 4 || sv[i].result < 5)
			strcpy(sv[i].status, "Incompleted");
		else strcpy(sv[i].status, "Completed");
	}
}

void findStruct(struct Student sv[999], int n, char findID[9]) {
	int i = -1, j;
	for (j = 0; j < n; j++) {
		if (strcmp(findID, sv[j].ID) == 0) {
			i = j;
			break;
		}
	}
	if (i == -1) {
		printf("\n");
		printf("------------------------------------\n");
		printf("|     Student Have Not Founded     |\n");
		printf("------------------------------------\n\n");
	} else {
		printf("\n------------+---------------------------------+--------+------THONG TIN SINH VIEN---+----------+----------------+-----------+--------+-------------+");
		printf("\n Student ID |            Full Name            | Gender | Assignment | Progress Test | Workshop | Practical Exam | Final Exam| Result |    Status   |");
		printf("\n------------+---------------------------------+--------+------------+---------------+----------+----------------+-----------+--------+-------------+");
		printf("\n   %8s | %31s | %6s |    %.2f    |     %.2f      |   %.2f   |      %.2f      |    %.2f   |  %.2f  | %11s |", sv[i].ID, sv[i].name, sv[i].sex, sv[i].As, sv[i].PT, sv[i].Ws, sv[i].PE, sv[i].FE, sv[i].result, sv[i].status);
		printf("\n------------+---------------------------------+--------+------------+---------------+----------+----------------+-----------+--------+-------------+");
	}
}
