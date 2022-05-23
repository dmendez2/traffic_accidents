#include<SFML/Graphics.hpp>
#include <vector>
#include "TextureManager.h"
#include<unordered_map>
#include "Display.h"
#include <iostream>
#include "VisualElements.h"
#include "Accidents.h"
#include "MaxHeap.h"
#include "MinHeap.h"
#include "redblacktree.h"
#include "node.h"
#include "ReadFile.h"



template<typename H>
unordered_map<string, H> CreateMap();


int main()
{
    //Read in the data:
    float timedheap = 0.0f;
    float timedtree = 0.0f; 
    bool firstTime = true;
    unordered_map<string, MaxHeap<Accident>> maxStateMap = CreateMap<MaxHeap<Accident>>();
    unordered_map<string, MinHeap<Accident>> minStateMap = CreateMap<MinHeap<Accident>>();
    unordered_map<string, RedBlackTree> treeStateMap = CreateMap<RedBlackTree>();

    ReadFile("US_Accidents_100000.csv", maxStateMap, minStateMap, treeStateMap);
    cout << "Done reading file." << std::endl;


    //INITIALIZE IMPORTANT OBJECTS NECESSARY TO PRINT THINGS TO SCREEN
    sf::RenderWindow window(sf::VideoMode(1900, 1000), "SFML works!");
    std::map<string, Button> buttons;
    createButtons(buttons);

    std::vector<sf::Texture*> vect;
    sf::Texture search = TextureManager::GetTexture("search");
    sf::Texture results = TextureManager::GetTexture("results");

    sf::Texture fair = TextureManager::GetTexture("fair");
    sf::Texture cloudy = TextureManager::GetTexture("cloudy");
    sf::Texture rain = TextureManager::GetTexture("rain");
    sf::Texture snow = TextureManager::GetTexture("snow");
    sf::Texture fair_np = TextureManager::GetTexture("fair_notpressed");
    sf::Texture cloudy_np = TextureManager::GetTexture("cloudy_notpressed");
    sf::Texture snow_np = TextureManager::GetTexture("snow_notpressed");
    sf::Texture rain_np = TextureManager::GetTexture("rain_notpressed");

    std::map<string, sf::ConvexShape> states;
    loadStates(states);

    vector<StateButton> stateButtons; 
    loadStateButtons(stateButtons); 

    vector<Accident> accidents; 
    //WHILE WINDOW IS OPEN
    while (window.isOpen())
    {
        bool result = false;
        string stateSelected;
        sf::Event event;
        while (window.pollEvent(event))
        {
            //IF WINDOW IS CLOSED
            if (event.type == sf::Event::Closed) {
                window.close();
                TextureManager::Clear();
                //  deleteTree(rbtree);
            }

            //If left click is detected, get coordinates and see if a button was pressed
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                auto coordinates = sf::Mouse::getPosition(window);
                stateSelected = findStateButtonPressed(coordinates, stateButtons);  
                if (stateSelected != "Not Found"); {
                    accidents.clear(); 
                    timedheap = 0.0f; 
                    timedtree = 0.0f; 
                    result = true;
                    firstTime = false;
                }
            }

        }
        //display new board
        window.clear();
        if (result) {
            displayNewBoard(window, states, treeStateMap, maxStateMap, stateButtons, stateSelected,timedtree,timedheap, accidents);
        }
        else {
            displayNewBoard(window, states, treeStateMap, maxStateMap, stateButtons, accidents, timedtree, timedheap, firstTime);
        }
    }

    return 0;
}

template<typename H>
unordered_map<string, H> CreateMap() {
    unordered_map<string, H> StateMap;
    StateMap["AL"];
    StateMap["AK"];
    StateMap["AZ"];
    StateMap["AR"];
    StateMap["CA"];
    StateMap["CO"];
    StateMap["CT"];
    StateMap["DE"];
    StateMap["FL"];
    StateMap["GA"];

    StateMap["HI"];
    StateMap["ID"];
    StateMap["IL"];
    StateMap["IN"];
    StateMap["IA"];
    StateMap["KS"];
    StateMap["KY"];
    StateMap["LA"];
    StateMap["ME"];
    StateMap["MD"];

    StateMap["MA"];
    StateMap["MI"];
    StateMap["MN"];
    StateMap["MS"];
    StateMap["MO"];
    StateMap["MT"];
    StateMap["NE"];
    StateMap["NV"];
    StateMap["NH"];
    StateMap["NJ"];

    StateMap["NM"];
    StateMap["NY"];
    StateMap["NC"];
    StateMap["ND"];
    StateMap["OH"];
    StateMap["OK"];
    StateMap["OR"];
    StateMap["PA"];
    StateMap["RI"];
    StateMap["SC"];

    StateMap["SD"];
    StateMap["TN"];
    StateMap["TX"];
    StateMap["UT"];
    StateMap["VT"];
    StateMap["VA"];
    StateMap["WA"];
    StateMap["WV"];
    StateMap["WI"];
    StateMap["WY"];

    return StateMap;
}

