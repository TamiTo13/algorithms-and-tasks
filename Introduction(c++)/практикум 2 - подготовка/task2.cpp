#include <iostream>

bool isSubNumber(int bigger, int smaller)
{
	if (bigger == smaller || smaller == 0)
		return true;

	if (bigger == 0)
		return false;

	int biggerDigit = bigger % 10;
	int smallerDigit = smaller % 10;

	if (biggerDigit == smallerDigit)
		return isSubNumber(bigger / 10, smaller / 10);

	return isSubNumber(bigger / 10, smaller);
}

bool solve(int number1, int number2) // Wrapper function
{
	if (number1 > number2)
		return isSubNumber(number1, number2);
	
	return isSubNumber(number2, number1);
}




int main()
{
	std::cout << solve( 1025      , 125       ) << '\n';
	std::cout << solve( 123       , 12345     ) << '\n';
	std::cout << solve( 13        , 125       ) << '\n';
	std::cout << solve( 919293949	, 1234      ) << '\n';
	std::cout << solve( 1234      , 919293949	) << '\n';

	return 0;
}