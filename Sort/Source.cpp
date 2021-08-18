#include <iostream>
using namespace std;


typedef struct {
	int key;
	float info;
} JD;

void qksort(JD r[], int t, int w) {
	int i, j, k;
	JD x;
	if (t >= w) return;
	i = t; j = w; x = r[i];
	while (i < j) {
		while ((i < j) && (r[j].key >= x.key)) j--; // ������ֵ��������
		if (i < j) { r[i] = r[j]; i++; } // ��������ʱ�������ύ��
		while ((i < j) && (r[j].key <= x.key)) i++; // ������ֵ��������
		if (i < j) { r[i] = r[j]; j--; } // ��������ʱ�������ύ��
	}
	r[i] = x;
	qksort(r, t, j-1);
	qksort(r, j+1, w);
}

int main() {
	JD r[10];
	for (int i = 0; i < 10; i++) {
		r[i].key = 10 - i;
	}
	for (int i = 0; i < 10; i++)
		cout << r[i].key << " ";
	cout << endl;
	qksort(r, 0, 9);
	for (int i = 0; i < 10; i++)
		cout << r[i].key << " ";
	cout << endl;
}