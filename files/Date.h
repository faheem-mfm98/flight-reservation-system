#pragma once
using namespace std;

class Date {
	int day;
	int month;
	int year;

public:
	Date() {
		day = NULL;
		month = NULL;
		year = NULL;
	}

	void setDay(int day_val) {
		day = day_val;
	}

	void setMonth(int month_val) {
		month = month_val;
	}

	void setYear(int year_val) {
		year = year_val;
	}

	int getDay() {
		return day;
	}

	int getMonth() {
		return month;
	}

	int getYear() {
		return year;
	}

	void displayDate() {
		cout << getDay() << "/" << getMonth() << "/" << getYear() << endl;
	}

};