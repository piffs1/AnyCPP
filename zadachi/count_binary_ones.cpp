/// Подсчет единичных битов. 
/// 1234 -> 10011010010 -> 5. Есть ещё решение через битсет.
/// https://www.codewars.com/kata/526571aae218b8ee490006f4
unsigned int countBits(unsigned long long n) {
	unsigned int nCount = 0;
	while (n) {
		nCount++;
		n = n & (n - 1);
	}
	return nCount;
	//your code here
}

int main()
{
	cout << countBits(1234);
}