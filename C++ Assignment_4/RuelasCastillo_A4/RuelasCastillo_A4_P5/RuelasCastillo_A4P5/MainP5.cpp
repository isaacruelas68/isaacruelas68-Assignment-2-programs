//ISAAC RUELAS CASTILLO ASSIGNMENT 4 PROBLEM 5
#include <iostream>
#include <vector>
#include <fstream>
#include <typeinfo>
#include <string>
#include<map>
using namespace std;
int main()
{
	vector<string> m1;
	vector<int> m2;

	ifstream file;
	string grab;
	int zero = 0;
	file.open("C:\\Users\\Isaac's PC\\source\\repos\\RuelasCastillo_A4P5\\MovieFile.txt");
	
	while (!file.eof())//gets all of the strings saved into the m1 vector
	{
		getline(file, grab);
		m1.push_back(grab);
	}
	for (int i = 0; i < m1.size(); i++)//turns all of the number ratings into ints and saves them into a vector
	{
		
		m2.push_back(stoi(m1[i]));
		m1.erase(m1.begin()+zero);//deletes the numbers from the first vector array
		zero++;
	}

	int num = 1;
	map <string,vector<int>> movies;//creates the movies map//THIS USED TO BE MAP<STRING,INT> AND WE USED M2[RUN] 
	map<string, vector<int>>::const_iterator iter;
	map<string, vector<int>>::const_iterator its;
	vector<int> hold;
	movies[m1[0]] = hold;//puts the name and rating inside of the map

	for (int run = 0; run < m1.size()-1; run++)
	{
		hold.push_back(m2[num]);//adds the number to the hold vector
		
		for (iter = movies.begin(); iter != movies.end(); iter++)//run through the whole map
		{
			for (its = movies.begin(); its != movies.end(); its++)//this loop iterates through all the current maps
			{
				if ((movies.find(m1[run]) == movies.find(its->first)))//if the movie is already into the iteration
				{
					movies[m1[run]].push_back(m2[num]);//hold.push_back(m2[num]);
				}
			}
			
			if ((movies.find(m1[run]) == movies.end())&&(movies.find(m1[run]) != movies.find(iter->first)) )//checks that the end and the beginning arent the same
			{
				hold.clear();
				hold.push_back(m2[num]);//add the new rating to the new slotted map
				movies[m1[run]] = hold;//puts the name and rating inside of the map
				break;
	
			}
			
			
			else
				break;
		}
		
		
		num++;
	
	}

	int plus=0,ph=0;
	cout << "here is the end result and averages for the movies" << endl;
	
	
	for (auto bitsy = movies.begin(); bitsy != movies.end(); bitsy++)//this for loop runs through the entire map vector 
	{
		if (bitsy->second.size() > 1)//this checks for movies with more than one rating and takes he average
		{
			for (int rn = 0; rn < bitsy->second.size(); rn++)//this loop adds the average of all the vectors 
			{
				
				ph = bitsy->second[rn];
				plus = ph+plus;
			}
			cout << bitsy->first << " - " << bitsy->second.size() << " Reviews, Average of " << (double)plus/(double)(bitsy->second.size()) << "/5" << endl;//prints out the result
		}
		else
		cout << bitsy->first << " - " << bitsy->second.size() <<" Reviews, Average of "<<(bitsy->second[0])/(bitsy->second.size())<<"/5"<< endl;//prints out the results
		
		plus = 0;
	}

	return 0; 
}