/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:35:58 by rhafidi           #+#    #+#             */
/*   Updated: 2025/12/30 15:33:58 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
private:
    int value;
    static const int fractional;
public:
    Fixed():value(0){};
    Fixed(const int new_val);
    Fixed(const float new_val);
    float   toFloat(void) const;
    int     toInt(void) const;
    Fixed(const Fixed &other):value(other.value){};
    Fixed &operator=(const Fixed &other);
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;
    Fixed  operator+(const Fixed &other) const;
    Fixed  operator-(const Fixed &other) const;
    Fixed  operator*(const Fixed &other) const;
    Fixed  operator/(const Fixed &other) const;
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
    Fixed  &operator++();
    Fixed  operator++(int);
    Fixed  &operator--();
    Fixed  operator--(int);
    ~Fixed();
    int getRawBits(void) const;
    void    setRawBits(const int raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed &other);

#endif