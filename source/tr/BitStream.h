#pragma once


// CBitStream class definition
class CBitStream
{
public:
	// Public methods
	CBitStream(void);
	virtual ~CBitStream(void);
	void WriteBit(BYTE value);
	void ReadBit(BYTE& value);
	void WriteByte(BYTE value);
	void ReadByte(BYTE& value);
	void WriteWord(WORD value);
	void ReadWord(WORD& value);
	void WriteDWord(DWORD value);
	void ReadDWord(DWORD& value);
	void WriteData(LPBYTE lpData, long nLen);
	void ReadData(LPBYTE lpData, long nLen);
	void WriteData(LPWORD lpData, long nLen);
	void ReadData(LPWORD lpData, long nLen);
	void WriteData(LPDWORD lpData, long nLen);
	void ReadData(LPDWORD lpData, long nLen);
	void WriteBits(DWORD value, long nLen=32);
	void ReadBits(DWORD& value, long nLen=32);
	void LoadStream(LPTSTR lpszFileName);
	void SaveStream(LPTSTR lpszFileName);
	void LoadStream(LPBYTE lpStream, long nLen);
	void SaveStream(LPBYTE lpStream);
	LPBYTE GetStream()	{return m_lpStream;}
	DWORD GetStreamLength()	{return m_dwStreamOffset;}
	DWORD GetStreamTotalLength()	{return m_dwStreamLen;}
	DWORD GetCurrentPosition()	{return m_dwCurrentPosition;}
	void SetCurrentPosition(DWORD dwCurrentPosition)	{m_dwCurrentPosition = max(0, min(m_dwStreamOffset-1, dwCurrentPosition));}

private:
	// Private methods
	void _WriteBit(BYTE value);
	void _ReadBit(BYTE& value);

private:
	// Private members
	LPBYTE m_lpStream;
	DWORD m_dwStreamLen;
	DWORD m_dwStreamOffset;
	DWORD m_dwCurrentPosition;
	BYTE m_CurrentBit;

};
