// Jack Palmstrom            ccc username: jnpalmstrom

// ----------------------------------------------------- Header Files -------------------------------------------------------------------------------------- //
#include <iostream>
#include <iomanip>
using namespace std;
#include "Queue.h"
// -------------------------------------------------------------------------------------------------------------------------------------------------------- //

// argv[1] = Number of Customers
// argv[2] = Number of Tellers
// argv[3] = Simulation Time
// argv[4] = Average Service Time
// argv[5] = <seed>

int main(int argc, char* argv[]) {

	// Min & Max values for user input
	/*const int MIN_SIM_TIME = 0, MAX_SIM_TIME = 10000,
			MIN_TRANS_TIME = 0, MAX_TRANS_TIME = 100,
			MIN_NUM_SERV = 0, MAX_NUM_SERV = 10,
			MIN_ARRIV_TIME = 0, MAX_ARRIV_TIME = 100; */

	char runAgain = 'Y';																		//Set runAgain so the program runs
	int sim_Time, average_service_Time, num_Serv; //arriv_Time;												// User input variables
	int i, c_Time;																				// Counters
	int customers, wait_Time;																	// Total customers & integer for customer waiting time
	unsigned int seed;
	float arriv_Time;

	customers = 0;
	num_Serv = 0;
	sim_Time = 0;
	average_service_Time = 0;
	seed = 0;

	for (int x = 0; x < argc; x++) {

		switch(x) {
			case 1:
				customers = atoi(argv[1]);
				break;
			case 2:
				num_Serv = atoi(argv[2]);
				break;
			case 3:
				sim_Time = atoi(argv[3]);
				break;
			case 4:
				average_service_Time = atoi(argv[4]);
				break;
			case 5:
				seed = atoi(argv[5]);
				break;
			default:
				break;
		}
		x++;
	}

	if (!seed) {
		srand(seed);
	}
	else {
		srand(time(NULL));
	}

	while(runAgain != 'N') {

		i = 0;
		c_Time = 0;
		wait_Time = 0;
		Queue bankQ;																			// Create queue object

		cout << "\n------------------------------------------"
				<< "\n- Welcome to the Bank Simulation Program -"
				<< "\n------------------------------------------";

		Teller_s * tellArray = new Teller_s[num_Serv];

		// Set all tellers to empty
		for(i = 0; i <= num_Serv; i++) {
			tellArray[i].active = false;
			tellArray[i].time_At = average_service_Time;
			tellArray[i].id = 0;
			tellArray[i].count = 0;
		}

		int total_service_time = 0;
		int total_teller_Idle = 0;
		int arriv_Customers = 0;
		int wait = 0;
		int max_wait_Time = 0;

		while(c_Time < sim_Time) {																// Run until Sim time is reached

			arriv_Customers = rand() % 5;

			for (i = 0; i < arriv_Customers; i++) {
				arriv_Time = sim_Time * rand() / float(RAND_MAX);
				bankQ.enqueue(++customers, arriv_Time);
			}

			for (i = 0; i < num_Serv; i++) {
				if (tellArray[i].active == false && bankQ.getSize() != 0) { 					// Dequeue if a teller is open

					total_teller_Idle = total_teller_Idle + 1;

					float service_Time = (2 * average_service_Time * rand()) / float(RAND_MAX);
					total_service_time += service_Time;

					tellArray[i].active = true;
					tellArray[i].time_At = service_Time;
					tellArray[i].id = bankQ.front()->id;
					tellArray[i].count++;
					wait = arriv_Time - bankQ.front()->enqueue_Time;

					if (wait > max_wait_Time) {
						max_wait_Time = wait;
					}

					cout <<"Server " << i << "  is serving customer " << tellArray[i].id << "." << endl;
					cout << "Waited time " << wait << " transaction time " << service_Time << "." << endl;
					cout << "\n";
					bankQ.dequeue();
				}

			}

			for (i = 0; i < num_Serv; i++) {
				if (tellArray[i].active == true) {
					tellArray[i].time_At--;  //Decrement time spent at teller
				}
				if (tellArray[i].time_At == 0) {
					tellArray[i].active = false; //Set teller to open if time limit is reached
				}
			}
			wait_Time += bankQ.getSize(); //Set wait time to persons left in Queue*/
			c_Time++;
		}
		//Output user input data
		cout << "\n---------------"
			 << "\n- Data Output -"
			 << "\n---------------\n";

		// Total Number of Customers Served
		cout << setw(31) << left << "Total Number of Customers Served: ";
		cout << customers << endl;
		// Total Time required to serve all customers
		cout << setw(31) << left << "Total Time Required to Serve All Customers: ";
		cout << c_Time << endl;
		// Number of tellers and type of queuing (1 per teller or common)
		cout << setw(31) << left << "Number of Tellers: ";
		cout << num_Serv << endl;

		cout << setw(31) << left << "Type of Queuing: ";
		cout << "1 per Teller" << endl;
		// Average amount of time a customer spent in the bank & standard deviation

		cout << setw(31) << left << "Average Transaction Time: ";
		cout << float(total_service_time) / (customers - bankQ.getSize()) << endl;

		// Max wait time from the time of arrival to time seen by teller

		cout << setw(31) << left << "Max Wait Time: ";
		cout << max_wait_Time << endl;

		// Total Amount of teller service time

		cout << setw(31) << left << "Total Teller Service Time: ";
		cout << total_service_time << endl;

		// Total Amount of teller idle time

		cout << setw(31) << left << "Total Teller Idle Time: ";
		cout << total_teller_Idle << endl;

		cout << "\n";
		cout << "After simulation time : " << endl;
		cout << "\n";

		cout << "server " << i << " is serving customer " << tellArray[i].id << "." << endl;
		cout << "server " << i << " has served " << tellArray[i].count << " customers." << endl;

		//Ask to run again
		cout << "\nRun the program again? (y/n): ";
		cin >> runAgain;
		runAgain = (char)toupper(runAgain);
		while (runAgain != 'Y' && runAgain != 'N') {
			cout << "Invalid Entry, please re-enter: ";
			cin >> runAgain;
			runAgain = (char)toupper(runAgain);
		}
		//Deallocate teller structure array
		delete [] tellArray;
	}
	return 0;
}
