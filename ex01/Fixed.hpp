/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:35:58 by rhafidi           #+#    #+#             */
/*   Updated: 2026/01/09 18:53:26 by rhafidi          ###   ########.fr       */
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
    Fixed();
    Fixed(const int new_val);
    Fixed(const float new_val);
    float   toFloat(void) const;
    int     toInt(void) const;
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();
    int getRawBits(void) const;
    void    setRawBits(const int raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed &other);

#endif

