#pragma once

#if !defined(TOOL_H)
#define TOOL_H


#include <CommCtrl.h>

#define IDB_RECT                           1005
#define IDB_ELLIPSE                        1006
#define IDB_POINT                          1007
#define IDB_LINE                           1008
#define IDB_LINEOO						   1009
#define IDB_CUBE						   1010
#define IDB_PUNCKT						   1011
#define IDB_ROMB						   1012
#define IDB_CILINDER					   1013
#define IDB_CIRCUIT						   1014
#define IDB_FILL						   1015
#endif !defined(TOOL_H)

const TBBUTTON tbb_1[] = {
	{ 0,IDB_RECT,TBSTATE_ENABLED,TBSTYLE_BUTTON,0,0,0,0 },//кнопка прямокутник
	{ 1, IDB_ELLIPSE, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, 0 },//кнопка еліпс
	{ 2, IDB_LINE, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, 0 },//кнопка лінія
	{ 3, IDB_CUBE, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, 0 },//кнопка куб
	{ 4, IDB_PUNCKT, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, 0 },//кнопка пунктирна лінія
	{ 5, IDB_ROMB, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, 0 },//кнопка ромб
	{ 6, IDB_CILINDER, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, 0 },//кнопка циліндр
	{ 7, IDB_FILL, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, 0 },//кнопка зміни кольору заповнення
	{ 8, IDB_CIRCUIT, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, 0 },//кнопка зміни кольору контуру
};