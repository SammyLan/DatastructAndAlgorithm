


int gcd(int x, int y) {
	return	y == 0 ? x : gcd(y, x%y);
}

int gcdForBigInt(int x, int y) {
	if (x < y) {
		return gcd(y, x);
	}
	if (y == 0) {
		return x;
	}
	return gcd(x - y, y);
}