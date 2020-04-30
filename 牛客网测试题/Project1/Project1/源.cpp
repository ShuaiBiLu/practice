#include<iostream>
using namespace std;

int FUNC(int apple, int panel) {
	//非法数据
	if (apple == 0 || panel == 0) return -1;
	//只有一个盘子时，只有一种放法
	if (1 == panel) {
		return 1;
	}
	//盘子大于一个时，分苹果大于盘子以及苹果小于等于盘子的数量
	else {
		//苹果数量大于盘子数量
		if (apple > panel) {
			//无空盘子
			int Num = FUNC(apple - panel, panel);
			//有空盘子
			for (int i = 1; i < panel; i++) {
				Num += FUNC(apple - panel + i, panel - i);
			}
			return Num;
		}
		//苹果数量等于盘子数量
		else if (apple == panel) {
			//无空盘子
			int Num = 1;
			//有空盘子
			for (int i = 1; i < panel; i++) {
				Num += FUNC(apple - panel + i, panel - i);
			}
			return Num;
		}
		//苹果数量小于等于盘子数量
		else {
			//空盘子的情况之和 至少有panel - apple个空盘子，依次类推。
			//有 panel - apple个空盘时，每个盘子放一个，Num = 1
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