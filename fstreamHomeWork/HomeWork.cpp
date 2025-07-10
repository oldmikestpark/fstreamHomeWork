#include <conio.h>
#include <fstream>

namespace oldmike
{
	void print(const char* s)
	{
		for (; *s != 0; s++)
		{
			_putch(*s);
		}
	}

	void read(char* s, int maxSize)
	{
		const char* const pEnd = s + maxSize;
		for (char c = _getch(); c != 13 && (s + 1 < pEnd); c = _getch(), s++)
		{
			_putch(c);
			*s = c;
		}
		*s = 0;
	}

	int Fibonacci(const int n)
	{
		int arr[2] = { 1, 1 };
		int* p = arr;
		int result = 0;

		if (n == 0)
		{
			return result = 0;
		}
		else if (n == 1 || n == 2)
		{
			return result = 1;
		}

		for (int i = 3; i <= n; ++i)
		{
			if (i % 2 == 1)
			{
				*p = arr[0] + arr[1];
				result = *p;
				p++;
			}
			else if (i % 2 == 0)
			{
				*p = arr[0] + arr[1];
				result = *p;
				p--;
			}
		}
		return result;
	}

	int str2int(const char* s)
	{
		const char* p = s;
		for (; *p >= '0' && *p <= '9'; p++);
		p--;

		int val = 0;
		int place = 1;

		for (; p >= s; p--)
		{
			val += place * (*p - '0');
			place *= 10;
		}

		return val;
	}

	void strrev(char* pl)
	{
		char* pr = pl;
		for (; *pr != 0; pr++);
		pr--;
		for (; pl < pr; --pr, ++pl)
		{
			const char temp = *pl;
			*pl = *pr;
			*pr = temp;
		}
	}

	void int2str(int val, char* buf, int size)
	{
		char* const pStart = buf;
		char* const pEnd = buf + size;
		for (; val > 0 && (buf + 1 < pEnd); val /= 10, ++buf)
		{
			*buf = '0' + val % 10;
		}
		*buf = 0;
		strrev(pStart);
	}
}

int main() 
{
	do
	{
		oldmike::print("(l)oad (s)ave (a)dd (q)uit or (p)rint?\n");

		if (_getch() == 'a') 
		{
			oldmike::print("\nEnter name: ");
			char name[256];
			oldmike::read(name, 256);
			
			oldmike::print("\nEnter value: ");
			char value[256];
			oldmike::read(value, 256);
			
			oldmike::print("\n\n");
		}
	} while (!(_getch() == 'q'));

	while (!_kbhit());
	return 0;
}