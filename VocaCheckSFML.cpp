#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include <SFML/Graphics.hpp>

#include "VocaCheckSFML.h"
#include "CheatSheet.h"

// within bound nie dziala
// isWithin

class TxT : public sf::Text
{
private:
	sf::String txt;

public:



};




using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600, 12), "Title", sf::Style::Default);
	window.setFramerateLimit(60); // fps matching to monitor hz
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	int FrameCount = 0;
	bool isOn = false;
	sf::Text fromfile;
	sf::String fromfileS;

	
	
	CheatSheet TipSheet;
	TipSheet.setSheetPosition(window.getSize());
	

	sf::Text kk;
	kk = TipSheet.B();
	kk.setPosition(sf::Vector2f(50, 50));
	kk.setFillColor(sf::Color::Red);
	
	//kk.setString(test.a());
	



	sf::Event event;
	sf::Font MyFont;
	sf::Uint32 MyCharset[] = { 0x00E4, 0x00C4, 0x00C9, 0x00F6, 0x00D6, 0x00FC, 0x00DC, 0x00DF };
	//						ä		Ä		é		ö		Ö		ü		Ü		ß
	//					   0228	   0196    0233    0246    0214    0252    0220	  0223
	if (!MyFont.loadFromFile("../Resources/arial.ttf"))
	{
		cout << "Error while loading font." << endl;
		cout << "Font not found." << endl;
	}
	else
		cout << "Fonts loaded correctly." << endl;

	fromfile.setFont(MyFont);
	kk.setFont(MyFont);

	fromfile.setFillColor(sf::Color::Yellow);
	fromfile.setPosition(sf::Vector2f(250, 250));

	wfstream newfile;
	newfile.open("../Resources/wordlist.txt", ios::in);
	if (newfile.is_open() == 1)
	{
		cout << "Wordlist loaded ! " << endl;
		wchar_t ch;
		wstring strings = L"ó";
		while (1) {
			newfile >> ch;
			if (newfile.eof())
				break;
			fromfileS.insert(fromfileS.getSize(), ch);
			
		}
		sf::String ss = fromfileS;
		fromfile.setString(ss);
		// fromfile.setString(strings); dziala 
	}
	else
	{cout << "Wordlist not loaded! " << endl;}

	sf::String s_Backspace;
	s_Backspace.insert(s_Backspace.getSize(), "\u0008");
	sf::String input;
	

	sf::Mouse Mouse_Acces;
	sf::Vector2i MousePosition = Mouse_Acces.getPosition();

	sf::Text testowy;
	setDefText(&testowy, &MyFont);
	testowy.setString(L"aß");

	sf::Color Color_Button(50, 47, 47);
	sf::Color Color_ButtonClicked(74, 72, 72);

	sf::RectangleShape Rect(sf::Vector2f(100.f, 60.f));
	Rect.setFillColor(Color_Button);
	Rect.setPosition(300, 450);
	sf::RectangleShape *RectPath = &Rect;

	sf::RectangleShape ShapeCopy;
	sf::RectangleShape *ShapeCopyPath = &ShapeCopy;



	while (window.isOpen())
	{
		window.clear();


		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::TextEntered)
			{
				if ((event.text.unicode) == s_Backspace)

				{
					cout << "backspace detected" << endl;

					if (testowy.getString().getSize() != 0)
					{
						sf::String b_String = testowy.getString();
						b_String.erase(b_String.getSize() - 1, 1);
						testowy.setString(b_String);
						cout << "Letter deleted" << endl;
					}
					else
					{
						cout << "Can't delete. Empty buffer" << endl;
					}
				}
				else
				{
					input = (event.text.unicode);
					sf::String i_String = testowy.getString();
					cout << i_String.toAnsiString() << endl;
					i_String.insert(i_String.getSize(), input);
					testowy.setString(i_String);
				}


			}
			else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				cout << "LMB used" << endl;

				if (isWithinBordersRect(Rect, Mouse_Acces, window.getPosition()) == 1)
				{
					ButtonClicked(RectPath, ShapeCopy, Color_ButtonClicked, isOn);
					//
				}
				else cout << "not within" << endl;

			}
		}

		window.draw(fromfile);
		window.draw(kk);
		window.draw(testowy);
		window.draw(Rect);
		
		window.draw(TipSheet.getRectSheet());


		window.display();

		if (isFramesPassed(FrameCount, 20) == 1)
		{
			ButtonClickedOff(RectPath, ShapeCopy, isOn);
		}

		addFrame(FrameCount, isOn);
	}


	return 0;
}

