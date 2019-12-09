#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <list>
#include <ctime>
#include <stdexcept>
#include <regex>
#include <map>
#include "SalesAnalysis.h"
#include "StockItem.h"
#include "Sale.h"

enum class SIZE { XS, S, M, L, XL, XXL, XXXL };
using namespace std;

static string time_to_local_date(time_t& utc)
{
	struct tm newtime;
	time_t now = utc;
	localtime_s(&newtime, &now);

	string date = to_string(newtime.tm_mday) + "/" + to_string(newtime.tm_mon +1) + "/" + to_string(1900 + newtime.tm_year);

	return date;
}