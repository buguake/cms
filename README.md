### Course Management System
This project is a simple implementation of couse management system (cms) in C++.

Maintainers: [a530537501](https://github.com/a530537501), SiyuXie0601, [Stephen Tse](https://github.com/xjiajiahao), yuweizheng.

---
## CMS 设计说明
### 功能设计
#### 概述
选课系统主要面向学生、老师、管理员三种用户:
* 学生:选课,查看课程安排
* 教师:查看课程安排,查看选课情况,录入成绩等
* 管理员:管理课程信息,学生和老师的信息
#### 详细描述
##### 用户
学生、教师和管理员，分别拥有不同的权限，**系统管理员应该只能有一个**：
| User | 查看课程安排 | 选课 | 录入成绩 | 添加、删除用户和课程 |
| :--- | :---------: | :--: | :-----: | :----------: |
| 学生 | Y | Y | N | N |
| 教师 | Y | N | Y | N |
| 管理员 | Y | N | N | Y |

##### 界面
选课系统的界面用 Qt 实现，主界面的控件主要是查询到的数据库表格。

菜单栏上有登录、注销，查看所有课程安排、查看我的课程安排，新建用户、新建课程等条目。不同权限的用户登录后会激活不同的条目。

点击菜单或按钮后弹出子窗口，用户输入数据，完成相应的操作。或者弹出 Message Box，提示操作是否成功。可能用到的子窗口有：登录界面、消息框和单行的输入框。

##### 数据库
用 Qt 的 MySQL 的接口实现数据库的增删改操作，参考 [Qt Documentation: SQL Examples](http://doc.qt.io/qt-5/examples-sql.html)。


### 结构设计

### 人员分工

### 计划进度

