#include "pch.h"
#include "CppUnitTest.h"
#include "D:\Загрузки\Visual Studio\Project\ConsoleApplication9\ConsoleApplication9\ConsoleApplication9.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(calculate_Test1) //Unit тести для функції calculate
	{
	public:

		TEST_METHOD(calculate_get1and5_minus9returned) //перевірка при x=1, n=5 з помилкою
		{
			double x = 1;
			int n = 5;
			double expected = 3456; //невірне значення
			double actual = calculate1(x, n);
			Assert::AreEqual(expected, actual); 
		}
		TEST_METHOD(calculate_get2and3_returned2) //перевірка при x=2, n=3
		{
			double x = 2;
			int n = 3;
			double expected = -1;
			double actual = calculate1(x, n);
			Assert::AreEqual(expected, actual);
		}
	};
	TEST_CLASS(checkValidParams_Test2)//Unit тести для функції checkValidParams
	{
	public:

		TEST_METHOD(checkValidParams_get5and1and2and6_exceptionNotThrown)//перевірка з помилкою 
		{
			int n = 5;
			double h = -1, a = 7, b = 6; //помилкові данні вірні
			try
			{
				checkValidParams(n, h, a, b);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
		TEST_METHOD(checkValidParams_get5and0and2and6_exceptionNotThrown)//перевірка даних (h=0)
		{
			int n = 5;
			double h = 0, a = 2, b = 6;
			try
			{
				checkValidParams(n, h, a, b);
				Assert::Fail();
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
	};
}
