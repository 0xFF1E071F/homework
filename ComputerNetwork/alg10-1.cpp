/************************** 
Dijkstra�㷨�����ָ��Դ�㵽ÿ���ڵ�����·���뼰��һ��·�ɱ� 
**************************/

#include <iostream>
#define INF 999999
#define VN 32
using namespace std;

int dist[VN][VN], n;
int length[VN], predecessor[VN], path[VN];
bool mark[VN];
	
void dijkstra(int s, int t) {
	int i, k ,min, tmp;

	for(i = 1; i <= n; i++) {
		length[i] = INF;
		predecessor[i] = -1;
		mark[i] = false;
	}
	length[t] = 0;
	mark[t] = true;
	k = t;
	do {
		for(i = 1; i <= n; i++) {
			if(dist[k][i] != 0 && mark[i] == false) {
				if(length[k] + dist[k][i] < length[i]) {
					predecessor[i] = k;
					length[i] = length[k] + dist[k][i];
				}
			}
		}
		k = 0;
		min = INF;
		for(i = 1; i <= n; i++) {
			if(mark[i] == false && length[i] < min) {
				min = length[i];
				k = i;
			}
		}
		mark[k] = true;
	}while(k != s);
	
	i = 0;
	k = s;
	do {
		path[i++] = k;
		k = predecessor[k];
	} while(k >= 0);
	printf("\n��Դ�㵽%d��", s);
	printf("��һ��վ��Ϊ��");
	printf("%d\n", path[i - 2]);
}

int main() {
	int m, x, y, d, sp, i;
	memset(dist, INF, sizeof(dist));
	cout << "������ͼ�Ľڵ����ͱ�����";
	cin >> n >> m;
	cout << "������ͼ��\n";
	while(m--) {
		cin >> x >> y >> d;
		if(dist[x][y] > d) 
			dist[x][y] = dist[y][x] = d;
	}
	cout << "������Դ�㣺";
	cin >> sp;
	
	for(i = 1; i <= n; i++) {
		if(i != sp) {
			dijkstra(i, sp);
			cout << "���·����Ϊ��" << length[i] << endl;
		}
	}
	return 0;
}
