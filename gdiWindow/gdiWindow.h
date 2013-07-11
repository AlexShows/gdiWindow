// gdiWindow.h
// Authored by Alex Shows
// Released under the MIT License (http://opensource.org/licenses/mit-license.php) 
// 
// Header declaring the CGDIWindow class
// 
// An child class which inherits window creation from CSimpleWindow
// and provides its own window procedure for handling messages

#pragma once

#define MAX_DATAPOINTS 100
#define MAX_CLUSTERS 4

#include "simpleWindow.h"
#include "dataPoint.h"
#include <vector>
#include <time.h>
#include <sstream>

#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

class CGDIWindow:CSimpleWindow
{
public:
	CGDIWindow();
	CGDIWindow(const int width, const int height);
	CGDIWindow(string name, const int width, const int height);
	~CGDIWindow(void);
	void createWindow();
	void messageLoop();
	void updateWindow(HDC hdc);
	void drawPoint(HDC hdc, CDataPoint* pDP, const int xOffset = 0, const int yOffset = 0);
	void drawCluster(HDC hdc, CDataPoint* pDP, const int xOffset = 0, const int yOffset = 0);
	void drawOptimalCluster(HDC hdc, CDataPoint* pDP, const int xOffset, const int yOffset);
private:
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	vector<CDataPoint> vPoints;
	vector<CDataPoint> vClusters;
	vector<CDataPoint> vOptimalClusters;
	LRESULT CALLBACK windowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	void initializeData();
	void assignData();
	void computeCentroids();
	void randomizeClusterPositions();
	void handleKey(const char key = 0);
	CRITICAL_SECTION csPoints;
	CRITICAL_SECTION csClusters;
	CRITICAL_SECTION csOptimalClusters;
};