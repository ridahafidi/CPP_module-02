/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:46:37 by rhafidi           #+#    #+#             */
/*   Updated: 2026/01/09 18:53:30 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional = 8;

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this->value != other.value)
        this->value = other.value;
    std::cout << "Copy assignement operator called" << std::endl;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits memeber function called" << std::endl;
    return value;
}

void    Fixed::setRawBits(const int raw)
{
    std::cout << "setRawBits memebr function called" << std::endl;
    value = raw;
}

Fixed::Fixed(const int new_val)
{
    std::cout << "Int constructor called" << std::endl;
    setRawBits(new_val << fractional);
}

Fixed::Fixed(const float new_val)
{
    std::cout << "Float constructor called" << std::endl;
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

Fixed::Fixed():value(0)
{
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &other):value(other.value)
{
    std::cout << "Copy constructor called" << std::endl;
}
