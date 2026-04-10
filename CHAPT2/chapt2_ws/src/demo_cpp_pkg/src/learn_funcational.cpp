#include <iostream>
#include <functional>

// ============================================================
// 准备工作：定义一个简单的类
// ============================================================
class Calculator
{
public:
    // 普通成员函数（非静态）
    // 特点：调用时必须有一个 Calculator 对象，因为内部隐含了 this 指针
    int multiply(int a, int b)
    {
        return a * b;
    }

    // 静态成员函数
    // 特点：不属于任何对象，没有 this 指针，和普通全局函数几乎一样
    static int subtract(int a, int b)
    {
        return a - b;
    }
};

int main()
{
    Calculator calc; // 创建一个 Calculator 对象，后面要用到它

    // ============================================================
    // 【静态成员函数】— 最简单，和全局函数完全一样
    // ============================================================
    //
    // 静态函数没有 this 指针，所以可以像全局函数一样直接赋值
    //
    //   std::function<返回值(参数1, 参数2)> 变量名 = 类名::函数名;
    //
    std::function<int(int, int)> func_static = Calculator::subtract;
    std::function<int(int, int)> func_static1 = Calculator::subtract;

    std::cout << "静态成员函数: 10 - 3 = " << func_static(10, 3) << std::endl;
    std::cout << "静态成员函数: 10 - 3 = " << func_static1(5, 6) << std::endl;
    // 输出: 静态成员函数: 10 - 3 = 7

    // ============================================================
    // 【普通成员函数 — 方法一】用 std::bind 绑定
    // ============================================================
    //
    // 问题：普通成员函数调用时需要知道"是哪个对象在调用"，
    //       也就是说 calc.multiply(6, 7) 中的 calc 不能省略。
    //       但 std::function 存储的是"函数签名"，不带对象信息。
    //       所以需要用 std::bind 把对象和函数"绑定"在一起。
    //
    // std::bind 语法拆解：
    //
    //   std::bind(
    //       &Calculator::multiply,   // ① 取成员函数的地址，格式固定：& + 类名::函数名
    //       &calc,                   // ② 绑定对象的地址，告诉 bind "用 calc 这个对象来调用"
    //       std::placeholders::_1,   // ③ 第1个参数留给调用时传入（占位符）
    //       std::placeholders::_2    // ④ 第2个参数留给调用时传入（占位符）
    //   )
    //
    // 占位符 _1、_2 的意思：
    //   调用 func_member(6, 7) 时，6 填到 _1 的位置，7 填到 _2 的位置
    //
    std::function<int(int, int)> func_bind = std::bind(
        &Calculator::multiply, // ① 函数地址
        &calc,                 // ② 对象地址
        std::placeholders::_1, // ③ 第1个参数占位
        std::placeholders::_2  // ④ 第2个参数占位
    );

    std::function<int(int, int)> func_blind1 = std::bind(
        &Calculator::multiply,
        &calc,
        std::placeholders::_1,
        std::placeholders::_2);

    std::cout << "bind方式: 6 x 7 = " << func_bind(6, 7) << std::endl;
    std::cout << "bind方式: 6 x 7 = " << func_bind(4, 7) << std::endl;
    // 输出: bind方式: 6 x 7 = 42

    // ============================================================
    // 【普通成员函数 — 方法二】用 Lambda 包一层（更推荐，更直观）
    // ============================================================
    //
    // 思路：用 Lambda 捕获 calc 对象，在 Lambda 内部手动调用成员函数
    //       这样 std::function 存的是 Lambda，Lambda 里面帮你处理对象问题
    //
    //   [&calc]         — 捕获 calc 对象的引用（这样 Lambda 内部才能用 calc）
    //   (int a, int b)  — Lambda 接收两个参数
    //   -> int          — 返回值类型是 int
    //   { return calc.multiply(a, b); }  — 直接调用成员函数，清晰明了
    //
    std::function<int(int, int)>
        func_lambda = [&calc](int a, int b) -> int
    {
        return calc.multiply(a, b); // 直接用 calc 调用，一目了然
    };

    std::function<int(int, int)>
        func_lambda1 = [&calc](int a, int b) -> int
    {
        return calc.multiply(a, b);
    };

    std::cout << "lambda方式: 3 x 8 = " << func_lambda(3, 8) << std::endl;

    std::cout << "lambda方式: 3 x 8 = " << func_lambda1(3, 8) << std::endl;
    // 输出: lambda方式: 3 x 8 = 24

    // ============================================================
    // 【对比总结】
    // ============================================================
    //
    //  方式          | 代码直观度 | 推荐程度
    //  -------------|-----------|--------
    //  静态成员函数  | ★★★★★   | 直接赋值即可
    //  std::bind    | ★★☆☆☆   | 语法繁琐，但有时不得不用
    //  Lambda包装   | ★★★★☆   | 推荐！清晰、灵活
    //

    return 0;
}
