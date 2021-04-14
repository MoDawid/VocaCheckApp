#pragma once

void setDefText(sf::Text * a, sf::Font * b)
{
	a->setFont(*b);
	a->setCharacterSize(24);
	a->setFillColor(sf::Color::Green);

	std::cout << "Default String Values set." << std::endl;
}

sf::Vector2f MousePosition_2f(sf::Mouse m_acces)
{
	sf::Vector2i m_loci = m_acces.getPosition();
	sf::Vector2f m_locf = sf::Vector2f(m_loci);

	return m_locf;
}




bool isWithinBordersRect(sf::RectangleShape rect, sf::Mouse m_acces, sf::Vector2i w_pos)
{
	sf::FloatRect bounds = rect.getGlobalBounds();

	sf::Vector2f m_position = MousePosition_2f(m_acces);
	sf::Vector2f w_position = sf::Vector2f(w_pos);


	if ((m_position.x - 10) - w_pos.x >= bounds.left &&
		(m_position.x - 10) - w_pos.x <= bounds.left + bounds.width)
	{

		if ((m_position.y - w_pos.y) - 45 >= bounds.top &&
			(m_position.y - w_pos.y) - 45 <= bounds.top + bounds.height)
		{
			std::cout << "Button clicked" << std::endl;
		}
		return 1;

	}
	else
		std::cout << "x not correct" << std::endl;
	return 0;
}

void ButtonClicked(sf::RectangleShape *Shape, sf::RectangleShape &ShapeCopy, sf::Color color, bool &isOn)
{
	isOn = 1;
	ShapeCopy = *Shape;

	(*Shape).setFillColor(color);
	Shape->setOutlineColor(sf::Color::White);
	Shape->setOutlineThickness(2);

	std::cout << "ButtonClicked done " << std::endl;
}

void ButtonClickedOff(sf::RectangleShape *Shape, sf::RectangleShape ShapeCopy, bool &isOn)
{
	isOn = 0;
	*Shape = ShapeCopy;
	std::cout << "Button clicked off : " << std::endl;
}

void addFrame(int &FrameCount, bool isOn)
{
	if (isOn)
	{
		FrameCount++;
	}

}

bool isFramesPassed(int &FrameCount, int Num)
{
	if (FrameCount >= Num)
	{
		FrameCount = 0;
		return 1;
	}
	else
		return 0;
}






/*
void setDefTextArray(sf::Text* a, sf::Font *b)
{
	int i = 0;
	for (i = 0; i <= 99; i++)
	{
		a->setFont(*b);
		a->setCharacterSize(24);
		a->setFillColor(sf::Color::Green);
		a++;
	}
	std::cout << "Default String Values for TextArray set for " << i << std::endl;
}

void setDefStringArray(std::string* a)
{
	int i = 0;
	for (i = 0; i <= 99; i++)
	{

	}
	std::cout << "Default String Values for TextArray set for " << i << std::endl;
}

void TextArray_Pushback(sf::Text arr[], sf::Text pushed, int *counter)
{
	arr[*counter].setString(pushed.getString());
	std::cout << *counter << "pushed " << std::endl;
	(*counter)++;
}

sf::Text TextArray_Letter(sf::Text arr[], int *letter_num)
{
	arr[*letter_num].getString();
	return arr[*letter_num];
}



*/
