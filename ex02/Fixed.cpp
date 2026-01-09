/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:46:37 by rhafidi           #+#    #+#             */
/*   Updated: 2026/01/09 19:00:48 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional = 8;

Fixed::Fixed():value(0){}

Fixed::Fixed(const Fixed &other):value(other.value){}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this->value != other.value)
        this->value = other.value;
    return *this;
}

Fixed::~Fixed(){}

int Fixed::getRawBits(void) const
{
    return value;
}

void    Fixed::setRawBits(const int raw)
{
    value = raw;
}

Fixed::Fixed(const int new_val)
{
    setRawBits(new_val << fractional);
}

Fixed::Fixed(const float new_val)
{
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