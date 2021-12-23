// Assignment9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ASSIGNMENT9.H"
#include <fstream>
#include <vector>
struct customer {
	int start;
	int time_spending;
	double spending;
};
using namespace std;


int main()
{	
	string file_name;
	cout << "Enter the file you want to run ";
	cin >> file_name;
	int cashier;
	cout << "Number of cashier ";
	cin >> cashier;
	vector<queue<double>> cashiers;
	queue<double> temp;

	//create number of given cashiers
	for (unsigned int i = 0; i < cashier; i++) {
		cashiers.push_back(temp);
	}
	//create vectors to store num and detail of given customer;
	vector<customer> customers;
	customer a;
	//open file and input customers into vector
	fstream fin;
	fin.open(file_name);
	while (!fin.eof()) {
		fin >> a.start;
		fin >> a.time_spending;
		fin >> a.spending;
		customers.push_back(a);
	}

	// time tracking
	vector <int> cashier_time;
	for (unsigned int i = 0; i < cashier; i++) {
		cashier_time.push_back(0);
	}

	// keep track revenue in cashier
	vector <double> cashier_revenue;
	for (unsigned int i = 0; i < cashier; i++) {
		cashier_revenue.push_back(0);
	}
	// keep track number of customer
	vector <int> cashier_customer;
	for (unsigned int i = 0; i < cashier; i++) {
		cashier_customer.push_back(0);
	}

	int  global_time = 0;
	int index_customer = 0;
	while (index_customer < customers.size()) {
		global_time++;
		bool served = false; // insert customer into the queue if that queue is empty and that no previous cashier serve that customer
		customer new_customer = customers[index_customer];
		// checking whether cashier finish his/her customer
		for (unsigned int i = 0; i < cashier_time.size(); i++) {
			if (global_time == cashier_time[i]) {
				cashiers[i].dequeue(); // if yes, remove customer
			}
		}
		
		// if the cashier is empty, customer goes to that cashier
		if (global_time >= new_customer.start) {
			for (unsigned int i = 0; i < cashiers.size(); i++) {
				if (cashiers[i].isEmpty() && !served) {
					int total_time = customers[index_customer].start + customers[index_customer].time_spending; // total of start and talking time
					cashier_time[i] = total_time; // update the total time
					double new_revenue = cashier_revenue[i] + customers[index_customer].spending;
					cashier_revenue[i]=new_revenue;
					cashier_customer[i]++;
					cashiers[i].enqueue(customers[i].spending); // update the money customer spends on the queue
					index_customer++; // update number of customers serve
					served = true;
				}
			}
		}
	};

	// print results.
	int longest_time = cashier_time[0];
	for (unsigned int i = 1; i < cashier_time.size(); i++) {
		if (longest_time < cashier_time[i]) {
			longest_time = cashier_time[i];
		}
	}
	
	cout << "Total time " << longest_time << endl;
	for (unsigned int i = 0; i < cashiers.size(); i++) {
		cout << "cashiers " << i << " " << "help " << cashier_customer[i] << " " <<"customer and took in $ " << cashier_revenue[i] << endl;

	}
		

	return 0;
}

