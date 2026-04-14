# std::function 与回调（C++）

[[ROS2学习地图]] | [[Lambda表达式]] | [[CHAPT2 - 节点基础]]

---

## 什么是 std::function

`std::function` 是一个通用函数容器，可以存储任何可调用对象：
- 普通函数
- 静态成员函数
- Lambda 表达式
- std::bind 绑定结果

---

## 三种常见写法（learn_funcational.cpp）

### 1. 静态成员函数（最简单）

```cpp
// 静态函数没有 this，可直接赋值
std::function<int(int, int)> f = Calculator::subtract;
f(10, 3);   // 返回 7
```

### 2. std::bind（绑定成员函数 + 对象）

```cpp
// 普通成员函数需要指定"哪个对象调用"
std::function<int(int, int)> f = std::bind(
    &Calculator::multiply,  // 函数地址
    &calc,                  // 对象地址
    std::placeholders::_1,  // 第1个参数占位
    std::placeholders::_2   // 第2个参数占位
);
f(6, 7);   // 返回 42
```

占位符 `_1`、`_2` 在调用时由实参填充。

### 3. Lambda 包装（推荐）

```cpp
// 更直观，捕获对象后直接调用成员函数
std::function<int(int, int)> f = [&calc](int a, int b) -> int {
    return calc.multiply(a, b);
};
f(3, 8);   // 返回 24
```

---

## 三种方式对比

| 方式 | 直观度 | 推荐程度 |
|---|---|---|
| 静态成员函数 | ★★★★★ | 适合静态函数 |
| std::bind | ★★☆☆☆ | 语法繁琐 |
| Lambda 包装 | ★★★★☆ | 推荐，灵活清晰 |

---

## 在 ROS2 中的应用

ROS2 的定时器、订阅者回调参数类型都是 `std::function`，
所以三种写法都可以传进去：

```cpp
// std::bind 写法（turtle_circle.cpp）
timer_ = this->create_wall_timer(
    1000ms, std::bind(&Turtle_CircleNode::timer_callback, this));

// Lambda 写法（tutrtle_circle_yezi.cpp）
timer_ = this->create_wall_timer(
    100ms, [this]() { timer_callback(); });
```

---

## 相关笔记

- [[Lambda表达式]]
- [[Timer定时器]]
- [[Node节点]]
