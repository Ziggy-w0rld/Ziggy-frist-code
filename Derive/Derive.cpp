#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "ShapeproLib.h"

int main()
{
    srand((unsigned)time(NULL));
    std::cout << "========== 简单几何题库==========\n";

    ShapeproLib lib;

    int choice = 0;
    while (true) {
        cout << "\n请选择功能：\n"
            << "  1. 计算模式：显示每道题的图形信息、面积和周长\n"
            << "  2. 练习模式：输入你的答案，程序自动判分\n"
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
        case 0:
            std::cout << "已退出程序。\n";
            return 0;
        default:
            std::cout << "无效选项，请重新选择。\n";
            break;
        }
    }
}