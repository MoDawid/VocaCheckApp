#pragma once
class TXT : public sf::String, public sf::Text
{
private:
	sf::Text a_letter;
	sf::Text A_letter;
	sf::Text o_letter;
	sf::Text O_letter;
	sf::Text u_letter;
	sf::Text U_letter;
	sf::Text B_letter;

public:
	sf::Text a() { return a_letter; };
	sf::Text A() { return A_letter; };
	sf::Text o() { return o_letter; };
	sf::Text O() { return O_letter; };
	sf::Text u() { return u_letter; };
	sf::Text U() { return U_letter; };
	sf::Text B() { return B_letter; };

	TXT() 
	{ 
		a_letter.setString(L"ä");
		A_letter.setString(L"Ä");
		o_letter.setString(L"ö");
		O_letter.setString(L"Ö");
		u_letter.setString(L"ü");
		U_letter.setString(L"Ü");
		B_letter.setString(L"ß");
	};
};


	class CheatSheet : public sf::RectangleShape,  public TXT
{
private:
	sf::RectangleShape RectSheet;
	TXT de;
public:
	sf::RectangleShape getRectSheet() { return RectSheet; };
	void setSheetPosition(sf::Vector2u win_size);
	void setLettersPosition(); // tu moze da sie wyciagnac info z SetSheetPos, zeby latwiej inwokowac

	void setSheetSize(sf::Vector2f s) { RectSheet.setSize(s); };
	void setSheetColor(sf::Color c) { RectSheet.setFillColor(c); };
	void setSheetOutline(sf::Color c) { RectSheet.setOutlineColor(c); };
	void setSheetOutlineT(float i) { RectSheet.setOutlineThickness(i); };

	
	
	CheatSheet() 
	{ 
		this->setSheetSize(sf::Vector2f(100, 350)); 
		this->setSheetColor(sf::Color::Blue);
	//	this->setSheetPosition(sf::Vector2f(); // pobiera lokalizacje z deklaracji wind i odejmuje SheetSize
		this->setSheetOutline(sf::Color::White);
		this->setSheetOutlineT(2);
	}

};

	void CheatSheet::setSheetPosition(sf::Vector2u win_size)
	{
		//sf::Vector2u w_s = window.getSize();
		sf::Vector2i WinSize = sf::Vector2i(win_size);

		RectSheet.setPosition(WinSize.x - RectSheet.getSize().x - RectSheet.getOutlineThickness(),
			0 + RectSheet.getOutlineThickness());
			//WinSize.y - RectSheet.getSize().y - RectSheet.getOutlineThickness());
	}


	void CheatSheet::setLettersPosition()
	{
			
	}