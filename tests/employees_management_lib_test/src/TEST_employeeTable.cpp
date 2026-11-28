#include "myCompany/employeeTable.h"

#include <gtest/gtest.h>
#include <sstream>

class EmployeeTableTest : public ::testing::Test
{
public:
    myCompany::EmployeeTable table;
};

TEST_F(EmployeeTableTest, EmployeeTableIsEmptyAtCreation)
{
    EXPECT_TRUE(table.isEmpty());
}

TEST_F(EmployeeTableTest, EmployeeTableHasZeroSizeAtCreation)
{
    EXPECT_EQ(table.getEntryCount(), 0);
}

class EmployeeTableWithOneEmployee : public ::testing::Test
{
public:
    myCompany::EmployeeTable table;

    void SetUp() override
    {
        employee = new myCompany::Employee("Jhon Doe", 25, 45000.0, 8, 1500.0);
        table.addEmployee(*employee);
    }

    void TearDown() override { delete employee; }

private:
    myCompany::Employee* employee;
};

TEST_F(EmployeeTableWithOneEmployee, EmployeeTableIsNotEmpty)
{
    EXPECT_FALSE(table.isEmpty());
}

TEST_F(EmployeeTableWithOneEmployee, EmployeeTableHasOneEntry)
{
    EXPECT_EQ(table.getEntryCount(), 1);
}

class EmployeeTableForDisplayingTest : public ::testing::Test
{
public:
    myCompany::EmployeeTable table;
    std::stringstream        expectedDisplayemployees;

    void SetUp() override
    {
        myCompany::Employee john("Jhon Doe", 25, 45000.0, 8, 1500.0);
        myCompany::Employee homer("Homer simpson", 42, 32000.0, 5, 0.0);
        myCompany::Employee alberto("Alberto Pinto", 60, 72000.0, 20, 2500.0);

        table.addEmployee(john);
        table.addEmployee(homer);
        table.addEmployee(alberto);

        expectedDisplayemployees << "-------------------------------------------------- \n";
        expectedDisplayemployees << john.getName() << std::endl;
        expectedDisplayemployees << homer.getName() << std::endl;
        expectedDisplayemployees << alberto.getName() << std::endl;

        expectedDisplayemployees << "-------------------------------------------------- \n";
    }

private:
    myCompany::Employee* employee;
};

TEST_F(EmployeeTableForDisplayingTest, EmployeeTableDisplaySeveralEmployees)
{
    std::stringstream ss;
    table.displayEmployeesName(ss);

    EXPECT_EQ(ss.str(), expectedDisplayemployees.str());
}