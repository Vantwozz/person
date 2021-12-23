#include "Person.h"
vector<person> person::v = vector<person>();
void person::print() const
{
	cout << "Name: " << name << endl;
	if (motherID != -1) {
		cout << "Mother name : " << v[motherID].name << endl;
	}
	else {
		cout << "Person has no mother" << endl;
	}
	if (fatherID != -1) {
		cout << "Father name : " << v[fatherID].name << endl;
	}
	else {
		cout << "Person has no father" << endl;
	}
	cout << "Gender : " << getGender() << endl;
	cout << "ID : " << getID() << endl;
}
person person::GiveBirth(const string& name, Gender gender, person father)
{
	string bname;
	if (this->gender == Gender::female) {
		if (!name.empty()) {
			bname = name;
		}
		else {
			throw logic_error("Person must have a name");
		}
		return person(bname, gender, *this, father);
	}
	else {
		throw logic_error("Only Female gender can give birth");
	}
}
person::person() {
	ID = -1;
}
person::person(const string& name, Gender gender, person mother, person father)
{
	this->name = name;
	if (name.empty()) {
		throw logic_error("person must have a name");
	}
	this->gender = gender;
	motherID = mother.ID;
	fatherID = father.ID;
	ID = v.size();
	v.push_back(*this);
	if (motherID == -1 && ID > 1 && name != "Adam" && name != "Eva") {
		throw logic_error("Person must have mother if this person isn't first (Adam) or second (Eva) person on earth");
	}
	if (motherID != -1 && v[motherID].gender != Gender::female) {
		throw logic_error("Mother must be female");
	}
	if (fatherID != -1 && v[fatherID].gender != Gender::male) {
		throw logic_error("Father must be male");
	}
	
}

int person::getID() const
{
	return ID;
}

void person::getMotherInfo() const
{
	cout << "Information about " << getName() << "'s mother :" << endl;
	v[motherID].print();
}

void person::getFatherInfo() const
{
	if (fatherID != -1) {
		cout << "Information about " << getName() << "'s father :" << endl;
		v[fatherID].print();
	}
	else {
		cout << "person has no father" << endl;
	}
}

string person::getGender() const
{
	string s ;
	if (gender == Gender::male) {
		s = "male";
	}
	else {
		s = "female";
	}
	return s;
}

string person::getName() const
{
	return name;
}