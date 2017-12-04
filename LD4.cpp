#include "cuda_runtime.h"
#include <cuda.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const THREAD_COUNT = 5;
const int ARRAY_SIZE = 5;
const string FileName = "IFF-5-1_GuzauskasL_L4dat.txt";
const string printname = "IFF-5-1_GuzauskasL_L4a_rez.txt";

struct Student{
      char name[75];
      int course;
      double average;
};

struct Faculty{
      char tilte[15];
      int countSk;
      Student Stu[ARRAY_SIZE];
};

cudaError_t addWithCuda(Student *s, Faculty *p);

/* Skaito duomenis iš failo
@param File - failo vardas
@param P - objektų vardas*/
void ReadData(ifstream & File, Faculty & P)
{
	string faculty, name, line;
	int studCout, course;
	double average;
	File >> P.tilte >> P.stucout;
	for (int i = 0; i < P.stucout; i++) {
		File >> name >> course >> average;
		Student s = Student(name, course, average);
		P.setStudent(s);
	}
}

/* Spausdina duomenis į failą
@param File - failo vardas
@param P - objektų vardas*/
void WriteData(FILE * File, string *S, int *I, double *D, int length)
{
	fprintf(File, "    Vardas    kursas     vid\n");
	for (int i = 0; i < length; i++) {
		fprintf(File, " %i) %s \t %i \t %g \n", i + 1, S[i].c_str(), I[i], D[i]);
	}
}

int main(){
      Faculty F[THREAD_COUNT];
      
      ifstream infile;
	    infile.open(FileName);
  
      ReadFile(FileName, F[i]);
}
