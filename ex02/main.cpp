/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:35:49 by rhafidi           #+#    #+#             */
/*   Updated: 2025/12/30 15:27:51 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// int main( void ) {
//     Fixed const b( 1.2f );
//     Fixed a(1.3f);
//     std::cout << b.getRawBits() << '\n' << b << std::endl;
//     std::cout << a.getRawBits() << '\n' << a << std::endl;
//     if (a > b)
//     std::cout <<"a is larger\n";
//     if (b < a)
//     std::cout << "b is smaller \n";
//     if (a >= b)
//     std::cout << "a is larger or equal to b\n";
//     if (b <= a)
//     std::cout << "b is smaller or equal to a\n";
//     if (a == b)
//     std::cout << "a equals b \n";
//     if (a != b)
//     std::cout << "a differs from b\n";
    

//     std::cout << a+b << std::endl;
//     std::cout << a-b << std::endl;
//     std::cout << a*b << std::endl;
//     std::cout << a/b << std::endl;
//     std::cout << a++  << ' ' << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a--  << ' ' << std::endl;
//     std::cout << --a << std::endl;
//     std::cout << Fixed::min(a, b) << std::endl;
//     std::cout << Fixed::max(a, b) << std::endl;
// }

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}