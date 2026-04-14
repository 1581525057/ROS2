# Timer 定时器

[[ROS2学习地图]] | [[Publisher发布者]]

---

## 作用

让节点每隔固定时间自动执行一个函数（回调），不需要手动循环。

---

## C++ Timer

```cpp
// 方式一：std::bind（标准写法）
timer_ = this->create_wall_timer(
    1000ms,
    std::bind(&Turtle_CircleNode::timer_callback, this));

// 方式二：Lambda（更直观，叶子练习版用的这个）
timer_ = this->create_wall_timer(
    100ms,
    [this]() { timer_callback(); });
```

时间单位：需要 `using namespace std::chrono_literals;`
- `100ms` = 100 毫秒
- `1s` = 1 秒

---

## Python Timer

```python
# 每 5 秒触发一次 self.timer_callback
self.create_timer(5, self.timer_callback)
```

---

## 注意

定时器依赖 `spin()` 才能运转。
没有 `rclcpp::spin()` / `rclpy.spin()`，定时器永远不会触发。

---

## 相关笔记

- [[Publisher发布者]]
- [[Node节点]]
