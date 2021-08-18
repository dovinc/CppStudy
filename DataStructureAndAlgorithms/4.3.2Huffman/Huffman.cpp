#include <malloc.h>
#define MAXBIT 10
#define MAXVALUE 1000
/*
* 定义节点结构
*/
typedef struct HNode {
	int weight;
	int parent, lchild, rchild;

} HNode;

/*
* 定义Huffman编码结构
*/
typedef struct HCode {
	int bit[MAXBIT];
	int start;
} HCode;


void HuffmanCoding(HNode* HT, HCode* HC, int* w, int n) {
	// n==1 时，直接结束，不用计算Huffman编码
	if (n <= 1) return;
	// Huffman 节点个数
	int m = 2 * n - 1;
	// Huffman树的构造
	HT = (HNode*)malloc(m * sizeof(HNode));
	HNode* p = HT, int i = 1;
	for (; i < n; ++i, ++p, ++w) {// 叶子节点
		p->weight = *w; p->lchild = -1; p->rchild = -1; p->parent = -1;
	}
	for (; i < m; ++i, ++p) { // 分支节点
		p->weight = 0; p->lchild = -1; p->rchild = -1; p->parent = -1;
	}
	for (i = n; i < m; ++i) { // 寻找根节点权值最小m1和次小m2的两棵树
		int m1, m2; m1 = m2 = MAXVALUE;// 初始化为最大值
		int x1, x2; x1 = x2 = 0; //子树根节点在数组结构中的下标地址
		for (int j = 0; j < i; j++) {
			if (HT[j].parent == -1 && HT[j].weight < m1) {
				m2 = m1; x2 = x1; m1 = HT[j].weight; x1 = j;
			}
			else if (HT[j].parent == -1 && HT[j].weight < m2) {
				m2 = HT[j].weight; x2 = j;
			}
			// 合并成一棵新的子树
			HT[x1].parent = i; HT[x2].parent = i;
			HT[i].lchild = x1; HT[i].rchild = x2;
			HT[i].weight = m1 + m2;
		}
	}

	// 字符编码
	HC = (HCode*)malloc(n * sizeof(HCode));
	for (int i = 0; i < n; i++) {
		int start = n - 1;
		for (int c = i, f = HT[i].parent; f != -1; c = f, f = HT[f].parent) {
			if (HT[f].lchild = c) HC[i].bit[start--] = 0;
			else HC[i].bit[start--] = 1;
		}
		HC[i].start = start + 1;// 记录编码的起始位置
	}

}

int main() {

}