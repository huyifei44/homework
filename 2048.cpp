#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<windows.h>
using namespace std;
int i = 0, j = 0, k = 0;
bool is_full(int ar[][4]) {
	bool jud = true;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (ar[i][j] == 0) {
				jud = false;
				break;
			}
		}
	}
	return jud;
}
void Random(int ar[][4]) {
	if (!is_full(ar)) {
		do {
			i = rand() % 4;
			j = rand() % 4;
		} while (ar[i][j] != 0);
		ar[i][j] = 2;
	}
	
}
bool is_fail(int ar[][4]) {
	bool jud = true;
	if (!is_full(ar)) {
		jud = false;
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				if (ar[i][j] == ar[i + 1][j]) {
					jud = false;
					break;
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				if (ar[i][j] == ar[i][j + 1]) {
					jud = false;
					break;
				}
			}
		}
	}
	return jud;
}
bool judge(int a) {
	if (a == 0)return true;
	else {
		int pow = 1;
		while (pow<a) {
			pow = pow * 2;
		}
		if (pow == a)return true;
		else return false;
	}
}
void add(int & br1, int & br2) {
	if (judge(br1 + br2)) {

		br2 = br2 + br1;
		br1 = 0;
	}
}
void up(int ar1[4][4]) {
	for (i = 0; i<4; i++) {
		for (k = 0; k<3; k++) {
			for (j =k+1 ; j>0; j--)
			{
				add(ar1[j][i], ar1[j-1][i]);
			}
		}
	}
}
void down(int ar1[4][4]) {
	for (i = 0; i<4; i++) {
		for (int k = 0; k<3; k++)
		{
			for (j = 2-k; j<3; j++)
			{
				add(ar1[j][i], ar1[j+1][i]);
			}
		}
	}
}
void left(int ar1[4][4]) {
	for (i = 0; i<4; i++) {
		for (k = 0; k < 3;k++) {
			for (j = k; j >=0; j--) {
				add(ar1[i][j + 1], ar1[i][j]);
			}
		}
	}
}
void right(int ar1[4][4]) {
	for (i = 0; i<4; i++) {
		for (k = 0; k < 3;k++) {
			for (j = 2-k; j <3; j++) {
				add(ar1[i][j], ar1[i][j+1]);
			}
		}
	}
}
int findmax(int ar1[4][4]) {
	int max=2;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (ar1[i][j] > max)max = ar1[i][j];
		}
	}
	return max;
}
void show(int at[4][4]) {
	for (i = 0; i < 4; i++) {
		cout << at[0][i] << '\t';
	}
	cout << '\t' << '\t' << "the greatest level is" << findmax(at);
	cout << endl;
	for (i = 1; i<4; i++)
	{
		for (j = 0; j<4; j++) {
			cout << at[i][j] << '\t';
		}
		cout << endl;
	}
}
void contorl(int att[4][4]) {
	char con = 'q';
	do {
		cin >> con;
	} while (con != 'w'&&con != 'a'&&con != 's'&&con != 'd');
	switch (con) {
	case 'w':up(att); break;
	case 's':down(att); break;
	case 'a':left(att); break;
	case 'd':right(att); break;
	}
}
void restart(int ar[][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			ar[i][j] = 0;
		}
	}
	Random(ar);
	Random(ar);
}
void rancon(int ar[][4]) {
	int k = 0;
	k = rand() % 4;
	switch (k) {
	case 0:up(ar);  break;
	case 1:down(ar); break;
	case 2:left(ar);  break;
	case 3:right(ar);break;
	}
}
int main() {
	srand((unsigned)time(NULL));
	int arr[4][4] = { 0 };
	Random(arr);
	Random(arr);
	show(arr);
	char c = 't';
	int count64 = 0;
	int count128 = 0;
	int count256 = 0;
	int count512 = 0;
	for (int i = 0; i < 10000000; i++) {
		restart(arr);
		while (!is_fail(arr)) {
			rancon(arr);
			Random(arr);
		 }
		//Sleep(20);
		switch (findmax(arr)) {
		case 64:count64++; break;
		case 128:count128++; break;
		case 256:count256++; break;
		case 512:count512++; break;
		}
	}
	cout << count64 << '\t' << count128 << '\t' << count256 << '\t' << count512 << endl << endl;
	system("pause");
	return 0;
}
