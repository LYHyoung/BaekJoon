#include <iostream>
using namespace std;
void printting(int N);
int c = 0;
void ans(int N) {
	if (N == 0) {
		for (int i = 0; i < c; i++) cout << "____";
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
	}
	else {
		for (int i = 0; i < c; i++) cout << "____";
		cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���. \n";
		for (int i = 0; i < c; i++) cout << "____";
		cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���. \n";
		for (int i = 0; i < c; i++) cout << "____";
		cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\" \n";
		c++;
		int t = N - 1;
		printting(t);
		c--;
	}
}

void printting(int N) {
	for (int i = 0; i < c; i++) cout << "____";
	cout << "\"����Լ��� ������?\" \n";
	ans(N);
	for (int i = 0; i < c; i++) cout << "____";
	cout << "��� �亯�Ͽ���. \n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������. \n";
	printting(N);
	return 0;
}