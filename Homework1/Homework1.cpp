/*************************
** SAKARYA UNIVERSITY
** FACULTY OF COMPUTER AND INFORMATION SCIENCES
** DEPARTMENT OF COMPUTER ENGINEERING
** INTRODUCTION TO PROGRAMMING
** HOMEWORK NUMBER : 1
* *STUDENT NAME : Merve GÜNAY
* *STUDENT NUMBER : B201210017
* *LESSON GROUP : Group C
* *************************/

#include <iostream>
#include <clocale>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");
	//The one mission

	string randomCities[14];                                              //Randomly selected cities.
	string keptLetter;                                                    //The letters kept from randomly selected cities.
	int numberHeld;                                                       //The int holding the random number used when choosing a random city.

	srand(time(0));


	int cityFound = 0;                                                    //'Has the city been found?' controller.
	int shortestCityFound = 99;                                            //Keeps the number of letters of the shortest city found.
	int most = 80, least = 0;                                             //Which 2 Value Range Will Keep Random Number.
	int numberOfletter = 3;                                               //How many letters is city?

	//I took the cities into a String Array.
	string trCities[81]{ "adana", "adıyaman", "afyonkarahisar", "ağrı", "aksaray", "amasya", "ankara", "antalya", "ardahan", "artvin", "aydın", "balıkesir", "bartın", "batman", "bayburt", "bilecik", "bingöl", "bitlis", "bolu", "burdur", "bursa", "çanakkale", "çankırı", "çorum", "denizli", "diyarbakır", "düzce", "edirne", "elazığ", "erzincan", "erzurum", "eskişehir", "gaziantep", "giresun", "gümüşhane", "hakkari", "hatay", "ığdır", "ısparta", "istanbul", "izmir", "kahramanmaraş", "karabük", "karaman", "kars", "kastamonu", "kayseri", "kilis", "kırıkkale", "kırklareli", "kırşehir", "kocaeli", "konya", "kütahya", "malatya", "manisa", "mardin", "mersin", "muğla", "muş", "nevşehir", "niğde", "ordu", "osmaniye", "rize", "sakarya", "samsun", "şanlıurfa", "siirt", "sinop", "sivas", "şırnak", "tekirdağ", "tokat", "trabzon", "tunceli", "uşak", "van", "yalova", "yozgat", "zonguldak" };

	int mostAndleastCity[2]{ 0,0 };                                        //Array containing the longest and shortest city: 0th index shortest city, 1st index longest city.


	for (int z = 0; z < 81; z++)                                          //Finding the longest and shortest city.
	{

		if (trCities[mostAndleastCity[0]].size() > trCities[z].size())     //The shortest city.
		{

		}
		else
		{
			mostAndleastCity[0] = z;
		}
	}
	for (int z = 0; z < 81; z++)
	{
		if (trCities[mostAndleastCity[1]].size() < trCities[z].size())     //The longest city.
		{

		}
		else
		{
			mostAndleastCity[1] = z;
		}
	}
	cout << "The Longest Letter : " << trCities[mostAndleastCity[0]] << "   The Shortest Letter : " << trCities[mostAndleastCity[1]] << endl << endl << endl << endl;

	
	//2nd,3rd,4st mission.

	for (int numbertesting = 0; numbertesting < 100000; numbertesting++)   //For loop returning 100000 times.
	{
		// Number of letters of the shortest cities reset in each loops.
		int shortestCityFound = 99;

		for (int randomNumber = 0; randomNumber < numberOfletter; randomNumber++)       //Generate Random Number.
		{
			numberHeld = rand() % (most - least + 1) + least;
			randomCities[randomNumber] = trCities[numberHeld];

		}

		for (int p = 0; p < numberOfletter; p++)                           //The shortest city among the provinces found.
		{
			if (randomCities[p].size() < shortestCityFound)
			{
				shortestCityFound = randomCities[p].size();

			}
		}

		for (int u = 0; u < shortestCityFound; u++)                       //Finding which letter of random provinces to take.
		{
			for (int y = 0; y < numberOfletter; y++)                      //Finding how many random city of letters will be taken.
			{
				keptLetter += randomCities[y].substr(u, 1);
			}

			for (int w = 0; w < 81; w++)                                  // Checking 'Does the combined letters create a meaningful city name'.
			{
				if (keptLetter == trCities[w])
				{
					cityFound++;
					break;
				}
			}

			if (cityFound == 1)                                           //Actions to be taken when the city is found.
			{
				cout << " the city found with " << numberOfletter << " letters: " << keptLetter << endl;
				cout << " Found in the " << u + 1 << "st letters." << endl;           //The output of the city found comes from the number of which letters of the random cities.

				for (int m = 0; m < numberOfletter; m++)                  //Which random cities the found city consists of.
				{
					cout << randomCities[m] << endl;
				}
				cout << endl;

				keptLetter = "";                                         //Reset concatenated the letters.
				numberOfletter++;                                        //How many letter provinces are searched will put them in the next letter.
				cityFound = 0;
				break;
			}

			keptLetter = "";                                             //Reset concatenated the letters.
		}

		if (numberOfletter == 14 && numbertesting == 99999)              //If the 14-letter city cannot be found, break the loop.
		{
			cout << " No city found with " << numberOfletter << " letters! " << endl;
			break;
		}

		if (cityFound == 0 && numbertesting == 99999)                    //If the city is searched 100000 times and not found, start searching for the city with one more letter number.
		{
			cout << "No city found with " << numberOfletter << " letters!" <<  endl;
			numberOfletter++;
			cityFound = 0;
			numbertesting = 0;
		}
	}

	cout << endl;
	cout << endl;
	system("pause");
	return 0;
}