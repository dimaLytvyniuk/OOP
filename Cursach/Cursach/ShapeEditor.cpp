#include "stdafx.h"
#include "ShapeEditor.h"


Shape *ShapeEditor::pcshape[MY_SHAPE_ARRAY_SIZE];
int ShapeEditor::curr_length = 0;

ShapeEditor::ShapeEditor()
{

}

void ShapeEditor::OnPaint(HWND hWnd)
{	
	
	PAINTSTRUCT ps;
	HDC hdc;
	HBRUSH hBrush, hBrushOld;

	
	hdc = BeginPaint(hWnd, &ps);
	//hBrush = (HBRUSH)CreateSolidBrush(RGB(0, 255, 0));
	//hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

	for (int i = 0; i < curr_length; i++)
	{
		if (pcshape[i])
			pcshape[i]->Show(hdc);
		
	}
	EndPaint(hWnd, &ps);
/*
	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
	*/
}

void ShapeEditor::OnLBdown(HWND hWnd)
{
	GetCursorPos(&pt_start);
	ScreenToClient(hWnd, &pt_start);
	pt_old = pt_start; //кудись записуємо координати початкової точки
}

void ShapeEditor::OnLBup(HWND hWnd)
{
	
}

void ShapeEditor::OnMosuseMove(HWND)
{

}

void ShapeEditor::PrintInFile(char * str,int x1, int y1, int x2, int y2)
{
	ofstream fout(name, ios_base::out | ios_base::app);
	fout << str<<"\t" << x1 << "\t" << y1 << "\t" << x2 << " \t" << y2 << endl;
	fout.close();
}

void ShapeEditor::PrintInFile(char *name)
{
	ofstream fout(name, ios_base::out);

	for (int i = 0; i < curr_length; i++)
	{
		if (pcshape[i])
		{
			fout << pcshape[i]->RetData().c_str() <<endl;
		}
	}
	fout.close();
}

void ShapeEditor::ReadFromFile(char* name)
{
	ifstream file;
	file.open(name, ios_base::in);
	if (file)
	{
		int n = 0,
			c_dots = 0;
		int dots[4];
		char str[350],
			*next_token = NULL,
			*p,
			*delimiter = "\t";

		for (int i = 0; i < curr_length;i++)
		{
			pcshape[i] = NULL;
		}

		while (!file.eof() && n <= MY_SHAPE_ARRAY_SIZE)
		{
			file.getline(str, 350);
			p = strtok_s(str, delimiter, &next_token);
			
			if (p != NULL)
			{
				if (!strcmp(p, "PuncktLine"))
				{
					pcshape[n] = new PuncktLineShape;
				}
				else if (!strcmp(p, "Cube"))
				{
					pcshape[n] = new CubeShape;
				}
				else if (!strcmp(p, "Line"))
				{
					pcshape[n] = new LineShape;
				}
				else if (!strcmp(p, "Ellipse"))
				{
					pcshape[n] = new EllipseShape;
				}
				else if (!strcmp(p, "Cilinder"))
				{
					pcshape[n] = new CilinderShape;
				}
				else if (!strcmp(p, "Rect"))
				{
					pcshape[n] = new RectShape;
				}
				else if (!strcmp(p, "Romb"))
				{
					pcshape[n] = new RombShape;
				}
				else
				{
					return void(0);
				}

				p = strtok_s(NULL, delimiter, &next_token);

				while (p != NULL && c_dots < 4)
				{
					dots[c_dots] = atoi(p);
					c_dots++;
					p = strtok_s(NULL, delimiter, &next_token);
				}

				if (c_dots == 4)
				{
					pcshape[n]->Set(dots[0], dots[1], dots[2], dots[3]);
					c_dots = 0;
				}
				else
				{

				}
				n++;
			}
		}
		curr_length = n;
		file.close();
	}
}

void ShapeEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{

}

void ShapeEditor::PressButton(HWND hWnd)
{

}