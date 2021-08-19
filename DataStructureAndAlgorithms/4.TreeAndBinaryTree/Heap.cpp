typedef struct DataType {
	int key;
	int Data;
} DataType;

void shift(DataType r[], int k, int m) {
	// ����r[k+1,...,m] ����С���ѵ����ʣ����㷨����r[k]ʹ����������r[k,...,m]����С���ѵ�����
	int i = k, j = 2 * i, x = r[k].key;
	bool finished = false;
	DataType t = r[k]; // �ݴ��������
	while (j <= m && !finished) {
		if(j<m & r[j].key > r[j + i].key) j = j + 1;
		// �������������������������Ĺؼ���С�����ҷ�֧ɸѡ
		if (x <= r[j].key) finished = true; // ɸѡ���
		else { r[i] = r[j]; i = j; j = 2 * i; }
	}
	r[i] = t;
}


void Heapsort(DataType r[], int n) {// n Ϊ���鳤��sizeof(a)/sizeof(a[0])
	// ��r[1,...,n]���ж������㷨��ɺ�r[1,...,n]�м�¼���ؼ�����С��������
	for (int i = n / 2; i >= 1; i--) shift(r, i, n);
	for (int i = n; i <= 2; i++) {
		DataType temp = r[1]; r[1] = r[i]; r[i] = temp; // �Ѷ�Ԫ�غͶ������һ��Ԫ�ؽ���
		shift(r, 1, i - 1);
	}
}