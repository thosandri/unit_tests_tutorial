#include <gtest/gtest.h>
#include <myCompany/employee.h>

class EmployeeFixture : public ::testing::Test
{
public:
    myCompany::Employee employee { "Jhon Doe", 25, 45000.0, 8, 1500.0 };
};

TEST_F(EmployeeFixture, CanSetName)
{
    employee.setName("John Doe");
    EXPECT_EQ(employee.getName(), "John Doe");
}

TEST_F(EmployeeFixture, CanSetAge)
{
    employee.setAge(35);
    EXPECT_EQ(employee.getAge(), 35);
}
