#include<iostream>
using namespace std;

int FUNC(int apple, int panel) {
	//�Ƿ�����
	if (apple == 0 || panel == 0) return -1;
	//ֻ��һ������ʱ��ֻ��һ�ַŷ�
	if (1 == panel) {
		return 1;
	}
	//���Ӵ���һ��ʱ����ƻ�����������Լ�ƻ��С�ڵ������ӵ�����
	else {
		//ƻ������������������
		if (apple > panel) {
			//�޿�����
			int Num = FUNC(apple - panel, panel);
			//�п�����
			for (int i = 1; i < panel; i++) {
				Num += FUNC(apple - panel + i, panel - i);
			}
			return Num;
		}
		//ƻ������������������
		else if (apple == panel) {
			//�޿�����
			int Num = 1;
			//�п�����
			for (int i = 1; i < panel; i++) {
				Num += FUNC(apple - panel + i, panel - i);
			}
			return Num;
		}
		//ƻ������С�ڵ�����������
		else {
			//�����ӵ����֮�� ������panel - apple�������ӣ��������ơ�
			//�� panel - apple������ʱ��ÿ�����ӷ�һ����Num = 1
			int Num = 1;
			for (int i = panel - apple + 1; i < panel; i++) {
				Num += FUNC(apple - panel + i, panel - i);
			}
			return Num;
		}
	}
}
int main() {
	int apple, panel;
	while (cin >> apple >> panel)
	{
		cout << FUNC(apple, panel) << endl;
	}
	
	return 0;
}