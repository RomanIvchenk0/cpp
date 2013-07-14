#include "Header.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>


using namespace std;

const int maxX = 15;
const int maxY = 15;

CCell * pole[maxX][maxY] = {0};

//----------------------------------------------------------------------
CCell::CCell(int x, int y, bool mined) : m_opened(false), m_numberOfNearMines(0), m_gameOver(false) {
	m_coordX = x;
	m_coordY = y;
	m_mined  = mined;
}
//-----------------------------------------------------------------------
CCell::~CCell() {

}
//-----------------------------------------------------------------------
bool CCell::IsOpenedCell() const {
	return m_opened;
}
//-----------------------------------------------------------------------
int CCell::GetNumberOfNearMines() {
	
	//1
	if(m_coordX == 0 && m_coordY != 0 && (m_coordY < (maxY-1))) {
		int mines = 0;
		//if (pole[m_coordX - 1][m_coordY - 1]->m_mined) mines += 1;
		if (pole[m_coordX]    [m_coordY - 1]->m_mined) mines += 1;
		if (pole[m_coordX + 1][m_coordY - 1]->m_mined) mines += 1;
	 
		//if (pole[m_coordX - 1][m_coordY]->m_mined) mines += 1;
		if (pole[m_coordX + 1][m_coordY]->m_mined) mines += 1;

		//if (pole[m_coordX - 1][m_coordY + 1]->m_mined) mines += 1;
		if (pole[m_coordX]    [m_coordY + 1]->m_mined) mines += 1;
		if (pole[m_coordX + 1][m_coordY + 1]->m_mined) mines += 1;
		return mines;
	}
	//2
	if(m_coordX < (maxX-1) && (m_coordX != 0) && m_coordY == 0) {
		int mines = 0;
		//if (pole[m_coordX - 1][m_coordY - 1]->m_mined) mines += 1;
		//if (pole[m_coordX]    [m_coordY - 1]->m_mined) mines += 1;
		//if (pole[m_coordX + 1][m_coordY - 1]->m_mined) mines += 1;
	 
		if (pole[m_coordX - 1][m_coordY]->m_mined) mines += 1;
		if (pole[m_coordX + 1][m_coordY]->m_mined) mines += 1;

		if (pole[m_coordX - 1][m_coordY + 1]->m_mined) mines += 1;
		if (pole[m_coordX]    [m_coordY + 1]->m_mined) mines += 1;
		if (pole[m_coordX + 1][m_coordY + 1]->m_mined) mines += 1;
		return mines;
	}
	//3
	if(m_coordX == (maxX-1) && m_coordY < (maxY-1) && (m_coordY != 0)) {
		int mines = 0;
		if (pole[m_coordX - 1][m_coordY - 1]->m_mined) mines += 1;
		if (pole[m_coordX]    [m_coordY - 1]->m_mined) mines += 1;
		//if (pole[m_coordX + 1][m_coordY - 1]->m_mined) mines += 1;
	 
		if (pole[m_coordX - 1][m_coordY]->m_mined) mines += 1;
		//if (pole[m_coordX + 1][m_coordY]->m_mined) mines += 1;

		if (pole[m_coordX - 1][m_coordY + 1]->m_mined) mines += 1;
		if (pole[m_coordX]    [m_coordY + 1]->m_mined) mines += 1;
		//if (pole[m_coordX + 1][m_coordY + 1]->m_mined) mines += 1;
		return mines;
	}
	//4
	if(m_coordX < (maxX-1) && (m_coordX != 0) && m_coordY == (maxY-1)) {
		int mines = 0;
		if (pole[m_coordX - 1][m_coordY - 1]->m_mined) mines += 1;
		if (pole[m_coordX]    [m_coordY - 1]->m_mined) mines += 1;
		if (pole[m_coordX + 1][m_coordY - 1]->m_mined) mines += 1;
	 
		if (pole[m_coordX - 1][m_coordY]->m_mined) mines += 1;
		if (pole[m_coordX + 1][m_coordY]->m_mined) mines += 1;

		//if (pole[m_coordX - 1][m_coordY + 1]->m_mined) mines += 1;
		//if (pole[m_coordX]    [m_coordY + 1]->m_mined) mines += 1;
		//if (pole[m_coordX + 1][m_coordY + 1]->m_mined) mines += 1;
		return mines;
	}
	//5
	if(m_coordX == 0 && m_coordY == (maxY-1)) {
		int mines = 0;
		//if (pole[m_coordX - 1][m_coordY - 1]->m_mined) mines += 1;
		if (pole[m_coordX]    [m_coordY - 1]->m_mined) mines += 1;
		if (pole[m_coordX + 1][m_coordY - 1]->m_mined) mines += 1;
	 
		//if (pole[m_coordX - 1][m_coordY]->m_mined) mines += 1;
		if (pole[m_coordX + 1][m_coordY]->m_mined) mines += 1;

		//if (pole[m_coordX - 1][m_coordY + 1]->m_mined) mines += 1;
		//if (pole[m_coordX]    [m_coordY + 1]->m_mined) mines += 1;
		//if (pole[m_coordX + 1][m_coordY + 1]->m_mined) mines += 1;
		return mines;
	}
	//6
	if(m_coordX == 0 && m_coordY == 0) {
		int mines = 0;
		//if (pole[m_coordX - 1][m_coordY - 1]->m_mined) mines += 1;
		//if (pole[m_coordX]    [m_coordY - 1]->m_mined) mines += 1;
		//if (pole[m_coordX + 1][m_coordY - 1]->m_mined) mines += 1;
	 
		//if (pole[m_coordX - 1][m_coordY]->m_mined) mines += 1;
		if (pole[m_coordX + 1][m_coordY]->m_mined) mines += 1;

		//if (pole[m_coordX - 1][m_coordY + 1]->m_mined) mines += 1;
		if (pole[m_coordX]    [m_coordY + 1]->m_mined) mines += 1;
		if (pole[m_coordX + 1][m_coordY + 1]->m_mined) mines += 1;
		return mines;
	}
	//7
	if((m_coordX == (maxX-1)) && (m_coordY == 0)) {
		int mines = 0;
		//if (pole[m_coordX - 1][m_coordY - 1]->m_mined) mines += 1;
		//if (pole[m_coordX]    [m_coordY - 1]->m_mined) mines += 1;
		//if (pole[m_coordX + 1][m_coordY - 1]->m_mined) mines += 1;
	 
		if (pole[m_coordX - 1][m_coordY]->m_mined) mines += 1;
		//if (pole[m_coordX + 1][m_coordY]->m_mined) mines += 1;

		if (pole[m_coordX - 1][m_coordY + 1]->m_mined) mines += 1;
		if (pole[m_coordX]    [m_coordY + 1]->m_mined) mines += 1;
		//if (pole[m_coordX + 1][m_coordY + 1]->m_mined) mines += 1;
		return mines;
	}
	//8
	if(m_coordX == (maxX-1) && m_coordY == (maxY-1)) {
		int mines = 0;
		if (pole[m_coordX - 1][m_coordY - 1]->m_mined) mines += 1;
		if (pole[m_coordX]    [m_coordY - 1]->m_mined) mines += 1;
		//if (pole[m_coordX + 1][m_coordY - 1]->m_mined) mines += 1;
	 
		if (pole[m_coordX - 1][m_coordY]->m_mined) mines += 1;
		//if (pole[m_coordX + 1][m_coordY]->m_mined) mines += 1;

		//if (pole[m_coordX - 1][m_coordY + 1]->m_mined) mines += 1;
		//if (pole[m_coordX]    [m_coordY + 1]->m_mined) mines += 1;
		//if (pole[m_coordX + 1][m_coordY + 1]->m_mined) mines += 1;
		return mines;
	}
	//9
	if(m_coordX != 0 && m_coordY != 0 && m_coordX < (maxX-1) && m_coordY < (maxY-1)) {
		int mines = 0;
		if (pole[m_coordX - 1][m_coordY - 1]->m_mined) mines += 1;
		if (pole[m_coordX]    [m_coordY - 1]->m_mined) mines += 1;
		if (pole[m_coordX + 1][m_coordY - 1]->m_mined) mines += 1;
	 
		if (pole[m_coordX - 1][m_coordY]->m_mined) mines += 1;
		if (pole[m_coordX + 1][m_coordY]->m_mined) mines += 1;

		if (pole[m_coordX - 1][m_coordY + 1]->m_mined) mines += 1;
		if (pole[m_coordX]    [m_coordY + 1]->m_mined) mines += 1;
		if (pole[m_coordX + 1][m_coordY + 1]->m_mined) mines += 1;
		return mines;
	}

	
}
//----------------------------------------------------------------------
void		CCell::SetOpen() {
	m_opened = true;
}
//----------------------------------------------------------------------
void CCell::OpenNearZeroMines() {
		
		//1
		if ((m_coordX == 0) && (m_coordY != 0) && (m_coordY < (maxY-1))) {
			//pole[m_coordX - 1][m_coordY - 1]->SetOpen();
			pole[m_coordX]    [m_coordY - 1]->SetOpen();
			pole[m_coordX + 1][m_coordY - 1]->SetOpen();
	 
			//pole[m_coordX - 1][m_coordY]->SetOpen();
			pole[m_coordX + 1][m_coordY]->SetOpen();

			//pole[m_coordX - 1][m_coordY + 1]->SetOpen();
			pole[m_coordX]    [m_coordY + 1]->SetOpen();
			pole[m_coordX + 1][m_coordY + 1]->SetOpen();
		}
		//2
		if ((m_coordX != 0) && (m_coordX < (maxX-1)) && (m_coordY == 0)) {
			//pole[m_coordX - 1][m_coordY - 1]->SetOpen();
			//pole[m_coordX]    [m_coordY - 1]->SetOpen();
			//pole[m_coordX + 1][m_coordY - 1]->SetOpen();
	 
			pole[m_coordX - 1][m_coordY]->SetOpen();
			pole[m_coordX + 1][m_coordY]->SetOpen();

			pole[m_coordX - 1][m_coordY + 1]->SetOpen();
			pole[m_coordX]    [m_coordY + 1]->SetOpen();
			pole[m_coordX + 1][m_coordY + 1]->SetOpen();
		}
		//3
		if ((m_coordX == (maxX-1)) && (m_coordY != 0) && (m_coordY < (maxY-1))) {
			pole[m_coordX - 1][m_coordY - 1]->SetOpen();
			pole[m_coordX]    [m_coordY - 1]->SetOpen();
			//pole[m_coordX + 1][m_coordY - 1]->SetOpen();
	 
			pole[m_coordX - 1][m_coordY]->SetOpen();
			//pole[m_coordX + 1][m_coordY]->SetOpen();

			pole[m_coordX - 1][m_coordY + 1]->SetOpen();
			pole[m_coordX]    [m_coordY + 1]->SetOpen();
			//pole[m_coordX + 1][m_coordY + 1]->SetOpen();
		}
		//4
		if ((m_coordX != 0) && (m_coordX < (maxX-1)) && (m_coordY == (maxY-1))) {
			pole[m_coordX - 1][m_coordY - 1]->SetOpen();
			pole[m_coordX]    [m_coordY - 1]->SetOpen();
			pole[m_coordX + 1][m_coordY - 1]->SetOpen();
	 
			pole[m_coordX - 1][m_coordY]->SetOpen();
			pole[m_coordX + 1][m_coordY]->SetOpen();

			//pole[m_coordX - 1][m_coordY + 1]->SetOpen();
			//pole[m_coordX]    [m_coordY + 1]->SetOpen();
			//pole[m_coordX + 1][m_coordY + 1]->SetOpen();
		}
		//5
		if ((m_coordX == 0) && (m_coordY == (maxY-1))) {
			//pole[m_coordX - 1][m_coordY - 1]->SetOpen();
			pole[m_coordX]    [m_coordY - 1]->SetOpen();
			pole[m_coordX + 1][m_coordY - 1]->SetOpen();
	 
			//pole[m_coordX - 1][m_coordY]->SetOpen();
			pole[m_coordX + 1][m_coordY]->SetOpen();

			//pole[m_coordX - 1][m_coordY + 1]->SetOpen();
			//pole[m_coordX]    [m_coordY + 1]->SetOpen();
			//pole[m_coordX + 1][m_coordY + 1]->SetOpen();
		}
		//6
		if ((m_coordX == 0) && (m_coordY == 0)) {
			//pole[m_coordX - 1][m_coordY - 1]->SetOpen();
			//pole[m_coordX]    [m_coordY - 1]->SetOpen();
			//pole[m_coordX + 1][m_coordY - 1]->SetOpen();
	 
			//pole[m_coordX - 1][m_coordY]->SetOpen();
			pole[m_coordX + 1][m_coordY]->SetOpen();

			//pole[m_coordX - 1][m_coordY + 1]->SetOpen();
			pole[m_coordX]    [m_coordY + 1]->SetOpen();
			pole[m_coordX + 1][m_coordY + 1]->SetOpen();
		}
		//7
		if ((m_coordX == (maxX-1)) && (m_coordY == 0)) {
			//pole[m_coordX - 1][m_coordY - 1]->SetOpen();
			//pole[m_coordX]    [m_coordY - 1]->SetOpen();
			//pole[m_coordX + 1][m_coordY - 1]->SetOpen();
	 
			pole[m_coordX - 1][m_coordY]->SetOpen();
			//pole[m_coordX + 1][m_coordY]->SetOpen();

			pole[m_coordX - 1][m_coordY + 1]->SetOpen();
			pole[m_coordX]    [m_coordY + 1]->SetOpen();
			//pole[m_coordX + 1][m_coordY + 1]->SetOpen();
		}
		//8
		if ( (m_coordX == (maxX-1)) && (m_coordY == (maxY-1)) ) {
			pole[m_coordX - 1][m_coordY - 1]->SetOpen();
			pole[m_coordX]    [m_coordY - 1]->SetOpen();
			//pole[m_coordX + 1][m_coordY - 1]->SetOpen();
	 
			pole[m_coordX - 1][m_coordY]->SetOpen();
			//pole[m_coordX + 1][m_coordY]->SetOpen();

			//pole[m_coordX - 1][m_coordY + 1]->SetOpen();
			//pole[m_coordX]    [m_coordY + 1]->SetOpen();
			//pole[m_coordX + 1][m_coordY + 1]->SetOpen();
		}
		//9
		if((m_coordX > 0) && (m_coordY > 0) && (m_coordX < (maxX-1)) && (m_coordY < (maxY-1))) {
			pole[m_coordX - 1][m_coordY - 1]->SetOpen();
			pole[m_coordX]    [m_coordY - 1]->SetOpen();
			pole[m_coordX + 1][m_coordY - 1]->SetOpen();
	 
			pole[m_coordX - 1][m_coordY]->SetOpen();
			pole[m_coordX + 1][m_coordY]->SetOpen();

			pole[m_coordX - 1][m_coordY + 1]->SetOpen();
			pole[m_coordX]    [m_coordY + 1]->SetOpen();
			pole[m_coordX + 1][m_coordY + 1]->SetOpen();
		}


}
//----------------------------------------------------------------------
bool CCell::OpenCell() {
	
	if (m_mined) {
		m_opened = true;
		
		//SetGameOver();
		m_gameOver = true;
		return false;
	} else {
		m_opened = true;
		m_numberOfNearMines = GetNumberOfNearMines();
		if (m_numberOfNearMines == 0) {
			OpenNearZeroMines();
		}
		return true;
	}
}

void CCell::DisplayCell() {
	if (!IsOpenedCell()) {
		cout << "*";
	} else {
		if(!m_mined) {
			cout << GetNumberOfNearMines(); 
		}
		else {
			cout << "O";
			//SetGameOver();
		}
	}
}

void FillCells(int mines) {
	srand(time(0));
		for (int i=0; i<maxX; i++) {
			if ((rand() % 100) & 1) mines++; // Добавляем мину, чтоб мин было больше, а нам- чтоб было веселее играть
			for(int j = 0; j< maxY; j++) {
				
				if (!((rand() % 100) % 10))  {
					if (mines > 0) {
						pole[i][j] = new CCell(i,j, true); 
						mines--;
					} else pole[i][j] = new CCell(i,j, false);
				} else pole[i][j] = new CCell(i,j, false);
				
			}
		}
	

}

void DisplayPole() {
	cout << " ";
	for (int g=1; g<=maxX;g++) {
			if (g<10) cout << " " <<g;
			else cout <<g;
		}
	cout <<endl;
	for (int i=0; i<maxX; i++) {
		
		cout << i+1; if (i<9) cout << " ";
			for(int j = 0; j< maxY; j++) {
				
				pole[i][j]->DisplayCell();
				cout << " ";
			}
			cout << endl;
		}
}

void OpenAll() {
	for (int i=0; i<maxX; i++) {
			for(int j = 0; j< maxY; j++) {
				pole[i][j]->OpenCell();
				pole[i][j]->DisplayCell();
				cout << " ";
			}
			cout << endl;
		}

}
//------------------------------------------------------------------------


void main() {
	ftr: FillCells(5);
	int x=0; int y=0;
	char c;
	do {
		system("cls");
		DisplayPole();
		cin >> x;
		cin >> y;
		if (x > maxX) x=maxX;
		if (y > maxY) y=maxY;
		if (x <= 0) x = 1;
		if (y <= 0) y = 1;
		--x; --y;


	} while (pole[x][y]->OpenCell());
	OpenAll();
	cout <<"Play again? [Y/N]";
	cin >> c;
	if (c == 'Y' || c == 'y') goto ftr;
	system("pause");
}