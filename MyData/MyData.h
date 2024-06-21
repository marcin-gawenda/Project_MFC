// MyData.h : main header file for the MyData DLL
// 
//

#pragma once

#ifndef __AFXWIN_H__
#error "include 'pch.h' before including this file for PCH"
#endif

#ifdef MYDATA_EXPORTS
#define MYDATA_API __declspec(dllexport)
#else
#define MYDATA_API __declspec(dllimport)
#endif

#include "resource.h"		// main symbols
//#include "Except1.h"


// CMyDataApp
// See MyData.cpp for the implementation of this class
//

class CMyDataApp : public CWinApp
{
public:
	CMyDataApp();

	// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


#pragma pack(push, 1)
class CExcept1App;


class MYDATA_API MY_POINT
{
public:

	double x;
	double y;
	char* name = nullptr;
	int numb;
	COLORREF color;

	//MY_POINT() : x(0), y(0), name(NULL), numb(0), color(RGB(200, 200, 200)) {};

	// Constructor definition
	//MY_POINT(double xx, double yy, char* _name = nullptr, int _numb = 0, COLORREF _color = RGB(200, 200, 200));
		//: x(xx), y(yy), name(_name), numb(_numb), color(_color) {
	//}


	// copy constructor
	MY_POINT(MY_POINT& other);

	MY_POINT() { x = 0; y = 0; name = nullptr, numb = 0; color = RGB(200, 200, 200); }
	MY_POINT(double xx, double yy, char* _name = nullptr, int _numb = 0, COLORREF _color = RGB(200, 200, 200)) { x = xx; y = yy; name = _name; numb = _numb; color = _color; }

	~MY_POINT()
	{
		if (name) {
			delete[] name;
			name = nullptr;
		}
	}

public:

	// setter for name
	void setName(const char* name_);

	// getter for name 
	char* getName() const { return name; };

	// setter for numb
	//void setNumb(int numb_) { numb = numb_; };

	// getter for numb
	//int getNumb() const { return numb; };

	// setter for color
	//void setColor(COLORREF color_) { color = color_; };

	// getter for color
	//COLORREF getColor() const { return color; };

	//void disp() const;


	MY_POINT get() { return *this; }

	// is capable to compare MY_POINT to do std::string
	bool operator == (const CString& key) const {
		return CString(name) == key;
	}

	MY_POINT& operator = (const MY_POINT& other);
};

class MYDATA_API MY_DATA : public MY_POINT
{
protected:
	MY_POINT* pTab;
	int capacity;
	int last;
public:
	CExcept1App* pExcept;
public:
	MY_DATA(int no_it);
	MY_DATA(const MY_DATA& ob);
	~MY_DATA() { Free(); }
	void Free() { if (pTab) delete[] pTab; pTab = NULL; }
	void Init(int no_it);
	void Push(const MY_POINT& tmp);
	int size() { return last; }
	void clear() { last = 0; }

	MY_POINT& operator [] (const int i)
	{
		return pTab[i];
	}

	void GetMaxMinCoords(double& max_x, double& min_x, double& max_y, double& min_y);

private:
	MY_POINT* allocTab(MY_POINT* pTab, int i);
};

#pragma pack(pop)