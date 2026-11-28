#include "myCompany/employee.h"

#include <iostream>
#include <stdexcept>
#include <string>

namespace {
const double extraBonus            = 1000.0;
const int    yearsExpForExtraBonus = 10;
} // namespace

namespace myCompany {
Employee::Employee(const std::string& name, unsigned int age, double baseSalary,
                   unsigned int numberYearsEmployed, double basicBonus)
    : m_name(name)
    , m_age(age)
    , m_baseSalary(baseSalary)
    , m_numberYearsEmployed(numberYearsEmployed)
    , m_basicBonus(basicBonus)
    , m_netBonus(0)
    , m_taxAmount(0)
    , m_netSalary(0)
{
    calcNetBonus();
    calcTaxAmount();
    calcNetSalary();
}

void Employee::setName(const std::string& name)
{
    if (name.empty())
    {
        throw std::invalid_argument("Name cannot be empty");
    }
    m_name = name;
}

void Employee::setAge(unsigned int age)
{
    m_age = age;
}

void Employee::setBaseSalary(double baseSalary)
{
    m_baseSalary = baseSalary;

    // Calculate new tax based on new base salary
    calcTaxAmount();

    // Changing base salary will change net salary.
    calcNetSalary();
}

void Employee::setNumberYearsEmployed(unsigned int numberYearsEmployed)
{
    m_numberYearsEmployed = numberYearsEmployed;

    // Changing number of years employed will change net bonus.
    calcNetBonus();

    // Get the new tax.
    calcTaxAmount();

    // Changing net bonus will change net salary.
    calcNetSalary();
}

void Employee::setBasicBonus(double basicBonus)
{
    m_basicBonus = basicBonus;

    // Changing basic bonus will change net bonus.
    calcNetBonus();

    // Get the new tax.
    calcTaxAmount();

    // Changing net bonus will affect net salary.
    calcNetSalary();
}

// Employee gets additional £1000 bonus if they have been employed for more than 10 years.
void Employee::calcNetBonus()
{
    if (m_numberYearsEmployed > yearsExpForExtraBonus)
    {
        m_netBonus = m_basicBonus + extraBonus;
    }
    else
    {
        m_netBonus = m_basicBonus;
    }
}

void Employee::calcTaxAmount()
{
    double salary_with_bonus = m_baseSalary + m_netBonus;
    if (salary_with_bonus <= 10000)
    {
        m_taxAmount = 0.0;
    }
    else if (salary_with_bonus > 10000 && salary_with_bonus <= 20000)
    {
        m_taxAmount = 0.1 * (salary_with_bonus - 10000);
    }
    else if (salary_with_bonus > 20000 && salary_with_bonus <= 50000)
    {
        m_taxAmount = 0.1 * 10000 + 0.2 * (salary_with_bonus - 20000);
    }
    else if (salary_with_bonus > 50000)
    {
        m_taxAmount = 0.1 * 10000 + 0.2 * 30000 + 0.5 * (salary_with_bonus - 50000);
    }
}

void Employee::calcNetSalary()
{
    m_netSalary = m_baseSalary + m_netBonus - m_taxAmount;
}

const std::string& Employee::getName() const
{
    return m_name;
}

unsigned int Employee::getAge() const
{
    return m_age;
}

double Employee::getBasicSalary() const
{
    return m_baseSalary;
}

unsigned int Employee::getNumberYearsEmployed() const
{
    return m_numberYearsEmployed;
}

double Employee::getBasicBonus() const
{
    return m_basicBonus;
}

double Employee::getNetBonus() const
{
    return m_netBonus;
}

double Employee::getTaxAmount() const
{
    return m_taxAmount;
}

double Employee::getNetSalary() const
{
    return m_netSalary;
}

void Employee::displayInfo() const
{
    std::cout << "Name: " << m_name << std::endl;
    std::cout << "Age: " << m_age << std::endl;
    std::cout << "Base_Salary: £" << m_baseSalary << std::endl;
    std::cout << "Number of Years Employed: " << m_numberYearsEmployed << std::endl;

    std::cout << "Basic_Bonus: £" << m_basicBonus << std::endl;
    std::cout << "Net_Bonus: £" << m_netBonus << std::endl;

    std::cout << "Tax to be paid: £" << m_taxAmount << std::endl;
    std::cout << "Net_Salary: £" << m_netSalary << std::endl;
}

} // namespace MyCompany
