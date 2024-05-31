#include <iostream>
#include<thread>

using namespace std;
using namespace std::chrono_literals;
bool finich = false;
void Plus()
{
	while (!finich)
	{
		cout << "+ ";
		this_thread::sleep_for(1s);
	}
}void Minus()
{
	while (!finich)
	{
		cout << "- ";
		this_thread::sleep_for(1s);
	}
}
void main()
{
	setlocale(LC_ALL, "");
	//Plus();
	//Minus();
	thread plus_thread(Plus);
	thread minus_thread(Minus);

	cin.get();
	finich = true;

	if(minus_thread.joinable())
		minus_thread.join();
	if(plus_thread.joinable())
		plus_thread.join();
	
}