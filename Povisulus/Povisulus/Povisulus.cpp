// Povisulus.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <map>
using namespace std;


class CGallows
{
	ifstream m_input;
	const string m_word;
	map<char, vector<size_t>> m_posMap;
	string m_searchWord;

	static const vector<string> m_images;

	enum steps : size_t
	{
		BEGIN,
		ONE, TWO, THREE, FOR, FIVE, SIX, SEVEN,
		END
	} m_step = BEGIN;

	enum result : size_t
	{
		LOSE, WIN
	} m_res = LOSE;

	void FillMap()
	{
		size_t pos{};
		for (char ch : m_word)
			m_posMap[ch].emplace_back(pos++);
	}

	char getChar()
	{
		cout << "Enter one character: ";
		char ch{}; cin >> ch;

		return m_posMap.find(ch) != m_posMap.cend() ? ch : '\0';
	}

	friend steps& operator++(steps&);
public:
	CGallows(const string& filename = "word.txt") :
		m_input(filename),
		m_word(
		istream_iterator<char>(m_input),
		istream_iterator<char>()
		),
		m_searchWord(m_word.size(), '*')
	{
		FillMap();
	};

	void Play()
	{
		while (m_step != END)
		{
			system("cls");
			cout << "Tvoye slovo: " << m_searchWord << '\n' << endl;
			cout << m_images[m_step] << endl;

			if (char ch{ getChar() })
			{
				const vector<size_t>& vec{ m_posMap[ch] };
				for (size_t i{}, end{ vec.size() }; i < end; ++i)
					m_searchWord[vec[i]] = ch;

				m_posMap.erase(ch);

				if (m_searchWord.find('*') == string::npos)
					m_step = END, m_res = WIN;
			}
			else
				++m_step;
		}

		system("cls");
		cout << "\nSlovo: " << m_word << endl;
		cout << "Tu " << (m_res == WIN ? "Molodets.\n" : "prograv.\n") << endl;
	}
};

CGallows::steps& operator++(CGallows::steps&);

int main()
{
	CGallows game;
	game.Play();

	system("pause");
}

CGallows::steps& operator++(CGallows::steps& st)
{
	size_t tmp = st;
	return st = static_cast<CGallows::steps>(++tmp);
}

const vector<string> CGallows::m_images
{
	{},
	{
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		"\n"
		" $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
		" $                          $\n"
	},
	{
		"        $$$$$$$$$$$$$$$\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		" $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
		" $                          $\n"
	},
	{
		"        $$$$$$$$$$$$$$$\n"
		"        |             $\n"
		"        |             $\n"
		"        |             $\n"
		"        |             $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		" $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
		" $                          $\n"
	},
	{
		"        $$$$$$$$$$$$$$$\n"
		"        |             $\n"
		"        |             $\n"
		"        |             $\n"
		"        |             $\n"
		"        O             $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		" $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
		" $                          $\n"
	},
	{
		"        $$$$$$$$$$$$$$$\n"
		"        |             $\n"
		"        |             $\n"
		"        |             $\n"
		"        |             $\n"
		"        O             $\n"
		"      /   \\           $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		" $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
		" $                          $\n"
	},
	{
		"        $$$$$$$$$$$$$$$\n"
		"        |             $\n"
		"        |             $\n"
		"        |             $\n"
		"        |             $\n"
		"        O             $\n"
		"      / | \\           $\n"
		"        |             $\n"
		"                      $\n"
		"                      $\n"
		"                      $\n"
		" $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
		" $                          $\n"
	},
	{
		"        $$$$$$$$$$$$$$$\n"
		"        |             $\n"
		"        |             $\n"
		"        |             $\n"
		"        |             $\n"
		"        O             $\n"
		"      / | \\           $\n"
		"        |             $\n"
		"       / \\            $\n"
		"                      $\n"
		"                      $\n"
		" $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
		" $                          $\n"
	}
};