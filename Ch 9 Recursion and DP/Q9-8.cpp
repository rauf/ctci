#include<iostream>

int change(int amount, int denom) {

	int next = 0;

	switch(denom) {
		case 25:
			next = 10;
			break;

		case 10:
			next = 5;
			break;

		case 5:
			next = 1;
			break;

		case 1:
			return 1;
	}

	int ways = 0;

	for (int i = 0; i * denom <= amount; ++i) {
		ways += change(amount - i *denom, next);
	}

	return ways;
}

int main() {

	int n = 10000;
	std::cout << "\nNumber of ways for n = " << n << "  " << change(n, 25) << std::endl;

}