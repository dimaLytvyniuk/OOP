#pragma once

#include <CommCtrl.h>

#define IDB_RECT                           1005
#define IDB_ELLIPSE                        1006
#define IDB_POINT                          1007
#define IDB_LINE                           1008

TBBUTTON tbb_1[] = {
	{STD_COPY,IDB_RECT,TBSTATE_ENABLED,TBSTYLE_BUTTON,0,0,0,0 },
	{STD_CUT, IDB_ELLIPSE, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, 0 },
	{STD_DELETE, IDB_POINT, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, 0 },
	{STD_FILESAVE, IDB_LINE, TBSTATE_ENABLED, TBSTYLE_BUTTON, 0, 0, 0, 0 },
};
