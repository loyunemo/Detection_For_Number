## 任务执行脚本生成器 使用说明
#### ScriptGenerator Instruction

1. **文件目录**
> build: 可执行文件(ScriptGenerator.exe)和输出文件目录(filename.h和filename.c)
> Inc: ScriptGenerator.h 库 头文件
> Src: ScriptGenerator.cpp 库 源文件
> main.cpp: 程序入口
> TaskTemplate.txt: 模板编辑文本，操作编辑对象
> CMakeLists.txt, .vscode: 个人c++环境配置
> 使用说明.pdf
  
2. **使用方法**
> (1) 删除 build 目录下已有的 .h 和 .c 文件
> (2) 按照 TaskTemplate.txt 模板编辑文件名(**File Name**)、变量(**Variable**)、阶段名(**Stages**)
> **注: 阶段之间换行隔开，可以用空格或制表符但不能有空行**
> (3) 运行ScriptGenerator.exe
  

