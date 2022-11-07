#pragma once

#include <iostream>

#include "AbstractFruit.hpp"
#include "RealFruit.hpp"

/// @brief 抽象工厂 针对产品族的
class AbstractFactory
{
public:
	AbstractFactory() = default;
	virtual ~AbstractFactory() {}

	virtual AbstractApple* CreatApple() = 0;
	virtual AbstractBanana* CreatBanana() = 0;
	virtual AbstractPear* CreatPear() = 0;

private:

};

/// @brief 中国工厂
class ChineseFactory : public AbstractFactory
{
public:
	ChineseFactory() = default;
	virtual ~ChineseFactory() {}

	virtual AbstractApple* CreatApple() {
		return new ChineseApple;
	}

	virtual AbstractBanana* CreatBanana() {
		return new ChineseBanana;
	}

	virtual AbstractPear* CreatPear() {
		return new ChinesePear;
	}

private:

};

/// @brief 美国工厂
class AmericanFactory : public AbstractFactory
{
public:
	AmericanFactory() = default;
	virtual ~AmericanFactory() {}

	virtual AbstractApple* CreatApple() {
		return new AmericanApple;
	}

	virtual AbstractBanana* CreatBanana() {
		return new AmericanBanana;
	}

	virtual AbstractPear* CreatPear() {
		return new AmericanPear;
	}

private:

};

/// @brief 日本工厂
class JanpenseFactory : public AbstractFactory
{
public:
	JanpenseFactory() = default;
	virtual ~JanpenseFactory() {}

	virtual AbstractApple* CreatApple() {
		return new JanpenseApple;
	}

	virtual AbstractBanana* CreatBanana() {
		return new JanpenseBanana;
	}

	virtual AbstractPear* CreatPear() {
		return new JanpensePear;
	}

private:

};

void testAbstractFactoryPattern() {
	AbstractFactory* factory = NULL;
	AbstractApple* apple = NULL;
	AbstractBanana* banana = NULL;
	AbstractPear* pear = NULL;

	// 中国的水果
	factory = new ChineseFactory;
	apple = factory->CreatApple();
	banana = factory->CreatBanana();
	pear = factory->CreatPear();
	apple->ShowName();
	banana->ShowName();
	pear->ShowName();

	// 美国水果
	factory = new AmericanFactory;
	apple = factory->CreatApple();
	banana = factory->CreatBanana();
	pear = factory->CreatPear();
	apple->ShowName();
	banana->ShowName();
	pear->ShowName();

	// 日本水果
	factory = new JanpenseFactory;
	apple = factory->CreatApple();
	banana = factory->CreatBanana();
	pear = factory->CreatPear();
	apple->ShowName();
	banana->ShowName();
	pear->ShowName();

	delete apple;
	delete banana;
	delete pear;
	delete factory;
}
