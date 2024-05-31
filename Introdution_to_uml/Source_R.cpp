//#include <iostream>
//#include <conio.h>
//#include <Windows.h>
//#include <thread>
//using namespace std;
//
//#define Escape 27
//#define Enter 13
//
//#define min_tank_volume 20
//#define max_tank_volume 150
//const double max_consumption_per_second = 5.0;
//const double min_consumption_per_second = 0.0003;
//
//class Tank
//{
//private:
//	const int volume;// объем бака является его характеристикой
//	double fuel_level;//Уровень топлива отображает состояние бака
//public:
//	Tank(int volume) :
//		volume
//		(
//			volume < min_tank_volume ? min_tank_volume :
//			volume > max_tank_volume ? max_tank_volume :
//			volume
//		)
//	{
//		this->fuel_level = 0;
//		//cout << "Tank is ready " << this << endl;
//	}
//	//~Tank() { cout << "Tank is over " << this << endl; }
//	void info()const
//	{
//		cout << "Volume: " << this->volume << " liters" << endl;
//		cout << "Fuel level: " << get_fuel_level() << " liters" << endl;
//	}
//	int get_volume()const { return this->volume; }
//	double get_fuel_level() const { return this->fuel_level; }
//	void set_fuel_level(double amount)
//	{
//		if (amount < 0) { return; }
//		this->fuel_level += amount;
//		if (this->fuel_level > this->volume)
//			this->fuel_level = this->volume;
//	}
//	double give_fiel(double amount)
//	{
//		this->fuel_level -= amount;
//		if (this->fuel_level < 0)
//			this->fuel_level = 0;
//		return this->fuel_level;
//	}
//
//};
//
//class Engine
//{
//private:
//	bool is_started;
//	const double consumption_per_second;
//	double consumption;
//public:
//	void start_engine() { this->is_started = true; }
//	void stop_engine() { this->is_started = false; }
//	bool started() const { return this->is_started; }
//
//	Engine(double consumption_per_second, double consumption) :
//		consumption_per_second
//		(
//			consumption_per_second < min_consumption_per_second ? min_consumption_per_second :
//			consumption_per_second > max_consumption_per_second ? max_consumption_per_second :
//			consumption_per_second
//		)
//	{
//		this->is_started = false;
//		this->consumption = consumption;
//	}
//	//void consumption(double consumption)
//	//{
//	//	this->consumption = consumption;
//	//}
//
//	//мне кажется что расход топлива должен высчитываться на основание нажатого газа в моменте игры
//	double consumption1(double acceleration_percentage)
//	{
//		if (this->is_started == true)
//		{
//			if (acceleration_percentage <= 0)
//			{
//				return this->consumption_per_second;
//			}
//			else if (acceleration_percentage > 100)
//			{
//				acceleration_percentage = 100;
//			}
//			double a = consumption_per_second * (acceleration_percentage / 100) + consumption_per_second;
//			return a;
//		}
//		else
//		{
//			cout << "Двигатель заглушен" << endl;
//			return 0;
//		}
//
//	}
//};
//#define Max_speed_low_limit 120
//#define Max_speed_high_limit 400
//
//class Car
//{
//	Engine engine;
//	Tank tank;
//	int speed;
//	const int max_speed;
//	bool driver_inside;
//	struct
//	{
//		std::thread panel_thread;
//
//	}control_thread;
//public:
//	Car(int max_speed, double consumption, int volume) :engine(consumption, consumption), tank(volume),
//		max_speed(max_speed<Max_speed_low_limit ? Max_speed_low_limit : max_speed>Max_speed_high_limit ? Max_speed_high_limit : max_speed)
//	{
//		speed = 0;
//		driver_inside = false;
//		cout << "Car is ready" << endl;
//		cout << "Press enter to get in: " << endl;
//	}
//	~Car()
//	{
//		cout << "Car is over " << endl;
//	}
//	void control()
//	{
//		char key;
//		do
//		{
//			key = _getch();
//			switch (key)
//			{
//			case Enter: driver_inside ? get_out() : get_in();
//				break;
//			case Escape:
//				get_out();
//				break;
//			default:
//				break;
//			}
//		} while (key != Escape);
//	}
//
//	void get_in()
//	{
//		this->driver_inside = true;
//		//panel();
//		control_thread.panel_thread = std::thread(&Car::panel, this);
//	}
//	void get_out()
//	{
//		this->driver_inside = false;
//		if (control_thread.panel_thread.joinable())
//			control_thread.panel_thread.join();
//		system("CLS");
//		cout << "Вы вышли из машины" << endl;
//	}
//	void panel()
//	{
//		while (this->driver_inside)
//		{
//			system("CLS");
//			cout << "Speed: " << speed << " km/h" << endl;
//			cout << "Engine is " << engine.started() << endl;
//			cout << "Fuel level " << tank.get_fuel_level() << endl;
//			cout << "Consimption: " << engine.consumption1(0) << endl;
//			Sleep(200);
//		}
//	}
//	void info()const
//	{
//		tank.info();
//		cout << "Max speed: " << max_speed << " km" << endl;
//	}
//};
//
////#define TANK_CHECK
//
//void main()
//{
//	setlocale(LC_ALL, "");
//#if defined TANK_CHECK
//
//	// !1
//
//	Tank tank(3000);
//	Engine a(100.0, 1.0);
//	/*int fuel;
//	do
//	{
//		tank.info();
//		cout << "Введите объем топлива ";
//		cin >> fuel;
//		tank.set_fuel_level(fuel);
//	} while (fuel);*/
//	double acceleration_percentage;
//	a.start_engine();//заведем двигатель
//	if (a.started())
//	{
//		cout << "Двигатель - запущен" << endl;
//	}
//	else
//	{
//		cout << "Двигатель - заглушен" << endl;
//	}
//
//	do
//	{
//		cout << "Введите значение нажатия педали газа ";
//		cin >> acceleration_percentage;
//		cout << "Расход двигателя " << a.consumption1(acceleration_percentage) << endl;
//
//	} while (acceleration_percentage != -1);
//#endif
//
//	Car bmw(250, 10, 80);
//	//bmw.info();
//	bmw.control();
//}