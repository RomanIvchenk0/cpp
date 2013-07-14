#pragma once

class CCell {
private:

	bool		m_mined;
	bool		m_opened;
	int			m_numberOfNearMines;
	int			m_coordX;
	int			m_coordY;
	bool		m_gameOver;
public:
	CCell(int x, int y, bool mined);
	~CCell();
	bool		IsOpenedCell() const;
	int			GetNumberOfNearMines();
	bool		OpenCell();
	void		DisplayCell();
	void		OpenNearZeroMines();
	void		SetOpen();
};