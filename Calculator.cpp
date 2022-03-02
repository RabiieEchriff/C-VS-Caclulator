#include<iostream>
#include<string>
#include<fstream>
#include<cmath>
#include"Calculator.h"

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

using namespace System;
using namespace System::Windows::Forms;
[System::STAThread]

int main() {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Calculator::Calculator Calculator;
	Application::Run(% Calculator);

	int i; std::cin >> i;
}

std::string isolate(std::string inpu) {

	std::string part;
	int detector;
	int leng;

	leng = inpu.size();
	detector = inpu.find_first_of(")");
	part = inpu.substr(0, (detector + 1));
	leng = part.size();
	detector = part.find_last_of("(");
	part = part.substr((detector + 1), (leng - detector - 2));
	return part;
}

int char_count(std::string input, std::string chars) {
	int len = input.size();
	std::string inp = input;
	int charnumb = 0;
	int charnum = 1;
	int pos;
	int le = len;

	while (charnum != 0) {
		charnum = 1;
		for (int i = 0; i < le; i++) {
			pos = inp.find_first_of(chars);

			if (pos > (-1)) {
				inp = inp.erase(0, pos + 1);
				charnum++;
			}
			else {

			}

		}
		charnum = charnum - 1;
		charnumb = charnumb + charnum;
		le = inp.size();
		inp = input;
		charnum = 0;
	}


	return charnumb;
}

foo extrac(std::string inpu, std::string resul) {
	foo compos;

	std::string coe1;
	char o1;
	std::string coe2;
	char o2;
	std::string inp = inpu;
	int pos;

	if (resul == "NULL") {
		pos = inp.find_first_of("+-*/^");
		inp = inp.erase(0, pos + 1);
	}
	else {}

	pos = inp.find_first_of("+-*/^");
	coe1 = inp.substr(0, pos);
	o1 = inp[pos];

	inp = inp.erase(0, pos + 1);

	pos = inp.find_first_of("+-*/^");

	coe2 = inp.substr(0, pos);
	if (pos == (-1)) {
		o2 = 'E';
	}
	else {
		o2 = inp[pos];
	}

	compos.coef1 = coe1;
	compos.op1 = o1;
	compos.coef2 = coe2;
	compos.op2 = o2;

	return compos;

};

std::string microcalculate(std::string ch1, char ch2, std::string ch3, char ch4) {
	float in1;
	float in3;
	float result;
	std::string part;

	if (ch2 == '-') {
		if (ch4 == '*') {
			part = "NULL";
		}
		else if (ch4 == '/') {
			part = "NULL";
		}
		else if (ch4 == '^') {
			part = "NULL";
		}
		else {

			if (ch1[0] == 'n' || ch3[0] == 'n') {

				if (ch3[0] == 'n' && ch1[0] != 'n') {
					ch3 = ch3.substr(1);
					in1 = stof(ch1);
					in3 = stof(ch3);
					result = in1 + in3;
				}
				else if (ch1[0] == 'n' && ch3[0] != 'n') {
					ch1 = ch1.substr(1);
					in1 = stof(ch1);
					in3 = stof(ch3);
					result = -(in1 + in3);
				}
				else {
					ch1 = ch1.substr(1);
					ch3 = ch3.substr(1);
					in1 = stof(ch1);
					in3 = stof(ch3);
					result = -in1 + in3;
				}

			}

			else {
				in1 = stof(ch1);
				in3 = stof(ch3);
				result = in1 - in3;
			}

			part = std::to_string(result);
		}

	}

	else if (ch2 == '+') {
		if (ch4 == '*') {
			part = "NULL";
		}
		else if (ch4 == '/') {
			part = "NULL";
		}
		else if (ch4 == '^') {
			part = "NULL";
		}
		else {
			if (ch1[0] == 'n' || ch3[0] == 'n') {

				if (ch3[0] == 'n' && ch1[0] != 'n') {
					ch3 = ch3.substr(1);
					in1 = stof(ch1);
					in3 = stof(ch3);
					result = in1 - in3;
				}
				else if (ch1[0] == 'n' && ch3[0] != 'n') {
					ch1 = ch1.substr(1);
					in1 = stof(ch1);
					in3 = stof(ch3);
					result = -in1 + in3;
				}
				else {
					ch1 = ch1.substr(1);
					ch3 = ch3.substr(1);
					in1 = stof(ch1);
					in3 = stof(ch3);
					result = -(in1 + in3);
				}

			}

			else {
				in1 = stof(ch1);
				in3 = stof(ch3);
				result = in1 + in3;
			}
			part = std::to_string(result);

		}
	}

	else if (ch2 == '*') {

		if (ch4 == '/') {
			part = "NULL";
			return part;
		}
		else if (ch4 == '^') {
			part = "NULL";
			return part;
		}
		else {
			if (ch1[0] == 'n' || ch3[0] == 'n') {
				if (ch1[0] == 'n' && ch3[0] != 'n') {
					ch1 = ch1.substr(1);
					in1 = stof(ch1);
					in3 = stof(ch3);
					result = -(in1 * in3);
				}
				else if (ch3[0] == 'n' && ch1[0] != 'n') {
					ch3 = ch3.substr(1);
					in1 = stof(ch1);
					in3 = stof(ch3);
					result = -(in1 * in3);
				}
				else if (ch1[0] == 'n' && ch3[0] == 'n') {
					ch1 = ch1.substr(1);
					ch3 = ch3.substr(1);
					in1 = stof(ch1);
					in3 = stof(ch3);
					result = in1 * in3;
				}
			}
			else {
				in1 = stof(ch1);
				in3 = stof(ch3);
				result = in1 * in3;
			}

			part = std::to_string(result);
		}
	}

	else if (ch2 == '/') {
		if (ch4 == '/') {
			part = "NULL";
			return part;
		}
		else if (ch4 == '^') {
			part = "NULL";
			return part;
		}
		else {
			if (ch1[0] == 'n' || ch3[0] == 'n') {

				if (ch1[0] == 'n' && ch3[0] != 'n') {
					ch1 = ch1.substr(1);
					in1 = stof(ch1);
					in3 = stof(ch3);
					result = -(in1 / in3);
				}
				else if (ch3[0] == 'n' && ch1[0] != 'n') {
					ch3 = ch3.substr(1);
					in1 = stof(ch1);
					in3 = stof(ch3);
					result = -(in1 / in3);
				}
				else if (ch1[0] == 'n' && ch3[0] == 'n') {
					in1 = stof(ch1);
					in3 = stof(ch3);
					result = in1 / in3;
				}
			}
			else {
				in1 = stof(ch1);
				in3 = stof(ch3);
				result = in1 / in3;
			}
		}


		part = std::to_string(result);

	}

	else if (ch2 == '^') {
		if (ch4 == '^') {
			part = "NULL";
			return part;
		}
		else {
			if (ch1[0] == 'n' || ch3[0] == 'n') {

				if (ch3[0] == 'n' && ch1[0] != 'n') {
					ch3 = ch3.substr(1);
					in1 = stof(ch1);
					in3 = stof(ch3);
					result = pow(in1, -in3);
				}
				else if (ch1[0] == 'n' && ch3[0] != 'n') {
					ch1 = ch1.substr(1);
					in1 = stof(ch1);
					in3 = stof(ch3);
					result = pow(-in1, in3);
				}
				else if (ch1[0] == 'n' && ch3[0] == 'n') {
					ch1 = ch1.substr(1);
					ch3 = ch3.substr(1);
					in1 = stof(ch1);
					in3 = stof(ch3);
					result = pow(-in1, -in3);
				}

			}
			else {
				in1 = stof(ch1);
				in3 = stof(ch3);
				result = pow(in1, in3);
			}
			part = std::to_string(result);
		}
	}

	return part;
}

std::string macrocalculate(std::string part) {
	int opcalc = 1;
	int i = part.find_first_of("+-*/");
	int j;
	int t1 = part.find("+-");
	int t2 = part.find("--");
	int t3 = part.find("*-");
	int t4 = part.find("/-");
	int t5 = part.find("^-");
	std::string result = "INIT";

	while (opcalc != 0) {

		if (part[0] == '-') {
			part[0] = 'n';
		}
		if (t1 != (-1) || t2 != (-1) || t3 != (-1) || t4 != (-1) || t5 != (-1)) {
			if (t1 != (-1)) { part[t1 + 1] = 'n'; t1 = (-1); }
			else if (t2 != (-1)) { part[t2 + 1] = 'n'; t2 = (-1); }
			else if (t3 != (-1)) { part[t3 + 1] = 'n'; t3 = (-1); }
			else if (t4 != (-1)) { part[t4 + 1] = 'n'; t4 = (-1); }
			else if (t5 != (-1)) { part[t5 + 1] = 'n'; t5 = (-1); }
		}
		else {
			opcalc = char_count(part, "+-*/^");

			if (opcalc == (0)) {
				return part;
			}

			foo four = extrac(part, result);

			std::string cha1 = four.coef1;
			char cha2 = four.op1;
			std::string cha3 = four.coef2;
			char cha4 = four.op2;

			result = microcalculate(cha1, cha2, cha3, cha4);

			if (result == "NULL") {
				four = extrac(part, result);

				std::string cha1 = four.coef1;
				char cha2 = four.op1;
				std::string cha3 = four.coef2;
				char cha4 = four.op2;

				result = microcalculate(cha1, cha2, cha3, cha4);

				if (cha2 == '*') { j = 0; }
				else if (cha2 == '/') { j = 1; }
				else if (cha2 == '^') { j = 2; }

				part = replac_priority(result, part, j);
			}
			else {
				i = part.find_first_of("+-*/^");
				part = replac(result, part, i);
			}



			opcalc = char_count(part, "+-*/^");

		}

	}
	return part;
}

std::string replac(std::string resul, std::string par, int i) {
	int opcalc = char_count(par, "+-*/^");

	if (opcalc == 1) {
		par = resul;
	}
	else {
		std::string resu = resul;
		int resulsize = resu.size();
		par = par.erase(0, i + 1);
		i = par.find_first_of("+-*/^");
		par = par.replace(0, i, resul);
	}
	return par;
}

std::string replac_priority(std::string result, std::string part, int j) {
	int pos;
	char op;
	std::string part1;
	std::string part2;




	if (j == 0) { op = '*'; }
	else if (j == 1) { op = '/'; }
	else if (j == 2) { op = '^'; }
	pos = part.find_first_of(op);
	part1 = part.substr(0, pos - 1);
	part2 = part.substr(pos + 1);
	pos = part1.find_last_of("+-*/^");
	part1 = part1.substr(0, pos + 1);
	pos = part2.find_first_of("+-*/^");

	if (pos == (-1)) {
		part = part1 + result;
	}
	else {
		part2 = part2.substr(pos);
		part = part1 + result + part2;
	}
	return part;
}

std::string replac_input(std::string input, std::string part) {
	std::string inpu = input;
	std::string par;
	int detector;
	int leng;

	leng = inpu.size();
	detector = inpu.find_first_of(")");
	par = inpu.substr(0, (detector + 1));
	leng = par.size();
	detector = par.find_last_of("(");
	par = par.substr((detector + 1), (leng - detector - 2));
	leng = par.size();
	input = input.erase(detector, leng + 2);
	leng = part.size();
	input = input.insert(detector, part);


	return input;
}

std::string calculate(System::String^ p_input) {
	std::fstream file;
	std::string input = " ";
	std::string part;


	msclr::interop::marshal_context context;
	input = context.marshal_as<std::string>(p_input);

	int parentcalc = 1;

	while (parentcalc != 0) {
		parentcalc = char_count(input, "()");


		if (parentcalc != 0) {


			part = isolate(input);

			part = macrocalculate(part);//Nice!

			input = replac_input(input, part);


		}

		else {
			part = input;
			part = macrocalculate(part);//Nice!
			input = part;
		}

	}
	if (input[0] == 'n') {
		input[0] = '-';
	}

	return input;
}

