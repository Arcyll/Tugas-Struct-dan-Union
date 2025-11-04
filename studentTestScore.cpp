#include <iostream>
#include <iomanip> //untuk setw
using namespace std;

struct studentType {
	string studentFName;
	string studentLName;
	int testScore;
	char grade;
};

//berisi data 20 siswa
void studentData (studentType student[], int size) {
	string FName[] = {"Nur", "Jafar", "Irfan", "Rafi", "Arif", "Cantika", "Andhika", "Fadil", "Tiara", "Andhika", "Rangga", "Julia", "Indah", "Ahmad", "Jason", "Risky", "Muhammad", "Alifa", "Dila", "Andhika"};
	string LName[] = {"Azizah", "Shodiq", "Hakim", "Ahmad", "Setiawan", "Bunga", "Pratama", "Ikram", "Andini", "Prasetya", "Saputra", "Isnaini", "Aprilia", "Zidan", "Susanto", "Febian", "Ibrahim", "Qonita", "Aulia", "Nugraha"};
	int Score[] = {75, 85, 90, 15, 55, 70, 95, 20, 30, 10, 95, 80, 70, 65, 95, 80, 75, 90, 100, 40};
	
	for (int i = 0; i < size; i++)
    {
        student[i].studentFName = FName[i];
        student[i].studentLName = LName[i];
        student[i].testScore = Score[i];
    }
}

//menentukan grade siswa berdasarkan skornya
void studentGrade (studentType s[], int counter) {
	for (int i = 0; i < counter; i++) {
		if (s[i].testScore >= 90) s[i].grade = 'A';
		else if (s[i].testScore >= 80) s[i].grade = 'B';
		else if (s[i].testScore >= 75) s[i].grade = 'C';
		else if (s[i].testScore >= 50) s[i].grade = 'D';
		else s[i].grade = 'E';
	}
}

//mencari skor tertinggi
int highestScore (studentType s[], int counter) {
	int highest_score = 0;
	
	for (int j = 0; j < counter; j++) {
		if (s[j].testScore > highest_score)
		highest_score = s[j].testScore;
	}
	return highest_score;
}

//menampilkan data siswa dalam bentuk tabel
void printName (studentType s[], int size, int highest) {
	cout << left << setw(25) << "Full Name"
        << setw(10) << "Score"
        << setw(6) << "Grade" << endl;
    cout << "------------------------------------------" << endl;
    
    for (int i = 0; i < size; i++) {
    	string fullName = s[i].studentLName + ", " + s[i].studentFName;
        cout << left << setw(25) << fullName
            << setw(10) << s[i].testScore
            << setw(6) << s[i].grade << endl;
    }
    cout << endl;
    
    cout << "Highest score : ";
    for (int i = 0; i < size; i++) {
        if (s[i].testScore == highest)
            cout << highest << endl;
    }
    
    cout << "Student with the highest score :" << endl;
    for (int i = 0; i < size; i++) {
        if (s[i].testScore == highest)
            cout << s[i].studentLName << ", " << s[i].studentFName << endl;
    }
}
int main() {
	const int NUM_STUDENT = 20;
	studentType student [NUM_STUDENT];
	
	studentData(student, NUM_STUDENT);
	studentGrade (student, NUM_STUDENT);
	int highest = highestScore (student, NUM_STUDENT);
	printName (student, NUM_STUDENT, highest);
	
	return 0;
}
