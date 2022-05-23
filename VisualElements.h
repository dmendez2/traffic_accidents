#pragma once
#include <string>
#include <map>
using namespace std;

class StateButton{
public:
	StateButton(){
		xPos = 0; 
		yPos = 0; 
		state = ""; 
		isPressed = false; 
		rectangle.setSize(sf::Vector2f(0.0f, 0.0f));
		rectangle.setFillColor(sf::Color(0, 0, 0));
		rectangle.setPosition(0.0f, 0.0f);
	}

	StateButton(float x, float y, string name) {
		xPos = x;
		yPos = y;
		state = name;
		isPressed = false;
		rectangle.setSize(sf::Vector2f(20.f, 20.0f));
		rectangle.setPosition(x, y);

		if (state == "DC") {
			rectangle.setFillColor(sf::Color(255,153, 51));
		}
		else {
			rectangle.setFillColor(sf::Color(255, 0, 0));
		}
	}

	void Pressed()
	{
		isPressed = true; 
	}

	void Reset() {
		isPressed = false; 
	}

	bool IsPressed() {
		return isPressed; 
	}

	float GetX() {
		return xPos; 
	}

	float GetY() {
		return yPos; 
	}

	string GetState() {
		return state; 
	}

	sf::RectangleShape rectangle; 
	private: 
	float xPos; 
	float yPos; 
	string state;
	bool isPressed; 
};


class Button { //button for years, month, and additional tags

public:
	Button(int y, int x, int w, int h, string t)
		: xPos(x), yPos(y), width(w), height(h), text(t)
	{
		isPressed = false;
		isWeather = false;
	}
	Button()
		: xPos(0), yPos(0), width(0), height(0), text("")
	{
		isPressed = false;
		isWeather = false;
	}
	int xPos;
	int yPos;
	int width;
	int height;
	string text;
	bool isPressed;
	bool isWeather;

};

void creatStateButtons(map<string, StateButton>& stateButtons) {

}

void createButtons(map<string, Button>& buttons) { //initialize buttons that are being used

	buttons["2016"] = Button(35, 154, 35, 100, "2016");
	buttons["2017"] = Button(155, 154, 35, 100, "2017");
	buttons["2018"] = Button(270, 154, 35, 100, "2018");
	buttons["2019"] = Button(385, 154, 35, 100, "2019");
	buttons["2020"] = Button(500, 154, 35, 100, "2020");

	buttons["January"] = Button(35, 269, 35, 150, "January");
	buttons["February"] = Button(220, 269, 35, 150, "February");
	buttons["March"] = Button(405, 269, 35, 150, "March");
	buttons["April"] = Button(35, 319, 35, 150, "April");
	buttons["May"] = Button(220, 319, 35, 150, "May");
	buttons["June"] = Button(405, 319, 35, 150, "June");
	buttons["July"] = Button(35, 369, 35, 150, "July");
	buttons["August"] = Button(220, 369, 35, 150, "August");
	buttons["September"] = Button(405, 369, 35, 150, "September");
	buttons["October"] = Button(35, 419, 35, 150, "October");
	buttons["November"] = Button(220, 419, 35, 150, "November");
	buttons["December"] = Button(405, 419, 35, 150, "December");

	buttons["City"] = Button(35, 530, 35, 400, "");

	buttons["State"] = Button(35, 605, 35, 400, "");

	buttons["Clear"] = Button(35, 710, 150, 120, "");
	buttons["Cloudy"] = Button(185, 710, 150, 120, "");
	buttons["Rain"] = Button(335, 710, 150, 120, "");
	buttons["Snow"] = Button(485, 710, 150, 120, "");

	buttons["Clear"].isWeather = true;
	buttons["Cloudy"].isWeather = true;
	buttons["Rain"].isWeather = true;
	buttons["Snow"].isWeather = true;

	buttons["searchResults"] = Button(0, 0, 80, 633, "");
}