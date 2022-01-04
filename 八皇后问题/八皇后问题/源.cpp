#include<iostream>
//#include<bits/stdc++.h>
using namespace std;
int Max = 0; // ������� 
int(*p)[9] = new int[9][9]; // ��ż��� 
int(*check)[17] = new int[3][17]; // ����к������Խ��ߵ�ʹ����� 
int* tmp = new int[10]; //��ǻʺ��λ��Ϊ(i, tmp[i]) 
void DFS(int i) {
	if (i > 8) {
		int x = 0;
		for (int j = 1; j <= 8; j++) {
			x += p[j][tmp[j]];
		}
		if (x > Max) Max = x;
	}
	for (int j = 1; j <= 8; j++) {
		if (check[0][j] != 1 && check[1][i + j] != 1 && check[2][i - j + 8] != 1) {
			tmp[i] = j;
			// �߹���·�����Ϊ 1
			check[0][j] = check[1][i + j] = check[2][i - j + 8] = 1;
			DFS(i + 1);
			// ������һ��״̬ 
			check[0][j] = check[1][i + j] = check[2][i - j + 8] = 0;
		}
	}
}
int main() {
	int k;
	cin >> k;
	while (k--) {
		// ��ʼ�� 
		Max = 0;
		memset(tmp, 0, 10);
		for (int i = 1; i <= 8; i++) {
			for (int j = 1; j <= 8; j++) {
				cin >> p[i][j];
			}
			if (i < 4) memset(check[i - 1], 0, 17);
		}
		// ���� 
		DFS(1);
		cout << Max << endl;
	}
	return 0;
}
