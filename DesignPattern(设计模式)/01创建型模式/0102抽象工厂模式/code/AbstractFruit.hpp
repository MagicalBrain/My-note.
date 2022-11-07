#pragma once

#include <iostream>

/// @brief 抽象苹果
class AbstractApple
{
public:
	AbstractApple() = default;
	virtual ~AbstractApple() {}

	virtual void ShowName() = 0;

private:

};

/// @brief 抽象香蕉
class AbstractBanana
{
public:
	AbstractBanana() = default;
	virtual ~AbstractBanana() {}

	virtual void ShowName() = 0;

private:

};

/// @brief 抽象鸭梨
class AbstractPear
{
public:
	AbstractPear() = default;
	virtual ~AbstractPear() {}

	virtual void ShowName() = 0;

private:

};


