#include "HomeWork.h"

int main() 
{
	HomeWork hw;

	do
	{
		oldmike::print("(l)oad (s)ave (a)dd (q)uit or (p)rint?\n");

		char name[256][20];
		char value[256][sizeof(int)];
		
		if (_getch() == 'a') 
		{
			oldmike::print("\nEnter name: ");
			oldmike::read(name[hw.n], 256);
			
			oldmike::print("\nEnter value: ");
			oldmike::read(value[hw.n], 256);
			
			oldmike::print("\n\n");
			++hw.n;
		}
		else if (_getch() == 'p') 
		{
			oldmike::print("\n     Beautiful Chart Bitches!\n");
			oldmike::print("       ------------------------\n\n\n");
			for (int i = 0; i < hw.n; ++i)
			{
				oldmike::print(name[i]);
				oldmike::print("   |");
				int number = oldmike::str2int(value[i]);
				for (int i = 0; i < number; ++i)
				{
					_putch('=');
				}
				oldmike::print("\n");
			}
		}
	} while (!(_getch() == 'q'));

	while (!_kbhit());
	return 0;
}
