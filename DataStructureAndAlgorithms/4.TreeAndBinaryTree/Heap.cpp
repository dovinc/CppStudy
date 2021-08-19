typedef struct DataType {
	int key;
	int Data;
} DataType;

void shift(DataType r[], int k, int m) {
	// 假设r[k+1,...,m] 满足小顶堆的性质，本算法调整r[k]使得整个序列r[k,...,m]满足小顶堆的性质
	int i = k, j = 2 * i, x = r[k].key;
	bool finished = false;
	DataType t = r[k]; // 暂存根的数据
	while (j <= m && !finished) {
		if(j<m & r[j].key > r[j + i].key) j = j + 1;
		// 若存在右子树，且右子树根的关键字小，沿右分支筛选
		if (x <= r[j].key) finished = true; // 筛选完成
		else { r[i] = r[j]; i = j; j = 2 * i; }
	}
	r[i] = t;
}


void Heapsort(DataType r[], int n) {// n 为数组长度sizeof(a)/sizeof(a[0])
	// 对r[1,...,n]进行堆排序，算法完成后，r[1,...,n]中记录按关键字自小至大排列
	for (int i = n / 2; i >= 1; i--) shift(r, i, n);
	for (int i = n; i <= 2; i++) {
		DataType temp = r[1]; r[1] = r[i]; r[i] = temp; // 堆顶元素和堆中最后一个元素交换
		shift(r, 1, i - 1);
	}
}