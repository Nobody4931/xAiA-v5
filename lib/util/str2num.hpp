#pragma once


#include <cstdint>
#include <string>


template< typename T >
inline T str_to_int( const std::string& string ) {
	T integer = 0;

	auto iter = string.begin();
	auto end = string.end();

	bool negative = *iter == '-';
	if ( negative ) ++iter;

	for ( ; iter != end; ++iter )
		integer = ( integer * 10 ) + ( *iter - '0' );

	if ( negative )
		integer *= -1;

	return integer;
}

template< typename T >
inline T str_to_num( const std::string& string ) {
	int64_t number = 0;
	int64_t decimal = 0;
	int64_t places = 1;

	auto iter = string.begin();
	auto end = string.end();

	bool negative = *iter == '-';
	if ( negative ) ++iter;

	bool passed = false;
	for ( ; iter != end; ++iter ) {
		if ( *iter == '.' ) {
			passed = true;
			continue;
		}

		char char_number = *iter - '0';
		if ( passed == false ) {
			number = ( number * 10 ) + char_number;
		} else {
			decimal = ( decimal * 10 ) + char_number;
			places *= 10;
		}
	}

	if ( negative ) {
		number *= -1;
		decimal *= -1;
	}

	return static_cast<T>( number ) +
		static_cast<T>( decimal ) / static_cast<T>( places );
}
