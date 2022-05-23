#pragma once

#include <string>
#include <vector>
using namespace std;

class Accident {
public:
	Accident(); 
	Accident(vector<int> intVector, vector<string> stringVector, vector<double> doubleVector);
	Accident(const Accident& rhs);
	bool operator<(const Accident& rhs);
	bool operator>(const Accident& rhs); 
	bool operator>(int rhs); 
	bool operator<(int rhs); 
	Accident&  operator=(const Accident& rhs); 
	void calculateSeverity(); 
	double getWeightedSeverity(); 
	string getState(); 
	string getCity(); 
	string getID(); 
	string getDescription(); 
private:
	int severity;
	int casualties; 
	int vehiclesInvolved; 
	string ID;
	string description;
	string city;
	string county;
	string state;
	string timeZone;
	string windDirection;
	string weatherCondition;
	string night_day;
	double start_lat;
	double start_long;
	double end_lat;
	double end_long;
	double distance;
	double temperature;
	double windChill;
	double humidity;
	double pressure;
	double visibility;
	double windSpeed;
	double precipitation;
	double weightedSeverity; 
	double timeDifference; 
};