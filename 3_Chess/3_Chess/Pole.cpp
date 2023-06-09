#include "Pole.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <cstdlib>

#define M_PI 3.14159265358979323846

bool Pole::operator ==(const Pole& a)
{
	if (czesc_planszy==a.czesc_planszy && x == a.x && y == a.y)
		return true;
	else
		return false;
}

bool Pole::operator !=(const Pole& a)
{
	if (czesc_planszy != a.czesc_planszy || x != a.x || y != a.y)
		return true;
	else
		return false;
}


Pole::Pole(int _x, int _y, int _czesc_planszy, int _srodek_szachownicy_x, int _srodek_szachownicy_y, float _rozmiar_szachownicy)
	:x(_x),
	y(_y),
	czesc_planszy(_czesc_planszy),
	srodek_szachownicy_x(_srodek_szachownicy_x),
	srodek_szachownicy_y(_srodek_szachownicy_y),
	rozmiar_szachownicy(_rozmiar_szachownicy)
{
		if (x>3)
		{
			wy = srodek_szachownicy_y - rozmiar_szachownicy * (0.105*(y+1) - 0.47 - 0.013 * (x-3.5 ) * (y +0.5));  
			wx = srodek_szachownicy_x + rozmiar_szachownicy * ((x-3)*0.06-0.03+ 0.0075 * (x - 3.5) * (y + 0.5));

		}
		else
		{
			wy = srodek_szachownicy_y - rozmiar_szachownicy * (0.105 * (y + 1) - 0.47 - 0.013 * (3-x +0.5) * (y + 0.5));
			wx = srodek_szachownicy_x - rozmiar_szachownicy * ((3-x +1) * 0.06 - 0.03 + 0.0075 * (3-x +0.5) * (y + 0.5));
		}
		if (czesc_planszy == 1)
		{
			float pwx = wx;
			wx = (wx-srodek_szachownicy_x) * cos(M_PI *0.66666) - (srodek_szachownicy_y-wy) * sin(M_PI * 0.66666)+srodek_szachownicy_x+ 0.005 * rozmiar_szachownicy;
			wy = srodek_szachownicy_y-(pwx - srodek_szachownicy_x) * sin(M_PI * 0.66666) - (srodek_szachownicy_y - wy) * cos(M_PI * 0.66666)- 0.01 * rozmiar_szachownicy;
			if (y < 3)
			{
				if(x>3)
					pole_tab = std::string() + (char)('E' + x) + '1' + (char)('2' - y);
				else
					pole_tab = std::string() + (char)('H' - x) + '1' + (char)('2' - y);
			}
			else
			{
				if (x > 3)
					pole_tab = std::string() + (char)('E' + x)  + '9';
				else
					pole_tab = std::string() + (char)('H' - x)  + '9';
			}
		}
		else if (czesc_planszy == 2)
		{
			float pwx = wx;
			wx = (wx - srodek_szachownicy_x) * cos(M_PI * 1.333333) - (srodek_szachownicy_y - wy) * sin(M_PI * 1.333333) + srodek_szachownicy_x - 0.005 * rozmiar_szachownicy;
			wy = srodek_szachownicy_y - (pwx - srodek_szachownicy_x) * sin(M_PI * 1.333333) - (srodek_szachownicy_y - wy) * cos(M_PI * 1.333333) - 0.01 * rozmiar_szachownicy;
			if (x > 3)
				pole_tab = std::string() + (char)('H' - x) + (char)('8' - y);
			else
				pole_tab = std::string() + (char)('L' - x) + (char)('8' - y);
		}
		else
			pole_tab= std::string() + (char)('A' + x) + (char)('1'+y);
}

int Pole::get_x()
{
	return x;
}
int Pole::get_y()
{
	return y;
}
float Pole::get_wx()
{
	return wx;
}
float Pole::get_wy()
{
	return wy;
}

int Pole::get_czesc_planszy()
{
	return czesc_planszy;
}

void Pole::set_position(float x, float y)
{
	wx = x;
	wy = y;
}

std::string Pole::get_pole_tab()
{
	return pole_tab;
}