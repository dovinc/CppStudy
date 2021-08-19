#include <malloc.h>
#define MAXBIT 10
#define MAXVALUE 1000
/*
* ����ڵ�ṹ
*/
typedef struct HNode {
	int weight;
	int parent, lchild, rchild;

} HNode;

/*
* ����Huffman����ṹ
*/
typedef struct HCode {
	int bit[MAXBIT];
	int start;
} HCode;


void HuffmanCoding(HNode* HT, HCode* HC, int* w, int n) {
	// n==1 ʱ��ֱ�ӽ��������ü���Huffman����
	if (n <= 1) return;
	// Huffman �ڵ����
	int m = 2 * n - 1;
	// Huffman���Ĺ���
	HT = (HNode*)malloc(m * sizeof(HNode));
	HNode* p = HT, int i = 1;
	for (; i < n; ++i, ++p, ++w) {// Ҷ�ӽڵ�
		p->weight = *w; p->lchild = -1; p->rchild = -1; p->parent = -1;
	}
	for (; i < m; ++i, ++p) { // ��֧�ڵ�
		p->weight = 0; p->lchild = -1; p->rchild = -1; p->parent = -1;
	}
	for (i = n; i < m; ++i) { // Ѱ�Ҹ��ڵ�Ȩֵ��Сm1�ʹ�Сm2��������
		int m1, m2; m1 = m2 = MAXVALUE;// ��ʼ��Ϊ���ֵ
		int x1, x2; x1 = x2 = 0; //�������ڵ�������ṹ�е��±��ַ
		for (int j = 0; j < i; j++) {
			if (HT[j].parent == -1 && HT[j].weight < m1) {
				m2 = m1; x2 = x1; m1 = HT[j].weight; x1 = j;
			}
			else if (HT[j].parent == -1 && HT[j].weight < m2) {
				m2 = HT[j].weight; x2 = j;
			}
			// �ϲ���һ���µ�����
			HT[x1].parent = i; HT[x2].parent = i;
			HT[i].lchild = x1; HT[i].rchild = x2;
			HT[i].weight = m1 + m2;
		}
	}

	// �ַ�����
	HC = (HCode*)malloc(n * sizeof(HCode));
	for (int i = 0; i < n; i++) {
		int start = n - 1;
		for (int c = i, f = HT[i].parent; f != -1; c = f, f = HT[f].parent) {
			if (HT[f].lchild = c) HC[i].bit[start--] = 0;
			else HC[i].bit[start--] = 1;
		}
		HC[i].start = start + 1;// ��¼�������ʼλ��
	}

}

int main() {

}