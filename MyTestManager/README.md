# README

## 使用cmake编译的错误

```bash
Undefined symbols for architecture arm64:
  "questions::questions()", referenced from:
      choiceQuestions::choiceQuestions() in choiceQuestions.cpp.o
  "questions::~questions()", referenced from:
      choiceQuestions::~choiceQuestions() in choiceQuestions.cpp.o
  "typeinfo for questions", referenced from:
      typeinfo for choiceQuestions in choiceQuestions.cpp.o
ld: symbol(s) not found for architecture arm64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
make[2]: *** [questionsDemo] Error 1
make[1]: *** [CMakeFiles/questionsDemo.dir/all] Error 2
make: *** [all] Error 2
```

恐怕是要先生成.so动态库才能够编译吧。

先不用cmake，使用g++编译试试
