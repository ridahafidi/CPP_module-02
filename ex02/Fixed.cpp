/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:46:37 by rhafidi           #+#    #+#             */
/*   Updated: 2025/12/30 15:33:58 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional = 8;

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this->value != other.value)
        this->value = other.value;
    // std::cout << "Copy assignement operator called" << std::endl;
    return *this;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits memeber function called" << std::endl;
    return value;
}

void    Fixed::setRawBits(const int raw)
{
    // std::cout << "setRawBits memebr function called" << std::endl;
    value = raw;
}

Fixed::Fixed(const int new_val)
{
    // std::cout << "Int constructor called" << std::endl;
    setRawBits(new_val << fractional);
}

Fixed::Fixed(const float new_val)
{
    // std::cout << "Float constructor called" << std::endl;
    int scale = 1 << fractional;
    int  rounded_value = (int)roundf(new_val * scale);
    value = rounded_value;
}

int Fixed::toInt(void) const
{
    return (value >> fractional);
}

float Fixed::toFloat(void) const
{
    int scale = 1 << fractional;
    return ((float)value / scale);
}

std::ostream& operator<<(std::ostream &os, const Fixed &other)
{
    os << other.toFloat();
    return os;
}


bool Fixed::operator>(const Fixed &other) const
{
    return (value > other.value);
}

bool Fixed::operator<(const Fixed &other) const
{
    return (value < other.value);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (value <= other.value);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (value >= other.value);
}

bool Fixed::operator==(const Fixed &other) const
{
    return (value == other.value);
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (value != other.value);
}

Fixed  Fixed::operator+(const Fixed &other) const
{
    Fixed res;
    res.setRawBits(value + other.value);
    return res;
}

Fixed  Fixed::operator-(const Fixed &other) const
{
    Fixed res;
    res.setRawBits(value - other.value);
    return res;
}

Fixed  Fixed::operator*(const Fixed &other) const
{
    Fixed res;
    long long tmp = (long long)value * (long long)other.value;
    tmp = tmp >> fractional;
    res.setRawBits((int)tmp);
    return res;
}

Fixed  Fixed::operator/(const Fixed &other) const
{
    Fixed res;
    long long tmp = ((long long)value << fractional) / (long long)other.value;
    res.setRawBits((int)tmp);
    return res;
}

Fixed  &Fixed::operator++()
{
    value += 1;
    return (*this);
}

Fixed  Fixed::operator++(int)
{
    Fixed temp = *this;
    operator++();
    return (temp);
}

Fixed  &Fixed::operator--()
{
    value -= 1;
    return (*this);
}

Fixed  Fixed::operator--(int)
{
    Fixed temp = *this;
    operator--();
    return (temp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return (a);
    return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return (a);
    return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return (a);
    return (b);
}