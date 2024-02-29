#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_7.2_REC/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestCreate)
		{
			// Arrange
			int k = 3, n = 4;
			int Low = 7, High = 65;
			int** a = new int* [k];
			for (int i = 0; i < k; i++)
				a[i] = new int[n];

			// Act
			Create(a, k, n, Low, High);

			// Assert
			for (int i = 0; i < k; i++)
				for (int j = 0; j < n; j++)
					Assert::IsTrue(a[i][j] >= Low && a[i][j] <= High);

			// Clean up
			for (int i = 0; i < k; i++)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(TestFindAndSwapMinMax)
		{
			// Arrange
			int k = 4, n = 5;
			int** a = new int* [k];
			for (int i = 0; i < k; i++)
				a[i] = new int[n];
			a[0][0] = 10; a[0][1] = 20; a[0][2] = 30; a[0][3] = 40; a[0][4] = 50;
			a[1][0] = 15; a[1][1] = 25; a[1][2] = 35; a[1][3] = 45; a[1][4] = 55;
			a[2][0] = 11; a[2][1] = 21; a[2][2] = 31; a[2][3] = 41; a[2][4] = 51;
			a[3][0] = 12; a[3][1] = 22; a[3][2] = 32; a[3][3] = 42; a[3][4] = 52;

			// Act
			FindAndSwapMinMax(a, k, n);

			// Assert
			Assert::AreEqual(50, a[0][0]);
			Assert::AreEqual(10, a[0][4]);
			Assert::AreEqual(51, a[2][0]);
			Assert::AreEqual(11, a[2][4]);

			// Clean up
			for (int i = 0; i < k; i++)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(TestFindMinMaxRecursive)
		{
			// Arrange
			int k = 3, n = 4;
			int** a = new int* [k];
			for (int i = 0; i < k; i++)
				a[i] = new int[n];
			a[0][0] = 10; a[0][1] = 20; a[0][2] = 30; a[0][3] = 40;
			a[1][0] = 15; a[1][1] = 25; a[1][2] = 35; a[1][3] = 45;
			a[2][0] = 11; a[2][1] = 21; a[2][2] = 31; a[2][3] = 41;

			int minValue, minCol, maxValue, maxCol;

			// Act
			minValue = a[0][0];
			minCol = 0;
			maxValue = a[0][0];
			maxCol = 0;
			FindMinMaxRecursive(a, k, n, 0, 0, minValue, minCol, maxValue, maxCol);

			// Assert
			Assert::AreEqual(10, minValue);
			Assert::AreEqual(0, minCol);
			Assert::AreEqual(40, maxValue);
			Assert::AreEqual(3, maxCol);

			// Clean up
			for (int i = 0; i < k; i++)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(TestSwap)
		{
			// Arrange
			int a = 5, b = 10;

			// Act
			Swap(a, b);

			// Assert
			Assert::AreEqual(10, a);
			Assert::AreEqual(5, b);
		}
	};
}
