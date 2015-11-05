//============================================================================
// Name        : findStatisticsMGNLO.cpp
// Author      : Raquel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include<iostream>
#include<fstream>
using namespace std;
//#include "Plot.h"
//#include "YodaFile.h"
#include <sys/stat.h>  //What is this?
#include <sstream> //For scientific notation

string line;
ifstream file;
ofstream outfile;
int nBins;
long double entry;
float scale0bin[5][60]; // 60 bins for the scale 0 yoda, we want the 3rd entry: val
float downbin[5][60]; //bins for the smaller yoda file
float upbin[5][60];  // bins for the bigger file
float temp1, temp2;

int main() {
	cout << "Hello World!" << endl; // prints !!!Hello World!!!

	mkdir("./newFiles", ACCESSPERMS);

	file.open("ZZGen_05-njet_onPeak.dat");
	outfile.open("./newFiles/statisticsMGNLO.txt");

	outfile << "Plot nr1: " << "n-jet on-peak" << endl << endl;
	outfile
			<< "bin \t \t value \t \t \t smaller \t \t bigger \t \t down % \t \t up % "
			<< endl;

	do {
		getline(file, line);
		//cout << line << endl;
	} while (line != "# xlow	 xhigh	 val	 errminus	 errplus");
	streampos oldpos = file.tellg();  //stores position

	nBins = -1; //to discount the line #END HISTOGRAM
	while (line != "# END HISTOGRAM") {
		getline(file, line);
		nBins++;
	}

	cout << "This histogram has " << nBins << " bins " << endl;

	file.seekg(oldpos); //goes back to the bookmarked position

	for (int i = 0; i < nBins; i++) {  //record reference values
		for (int j = 0; j < 5; j++)
			file >> scale0bin[j][i];
	}

	do {  // Seek for next plot: smallest
		getline(file, line);
		//cout << line << endl;
	} while (line != "# xlow	 xhigh	 val	 errminus	 errplus");

	for (int i = 0; i < nBins; i++) {  //record smaller values
		for (int j = 0; j < 5; j++)
			file >> downbin[j][i];
	}

	do {  // Seek for next plot: biggest
		getline(file, line);
		//cout << line << endl;
	} while (line != "# xlow	 xhigh	 val	 errminus	 errplus");

	for (int i = 0; i < nBins; i++) {  //record bigger values
		for (int j = 0; j < 5; j++)
			file >> upbin[j][i];
	}

	for (int j = 0; j < nBins; j++) {
		outfile << j + 1 << "\t \t" << scientific << scale0bin[2][j] << "\t \t"
				<< downbin[2][j] << "\t \t" << upbin[2][j];
		temp1 = (upbin[2][j] / scale0bin[2][j] - 1.0) * 100;
		temp2 = (downbin[2][j] / scale0bin[2][j] - 1.0) * 100;
		outfile << "\t " << fixed << temp2 << "\t \t" << temp1 << endl;
	}

	file.close();

	outfile << endl << endl << endl << endl;
	outfile << "Plot nr2: " << "TotalMass 0j" << endl << endl;
	outfile
	<< "bin \t \t value \t \t \t smaller \t \t bigger \t \t down % \t \t up % "
			<< endl;

	file.open("ZZGen_07-totalMass_0j.dat");

	do {
		getline(file, line);
		//cout << line << endl;
	} while (line != "# xlow	 xhigh	 val	 errminus	 errplus");
	oldpos = file.tellg();  //stores position

	nBins = -1; //to discount the line #END HISTOGRAM
	while (line != "# END HISTOGRAM") {
		getline(file, line);
		nBins++;
	}

	//cout << "This histogram has " << nBins << " bins " << endl;

	file.seekg(oldpos); //goes back to the bookmarked position

	for (int i = 0; i < nBins; i++) {  //record reference values
		for (int j = 0; j < 5; j++)
			file >> scale0bin[j][i];
	}

	do {  // Seek for next plot: smallest
		getline(file, line);
		//cout << line << endl;
	} while (line != "# xlow	 xhigh	 val	 errminus	 errplus");

	for (int i = 0; i < nBins; i++) {  //record smaller values
		for (int j = 0; j < 5; j++)
			file >> downbin[j][i];
	}

	do {  // Seek for next plot: biggest
		getline(file, line);
		//cout << line << endl;
	} while (line != "# xlow	 xhigh	 val	 errminus	 errplus");

	for (int i = 0; i < nBins; i++) {  //record bigger values
		for (int j = 0; j < 5; j++)
			file >> upbin[j][i];
	}

	for (int j = 0; j < nBins; j++) {
		outfile << j + 1 << "\t \t" << scientific << scale0bin[2][j] << "\t \t"
				<< downbin[2][j] << "\t \t" << upbin[2][j];
		temp1 = (upbin[2][j] / scale0bin[2][j] - 1.0) * 100;
		temp2 = (downbin[2][j] / scale0bin[2][j] - 1.0) * 100;
		outfile << "\t " << fixed << temp2 << "\t \t" << temp1 << endl;
	}

	file.close();

	outfile << endl << endl << endl << endl;
	outfile << "Plot nr3: " << "TotalMass 1j" << endl << endl;
	outfile
	<< "bin \t \t value \t \t \t smaller \t \t bigger \t \t down % \t \t up % "
			<< endl;

	file.open("ZZGen_08-totalMass_1j.dat");

	do {
		getline(file, line);
		//cout << line << endl;
	} while (line != "# xlow	 xhigh	 val	 errminus	 errplus");
	oldpos = file.tellg();  //stores position

	nBins = -1; //to discount the line #END HISTOGRAM
	while (line != "# END HISTOGRAM") {
		getline(file, line);
		nBins++;
	}

	cout << "This histogram has " << nBins << " bins " << endl;

	file.seekg(oldpos); //goes back to the bookmarked position

	for (int i = 0; i < nBins; i++) {  //record reference values
		for (int j = 0; j < 5; j++)
			file >> scale0bin[j][i];
	}

	do {  // Seek for next plot: smallest
		getline(file, line);
		//cout << line << endl;
	} while (line != "# xlow	 xhigh	 val	 errminus	 errplus");

	for (int i = 0; i < nBins; i++) {  //record smaller values
		for (int j = 0; j < 5; j++)
			file >> downbin[j][i];
	}

	do {  // Seek for next plot: biggest
		getline(file, line);
		//cout << line << endl;
	} while (line != "# xlow	 xhigh	 val	 errminus	 errplus");

	for (int i = 0; i < nBins; i++) {  //record bigger values
		for (int j = 0; j < 5; j++)
			file >> upbin[j][i];
	}

	for (int j = 0; j < nBins; j++) {
		outfile << j + 1 << "\t \t" << scientific << scale0bin[2][j] << "\t \t"
				<< downbin[2][j] << "\t \t" << upbin[2][j];
		temp1 = (upbin[2][j] / scale0bin[2][j] - 1.0) * 100;
		temp2 = (downbin[2][j] / scale0bin[2][j] - 1.0) * 100;
		outfile << "\t " << fixed << temp2 << "\t \t" << temp1 << endl;
	}

	file.close();

	outfile << endl << endl << endl << endl;
	outfile << "Plot nr4: " << "TotalMass 2j" << endl << endl;
	outfile
	<< "bin \t \t value \t \t \t smaller \t \t bigger \t \t down % \t \t up % "
			<< endl;

	file.open("ZZGen_09-totalMass_2j.dat");

	do {
		getline(file, line);
		//cout << line << endl;
	} while (line != "# xlow	 xhigh	 val	 errminus	 errplus");
	oldpos = file.tellg();  //stores position

	nBins = -1; //to discount the line #END HISTOGRAM
	while (line != "# END HISTOGRAM") {
		getline(file, line);
		nBins++;
	}

	cout << "This histogram has " << nBins << " bins " << endl;

	file.seekg(oldpos); //goes back to the bookmarked position

	for (int i = 0; i < nBins; i++) {  //record reference values
		for (int j = 0; j < 5; j++)
			file >> scale0bin[j][i];
	}

	do {  // Seek for next plot: smallest
		getline(file, line);
	//	cout << line << endl;
	} while (line != "# xlow	 xhigh	 val	 errminus	 errplus");

	for (int i = 0; i < nBins; i++) {  //record smaller values
		for (int j = 0; j < 5; j++)
			file >> downbin[j][i];
	}

	do {  // Seek for next plot: biggest
		getline(file, line);
	//	cout << line << endl;
	} while (line != "# xlow	 xhigh	 val	 errminus	 errplus");

	for (int i = 0; i < nBins; i++) {  //record bigger values
		for (int j = 0; j < 5; j++)
			file >> upbin[j][i];
	}

	for (int j = 0; j < nBins; j++) {
		outfile << j + 1 << "\t \t" << scientific << scale0bin[2][j] << "\t \t"
				<< downbin[2][j] << "\t \t" << upbin[2][j];
		temp1 = (upbin[2][j] / scale0bin[2][j] - 1.0) * 100;
		temp2 = (downbin[2][j] / scale0bin[2][j] - 1.0) * 100;
		outfile << "\t " << fixed << temp2 << "\t \t" << temp1 << endl;
	}

	file.close();


	//TO add more plots:
	/*
	 * file.open(<FILENAME>);
	 * 	outfile << endl << endl << endl << endl;
	outfile << "Plot nr5: " << "<TITLE>" << endl << endl;
	outfile
			<< "bin \t value \t \t \t \t  smaller  \t \t \t \t bigger \t \t down % \t \t  up % "
			<< endl;



	do {
		getline(file, line);
		cout << line << endl;
	} while (line != "# xlow	 xhigh	 val	 errminus	 errplus");
	oldpos = file.tellg();  //stores position

	nBins = -1; //to discount the line #END HISTOGRAM
	while (line != "# END HISTOGRAM") {
		getline(file, line);
		nBins++;
	}

	cout << "This histogram has " << nBins << " bins " << endl;

	file.seekg(oldpos); //goes back to the bookmarked position

	for (int i = 0; i < nBins; i++) {  //record reference values
		for (int j = 0; j < 5; j++)
			file >> scale0bin[j][i];
	}

	do {  // Seek for next plot: smallest
		getline(file, line);
		cout << line << endl;
	} while (line != "# xlow	 xhigh	 val	 errminus	 errplus");

	for (int i = 0; i < nBins; i++) {  //record smaller values
		for (int j = 0; j < 5; j++)
			file >> downbin[j][i];
	}

	do {  // Seek for next plot: biggest
		getline(file, line);
		cout << line << endl;
	} while (line != "# xlow	 xhigh	 val	 errminus	 errplus");

	for (int i = 0; i < nBins; i++) {  //record bigger values
		for (int j = 0; j < 5; j++)
			file >> upbin[j][i];
	}

	for (int j = 0; j < nBins; j++) {
		outfile << j + 1 << "\t \t" << scientific << scale0bin[2][j] << "\t \t"
				<< downbin[2][j] << "\t \t" << upbin[2][j];
		temp1 = (upbin[2][j] / scale0bin[2][j] - 1.0) * 100;
		temp2 = (downbin[2][j] / scale0bin[2][j] - 1.0) * 100;
		outfile << "\t " << fixed << temp2 << "\t \t" << temp1 << endl;
	}

	file.close();
	 *
	 */


	outfile.close();

	return 0;
}
