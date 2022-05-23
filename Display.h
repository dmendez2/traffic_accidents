#pragma once
#include <SFML/Graphics.hpp>
#include "VisualElements.h"
#include <algorithm>
#include "redblacktree.h"
#include "MaxHeap.h"
#include "Accidents.h"
#include <iostream>
#include <chrono>


string fixDescription(string desc, int& textOffset) {
	string description;

	while (desc.size() > 0) {
		if (desc.size() > 55) {
			description += desc.substr(0, 55);
			description += "\n";
			desc.erase(0, 55);
			textOffset += 10;
		}
		else {
			description += desc;
			desc.erase(0, string::npos);
			textOffset += 10;
		}


	}
	return description;
}

string findStateButtonPressed(sf::Vector2i& vect, vector<StateButton>& buttons) {
	for (int ii = 0; ii < buttons.size(); ii += 1) {
		float xPos = buttons.at(ii).GetX();
		float yPos = buttons.at(ii).GetY();
		if (vect.x >= xPos && vect.x <= xPos + 20 && vect.y >= yPos && vect.y <= yPos + 20) {
			return buttons.at(ii).GetState();
		}
	}
	return "Not Found";
}

void printSupplementalImagesResults(sf::RenderWindow& window, std::map<string, Button>& buttons, float& timediffTree, float& timediffHeap, vector<Accident>& maxHeapAccidents) { //prints supplemental images/text like title, text boxes, etc. for when results tab is selected

	sf::Font font;
	font.loadFromFile("Font/Montserrat-Medium.ttf");

	sf::RectangleShape boxes;
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(30);

	//TITLE
	text.setPosition(sf::Vector2f(650, 15));
	text.setString("United States Car Accident Database (2016-2020)");
	window.draw(text);

	text.setPosition(sf::Vector2f(1000, 75));
	text.setString("Project by: David Mendez, Jeffrey Yu, Cody Hutcheson");
	window.draw(text);

	boxes.setSize(sf::Vector2f(1230, 10));
	boxes.setPosition(sf::Vector2f(650, 5));
	boxes.setFillColor(sf::Color(0xf7, 0xb5, 0x00, 255));
	window.draw(boxes);

	boxes.setPosition(sf::Vector2f(650, 120)); //650 150
	window.draw(boxes);


	int index = 650;
	boxes.setSize(sf::Vector2f(50, 10));
	boxes.setPosition(sf::Vector2f(index, 60)); //80
	boxes.setFillColor(sf::Color(255, 255, 255, 255));
	while (index < 1850) {
		window.draw(boxes);
		index += 90;
		boxes.setPosition(sf::Vector2f(index, 60));
	}

	//DISPLAY TIME BOX
	boxes.setPosition(sf::Vector2f(20, 90));
	boxes.setSize(sf::Vector2f(600, 180));
	boxes.setFillColor(sf::Color(41, 41, 41, 255));
	window.draw(boxes);

	text.setPosition(sf::Vector2f(30, 100));
	text.setString("Time taken for tree to find top \n ten accidents: " + std::to_string(timediffTree * 1000) + " ms");
	window.draw(text);

	text.setPosition(sf::Vector2f(30, 180));
	text.setString("Time taken for heap to find top \n ten accidents: " + std::to_string(timediffHeap * 1000) + " ms");
	window.draw(text);

	//display results
	boxes.setPosition(sf::Vector2f(20, 300));
	boxes.setSize(sf::Vector2f(600, 1000));
	boxes.setFillColor(sf::Color(41, 41, 41, 255));
	window.draw(boxes);

	int textOffset = 0;
	int count = 1;
	text.setCharacterSize(20);
	for (auto iter = maxHeapAccidents.begin(); iter != maxHeapAccidents.end(); iter++) {
		text.setCharacterSize(20);
		text.setPosition(sf::Vector2f(30, 300 + textOffset));
		text.setString(to_string(count) + ") ID: " + (*iter).getID()+ "   City: " + (*iter).getCity() + "   State: " + (*iter).getState());
		window.draw(text);
		textOffset += 20;
		text.setCharacterSize(15);
		text.setPosition(sf::Vector2f(30, 300 + textOffset));
		string description = (*iter).getDescription();

		description = fixDescription(description, textOffset);

		text.setString("Description: " + description);
		textOffset += 25;
		count++;
		window.draw(text);
	}
}

void printSupplementalImagesSearch(sf::RenderWindow& window, std::map<string, Button>& buttons) { //print supplemental images for when search tab is selected
	sf::RectangleShape boxes;
	sf::Text text;

	sf::Font font;
	font.loadFromFile("Font/Montserrat-Medium.ttf");

	//YEAR
	boxes.setFillColor(sf::Color(41, 41, 41, 255));
	boxes.setSize(sf::Vector2f(600, 120));
	boxes.setPosition(sf::Vector2f(20, 90));
	window.draw(boxes);


	text.setFont(font);
	text.setCharacterSize(30);
	text.setPosition(sf::Vector2f(250, 95));
	text.setString("YEAR");
	window.draw(text);

	//MONTH
	boxes.setSize(sf::Vector2f(600, 250));
	boxes.setPosition(sf::Vector2f(20, 220));
	window.draw(boxes);

	text.setPosition(sf::Vector2f(250, 225));
	text.setString("MONTH");
	window.draw(text);

	//CITY
	text.setPosition(sf::Vector2f(35, 480));
	text.setString("CITY");
	window.draw(text);

	//STATE
	text.setPosition(sf::Vector2f(35, 565));
	text.setString("STATE");
	window.draw(text);

	//WEATHER

	text.setPosition(sf::Vector2f(250, 655));
	text.setString("WEATHER");
	window.draw(text);

	//TITLE
	text.setPosition(sf::Vector2f(650, 15));
	text.setString("United States Car Accident Database (2016-2020)");
	window.draw(text);

	text.setPosition(sf::Vector2f(1000, 75));
	text.setString("Project by: David Mendez, Jeffrey Yu, Cody Hutcheson");
	window.draw(text);

	boxes.setSize(sf::Vector2f(1230, 10));
	boxes.setPosition(sf::Vector2f(650, 5));
	boxes.setFillColor(sf::Color(0xf7, 0xb5, 0x00, 255));
	window.draw(boxes);

	boxes.setPosition(sf::Vector2f(650, 120)); //650 150
	window.draw(boxes);


	int index = 650;
	boxes.setSize(sf::Vector2f(50, 10));
	boxes.setPosition(sf::Vector2f(index, 60)); //80
	boxes.setFillColor(sf::Color(255, 255, 255, 255));
	while (index < 1850) {
		window.draw(boxes);
		index += 90;
		boxes.setPosition(sf::Vector2f(index, 60));
	}

}

void loadStateButtons(vector<StateButton>& stateButtons) {
	StateButton Florida(1580, 780, "FL");
	stateButtons.push_back(Florida);
	StateButton Georgia(1540, 650, "GA");
	stateButtons.push_back(Georgia);
	StateButton Alabama(1450, 650, "AL");
	stateButtons.push_back(Alabama);
	StateButton Mississippi(1390, 650, "MS");
	stateButtons.push_back(Mississippi);
	StateButton Arkansas(1330, 630, "AR");
	stateButtons.push_back(Arkansas);
	StateButton Louisiana(1330, 730, "LA");
	stateButtons.push_back(Louisiana);
	StateButton Oklahoma(1230, 600, "OK");
	stateButtons.push_back(Oklahoma);
	StateButton Kansas(1210, 515, "KS");
	stateButtons.push_back(Kansas);
	StateButton Texas(1190, 700, "TX");
	stateButtons.push_back(Texas);
	StateButton Colorado(1050, 500, "CO");
	stateButtons.push_back(Colorado);
	StateButton NewMexico(1040, 620, "NM");
	stateButtons.push_back(NewMexico);
	StateButton Arizona(900, 620, "AZ");
	stateButtons.push_back(Arizona);
	StateButton Alaska(900, 750, "AK");
	stateButtons.push_back(Alaska);
	StateButton Hawaii(1120, 880, "HI");
	stateButtons.push_back(Hawaii);
	StateButton Utah(930, 480, "UT");
	stateButtons.push_back(Utah);
	StateButton Nevada(820, 450, "NV");
	stateButtons.push_back(Nevada);
	StateButton California(720, 480, "CA");
	stateButtons.push_back(California);
	StateButton Oregon(780, 290, "OR");
	stateButtons.push_back(Oregon);
	StateButton Washington(800, 190, "WA");
	stateButtons.push_back(Washington);
	StateButton Idaho(900, 310, "ID");
	stateButtons.push_back(Idaho);
	StateButton Wyoming(1010, 370, "WY");
	stateButtons.push_back(Wyoming);
	StateButton Montana(1010, 250, "MT");
	stateButtons.push_back(Montana);
	StateButton NorthDakota(1170, 270, "ND");
	stateButtons.push_back(NorthDakota);
	StateButton SouthDakota(1170, 350, "SD");
	stateButtons.push_back(SouthDakota);
	StateButton Nebraska(1170, 435, "NE");
	stateButtons.push_back(Nebraska);
	StateButton Missouri(1320, 510, "MO");
	stateButtons.push_back(Missouri);
	StateButton Iowa(1290, 420, "IA");
	stateButtons.push_back(Iowa);
	StateButton Minnesota(1270, 300, "MN");
	stateButtons.push_back(Minnesota);
	StateButton Tennessee(1450, 580, "TN");
	stateButtons.push_back(Tennessee);
	StateButton NorthCarolina(1600, 570, "NC");
	stateButtons.push_back(NorthCarolina);
	StateButton SouthCarolina(1590, 620, "SC");
	stateButtons.push_back(SouthCarolina);
	StateButton Kentucky(1470, 530, "KY");
	stateButtons.push_back(Kentucky);
	StateButton Virginia(1610, 510, "VA");
	stateButtons.push_back(Virginia);
	StateButton Illinois(1380, 460, "IL");
	stateButtons.push_back(Illinois);
	StateButton Wisconsin(1370, 340, "WI");
	stateButtons.push_back(Wisconsin);
	StateButton Michigan(1460, 340, "MI");
	stateButtons.push_back(Michigan);
	StateButton Indiana(1450, 450, "IN");
	stateButtons.push_back(Indiana);
	StateButton Ohio(1520, 450, "OH");
	stateButtons.push_back(Ohio);
	StateButton WestVirginia(1570, 480, "WV");
	stateButtons.push_back(WestVirginia);
	StateButton Maryland(1660, 450, "MD");
	stateButtons.push_back(Maryland);
	StateButton Pennsylvania(1620, 400, "PA");
	stateButtons.push_back(Pennsylvania);
	StateButton NewJersey(1680, 410, "NJ");
	stateButtons.push_back(NewJersey);
	StateButton NewYork(1640, 330, "NY");
	stateButtons.push_back(NewYork);
	StateButton Vermont(1690, 290, "VT");
	stateButtons.push_back(Vermont);
	StateButton NewHampshire(1720, 290, "NH");
	stateButtons.push_back(NewHampshire);
	StateButton Massachusets(1720, 330, "MA");
	stateButtons.push_back(Massachusets);
	StateButton Connecticut(1710, 380, "CT");
	stateButtons.push_back(Connecticut);
	StateButton RhodeIsland(1745, 380, "RI");
	stateButtons.push_back(RhodeIsland);
	StateButton Maine(1750, 250, "ME");
	stateButtons.push_back(Maine);
	StateButton DC(1545, 525, "DC");
	stateButtons.push_back(DC);
	StateButton Deleware(1690, 450, "DE");
	stateButtons.push_back(Deleware);

}

void loadStates(map<string, sf::ConvexShape>& states) { //contains vertices of states to be printed out to screen

	states["FL"] = sf::ConvexShape(6);
	states["FL"].setPoint(0, sf::Vector2f(1461, 725));
	states["FL"].setPoint(1, sf::Vector2f(1465, 755));
	states["FL"].setPoint(2, sf::Vector2f(1577, 765));
	states["FL"].setPoint(3, sf::Vector2f(1623, 871));
	states["FL"].setPoint(4, sf::Vector2f(1660, 860));
	states["FL"].setPoint(5, sf::Vector2f(1600, 725));

	states["GA"] = sf::ConvexShape(5);
	states["GA"].setPoint(0, sf::Vector2f(1515, 718));
	states["GA"].setPoint(1, sf::Vector2f(1494, 616));
	states["GA"].setPoint(2, sf::Vector2f(1549, 616));
	states["GA"].setPoint(3, sf::Vector2f(1603, 674));
	states["GA"].setPoint(4, sf::Vector2f(1591, 718));

	states["AL"] = sf::ConvexShape(5);
	states["AL"].setPoint(0, sf::Vector2f(1436, 756));
	states["AL"].setPoint(1, sf::Vector2f(1461, 715));
	states["AL"].setPoint(2, sf::Vector2f(1505, 715));
	states["AL"].setPoint(3, sf::Vector2f(1490, 616));
	states["AL"].setPoint(4, sf::Vector2f(1436, 616));

	states["MS"] = sf::ConvexShape(6);
	states["MS"].setPoint(0, sf::Vector2f(1427, 760));
	states["MS"].setPoint(1, sf::Vector2f(1425, 619));
	states["MS"].setPoint(2, sf::Vector2f(1392, 619));
	states["MS"].setPoint(3, sf::Vector2f(1361, 735));
	states["MS"].setPoint(4, sf::Vector2f(1391, 735));
	states["MS"].setPoint(5, sf::Vector2f(1408, 760));

	states["LA"] = sf::ConvexShape(6);
	states["LA"].setPoint(0, sf::Vector2f(1314, 787));
	states["LA"].setPoint(1, sf::Vector2f(1390, 794));
	states["LA"].setPoint(2, sf::Vector2f(1390, 739));
	states["LA"].setPoint(3, sf::Vector2f(1355, 740));
	states["LA"].setPoint(4, sf::Vector2f(1365, 687));
	states["LA"].setPoint(5, sf::Vector2f(1307, 695));

	states["TX"] = sf::ConvexShape(11);
	states["TX"].setPoint(0, sf::Vector2f(1096, 711));
	states["TX"].setPoint(1, sf::Vector2f(1108, 596));
	states["TX"].setPoint(2, sf::Vector2f(1166, 606));
	states["TX"].setPoint(3, sf::Vector2f(1207, 657));
	states["TX"].setPoint(4, sf::Vector2f(1293, 656));
	states["TX"].setPoint(5, sf::Vector2f(1304, 776));
	states["TX"].setPoint(6, sf::Vector2f(1229, 819));
	states["TX"].setPoint(7, sf::Vector2f(1225, 897));
	states["TX"].setPoint(8, sf::Vector2f(1127, 774));
	states["TX"].setPoint(9, sf::Vector2f(1080, 789));
	states["TX"].setPoint(10, sf::Vector2f(1025, 711));

	states["SC"] = sf::ConvexShape(3);
	states["SC"].setPoint(0, sf::Vector2f(1553, 612));
	states["SC"].setPoint(1, sf::Vector2f(1605, 666));
	states["SC"].setPoint(2, sf::Vector2f(1647, 609));

	states["NC"] = sf::ConvexShape(4);
	states["NC"].setPoint(0, sf::Vector2f(1520, 604));
	states["NC"].setPoint(1, sf::Vector2f(1652, 604));
	states["NC"].setPoint(2, sf::Vector2f(1704, 538));
	states["NC"].setPoint(3, sf::Vector2f(1567, 559));

	states["TN"] = sf::ConvexShape(4);
	states["TN"].setPoint(0, sf::Vector2f(1391, 613));
	states["TN"].setPoint(1, sf::Vector2f(1511, 608));
	states["TN"].setPoint(2, sf::Vector2f(1553, 556));
	states["TN"].setPoint(3, sf::Vector2f(1406, 582));

	states["AR"] = sf::ConvexShape(4);
	states["AR"].setPoint(0, sf::Vector2f(1304, 683));
	states["AR"].setPoint(1, sf::Vector2f(1370, 679));
	states["AR"].setPoint(2, sf::Vector2f(1388, 593));
	states["AR"].setPoint(3, sf::Vector2f(1295, 594));

	states["OK"] = sf::ConvexShape(6);
	states["OK"].setPoint(0, sf::Vector2f(1113, 586));
	states["OK"].setPoint(1, sf::Vector2f(1169, 598));
	states["OK"].setPoint(2, sf::Vector2f(1211, 648));
	states["OK"].setPoint(3, sf::Vector2f(1288, 647));
	states["OK"].setPoint(4, sf::Vector2f(1283, 577));
	states["OK"].setPoint(5, sf::Vector2f(1109, 569));

	states["NM"] = sf::ConvexShape(5);
	states["NM"].setPoint(0, sf::Vector2f(961, 715));
	states["NM"].setPoint(1, sf::Vector2f(980, 562));
	states["NM"].setPoint(2, sf::Vector2f(1102, 574));
	states["NM"].setPoint(3, sf::Vector2f(1092, 707));
	states["NM"].setPoint(4, sf::Vector2f(1011, 701));

	states["AZ"] = sf::ConvexShape(4);
	states["AZ"].setPoint(0, sf::Vector2f(830, 652));
	states["AZ"].setPoint(1, sf::Vector2f(954, 710));
	states["AZ"].setPoint(2, sf::Vector2f(973, 563));
	states["AZ"].setPoint(3, sf::Vector2f(872, 533));

	states["CA"] = sf::ConvexShape(7);
	states["CA"].setPoint(0, sf::Vector2f(696, 336));
	states["CA"].setPoint(1, sf::Vector2f(782, 364));
	states["CA"].setPoint(2, sf::Vector2f(755, 440));
	states["CA"].setPoint(3, sf::Vector2f(847, 587));
	states["CA"].setPoint(4, sf::Vector2f(821, 644));
	states["CA"].setPoint(5, sf::Vector2f(742, 587));
	states["CA"].setPoint(6, sf::Vector2f(686, 445));

	states["NV"] = sf::ConvexShape(4);
	states["NV"].setPoint(0, sf::Vector2f(798, 364));
	states["NV"].setPoint(1, sf::Vector2f(775, 455));
	states["NV"].setPoint(2, sf::Vector2f(852, 580));
	states["NV"].setPoint(3, sf::Vector2f(893, 391));

	states["OR"] = sf::ConvexShape(4);
	states["OR"].setPoint(0, sf::Vector2f(703, 325));
	states["OR"].setPoint(1, sf::Vector2f(724, 235));
	states["OR"].setPoint(2, sf::Vector2f(868, 274));
	states["OR"].setPoint(3, sf::Vector2f(836, 363));

	states["WA"] = sf::ConvexShape(4);
	states["WA"].setPoint(0, sf::Vector2f(724, 224));
	states["WA"].setPoint(1, sf::Vector2f(762, 135));
	states["WA"].setPoint(2, sf::Vector2f(885, 180));
	states["WA"].setPoint(3, sf::Vector2f(861, 262));

	states["ID"] = sf::ConvexShape(4);
	states["ID"].setPoint(0, sf::Vector2f(895, 196));
	states["ID"].setPoint(1, sf::Vector2f(851, 367));
	states["ID"].setPoint(2, sf::Vector2f(955, 397));
	states["ID"].setPoint(3, sf::Vector2f(971, 336));

	states["MT"] = sf::ConvexShape(4);
	states["MT"].setPoint(0, sf::Vector2f(908, 191));
	states["MT"].setPoint(1, sf::Vector2f(973, 313));
	states["MT"].setPoint(2, sf::Vector2f(1098, 333));
	states["MT"].setPoint(3, sf::Vector2f(1107, 230));

	states["UT"] = sf::ConvexShape(6);
	states["UT"].setPoint(0, sf::Vector2f(906, 395));
	states["UT"].setPoint(1, sf::Vector2f(960, 404));
	states["UT"].setPoint(2, sf::Vector2f(955, 433));
	states["UT"].setPoint(3, sf::Vector2f(984, 442));
	states["UT"].setPoint(4, sf::Vector2f(972, 552));
	states["UT"].setPoint(5, sf::Vector2f(882, 526));

	states["WY"] = sf::ConvexShape(4);
	states["WY"].setPoint(0, sf::Vector2f(980, 319));
	states["WY"].setPoint(1, sf::Vector2f(1098, 346));
	states["WY"].setPoint(2, sf::Vector2f(1086, 443));
	states["WY"].setPoint(3, sf::Vector2f(962, 427));

	states["CO"] = sf::ConvexShape(4);
	states["CO"].setPoint(0, sf::Vector2f(995, 447));
	states["CO"].setPoint(1, sf::Vector2f(985, 547));
	states["CO"].setPoint(2, sf::Vector2f(1114, 563));
	states["CO"].setPoint(3, sf::Vector2f(1130, 459));

	states["ND"] = sf::ConvexShape(4);
	states["ND"].setPoint(0, sf::Vector2f(1114, 224));
	states["ND"].setPoint(1, sf::Vector2f(1229, 224));
	states["ND"].setPoint(2, sf::Vector2f(1245, 319));
	states["ND"].setPoint(3, sf::Vector2f(1108, 310));

	states["SD"] = sf::ConvexShape(4);
	states["SD"].setPoint(0, sf::Vector2f(1112, 322));
	states["SD"].setPoint(1, sf::Vector2f(1106, 390));
	states["SD"].setPoint(2, sf::Vector2f(1245, 399));
	states["SD"].setPoint(3, sf::Vector2f(1242, 326));

	states["NE"] = sf::ConvexShape(6);
	states["NE"].setPoint(0, sf::Vector2f(1102, 399));
	states["NE"].setPoint(1, sf::Vector2f(1246, 409));
	states["NE"].setPoint(2, sf::Vector2f(1267, 488));
	states["NE"].setPoint(3, sf::Vector2f(1141, 479));
	states["NE"].setPoint(4, sf::Vector2f(1141, 455));
	states["NE"].setPoint(5, sf::Vector2f(1096, 445));

	states["KS"] = sf::ConvexShape(4);
	states["KS"].setPoint(0, sf::Vector2f(1141, 488));
	states["KS"].setPoint(1, sf::Vector2f(1271, 496));
	states["KS"].setPoint(2, sf::Vector2f(1278, 564));
	states["KS"].setPoint(3, sf::Vector2f(1126, 562));

	states["MN"] = sf::ConvexShape(5);
	states["MN"].setPoint(0, sf::Vector2f(1237, 235));
	states["MN"].setPoint(1, sf::Vector2f(1354, 255));
	states["MN"].setPoint(2, sf::Vector2f(1319, 319));
	states["MN"].setPoint(3, sf::Vector2f(1348, 386));
	states["MN"].setPoint(4, sf::Vector2f(1256, 386));

	states["IA"] = sf::ConvexShape(4);
	states["IA"].setPoint(0, sf::Vector2f(1255, 397));
	states["IA"].setPoint(1, sf::Vector2f(1352, 398));
	states["IA"].setPoint(2, sf::Vector2f(1339, 466));
	states["IA"].setPoint(3, sf::Vector2f(1273, 467));

	states["MO"] = sf::ConvexShape(4);
	states["MO"].setPoint(0, sf::Vector2f(1278, 475));
	states["MO"].setPoint(1, sf::Vector2f(1342, 475));
	states["MO"].setPoint(2, sf::Vector2f(1402, 579));
	states["MO"].setPoint(3, sf::Vector2f(1296, 590));

	states["IL"] = sf::ConvexShape(5);
	states["IL"].setPoint(0, sf::Vector2f(1369, 418));
	states["IL"].setPoint(1, sf::Vector2f(1426, 428));
	states["IL"].setPoint(2, sf::Vector2f(1427, 538));
	states["IL"].setPoint(3, sf::Vector2f(1405, 565));
	states["IL"].setPoint(4, sf::Vector2f(1347, 475));

	states["KY"] = sf::ConvexShape(7);
	states["KY"].setPoint(0, sf::Vector2f(1409, 577));
	states["KY"].setPoint(1, sf::Vector2f(1519, 557));
	states["KY"].setPoint(2, sf::Vector2f(1551, 534));
	states["KY"].setPoint(3, sf::Vector2f(1538, 509));
	states["KY"].setPoint(4, sf::Vector2f(1488, 500));
	states["KY"].setPoint(5, sf::Vector2f(1463, 533));
	states["KY"].setPoint(6, sf::Vector2f(1431, 540));

	states["WI"] = sf::ConvexShape(5);
	states["WI"].setPoint(0, sf::Vector2f(1336, 295));
	states["WI"].setPoint(1, sf::Vector2f(1419, 327));
	states["WI"].setPoint(2, sf::Vector2f(1410, 406));
	states["WI"].setPoint(3, sf::Vector2f(1370, 407));
	states["WI"].setPoint(4, sf::Vector2f(1330, 318));

	states["IN"] = sf::ConvexShape(4);
	states["IN"].setPoint(0, sf::Vector2f(1436, 434));
	states["IN"].setPoint(1, sf::Vector2f(1486, 429));
	states["IN"].setPoint(2, sf::Vector2f(1487, 496));
	states["IN"].setPoint(3, sf::Vector2f(1435, 532));

	states["VA"] = sf::ConvexShape(4);
	states["VA"].setPoint(0, sf::Vector2f(1540, 553));
	states["VA"].setPoint(1, sf::Vector2f(1691, 534));
	states["VA"].setPoint(2, sf::Vector2f(1634, 470));
	states["VA"].setPoint(3, sf::Vector2f(1589, 523));

	states["WV"] = sf::ConvexShape(5);
	states["WV"].setPoint(0, sf::Vector2f(1548, 507));
	states["WV"].setPoint(1, sf::Vector2f(1556, 529));
	states["WV"].setPoint(2, sf::Vector2f(1632, 463));
	states["WV"].setPoint(3, sf::Vector2f(1595, 472));
	states["WV"].setPoint(4, sf::Vector2f(1576, 460));

	states["OH"] = sf::ConvexShape(5);
	states["OH"].setPoint(0, sf::Vector2f(1493, 426));
	states["OH"].setPoint(1, sf::Vector2f(1566, 407));
	states["OH"].setPoint(2, sf::Vector2f(1571, 453));
	states["OH"].setPoint(3, sf::Vector2f(1540, 503));
	states["OH"].setPoint(4, sf::Vector2f(1499, 494));

	states["MD"] = sf::ConvexShape(6);
	states["MD"].setPoint(0, sf::Vector2f(1602, 454));
	states["MD"].setPoint(1, sf::Vector2f(1678, 439));
	states["MD"].setPoint(2, sf::Vector2f(1693, 486));
	states["MD"].setPoint(3, sf::Vector2f(1658, 488));
	states["MD"].setPoint(4, sf::Vector2f(1633, 458));
	states["MD"].setPoint(5, sf::Vector2f(1602, 466));

	states["PA"] = sf::ConvexShape(4);
	states["PA"].setPoint(0, sf::Vector2f(1567, 400));
	states["PA"].setPoint(1, sf::Vector2f(1671, 379));
	states["PA"].setPoint(2, sf::Vector2f(1675, 434));
	states["PA"].setPoint(3, sf::Vector2f(1584, 454));

	states["NJ"] = sf::ConvexShape(4);
	states["NJ"].setPoint(0, sf::Vector2f(1681, 390));
	states["NJ"].setPoint(1, sf::Vector2f(1697, 391));
	states["NJ"].setPoint(2, sf::Vector2f(1702, 446));
	states["NJ"].setPoint(3, sf::Vector2f(1680, 447));

	states["NY"] = sf::ConvexShape(6);
	states["NY"].setPoint(0, sf::Vector2f(1578, 388));
	states["NY"].setPoint(1, sf::Vector2f(1588l, 353));
	states["NY"].setPoint(2, sf::Vector2f(1674, 286));
	states["NY"].setPoint(3, sf::Vector2f(1705, 385));
	states["NY"].setPoint(4, sf::Vector2f(1678, 390));
	states["NY"].setPoint(5, sf::Vector2f(1671, 367));

	states["CT"] = sf::ConvexShape(4);
	states["CT"].setPoint(0, sf::Vector2f(1709, 364));
	states["CT"].setPoint(1, sf::Vector2f(1732, 358));
	states["CT"].setPoint(2, sf::Vector2f(1729, 378));
	states["CT"].setPoint(3, sf::Vector2f(1705, 386));

	states["RI"] = sf::ConvexShape(4);
	states["RI"].setPoint(0, sf::Vector2f(1739, 364));
	states["RI"].setPoint(1, sf::Vector2f(1752, 361));
	states["RI"].setPoint(2, sf::Vector2f(1752, 377));
	states["RI"].setPoint(3, sf::Vector2f(1738, 377));

	states["MA"] = sf::ConvexShape(5);
	states["MA"].setPoint(0, sf::Vector2f(1702, 340));
	states["MA"].setPoint(1, sf::Vector2f(1742, 328));
	states["MA"].setPoint(2, sf::Vector2f(1775, 352));
	states["MA"].setPoint(3, sf::Vector2f(1732, 346));
	states["MA"].setPoint(4, sf::Vector2f(1706, 354));

	states["VT"] = sf::ConvexShape(4);
	states["VT"].setPoint(0, sf::Vector2f(1681, 282));
	states["VT"].setPoint(1, sf::Vector2f(1711, 272));
	states["VT"].setPoint(2, sf::Vector2f(1713, 329));
	states["VT"].setPoint(3, sf::Vector2f(1697, 336));

	states["NH"] = sf::ConvexShape(4);
	states["NH"].setPoint(0, sf::Vector2f(1713, 275));
	states["NH"].setPoint(1, sf::Vector2f(1732, 265));
	states["NH"].setPoint(2, sf::Vector2f(1750, 316));
	states["NH"].setPoint(3, sf::Vector2f(1717, 328));

	states["ME"] = sf::ConvexShape(5);
	states["ME"].setPoint(0, sf::Vector2f(1735, 261));
	states["ME"].setPoint(1, sf::Vector2f(1751, 309));
	states["ME"].setPoint(2, sf::Vector2f(1799, 239));
	states["ME"].setPoint(3, sf::Vector2f(1767, 185));
	states["ME"].setPoint(4, sf::Vector2f(1735, 188));

	states["MI"] = sf::ConvexShape(7);
	states["MI"].setPoint(0, sf::Vector2f(1370, 297));
	states["MI"].setPoint(1, sf::Vector2f(1404, 270));
	states["MI"].setPoint(2, sf::Vector2f(1485, 283));
	states["MI"].setPoint(3, sf::Vector2f(1527, 403));
	states["MI"].setPoint(4, sf::Vector2f(1444, 423));
	states["MI"].setPoint(5, sf::Vector2f(1456, 321));
	states["MI"].setPoint(6, sf::Vector2f(1422, 322));

	states["AK"] = sf::ConvexShape(9);
	states["AK"].setPoint(0, sf::Vector2f(764, 872));
	states["AK"].setPoint(1, sf::Vector2f(841, 787));
	states["AK"].setPoint(2, sf::Vector2f(870, 723));
	states["AK"].setPoint(3, sf::Vector2f(916, 710));
	states["AK"].setPoint(4, sf::Vector2f(966, 737));
	states["AK"].setPoint(5, sf::Vector2f(963, 799));
	states["AK"].setPoint(6, sf::Vector2f(1013, 888));
	states["AK"].setPoint(7, sf::Vector2f(910, 831));
	states["AK"].setPoint(8, sf::Vector2f(848, 861));

	states["HI"] = sf::ConvexShape(3);
	states["HI"].setPoint(0, sf::Vector2f(997, 786));
	states["HI"].setPoint(1, sf::Vector2f(1025, 779));
	states["HI"].setPoint(2, sf::Vector2f(1013, 803));

	states["HI2"] = sf::ConvexShape(3);
	states["HI2"].setPoint(0, sf::Vector2f(1039, 799));
	states["HI2"].setPoint(1, sf::Vector2f(1064, 793));
	states["HI2"].setPoint(2, sf::Vector2f(1060, 820));

	states["HI3"] = sf::ConvexShape(3);
	states["HI3"].setPoint(0, sf::Vector2f(1075, 815));
	states["HI3"].setPoint(1, sf::Vector2f(1109, 822));
	states["HI3"].setPoint(2, sf::Vector2f(1093, 841));

	states["HI4"] = sf::ConvexShape(3);
	states["HI4"].setPoint(0, sf::Vector2f(1107, 839));
	states["HI4"].setPoint(1, sf::Vector2f(1143, 864));
	states["HI4"].setPoint(2, sf::Vector2f(1109, 886));

	//Deleware is a state Cody!!!
	states["DE"] = sf::ConvexShape(4);
	states["DE"].setPoint(0, sf::Vector2f(1690, 450));
	states["DE"].setPoint(1, sf::Vector2f(1700, 450));
	states["DE"].setPoint(2, sf::Vector2f(1710, 490));
	states["DE"].setPoint(3, sf::Vector2f(1700, 490));
}
void printStates(sf::RenderWindow& window, std::map<string, sf::ConvexShape>& states) { //prints states to screen
	for (auto iter = states.begin(); iter != states.end(); iter++) {
		window.draw((*iter).second);
	}
}

void resetStates(sf::RenderWindow& window, std::map<string, sf::ConvexShape>& states) {
	for (auto iter = states.begin(); iter != states.end(); iter++) {
		(*iter).second.setFillColor(sf::Color(255, 255, 255, 255));
	}
}

void printStateButtons(sf::RenderWindow& window, vector<StateButton>& stateButtons) {
	for (int ii = 0; ii < stateButtons.size(); ii += 1) {
		window.draw(stateButtons.at(ii).rectangle);
	}
}


void displayNewBoard(sf::RenderWindow& window, std::map<string, sf::ConvexShape>& states, unordered_map<string, RedBlackTree> treeStateMap, unordered_map<string, MaxHeap<Accident>> maxStateMap, vector<StateButton>& stateButtons, string stateSelected, float& timediffTree, float& timediffHeap, vector<Accident>& accidents) {

	//update the board

	window.clear(sf::Color(41, 41, 41, 255));

	sf::RectangleShape sidebar;								//draw the sidebar
	sidebar.setFillColor(sf::Color(0x21, 0x21, 0x21, 0xff));
	sidebar.setSize(sf::Vector2f(633, 1000));
	sidebar.setPosition(sf::Vector2f(0, 60));
	window.draw(sidebar);

	sf::RectangleShape searchResult;						//search and result buttons


	if (treeStateMap.find(stateSelected) != treeStateMap.end()) {
		resetStates(window, states);
		vector<Node*> treeAccidents;
		vector<Accident> maxHeapAccidents;

		treeStateMap[stateSelected].FindXMostSevereAccidents(10, treeAccidents); //get top 10 accidents for tree
		for (int ii = 0; ii < treeAccidents.size(); ii += 1) {
			accidents.push_back(treeAccidents.at(ii)->GetAccident()); 
		}

		MaxHeap<Accident> heap = maxStateMap[stateSelected];

		for (int i = 0; i < 10; i++) { //get top 10 accidents for heap
			if (heap.Size() != 0) {
				maxHeapAccidents.push_back(heap.top());
				heap.pop();
			}
			else
				break;
		}

		std::cout << treeAccidents.size() << " " << maxHeapAccidents.size() << std::endl;

		for (int i = 0; i < treeAccidents.size(); i++) {

			std::cout << i << " tree: " << treeAccidents[i]->GetAccident().getWeightedSeverity() << " heap: " << maxHeapAccidents[i].getWeightedSeverity() << std::endl;
		}
		states[stateSelected].setFillColor(sf::Color(0x03, 0xa9, 0xf4, 255));
	}



	printStates(window, states); //print states
	printStateButtons(window, stateButtons);

	vector<Accident> accidentVector;
	if (timediffTree == 0.0f) {

		//CITATION: USED SNIPPETS IN EXAMPLE CODE IN DOCUMENTATION ON CPLUSPLUS.COM TO UTILIZE THE CHRONO CLASS
		// https://www.cplusplus.com/reference/chrono/steady_clock/
		//*****************************************************************************************

		std::chrono::steady_clock::time_point tbegin = std::chrono::steady_clock::now();

		vector<Node*> nodeVector; 
		treeStateMap[stateSelected].FindXMostSevereAccidents(10,nodeVector); //get top 10 accidents for tree




		std::chrono::steady_clock::time_point tend = std::chrono::steady_clock::now();

		std::chrono::duration<float> timeTree = std::chrono::duration_cast<std::chrono::duration<float>>(tend - tbegin);

		timediffTree = timeTree.count();
		cout << timediffTree << endl;

	}
	int sizeVect;
	if (timediffHeap == 0.0f) {
		MaxHeap<Accident> heap = maxStateMap[stateSelected];

		std::chrono::steady_clock::time_point tbegin = std::chrono::steady_clock::now();

		heap.MaxKElements(10, accidentVector);


		std::chrono::steady_clock::time_point tend = std::chrono::steady_clock::now();

		std::chrono::duration<float> timeHeap = std::chrono::duration_cast<std::chrono::duration<float>>(tend - tbegin);


		timediffHeap = timeHeap.count();
	}



		sf::Font font;
		font.loadFromFile("Font/Montserrat-Medium.ttf");

		sf::RectangleShape boxes;
		sf::Text text;
		text.setFont(font);
		text.setCharacterSize(30);

		//DISPLAY TIME BOX
		boxes.setPosition(sf::Vector2f(20, 90));
		boxes.setSize(sf::Vector2f(600, 180));
		boxes.setFillColor(sf::Color(41, 41, 41, 255));
		window.draw(boxes);

		if (accidentVector.size() != 0) {
			text.setPosition(sf::Vector2f(30, 100));
			text.setString("Time taken for tree to find top \n ten accidents: " + std::to_string(timediffTree * 1000) + " ms");
			window.draw(text);

			text.setPosition(sf::Vector2f(30, 180));
			text.setString("Time taken for heap to find top \n ten accidents: " + std::to_string(timediffHeap * 1000) + " ms");
			window.draw(text);
		}
		else {
			text.setPosition(sf::Vector2f(30, 100));
			text.setString("No Results Found For This State, Sorry!");
			window.draw(text);
		}

		//display results
		boxes.setPosition(sf::Vector2f(20, 300));
		boxes.setSize(sf::Vector2f(600, 1000));
		boxes.setFillColor(sf::Color(41, 41, 41, 255));
		window.draw(boxes);

		int textOffset = 0;
		int count = 1;
		text.setCharacterSize(20);
		for (auto iter = accidentVector.begin(); iter != accidentVector.end(); iter++) {
			text.setCharacterSize(20);
			text.setPosition(sf::Vector2f(30, 300 + textOffset));
			text.setString(to_string(count) + ") ID: " + (*iter).getID() + "   City: " + (*iter).getCity() + "   State: " + (*iter).getState());
			window.draw(text);
			textOffset += 20;
			text.setCharacterSize(15);
			text.setPosition(sf::Vector2f(30, 300 + textOffset));
			string description = (*iter).getDescription(); 

			description = fixDescription(description, textOffset);

			text.setString("Description: " + description);
			textOffset += 25;
			count++;
			window.draw(text);
		}

		window.display(); //display new content


	}

void displayNewBoard(sf::RenderWindow& window, std::map<string, sf::ConvexShape>& states, unordered_map<string, RedBlackTree> treeStateMap, unordered_map<string, MaxHeap<Accident>> maxStateMap, vector<StateButton>& stateButtons, vector<Accident>& accidents, float& timediffTree, float& timediffHeap, bool& firstTime) {

	//update the board
	window.clear(sf::Color(41, 41, 41, 255));
	sf::RectangleShape sidebar;								//draw the sidebar
	sidebar.setFillColor(sf::Color(0x21, 0x21, 0x21, 0xff));
	sidebar.setSize(sf::Vector2f(633, 1000));
	sidebar.setPosition(sf::Vector2f(0, 60));
	window.draw(sidebar);

	sf::Font font;
	font.loadFromFile("Font/Montserrat-Medium.ttf");

	sf::RectangleShape boxes;
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(30);

	//DISPLAY TIME BOX
	boxes.setPosition(sf::Vector2f(20, 90));
	boxes.setSize(sf::Vector2f(600, 180));
	boxes.setFillColor(sf::Color(41, 41, 41, 255));
	window.draw(boxes);

	if (firstTime) {
		text.setPosition(sf::Vector2f(30, 100));
		text.setString("Click on a State to Begin");
		window.draw(text);
	}
	else if (accidents.size() != 0) {
		text.setPosition(sf::Vector2f(30, 100));
		text.setString("Time taken for tree to find top \n ten accidents: " + std::to_string(timediffTree * 1000) + " ms");
		window.draw(text);

		text.setPosition(sf::Vector2f(30, 180));
		text.setString("Time taken for heap to find top \n ten accidents: " + std::to_string(timediffHeap * 1000) + " ms");
		window.draw(text);
	}
	else {
		text.setPosition(sf::Vector2f(30, 100));
		text.setString("No Results Found For This State");
		window.draw(text);
	}

	//display results
	boxes.setPosition(sf::Vector2f(20, 300));
	boxes.setSize(sf::Vector2f(600, 1000));
	boxes.setFillColor(sf::Color(41, 41, 41, 255));
	window.draw(boxes);

	int textOffset = 0;
	int count = 1;
	text.setCharacterSize(20);

	for (auto iter = accidents.begin(); iter != accidents.end(); iter++) {

		text.setCharacterSize(20);
		text.setPosition(sf::Vector2f(30, 300 + textOffset));
		text.setString(to_string(count) + ") ID: " + (*iter).getID() + "   City: " + (*iter).getCity() + "   State: " + (*iter).getState());
		window.draw(text);
		textOffset += 20;
		text.setCharacterSize(15);
		text.setPosition(sf::Vector2f(30, 300 + textOffset));
		string description = (*iter).getDescription();

		description = fixDescription(description, textOffset);

		text.setString("Description: " + description);
		textOffset += 25;
		count++;
		window.draw(text);
	}
	printStates(window, states); //print states
	printStateButtons(window, stateButtons);

	window.display(); //display new content
}
