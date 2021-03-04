#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

#include "super_alg.hpp"

class SuperAlgTest : public CppUnit::TestCase {
public:
    void additionCheck() {
        // Складываем два длинных числа.
        {
            super_alg::int100500_t num1; num1.Initialize("100000");
            super_alg::int100500_t num2; num2.Initialize("500");

            super_alg::int100500_t res = num1 + num2;
            super_alg::int100500_t expected; expected.Initialize("100500");
            CPPUNIT_ASSERT_EQUAL_MESSAGE("Failed to add two long numbers", expected, res );
        }

        // Складываем длинное число с нулём.
        {
            super_alg::int100500_t num1; num1.Initialize("100500");
            super_alg::int100500_t num2; num2.Initialize("0");

            super_alg::int100500_t res = num1 + num2;
            super_alg::int100500_t expected; expected.Initialize("100500");
            CPPUNIT_ASSERT_EQUAL_MESSAGE("Failed to add two long numbers", expected, res );
        }
    }

    void subsctractCheck()
    {
        // Классический тест, проверяющий, базовое вычитание.
        {
            super_alg::int100500_t num1; num1.Initialize("101000");
            super_alg::int100500_t num2; num2.Initialize("500");

            super_alg::int100500_t res = num1 - num2;
            super_alg::int100500_t expected; expected.Initialize("100500");
            CPPUNIT_ASSERT_EQUAL_MESSAGE("Failed to subsctract two long numbers", expected, res );
        }

        // Проверяем, что разница двух одинаковых чисел это ноль.
        {
            super_alg::int100500_t num1; num1.Initialize("100500");
            super_alg::int100500_t num2; num2.Initialize("100500");

            super_alg::int100500_t res = num1 - num2;
            super_alg::int100500_t expected; expected.Initialize("0");
            CPPUNIT_ASSERT_EQUAL_MESSAGE("Failed to subsctract two long numbers", expected, res );
        }
    }

    void equalCheck()
    {
        // Проверяем оператор равенство для двух чисел.
        {
            super_alg::int100500_t num1; num1.Initialize("100500");
            super_alg::int100500_t num2; num2.Initialize("100500");

            CPPUNIT_ASSERT_MESSAGE("Failed to compare(=) two long numbers", num1 == num2 );
        }

        // Проверяем оператор равенство для двух чисел.
        {
            super_alg::int100500_t num1; num1.Initialize("100500");
            super_alg::int100500_t num2; num2.Initialize("100501");

            CPPUNIT_ASSERT_MESSAGE("Failed to compare(!=) two long numbers", !(num1 == num2) );
        }
    }

    CPPUNIT_TEST_SUITE( SuperAlgTest );
    CPPUNIT_TEST( additionCheck );
    CPPUNIT_TEST( subsctractCheck );
    CPPUNIT_TEST( equalCheck );
    CPPUNIT_TEST_SUITE_END();
};

CPPUNIT_TEST_SUITE_REGISTRATION ( SuperAlgTest );

int main ()
{
    CppUnit::Test *test =
    CppUnit::TestFactoryRegistry::getRegistry().makeTest();
    CppUnit::TextTestRunner runner;
    runner.addTest(test);

    runner.run();
    return 0;
}
