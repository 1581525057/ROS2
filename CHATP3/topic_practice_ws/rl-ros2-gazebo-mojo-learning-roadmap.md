# ROS 2 Humble + Gazebo + 强化学习训练 16 周快稳路线

> 生成日期：2026-05-22  
> 适用对象：ROS 2 小白，已经接触过 Topic，但 Python、机器学习、强化学习、Gazebo 都还不扎实。  
> 当前环境：ROS 2 Humble。  
> 总目标：16 周内跑通一个最小但完整的机器人强化学习训练闭环：`reset -> step -> reward -> PPO 训练 -> 评估 -> 记录结果`。

---

## 0. 先给结论

你现在不要追最新版本，也不要一开始学太多方向。

推荐主线：

| 模块 | 推荐选择 | 为什么 |
|---|---|---|
| 系统 | Ubuntu 22.04 LTS | ROS 2 Humble 的主流系统，资料最多，少踩版本坑 |
| ROS 2 | Humble Hawksbill | 你正在用的版本，长期支持，学习成本最低 |
| 仿真 | Gazebo Classic 11 | Humble 入门资料多，TurtleBot3 示例成熟，适合小白先跑通 |
| 机器人 | TurtleBot3 或极简差速小车 | 任务简单，动作就是线速度和角速度，适合 RL 入门 |
| 编程语言 | Python 优先 | 强化学习生态主要在 Python，先训练成功比语言完美更重要 |
| 深度学习 | PyTorch | 教程多，Stable-Baselines3 底层常用 |
| RL 接口 | Gymnasium | 统一 `reset()` / `step()`，方便从普通环境迁移到 Gazebo |
| RL 算法库 | Stable-Baselines3 | 先用成熟 PPO 跑通流程，不要一开始手写 PPO |
| 可视化 | Gazebo + RViz2 + TensorBoard | 分别看仿真、机器人状态、训练曲线 |
| Mojo | 第 16 周之后再了解 | Mojo 不是 ROS 2 Humble 强化学习训练的主线 |

第一阶段的唯一作品目标：

```text
在 Gazebo 里让一个差速小车根据激光雷达和目标方向训练 PPO，
最后能输出成功率、碰撞率、平均步数、reward 曲线。
```

---

## 1. 为什么要这样排序

很多人学机器人强化学习失败，不是因为 PPO 太难，而是因为顺序错了。

正确顺序是：

```text
Python 基础
-> ROS 2 通信基础
-> PyTorch 和 Gymnasium
-> 不接 ROS 的 RL 小环境
-> Gazebo 小车能动
-> 把 Gazebo 包装成 Gymnasium 环境
-> PPO 训练和评估
```

原因：

1. **先学 Python**：RL 训练脚本、日志、画图、Gymnasium 环境都靠 Python。Python 不稳，后面所有报错都看不懂。
2. **再补 ROS 2 基础**：Gazebo RL 环境本质上要发布 `/cmd_vel`，订阅 `/scan`、`/odom`，还要会 launch 和参数。
3. **再学 PyTorch/Gymnasium**：你要知道训练循环、observation、action、reward 是什么，否则只会复制代码。
4. **先离开 Gazebo 练 RL**：Gazebo 很慢，调试成本高。先在 CartPole、GridWorld、2D 小车里理解 RL。
5. **最后接 Gazebo**：这时你已经知道 RL 需要什么，再去把 ROS 2/Gazebo 数据接成 `reset()` 和 `step()`。

不要一开始做这些：

- 不要先学机械臂强化学习，状态和动作太复杂。
- 不要先学视觉强化学习，图像输入会把问题放大很多倍。
- 不要先学 Nav2 深入，Nav2 先作为 baseline 概念了解即可。
- 不要先用 Mojo 写 RL，生态不适合小白快速训练。
- 不要先自己从零实现 PPO，先用 Stable-Baselines3。
- 不要同时折腾 Humble、Jazzy、Gazebo Classic、Gazebo Harmonic，多版本混用会浪费大量时间。

---

## 2. 16 周总览

| 周数 | 主题 | 本周产物 |
|---|---|---|
| 第 1 周 | 环境、终端、Python 最小基础 | 能运行 ROS 2 demo，能创建 Python 虚拟环境 |
| 第 2 周 | ROS 2 Topic 复盘和 Python 节点 | 一个发布/订阅小系统 |
| 第 3 周 | Service、Action、Parameter | 一个模拟电池系统 |
| 第 4 周 | Launch、包结构、日志、调试 | 一条命令启动多节点 |
| 第 5 周 | NumPy、Matplotlib、训练曲线 | 能生成数据并画 loss/reward 曲线 |
| 第 6 周 | PyTorch 最小神经网络 | 一个监督学习小模型 |
| 第 7 周 | Gymnasium 和 RL 基础 | 能手写随机策略跑 CartPole |
| 第 8 周 | Stable-Baselines3 PPO | PPO 训练 CartPole 并保存模型 |
| 第 9 周 | 自定义 GridWorld | 自己写 `reset()` 和 `step()` |
| 第 10 周 | 2D 差速小车环境 | 不用 Gazebo 训练小车到点 |
| 第 11 周 | Gazebo Classic + TurtleBot3 | Gazebo 中小车能动 |
| 第 12 周 | ROS 2 读取仿真数据 | 能发布 `/cmd_vel`，读取 `/scan` 和 `/odom` |
| 第 13 周 | Gazebo Gym 环境骨架 | `GazeboNavEnv.reset()` 和 `step()` 能跑 |
| 第 14 周 | Reward、done、reset 稳定性 | 随机策略能跑 100 局不崩 |
| 第 15 周 | PPO 正式训练 | PPO 在 Gazebo 环境开始收敛 |
| 第 16 周 | 评估、对比、整理作品 | 输出训练报告和代码结构 |

4 个关键检查点：

```text
第 4 周：ROS 2 小系统跑通
第 8 周：PPO 在普通 Gym 环境跑通
第 12 周：Gazebo 小车能被 ROS 2 控制
第 16 周：Gazebo RL 训练闭环跑通
```

---

## 3. 每天怎么学

每天 3 到 4 小时比较合适。

如果当天只有 2 小时，也按这个比例缩短。

```text
30 分钟：看概念，只看今天会用到的
90 分钟：敲代码或跑命令
30 分钟：记录报错、原因、解决方式
30 分钟：写验收结果
```

每天必须写 `study_log.md`：

```markdown
## 2026-xx-xx

### 今天目标
- 

### 跑通了什么
- 

### 卡住了什么
- 

### 我判断问题属于哪一类
- Python / ROS 2 / Gazebo / RL / 环境安装

### 明天只做一件什么事
- 
```

为什么必须写日志：

- 强化学习训练结果会变，不记录就无法复现。
- Gazebo 和 ROS 2 报错经常来自环境，不记录会反复踩坑。
- 小白最容易每天学很多名词，但没有一个可运行产物。

---

## 4. 第 1-2 周：Python 和 ROS 2 通信基础

### 第 1 周：环境和 Python 最小基础

目标：

- 确认你的 Humble 环境能用。
- Python 能写函数、类、虚拟环境、安装包。
- 终端常用命令不再陌生。

必须跑通：

```bash
ros2 run demo_nodes_cpp talker
ros2 run demo_nodes_py listener
ros2 topic list
ros2 topic echo /chatter
python3 -m venv .venv
```

Python 必会：

- 变量、函数、类
- list、dict、tuple
- 文件读写
- `try/except`
- `pip install`
- 虚拟环境
- `if __name__ == "__main__"`

为什么先学这些：

- 后面所有训练脚本都是 Python。
- ROS 2 Python 节点也要用类。
- Gymnasium 环境就是一个 Python 类。

本周不要学：

- C++ 模板。
- 复杂算法。
- Gazebo 插件开发。

验收标准：

- 你能解释 `source /opt/ros/humble/setup.bash` 是干什么的。
- 你能创建一个 Python 文件并运行。
- 你能安装一个包并知道它装在哪个虚拟环境里。

### 第 2 周：Topic 复盘和 Python 节点

目标：

- 真正理解 node、topic、message、publisher、subscriber。
- 会写一个最简单的 Python 发布者和订阅者。

练习项目：

```text
sys_status_pub 节点：
  每 1 秒发布 CPU、内存、电池或模拟状态

sys_status_sub 节点：
  订阅状态并打印
```

为什么要做这个：

- Gazebo RL 里，你要发布动作到 `/cmd_vel`。
- 你要订阅传感器数据，比如 `/scan`。
- 这和发布系统状态、订阅系统状态是同一种通信模型。

验收标准：

- `ros2 topic list` 能看到你的话题。
- `ros2 topic echo` 能看到消息。
- 你能解释发布者不需要知道订阅者是谁。

---

## 5. 第 3-4 周：ROS 2 小系统能力

### 第 3 周：Service、Action、Parameter

目标：

- 知道 Topic、Service、Action 各自适合什么任务。
- 会用 Parameter 控制节点行为。

练习项目：模拟电池系统。

```text
battery_pub:
  持续发布电量

battery_query_service:
  查询当前电量

charge_action:
  充电到指定百分比，过程中反馈进度

参数：
  discharge_rate
  charge_rate
```

为什么要学：

- Gazebo reset 常常需要服务。
- 长时间任务适合 Action。
- 训练参数不能写死，要能从 YAML 改。

验收标准：

- 你能说清楚 Topic 和 Service 的区别。
- 你能说清楚 Service 和 Action 的区别。
- 你能不改代码，只改参数改变行为。

### 第 4 周：Launch、包结构、日志、调试

目标：

- 一条命令启动多个节点。
- 会看 ROS 2 日志。
- 会用 YAML 配置参数。

练习：

把第 3 周电池系统改成：

```text
launch/battery_system.launch.py
config/battery.yaml
```

要求：

- launch 同时启动发布节点、服务节点、动作节点。
- YAML 控制耗电速度和充电速度。
- 日志能显示节点启动、参数读取、状态变化。

为什么要学：

- 后面 Gazebo、RViz2、训练节点不可能一个个手动启动。
- 训练要频繁换参数，必须用配置文件。

验收标准：

- 一条 `ros2 launch` 命令启动整个小系统。
- 参数改了以后行为真的变化。
- 报错时你知道先看终端日志、节点名、话题名、参数名。

---

## 6. 第 5-6 周：机器学习最小基础

### 第 5 周：NumPy、Matplotlib、数据和曲线

目标：

- 会用数组表示 observation。
- 会画 loss 和 reward 曲线。

必须学：

- `np.array`
- shape
- 切片
- 均值、方差
- 随机数
- 折线图
- 保存图片

练习：

```text
生成 1000 条模拟电池数据：
输入：当前电量、速度、负载
输出：剩余运行时间
画出输入和输出关系
```

为什么要学：

- RL 的 observation 本质上就是数组。
- 训练是否有效主要看曲线，不是只看 Gazebo 画面。

验收标准：

- 你能打印数组 shape。
- 你能画一条 reward 曲线。
- 你知道曲线乱跳不等于训练一定失败，但长期不变需要检查 reward。

### 第 6 周：PyTorch 最小神经网络

目标：

- 会定义一个小网络。
- 会跑训练循环。
- 知道 loss 是什么。

练习：

用 PyTorch 做电池剩余时间预测。

必须包含：

```text
model
loss function
optimizer
training loop
loss curve
```

为什么要学：

- PPO 里面也有神经网络。
- 你不一定要手写 PPO，但要知道模型在被优化。

验收标准：

- loss 能下降。
- 你能保存模型参数。
- 你能解释 `optimizer.step()` 大概在做什么。

---

## 7. 第 7-10 周：先不接 Gazebo，学会 RL 训练

### 第 7 周：Gymnasium 和 RL 基础

目标：

- 理解 `reset()` 和 `step()`。
- 理解 observation、action、reward、done。

第一个环境：CartPole。

必须跑通：

```python
obs, info = env.reset()
action = env.action_space.sample()
next_obs, reward, terminated, truncated, info = env.step(action)
```

为什么先用 CartPole：

- 它足够小。
- 不需要 ROS 2。
- 可以让你专心理解 RL 数据流。

验收标准：

- 随机策略能跑 10 局。
- 能记录每局总 reward。
- 你能解释一局 episode 为什么会结束。

### 第 8 周：Stable-Baselines3 PPO

目标：

- 用成熟库训练 PPO。
- 会保存和加载模型。
- 会评估训练结果。

练习：

```text
train_cartpole.py
eval_cartpole.py
models/cartpole_ppo.zip
logs/
```

为什么现在学 PPO：

- PPO 支持连续动作，适合后面的机器人速度控制。
- Stable-Baselines3 能让你先关注环境设计，而不是算法细节。

验收标准：

- 训练后平均 reward 高于随机策略。
- 能保存模型。
- 能加载模型并运行评估。

### 第 9 周：自定义 GridWorld

目标：

- 自己写一个 Gymnasium 环境。
- 知道环境比算法更重要。

环境规则：

```text
机器人从起点到终点
撞墙：-10
到达终点：+50
每走一步：-0.1
超过最大步数：结束
```

为什么要写 GridWorld：

- Gazebo RL 环境本质上也是自定义环境。
- 你要先在简单环境里练会 `reset()`、`step()`、reward、done。

验收标准：

- 随机策略能跑。
- Q-learning 或 PPO 能训练。
- 你能解释 reward 每一项为什么存在。

### 第 10 周：2D 差速小车环境

目标：

- 不用 Gazebo，先模拟小车运动学。
- 动作开始接近真实机器人。

状态：

```text
x
y
yaw
goal_x
goal_y
distance_to_goal
angle_to_goal
```

动作：

```text
linear_velocity
angular_velocity
```

reward：

```text
接近目标：加分
远离目标：扣分
到达目标：大奖励
超时：结束并扣分
动作过大：轻微扣分
```

为什么要做这个：

- 差速小车动作就是 Gazebo 小车动作的简化版。
- 你可以在很快的环境里调 reward，再迁移思想到 Gazebo。

验收标准：

- 随机策略效果差。
- PPO 训练后到达目标更稳定。
- 能画出小车轨迹。

---

## 8. 第 11-12 周：Gazebo Classic 和 ROS 2 仿真数据

### 第 11 周：Gazebo Classic + 小车能动

目标：

- Gazebo 里有小车。
- ROS 2 能控制小车。

推荐从 TurtleBot3 开始，原因：

- Humble 教程多。
- 已经有差速驱动、激光雷达、模型、launch 示例。
- 小白不需要先从零写 SDF/URDF。

必须理解：

- Gazebo 是仿真器。
- ROS 2 是通信和算法框架。
- `/cmd_vel` 是速度命令。
- `/scan` 是激光雷达。
- `/odom` 是里程计。
- `use_sim_time` 表示使用仿真时间。

验收标准：

- 能打开 Gazebo。
- 能看到小车。
- 能用键盘或命令控制小车移动。
- 能看到 `/scan` 或 `/odom`。

### 第 12 周：ROS 2 读取仿真数据

目标：

- 自己写一个节点控制小车。
- 自己写一个节点读取传感器。

练习：

```text
cmd_vel_test_node:
  每秒发布一个速度命令

scan_reader_node:
  订阅 /scan，打印最近障碍物距离

odom_reader_node:
  订阅 /odom，打印位置和朝向
```

为什么要做：

- RL 的 action 最后要变成 `/cmd_vel`。
- RL 的 observation 来自 `/scan`、`/odom` 和目标点。
- 如果这一步不稳，后面训练一定不稳。

验收标准：

- 小车能按你的 Python 节点动。
- 能读到最近障碍物距离。
- 能读到小车位置。
- 你能判断问题是话题名错、消息类型错，还是节点没启动。

---

## 9. 第 13-14 周：把 Gazebo 包装成 Gymnasium 环境

### 推荐项目结构

```text
rl_gazebo_nav/
  envs/
    gazebo_nav_env.py
  scripts/
    random_policy.py
    train_ppo.py
    eval_policy.py
  launch/
    gazebo_training.launch.py
  config/
    env.yaml
    ppo.yaml
  models/
  logs/
  reports/
```

### 第 13 周：环境骨架

目标：

- `GazeboNavEnv` 能创建。
- `reset()` 能返回 observation。
- `step()` 能发布动作并返回结果。

第一版 observation：

```text
24 维激光雷达距离
到目标距离
到目标角度
当前线速度
当前角速度
```

第一版 action：

```text
linear_velocity: 0.0 到 0.25 m/s
angular_velocity: -1.0 到 1.0 rad/s
```

为什么 observation 不用图像：

- 图像训练慢。
- 调试难。
- 小白阶段先用低维传感器更容易判断问题。

验收标准：

- `env.reset()` 能返回固定 shape 的数组。
- `env.step(action)` 能让小车动一下。
- action 会被限幅。
- observation 没有 NaN。

### 第 14 周：reward、done、reset 稳定性

目标：

- 随机策略能跑 100 局不崩。
- 每一局都能正常结束。
- reset 后状态干净。

第一版 reward：

```text
到达目标：+100
碰撞：-100
每一步：-0.01
距离变近：+1.0 * 距离减少量
距离变远：-1.0 * 距离增加量
最近障碍物小于 0.25m：-1.0
```

done 条件：

```text
到达目标
碰撞
超过最大步数
仿真或传感器异常
```

为什么先跑随机策略：

- PPO 训练失败时，你要先确认环境本身是否稳定。
- 如果随机策略都跑不完，算法训练没有意义。

验收标准：

- 随机策略 100 局不崩。
- 每局 reward、步数、是否碰撞都有记录。
- reset 后目标点和机器人位置正确。
- observation shape 永远不变。

---

## 10. 第 15-16 周：PPO 训练、评估和作品整理

### 第 15 周：PPO 正式训练

目标：

- 用 Stable-Baselines3 的 PPO 训练 Gazebo 环境。
- 能保存日志和模型。

起始参数：

```yaml
algorithm: PPO
policy: MlpPolicy
learning_rate: 0.0003
n_steps: 1024
batch_size: 64
gamma: 0.99
gae_lambda: 0.95
clip_range: 0.2
ent_coef: 0.01
total_timesteps: 300000
```

为什么先用 300000 步：

- Gazebo 慢，先用较小训练量验证流程。
- 等环境稳定后再增加到 1000000 步。

每次实验必须记录：

```markdown
## Experiment 001

### 环境
- 地图：
- 机器人：
- observation：
- action：
- reward：

### 算法
- PPO 参数：

### 结果
- 平均 reward：
- 成功率：
- 碰撞率：
- 平均步数：

### 现象
- 

### 下一次只改一个变量
- 
```

验收标准：

- 训练能持续运行，不频繁崩溃。
- TensorBoard 能看到曲线。
- 模型能保存。
- 训练后策略至少比随机策略更好。

### 第 16 周：评估和作品整理

目标：

- 不只看训练 reward，要做评估。
- 整理成一个能展示的项目。

评估方式：

```text
随机策略 50 局
规则策略 50 局
PPO 策略 50 局
```

记录指标：

```text
success_rate
collision_rate
average_steps
average_reward
average_time
```

为什么要和随机策略、规则策略对比：

- 否则你不知道 PPO 是真的学会了，还是只是看起来会动。
- baseline 是判断 RL 是否有价值的最低标准。

最终产物：

```text
README.md
训练脚本
评估脚本
配置文件
模型文件
训练曲线
评估表格
一段 Gazebo 演示视频或截图
```

验收标准：

- 能一条命令启动训练。
- 能一条命令启动评估。
- 能解释 observation、action、reward。
- 能说出当前策略失败的主要原因。

---

## 11. 卡住时怎么定位问题

先分类，不要乱改。

### Python 问题

典型表现：

- import 报错。
- shape 不对。
- 类型不对。
- 虚拟环境不对。

先检查：

```bash
which python
python --version
pip list
```

### ROS 2 问题

典型表现：

- 话题不存在。
- 节点没启动。
- 消息类型不匹配。
- 参数没生效。

先检查：

```bash
ros2 node list
ros2 topic list -t
ros2 topic echo /topic_name
ros2 param list
```

### Gazebo 问题

典型表现：

- 小车不动。
- reset 后位置不对。
- 传感器没数据。
- 仿真很慢。

先检查：

```text
Gazebo GUI 里机器人是否存在
/cmd_vel 是否真的发出
/odom 是否变化
/scan 是否有数据
use_sim_time 是否设置
```

### RL 问题

典型表现：

- reward 不涨。
- 策略原地转圈。
- 总是撞墙。
- 训练曲线剧烈震荡。

先检查：

```text
随机策略能不能跑完
reward 数值是否过大
碰撞是否真的终止
到达目标是否真的加分
observation 是否归一化
action 是否限幅
reset 是否干净
```

原则：

```text
随机策略跑不稳 -> 先修环境
规则策略跑不通 -> 先修 observation/action/reward
PPO 不收敛 -> 再调算法参数
```

---

## 12. 你现在最该学什么

如果你今天就开始，顺序是：

1. 确认 Ubuntu 22.04 + ROS 2 Humble 能正常运行。
2. 把 Topic、Service、Action、Parameter、Launch 补齐。
3. 同时每天练 Python。
4. 第 5 周开始学 NumPy 和 PyTorch。
5. 第 7 周开始碰 Gymnasium。
6. 第 8 周用 Stable-Baselines3 跑 PPO。
7. 第 11 周再进入 Gazebo。

为什么不是先学 Gazebo：

- Gazebo 里的错误太多，容易把 Python、ROS 2、RL 的问题混在一起。
- 小白阶段最重要的是先形成“一个问题只调一个变量”的习惯。

为什么不是先学数学：

- 你需要最低数学直觉，但不需要先学完整机器学习课程。
- 向量、矩阵、概率、梯度、loss 先够用，遇到算法再补。

为什么不是先学 Mojo：

- 你的目标是强化学习训练，不是语言性能优化。
- ROS 2 Humble、PyTorch、Stable-Baselines3、Gymnasium 都以 Python 生态为主。
- Mojo 可以等你有一个能跑的训练项目后，再作为性能和语言探索。

---

## 13. Mojo 放在哪里

Mojo 当前不进 16 周主线。

可以在第 16 周之后这样学：

1. 读基础语法。
2. 理解它和 Python 的关系。
3. 写几个数组计算小例子。
4. 对比 Python/NumPy/PyTorch 的速度和开发体验。
5. 不要用它重写 PPO。
6. 不要用它接 ROS 2 作为第一项目。

判断标准：

```text
如果你还不能在 Gazebo 中训练一个 PPO 小车，
就先不要把 Mojo 加进主线。
```

---

## 14. 最小毕业标准

完成下面 10 项，就算真正入门 ROS 2 + Gazebo 强化学习训练：

- [ ] 会写 ROS 2 Python publisher/subscriber。
- [ ] 会写 service、action、parameter、launch。
- [ ] 会用 NumPy 表示 observation。
- [ ] 会用 Matplotlib 画 reward 曲线。
- [ ] 会用 PyTorch 训练一个小网络。
- [ ] 会用 Gymnasium 跑 CartPole。
- [ ] 会用 Stable-Baselines3 训练 PPO。
- [ ] 会在 Gazebo 中控制差速小车。
- [ ] 会把 Gazebo 包装成 `reset()` / `step()` 环境。
- [ ] 会评估 PPO 策略并输出成功率、碰撞率、平均步数。

最终你应该能解释这句话：

```text
强化学习训练不是只调用 PPO，
而是设计一个稳定环境，
把 observation、action、reward、done 做对，
再用算法优化策略。
```

---

## 15. 参考资料

优先看官方文档和成熟项目，不要一开始刷零散视频。

- ROS 2 Humble 文档：https://docs.ros.org/en/humble/
- ROS 2 Humble 安装文档：https://docs.ros.org/en/humble/Installation.html
- Gazebo Classic 文档：https://classic.gazebosim.org/tutorials
- TurtleBot3 文档：https://emanual.robotis.com/docs/en/platform/turtlebot3/overview/
- Gymnasium 文档：https://gymnasium.farama.org/
- Stable-Baselines3 文档：https://stable-baselines3.readthedocs.io/
- PyTorch 文档：https://pytorch.org/docs/stable/index.html
- Mojo 文档：https://docs.modular.com/mojo/
