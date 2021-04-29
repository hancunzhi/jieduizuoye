#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cerrno>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;
#define FILE_PATH "C:/Users/Hh/source/repos/jieduizuoye/Demo.txt"  // 文件路径
char Calculation_brackets[4] = { '(' , ' ' , ')' , ' ' }; //括号
char Calculation_operators[4] = { '+' , '-' , '*' , '/' }; //运算符
const int Calculation_operation = 4; //生成随机运算符
const int Calculation_bracket = 2; //生成随机括号
int Calculation_number; //题目数目
int Calculation_max; //最大数
int Calculation_iffile;   //确定是否打印
int Calculation_ifdecimal;  //确定是否有小数
int Calculation_ifbrackets;  //确定是否有括号
FILE* fp;   //文件地址
void showMenu();    //欢迎界面
void showExit();    //退出界面
void Calculation_Output_Screen();//屏幕输出函数
void Calculation_Output_File();  //文本输出函数
void menu();
int main()
{

    showMenu();    //欢迎界面
    menu();
    if (Calculation_iffile == 0)
    {
        Calculation_Output_Screen();
    }
    else
    {
        fp = fopen(FILE_PATH, "at+");
        Calculation_Output_File();
    }
    return 0;

}

void showMenu()
{

    cout << "※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※" << endl;
    cout << "※                                                                                    ※" << endl;
    cout << "※                   欢迎您使用小学四则运算自动生成程序                               ※" << endl;
    cout << "※                                                                                    ※" << endl;

    cout << "※                                                                                    ※" << endl;
    cout << "※                   请您按照步骤来生成四则运算练习题：                               ※" << endl;
    cout << "※                                                                                    ※" << endl;
    cout << "※                   第1步：请设置题目数量 <1-100>                                    ※" << endl;
    cout << "※                   第2步：请设置最大数 <1-1000>                                     ※" << endl;
    cout << "※                   第3步：请选择是否有小数                                          ※" << endl;
    cout << "※                   第4步：请选择是否有括号                                          ※" << endl;
    cout << "※                   第5步：请选择是否打印到文件                                      ※" << endl;
    cout << "※                                                                                    ※" << endl;
    cout << "※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※" << endl;
}
void menu()
{
    cout << "第1步：请设置题目数量 <1-100> ：" << endl;
    cin >> Calculation_number;
    while ((Calculation_number > 100) || (Calculation_number < 1))
    {
        cout << "您设置的题目数目不符合要求(太多/太少)。 < 1 - 100 > " << endl;
        cout << endl;
        cout << "请按确认键重新输入，谢谢！" << endl;
        cin >> Calculation_number;
    }
    cout << "第2步：请设置最大数 <1-1000> ：" << endl;
    cin >> Calculation_max;
    while ((Calculation_max > 1000) || (Calculation_max < 1))
    {
        cout << "您设置的最大数不符合要求(太大/太小)。 < 1 - 1000 > " << endl;
        cout << endl;
        cout << "请按确认键重新输入，谢谢！" << endl;
        cin >> Calculation_max;
    }
    cout << "第3步：请选择是否有小数：(输入 <0> 生成整数 , 输入 <1> 生成小数) " << endl;
    cin >> Calculation_ifdecimal;
    while ((Calculation_ifdecimal != 0) && (Calculation_ifdecimal != 1))
    {
        cout << "您输入的数不符合要求。(输入 <0> 生成整数 , 输入 <1> 生成小数) " << endl;
        cout << endl;
        cout << "请按确认键重新输入！" << endl;
        cin >> Calculation_ifdecimal;
    }
    cout << "第4步：请选择是否有括号：(输入 <0> 无括号 , 输入 <1> 有括号)" << endl;
    cin >> Calculation_ifbrackets;
    while ((Calculation_ifbrackets != 0) && (Calculation_ifbrackets != 1))
    {
        cout << "您输入的数不符合要求。(输入 <0> 无括号 , 输入 <1> 有括号) " << endl;
        cout << endl;
        cout << "请按确认键重新输入！" << endl;
        cin >> Calculation_ifbrackets;
    }
    cout << "第5步：请选择是否打印到文件：(输入 <0> 不打印(屏幕显示) , 输入 <1> 打印)" << endl;
    cin >> Calculation_iffile;
    while ((Calculation_iffile != 0) && (Calculation_iffile != 1))
    {
        cout << "您输入的数不符合要求。(输入 <0> 不打印(屏幕显示) , 输入 <1> 打印) " << endl;
        cout << endl;
        cout << "请按确认键重新输入！" << endl;
        cin >> Calculation_iffile;
    }
}





void Calculation_Output_Screen()
{
    cout << "+----------------以下为*小学四则运算自动生成程序*所生成的四则运算练习题----------------+" << endl;

    for (int i = 0; i < Calculation_number; ++i)
    {
        /*随机生成四个整数*/
        int number1 = rand() % Calculation_max;
        int number2 = rand() % Calculation_max;
        int number3 = rand() % Calculation_max;
        int number4 = rand() % Calculation_max;

        /*随机生成四个小数*/
        float number5 = (float)rand() / Calculation_max;
        float number6 = (float)rand() / Calculation_max;
        float number7 = (float)rand() / Calculation_max;
        float number8 = (float)rand() / Calculation_max;

        /*随机生成三个运算符*/
        int operation1 = rand() % Calculation_operation;
        int operation2 = rand() % Calculation_operation;
        int operation3 = rand() % Calculation_operation;
        char cur_operation1 = Calculation_operators[operation1];
        char cur_operation2 = Calculation_operators[operation2];
        char cur_operation3 = Calculation_operators[operation3];

        /*随机产生括号()*/
        int barcket1 = rand() % Calculation_bracket;
        char cur_barckets1 = Calculation_brackets[barcket1];
        char cur_barckets2 = Calculation_brackets[barcket1 + 2];

        if (Calculation_ifdecimal)
        {
            if (Calculation_ifbrackets)
            {
                cout << "NO." << i << " : " << cur_barckets1 << number5 << " " << cur_operation1 << " " << number6 << cur_barckets2 << " " << cur_operation2 << " " << number7 << " " << cur_operation3 << " " << number8 << "=" << endl;
            }
            else
            {
                cout << "NO." << i << " : " << number5 << " " << cur_operation1 << " " << number6 << " " << cur_operation2 << " " << number7 << " " << cur_operation3 << " " << number8 << "=" << endl;
            }
        }
        else
        {
            if (Calculation_ifbrackets)
            {
                cout << "NO." << i << " : " << cur_barckets1 << number1 << " " << cur_operation1 << " " << number2 << cur_barckets2 << " " << cur_operation2 << " " << number3 << " " << cur_operation3 << " " << number4 << "=" << endl;
            }
            else
            {
                cout << "NO." << i << " : " << number1 << " " << cur_operation1 << " " << number2 << " " << cur_operation2 << " " << number3 << " " << cur_operation3 << " " << number4 << "=" << endl;
            }
        }
    }

    cout << "+--------------------------------------------------------------------------------------+" << endl;

}

void Calculation_Output_File()
{
    cout << Calculation_number << endl;
    fp = fopen(FILE_PATH, "at+");
    if (fp != NULL)
    {
        fprintf(fp, "\n");
        fprintf(fp, "+----------------以下为*小学四则运算自动生成程序*所生成的四则运算练习题----------------+\n");
        time_t now = time(0);

        for (int i = 0; i < Calculation_number; ++i)
        {
            /*随机生成四个整数*/
            int number1 = rand() % Calculation_max;
            int number2 = rand() % Calculation_max;
            int number3 = rand() % Calculation_max;
            int number4 = rand() % Calculation_max;

            /*随机生成四个小数*/
            float number5 = (float)rand() / Calculation_max;
            float number6 = (float)rand() / Calculation_max;
            float number7 = (float)rand() / Calculation_max;
            float number8 = (float)rand() / Calculation_max;

            /*随机生成三个运算符*/
            int operation1 = rand() % Calculation_operation;
            int operation2 = rand() % Calculation_operation;
            int operation3 = rand() % Calculation_operation;
            char cur_operation1 = Calculation_operators[operation1];
            char cur_operation2 = Calculation_operators[operation2];
            char cur_operation3 = Calculation_operators[operation3];

            /*随机产生括号()*/
            int barcket1 = rand() % Calculation_bracket;
            char cur_barckets1 = Calculation_brackets[barcket1];
            char cur_barckets2 = Calculation_brackets[barcket1 + 2];
            if (Calculation_ifdecimal)  //判断是否有小数
            {
                if (Calculation_ifbrackets)   //判断是否有括号
                {
                    fprintf(fp, "NO. %2d : %c %.2f %c %.2f %c %c %.2f %c %.2f = \n", i, cur_barckets1, number5, cur_operation1, number6, cur_barckets2, cur_operation2, number7, cur_operation3, number8);
                }
                else
                {
                    fprintf(fp, "NO. %2d : %.2f %c %.2f %c %.2f %c %.2f = \n", i, number5, cur_operation1, number6, cur_operation2, number7, cur_operation3, number8);
                    //fprint( << "NO." << i << " : "<< number5 << " " << cur_operation1 << " " << number6 << " " << cur_operation2 << " " << number7 << " " << cur_operation3 << " " << number8 << "=" << endl;
                }
            }
            else
            {
                if (Calculation_ifbrackets)
                {
                    fprintf(fp, "NO. %2d : %c %d %c %d %c %c %d %c %d = \n", i, cur_barckets1, number1, cur_operation1, number2, cur_barckets2, cur_operation2, number3, cur_operation3, number4);
                    //fprint( << "NO." << i << " : "<< cur_barckets1 << number1 << " " << cur_operation1 << " " << number2 << cur_barckets2 << " " << cur_operation2 << " " << number3 << " " << cur_operation3 << " " << number4 << "=" << endl;
                }
                else
                {
                    fprintf(fp, "NO. %2d : %d %c %d %c %d %c %d = \n", i, number1, cur_operation1, number2, cur_operation2, number3, cur_operation3, number4);
                    //fprint( << "NO." << i << " : "<< number1 << " " << cur_operation1 << " " << number2 << " " << cur_operation2 << " " << number3 << " " << cur_operation3 << " " << number4 << "=" << endl;
                }
            }
        }
    }
    else
    {
        perror(FILE_PATH);
        exit(-1);
    }
    fprintf(fp, "+--------------------------------------------------------------------------------------+\n");

    fprintf(fp, "\n");
}

void showExit()
{
    cout << "☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★" << endl;
    cout << "★                                                                                    ☆" << endl;
    cout << "☆       恭喜您，四则运算练习题已经成功生成！                                         ★" << endl;
    cout << "★                                                                                    ☆" << endl;
    cout << "☆       谢谢您的使用，欢迎您下次再来！                                               ★" << endl;
    cout << "★                                                                                    ☆" << endl;
    cout << "☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★" << endl;
    cout << "请按确认键退出！" << endl;
}
