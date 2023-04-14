#include "Hetman.h"


Hetman::Hetman(Pole p, int w)
	:Figura(p, w, "Hetman"),
	w_size(w)
{
	if (p.get_czesc_planszy() == 0)
		t.loadFromFile("images/hetman_b.png");
	else if (p.get_czesc_planszy() == 1)
		t.loadFromFile("images/hetman_c.png");
	else
		t.loadFromFile("images/hetman_r.png");
	s.setTexture(t);
	s.setScale(w_size * 0.0004, w_size * 0.0004);
	s.setOrigin(t.getSize().x * 0.5, t.getSize().y / 2);
	s.setPosition(p.get_wx(), p.get_wy());
}

void Hetman::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->s);
}

sf::Sprite Hetman::get_sprite()
{
	return s;
}

void Hetman::set_position(float wx, float wy)
{
	s.setPosition(wx, wy);
}

void Hetman::set_polozenie(Pole p)
{
	s.setPosition(p.get_wx(), p.get_wy());
	set_pole(p);
}