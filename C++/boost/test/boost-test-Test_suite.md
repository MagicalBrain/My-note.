# boost-test-Test_suite

## 测试套件

If you consider test cases as leaves on the test tree, the test suite can be considered as branch and the master test suite as the root. Unlike real trees though, our tree in many cases consists only of leaves attached directly to the root. This is common for all test cases to reside directly in the master test suite. If you do want to construct a hierarchical test suite structure the Unit Test Framework provides both manual and automated test suite creation and registration facilities:

如果您将测试用例看作是测试树的叶子，那么测试套件可以看作是分支，而主测试套件可以看作是根。但与真正的树不同的是，我们的树在很多情况下只由直接附在根上的叶子组成。这对于所有直接驻留在主测试套件中的测试用例是常见的。如果你想构建一个分层的测试套件结构，单元测试框架提供了手动和自动的测试套件创建和注册工具:

1. Test suite with automated registration
2. Manually registered test suite

In addition the Unit Test Framework presents a notion of the Master test suite. The most important reason to learn about this component is that it provides an ability to access command line arguments supplied to a test module.

此外，单元测试框架提出了主测试套件的概念。学习此组件的最重要原因是，它提供了访问提供给测试模块的命令行参数的能力。

## Automated registration

The solution the Unit Test Framework presents for automated test suite creation and registration is designed to facilitate multiple points of definition, arbitrary test suites depth and smooth integration with automated test case creation and registration. This facility should significantly simplify a test tree construction process in comparison with manual explicit registration case.

单元测试框架为自动化测试套件创建和注册提供的解决方案旨在促进多点定义、任意测试套件深度以及与自动化测试用例创建和注册的平滑集成。与手动显式注册的情况相比，该工具应该可以显著简化测试树的构建过程。

The implementation is based on the order of file scope variables definitions within a single compilation unit. The semantic of this facility is very similar to the namespace feature of C++, including support for test suite extension. To start test suite use the macro `BOOST_AUTO_TEST_SUITE`. To end test suite use the macro `BOOST_AUTO_TEST_SUITE_END`. The same test suite can be restarted multiple times inside the same test file or in a different test files. In a result all test units will be part of the same test suite in a constructed test tree.

```cpp
BOOST_AUTO_TEST_SUITE(test_suite_name);
BOOST_AUTO_TEST_SUITE_END();
```

fatal error: in "Test_Connect_websocket_01": critical check sensor->connected() == true has failed