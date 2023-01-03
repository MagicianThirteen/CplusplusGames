// 01_FirstGame.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int main()
{
   /* char c;
    cin >> c;
    cout << "Input Character is " << c << endl;
    std::cout << "Hello World!\n";
    return 0;*/

    //场景数据
    const char gStageData[] = "\
    ########\n\
    # .. p #\n\
    # oo   #\n\
    #      #\n\
    ########";
    const int gStageWidth = 8;
    const int gStageHeight = 5;

    enum Object {
        OBJ_SPACE,
        OBJ_WALL,
        OBJ_GOAL,
        OBJ_BLOCK,
        OBJ_BLOCK_ON_GOAL,
        OBJ_MAN,
        OBJ_MAN_ON_GOAL,

        OBJ_UNKNOW,
    };

    //创建状态数组
    Object* state = new Object[gStageWidth * gStageHeight];
    //初始化场景
    initialize(state, gStageWidth, gStageHeight, gStageData);
    //主循环
    while (true) {
        //首先绘制
        draw(state, gStageWidth, gStageHeight);
        //通关检测
        if (checkClear(state, gStageWidth, gStageHeight)) {
            break;
        }
        //获取输入
        cout << "a:left s:right w:up z:down. command?" << endl;//操作说明
        char input;
        cin >> input;
        //更新
        update(state, input, gStageWidth, gStageHeight);
    }
    //胜利时的提示信息
    cout << "Congratulation's you win." << endl;
    //通关(一些数据的处理)
    delete[] state;
    state = 0;//将无用的指针赋值为0

    return 0;
         
}

