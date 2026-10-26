#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include "ShapeproLib.h"
using namespace std;
const string wrongFileName = "wrong_questions.txt"; // 错题库文件名
int main()
{
    srand((unsigned)time(NULL));
    cout << "========== 简单几何题库==========\n";
    int num = 0;
	cout << "请输入题目数量：";
    cin >> num;
    ShapeproLib lib(num);
	lib.GetWrongLib().loadFromFile(wrongFileName); // 加载错题库
    int choice = 0;
    while (true) {
        cout << "\n请选择功能：\n"
            << "  1. 计算模式：显示每道题的图形信息、面积和周长\n"
            << "  2. 练习模式：输入你的答案，程序自动判分\n"
			<< "  3.查看错题库\n"
			<< "  4.重新练习错题库\n"
            << "  0. 退出\n"
            << "请选择：";
        cin >> choice;
        switch (choice) {
        case 1:
            std::cout << '\n';
            lib.showanswers();
            break;
        case 2:
            lib.testallpro();
            lib.showscore();
            break;
        case 3:
			lib.GetWrongLib().showWrong();
            break;
		case 4:
			lib.GetWrongLib().testWrong();
            break;
        case 0:
			lib.GetWrongLib().saveToFile(wrongFileName); // 保存错题库
            cout << "已退出程序。\n";
            return 0;
        default:
            cout << "无效选项，请重新选择。\n";
            break;
        }
    }
}