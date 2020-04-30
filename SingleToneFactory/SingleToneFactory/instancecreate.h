#pragma once
#include <map>
#include <iostream>
using namespace std;

template<typename T>
class SingleTone 
{

public:
	static T* getInstance() 
	{
		if (nullptr == Instance) 
		{
			Instance = new T;
		}
		return Instance;
	}

private:
	static T* Instance;
};

template<typename T>
T* SingleTone<T>::Instance = nullptr;

typedef void* (*CreateObjectPtr)(void);

class ClassFactory
{

public:
	void RegisterClass(string className, CreateObjectPtr method)
	{ 
		if (!map.count(className))
		{
			map.insert(pair<string, CreateObjectPtr>(className, method));
		}
	}

	void* GetClassByName(string className)
	{
		if (map.count(className))
		{
			return map[className]();
		}
		else
			return nullptr;
	}

private:
	map<string, CreateObjectPtr> map;
};

class Register 
{
	Register(const string& className, CreateObjectPtr method)
	{
		SingleTone<ClassFactory>::getInstance()->RegisterClass(className, method);
	}
};

IOtpSensor = (IOtpSensor*)SingleTone<Factory>::getInstance->getClassByName();