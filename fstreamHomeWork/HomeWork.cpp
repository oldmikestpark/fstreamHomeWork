#include "HomeWork.h"
HomeWork hw;

int main() 
{
	do
	{
		oldmike::print("(l)oad (s)ave (a)dd (q)uit or (p)rint?\n");

		char mission = _getch();
		switch (mission) 
		{
		case 'a':
			hw.Add();
			break;
		case 'p':
			if (hw.n != 0)
			{
				hw.PrintChart();
			}
			else
			{
				hw.PrintLoad(hw.loadName);
			}
			break;
		case 's':
			oldmike::print("\nEnter file name: ");

			char fileName[256];
			oldmike::read(fileName, 256);

			hw.Save(fileName);

			_putch('\n');
			break;
		case 'l':
			oldmike::print("\nEnter file name: ");

			oldmike::read(hw.loadName, 256);
			oldmike::print("\n");
			break;
		}
	} while (!(_getch() == 'q'));

	while (!_kbhit());
	return 0;
}

void HomeWork::Add() const
{
	oldmike::print("\nEnter name: ");
	oldmike::read(hw.name[hw.n], 256);

	oldmike::print("\nEnter value: ");
	oldmike::read(hw.value[hw.n], 256);

	oldmike::print("\n\n");
	++hw.n;
}

void HomeWork::PrintChart() const
{
	oldmike::print("\n     Beautiful Chart Bitches!\n");
	oldmike::print("       ------------------------\n\n\n");
	for (int i = 0; i < hw.n; ++i)
	{
		oldmike::print(hw.name[i]);
		oldmike::print("   |");
		int number = oldmike::str2int(hw.value[i]);
		for (int i = 0; i < number; ++i)
		{
			_putch('=');
		}
		oldmike::print("\n");
	}
}

void HomeWork::Save(char* fileName)
{
	std::ofstream out(fileName);
	out.write("\n     Beautiful Chart Bitches!\n       ------------------------\n\n\n", 66);
	for (int i = 0; i < hw.n; ++i) 
	{
		out.write(hw.name[i], sizeof(hw.name[i]));
		out.write("   |", 5);
		int number = oldmike::str2int(hw.value[i]);
		for (int i = 0; i < number; ++i)
		{
			out.put('=');
		}
		out.put('\n');
	}
}

void HomeWork::PrintLoad(char* loadName) const
{
	std::ifstream in(loadName);
	for (char c = in.get(); in.good(); c = in.get()) 
	{
		_putch(c);
	}
}


