#include <string>
#include <iostream>
#include <vector>
#pragma once
using namespace std;
enum class Gender { 
	male,
	female 
};
class person
{
public:
	person(const string& name, Gender gender, person mother = person(), person father = person());
	static vector<person> v;
	int getID()const;
	void getMotherInfo()const;
	void getFatherInfo()const;
	string getGender()const;
	string getName()const;
	void print()const;
	person GiveBirth(const string& name, Gender gender, person father = person());
private:
	person();
	Gender gender;
	string name;
	int ID;
	int fatherID =-1;
	int motherID =-1;
};