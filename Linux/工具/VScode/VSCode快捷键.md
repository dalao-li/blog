<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-12-15 21:10:23
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-09 20:56:58
-->

## 查找

| 功能             | 快捷键                                            |
| ---------------- | ------------------------------------------------- |
| 当前文件内容查找 | <kbd>Ctrl</kbd> + <kbd>F</kbd>                    |
| 全局查找         | <kbd>Ctrl</kbd> + <kbd>Shift</kbd> + <kbd>F</kbd> |
| 回到查看前位置   | <kbd>Alt</kbd> + <kbd>←</kbd>                     |
| 查找指定文件     | <kbd>Ctrl</kbd> + <kbd>E</kbd>                    |

- 高亮选中内容

```c
// 方法一，安装插件
highlight-icemode

// 方法二，settings.json增加
"workbench.colorCustomizations": {
    // 背景颜色
    "editor.selectionHighlightBackground": "#000000",
    // 边框颜色
    "editor.selectionHighlightBorder": "#ecd9d9"  
}
```

- C++ 文件查找

| 功能         | 快捷键                                         |
| ------------ | ---------------------------------------------- |
| 查看函数定义 | <kbd>F12</kbd>                                 |
| 查看函数引用 | <kbd>Ctrl</kbd> + <kbd>Alt</kbd>+ <kbd>F</kbd> |
| 查看函数调用 | <kbd>Ctrl</kbd> + <kbd>Alt</kbd>+ <kbd>C</kbd> |


## 跳转

| 功能                        | 快捷键                                                               |
| --------------------------- | -------------------------------------------------------------------- |
| 跳转到下个/上个查找到的内容 | <kbd>F3</kbd> / <kbd>Shift</kbd> + <kbd>F3</kbd>                     |
| 跳转指定行                  | <kbd>Ctrl</kbd> + <kbd>G</kbd>                                       |
| 跳转到行首/尾               | <kbd>Home</kbd> / <kbd>End</kbd>                                     |
| 跳转到当前文件开头/结尾     | <kbd>Ctrl</kbd> + <kbd>Home</kbd> / <kbd>Ctrl</kbd> + <kbd>End</kbd> |


## 显示

| 功能                 | 快捷键                                                                                                |
| -------------------- | ----------------------------------------------------------------------------------------------------- |
| 显示命令面板         | <kbd>Ctrl</kbd> + <kbd>Shift</kbd> + <kbd>P</kbd> 或 <kbd>F1</kbd>                                    |
| 快速打开             | <kbd>Ctrl</kbd> + <kbd>P</kbd>                                                                        |
| 新建/关闭窗口        | <kbd>Ctrl</kbd> + <kbd>Shift</kbd> + <kbd>N</kbd> / <kbd>Ctrl</kbd> + <kbd>Shift</kbd> + <kbd>W</kbd> |
| 新建/关闭文件        | <kbd>Ctrl</kbd> + <kbd>N</kbd> / <kbd>Ctrl</kbd> + <kbd>W</kbd>                                       |
| 重新打开关闭的编辑器 | <kbd>Ctrl</kbd> + <kbd>Shift</kbd> + <kbd>T</kbd>                                                     |

## 编辑

| 功能                 | 快捷键                                                                                       |
| -------------------- | -------------------------------------------------------------------------------------------- |
| 当前文件内容替换     | <kbd>Ctrl</kbd> + <kbd>H</kbd>                                                               |
| 全局替换             | <kbd>Ctrl</kbd> + <kbd>Shift</kbd> + <kbd>H</kbd>                                            |
| 编辑查找到的全部对象 | <kbd>Ctrl</kbd> + <kbd>F2</kbd>                                                              |
| 代码行向左/右缩进    | <kbd>Ctrl</kbd> + <kbd>[ </kbd> / <kbd>Ctrl</kbd> + <kbd>] </kbd>                            |
| 代码格式化           | <kbd>Alt</kbd> + <kbd>Shift</kbd> + <kbd>F</kbd>                                             |
| 在当前行上/下方插入  | <kbd>Ctrl</kbd> + <kbd>Shift</kbd> + <kbd>Enter</kbd>  /  <kbd>Ctrl</kbd> + <kbd>Enter</kbd> |
| 当前行上/下移        | <kbd>Alt</kbd> + <kbd>↑</kbd> / <kbd>Alt</kbd> + <kbd>↓</kbd>                                |
| 删除当前行           | <kbd>Ctrl</kbd> + <kbd>Shift</kbd> + <kbd>K</kbd>                                            |
| 切换行注释           | <kbd>Ctrl</kbd> + <kbd>/</kbd>                                                               |

