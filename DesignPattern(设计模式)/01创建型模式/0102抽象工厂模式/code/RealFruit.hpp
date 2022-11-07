#pragma once

#include "AbstractFruit.hpp"

/// @brief 中国苹果
class ChineseApple : public AbstractApple
{
public:
	ChineseApple() = default;
	~ChineseApple() = default;

	virtual void ShowName() override {
		std::cout << "ChineseApple\n";
	}

private:

};

/// @brief 中国香蕉
class ChineseBanana : public AbstractBanana
{
public:
	ChineseBanana() = default;
	~ChineseBanana() = default;

	virtual void ShowName() override {
		std::cout << "ChineseBanana\n";
	}

private:

};

/// @brief 中国鸭梨
class ChinesePear : public AbstractPear
{
public:
	ChinesePear() = default;
	~ChinesePear() = default;

	virtual void ShowName() override {
		std::cout << "ChinesePear\n";
	}

private:

};

/// @brief 美国苹果
class AmericanApple : public AbstractApple
{
public:
	AmericanApple() = default;
	~AmericanApple() = default;

	virtual void ShowName() override {
		std::cout << "AmericanApple\n";
	}

private:

};

/// @brief 美国香蕉
class AmericanBanana : public AbstractBanana
{
public:
	AmericanBanana() = default;
	~AmericanBanana() = default;

	virtual void ShowName() override {
		std::cout << "AmericanBanana\n";
	}

private:

};

/// @brief 美国鸭梨
class AmericanPear : public AbstractPear
{
public:
	AmericanPear() = default;
	~AmericanPear() = default;

	virtual void ShowName() override {
		std::cout << "AmericanPear\n";
	}

private:

};

/// @brief 日本苹果
class JanpenseApple : public AbstractApple
{
public:
	JanpenseApple() = default;
	~JanpenseApple() = default;

	virtual void ShowName() override {
		std::cout << "JanpenseApple\n";
	}

private:

};

/// @brief 日本香蕉
class JanpenseBanana : public AbstractBanana
{
public:
	JanpenseBanana() = default;
	~JanpenseBanana() = default;

	virtual void ShowName() override {
		std::cout << "JanpenseBanana\n";
	}

private:

};

/// @brief 日本鸭梨
class JanpensePear : public AbstractPear
{
public:
	JanpensePear() = default;
	~JanpensePear() = default;

	virtual void ShowName() override {
		std::cout << "JanpensePear\n";
	}

private:

};
