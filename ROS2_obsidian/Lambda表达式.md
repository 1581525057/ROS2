# Lambda 表达式（C++）

[[ROS2学习地图]] | [[std_function与回调]] | [[CHAPT2 - 节点基础]]

---

## 什么是 Lambda

Lambda 是一种"内联匿名函数"，可以在需要函数的地方直接写函数体，
不用单独定义函数名。在 ROS2 里常用于定时器回调。

---

## 基本语法

```cpp
[捕获列表](参数列表) -> 返回类型 {
    函数体
};
```

---

## 示例（learn_lambda.cpp）

```cpp
// 定义一个加法 Lambda
auto add = [](int a, int b) -> int {
    return a + b;
};

auto sum = add(3, 5);   // sum = 8

// 捕获局部变量（值捕获）
auto print_sum = [sum]() -> void {
    std::cout << "这个数字为：" << sum << std::endl;
};

print_sum();   // 输出：这个数字为：8
```

---

## 捕获方式

| 写法 | 含义 |
|---|---|
| `[]` | 不捕获任何外部变量 |
| `[x]` | 值捕获变量 x（复制一份） |
| `[&x]` | 引用捕获变量 x（共享同一个） |
| `[this]` | 捕获当前类对象的 this 指针 |
| `[&]` | 引用捕获所有外部变量 |
| `[=]` | 值捕获所有外部变量 |

---

## 在 ROS2 Timer 中的应用

```cpp
// Timer 创建时直接写 Lambda 回调，不需要单独定义函数
timer_ = this->create_wall_timer(
    100ms,
    [this]() {
        timer_callback();   // 在 Lambda 内调用成员函数
    });
```

`[this]` 捕获当前节点对象，这样 Lambda 里才能访问 `timer_callback()`。

---

## 相关笔记

- [[std_function与回调]]
- [[Timer定时器]]
