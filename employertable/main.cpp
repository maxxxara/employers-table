#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Person {
  public:
  	unsigned int id;
    string name;
	string surname;
	string date;
	unsigned int gender;
    Person() {}
    Person(unsigned int id, string name, string surname, string date, unsigned int gender) {
        this->id = id;
        this->name = name;
        this->surname = surname;
        this->date = date;
        this->gender = gender;
    }
};
class Employer : public Person {
    public:
    	string tanamdeboba;
        int xelfasi;
        Employer() {}
        Employer(unsigned int id, string name, string surname, string date, unsigned int gender, string tanamdeboba, int xelfasi) {
        	this->id = id;
	        this->name = name;
    	    this->surname = surname;
        	this->date = date;
        	this->gender = gender;
            this->tanamdeboba = tanamdeboba;
            this->xelfasi = xelfasi;
        }
};

class Table {
	private:
		Employer *data;
		unsigned int N = 0;
		string file_path = "C:/Users/datim/Desktop/c++/users.txt";
		void coutData(unsigned int i) {
			cout << data[i].name << " \t|\t" << data[i].surname << "\t|\t" << data[i].date << "\t|\t" << data[i].gender
				<< "\t|\t" << data[i].tanamdeboba << "\t|\t" << data[i].xelfasi << "\n" << endl;
		}
	public:
		Table() {
			createArray();
		}
		unsigned int getN() {
			return N;
		}
		void createArray() {
			string tmp;
			ifstream file(file_path.c_str());
			while(getline(file, tmp)) {
				this->N = this->N + 1;
			}
			data = new Employer[N];
		}
		void writeInArray() {
			fstream file(file_path.c_str());
			string id, name, surname, date, gender, tanamdeboba, xelfasi;
			unsigned int count = 0;
			while(file >> id >> name >> surname >> date >> gender >> tanamdeboba >> xelfasi) {
				if(count > N) {
					break;
				}
				data[count].id = atoi(id.c_str());
				data[count].name = name;
				data[count].surname = surname;
				data[count].date = date;
				data[count].gender = atoi(gender.c_str());
				data[count].tanamdeboba = tanamdeboba;
				data[count].xelfasi = atoi(xelfasi.c_str());
				count++;
			}
		}
		void selectAll() {
			writeInArray();
			for(int i = 0; i < N; i++){
				cout << data[i].name << " \t|\t" << data[i].surname << "\t|\t" << data[i].date << "\t|\t" << data[i].gender
				<< "\t|\t" << data[i].tanamdeboba << "\t|\t" << data[i].xelfasi << "\n" << endl;
			}
		}
		void selectAll(Employer *data) {
			writeInArray();
			for(int i = 0; i < N; i++){
				coutData(i);
			}
		}
		void insert(Employer single) {
			ofstream file;
			file.open(file_path.c_str(), std::ios_base::app);
			file << "\n"<< single.id << " " << single.name << " " << single.surname << " " << single.date << " " << single.gender << " " 
			<< single.tanamdeboba << " " << single.xelfasi;
		}
		void deleteId(unsigned int id) {
			writeInArray();
			for(int i = 0; i < N; i++){
				if(data[i].id != id) {
					coutData(i);
				}
			}
		}
		void filterGender(unsigned int gen) {
			writeInArray();
			for(int i = 0; i < N; i++){
				if(data[i].gender == gen) {
					coutData(i);
				}
			}
		}
		void xelfasiRange(unsigned int r1, unsigned int r2) {
			writeInArray();
			for(int i = 0; i < N; i++){
				if(data[i].xelfasi > r1 && data[i].xelfasi < r2) {
					cout << data[i].name << " \t|\t" << data[i].surname << "\t|\t" << data[i].date << "\t|\t" << data[i].gender
					<< "\t|\t" << data[i].tanamdeboba << "\t|\t" << data[i].xelfasi << "\n" << endl;
				}
			}
		}
};
int main() {
	Employer emp = Employer(3, "name3", "surname3", "date3", 0, "tanamdeboba3", 155464);
    Table t = Table();
    t.filterGender(1);
    return 0;
}
