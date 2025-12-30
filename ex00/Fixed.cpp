/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:46:37 by rhafidi           #+#    #+#             */
/*   Updated: 2025/12/30 15:37:08 by rhafidi          ###   ########.fr       */
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