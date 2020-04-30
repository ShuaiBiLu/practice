#pragma once
#include <Map>
#include <iostream>
using namespace std;

template<typename T>
class SingleTone
{
public:
	static T* getInstance()
	{
		if (nullptr == m_pInstance)
		{
			m_pInstance = new SingleTone();
		}
		
		return m_pInstance;
	}
private:
	static T* m_pInstance;
	SingleTone() {};
	SingleTone(const SingleTone&) {};
	SingleTone& operator=(const SingleTone&) {};
};

template<typename T>
T* SingleTone<T>::m_pInstance = NULL;

typedef void* (*CreateObjectPtr)(void);

class ClassFactory
{
public:
	void* getclassByName(string className)
	{
		if (m_classMap.count(className))
		{
			return m_classMap[className]();
		}
		else
		{
			return nullptr;
		}
	}
	
	void registerClass(string name, CreateObjectPtr method)
	{
		if (!m_classMap.count(name))
		{
			m_classMap.insert(pair<string, CreateObjectPtr>(name, method));
		}
	}

private:
	map<string, CreateObjectPtr> m_classMap;
};

class Register
{
public:
	Register(const string& className, CreateObjectPtr funPtr) 
	{
		SingleTone<ClassFactory>::getInstance()->registerClass(className, funPtr);
	}
};

#define REGISTER_OTPSENSOR(ClassName)\
	Register Register##ClassName(#ClassName, (CreateObjectPtr)(SingleTone<ClassName>::getInstance))

