#include "stdafx.h"
#include "ShapeEditor.h"


Shape *ShapeEditor::pcshape[MY_SHAPE_ARRAY_SIZE];
int ShapeEditor::curr_length = 0;

/*
	* brushColor - колір заливки
	* peColor - колір контуру
	*/
ShapeEditor::ShapeEditor(COLORREF brushColor,COLORREF peColor)
{
	brColor = brushColor;
	penColor = peColor;
}

ShapeEditor::ShapeEditor()
{
	
}

/*
	* функція малювання фігур
	* xk - зміщення по х
	* yk - зміщення по у
	*/
void ShapeEditor::OnPaint(HWND hWnd,HDC hdc,int xk, int yk)
{	
	for (int i = 0; i < curr_length; i++)
	{
		if (pcshape[i])
			pcshape[i]->Show(hdc,xk,yk);
		
	}
}

//функція орбробки повідомлення натиснення лівої клавіши миші
void ShapeEditor::OnLBdown(HWND hWnd)
{
	GetCursorPos(&pt_start);
	ScreenToClient(hWnd, &pt_start);
	pt_old = pt_start; //записуємо координати початкової точки
}

/*
	* функція орбробки повідомлення натиснення лівої клавіши миші
	* xk - зміщення по х
	* yk - зміщення по у
	*/
void ShapeEditor::OnLBup(HWND hWnd, int xk, int yk)
{
	
}

//функція орбробки повідомлення руху миші
void ShapeEditor::OnMosuseMove(HWND)
{

}

/*
	* записує у файл масив pcshape
	* name - ім'я файлу
	*/
void ShapeEditor::PrintInFile(char *name)
{
	ofstream fout(name, ios_base::out);//відкриття потоку

	for (int i = 0; i < curr_length; i++)
	{
		if (pcshape[i])
		{
			fout << pcshape[i]->RetData().c_str() <<endl;//запис у файл
		}
	}
	fout.close();//закриття потоку
}

/*
	* зчитує з файлу у масив pcshape
	* name - ім'я файлу
	*/
void ShapeEditor::ReadFromFile(char* name)
{
	ifstream file;
	file.open(name, ios_base::in);
	
	if (file) // якщо файл існує
	{
		int n = 0,
			c_dots = 0;
		int dots[6];
		char str[350],
			*next_token = NULL,
			*p,
			*delimiter = "\t";
		bool fl = true;

		//видалення елементів з pcshape
		for (int i = 0; i < curr_length;i++)
		{
			pcshape[i] = NULL;
		}

		//цикл зчитування з файлу
		while (!file.eof() && n <= MY_SHAPE_ARRAY_SIZE)
		{
			file.getline(str, 350);
			p = strtok_s(str, delimiter, &next_token);
			
			if (p != NULL)
			{
				//визначення типу об'єкта
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
					fl = false;
				}

				p = strtok_s(NULL, delimiter, &next_token);

				if (fl)
				{
					//зчитування координат та зміщення
					while (p != NULL && c_dots < 6)
					{
						dots[c_dots] = atoi(p);
						c_dots++;
						p = strtok_s(NULL, delimiter, &next_token);
					}

					if (c_dots == 6)
					{
						pcshape[n]->Set(dots[0], dots[1], dots[2], dots[3], dots[4], dots[5], 0, 0);
						c_dots = 0;
						n++;
					}
				}
				else
					fl = true;

			}
		}
		curr_length = n;
		file.close();
	}
	else
	{
		MessageBox(0, "Не вдалося відкрити файл", "Курсова робота", 0);
	}
}

//позначає вибраний елемент у меню
void ShapeEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{

}

//позначає вибраний елемент на панелі інструментів 
void ShapeEditor::PressButton(HWND hWnd)
{

}

void ShapeEditor::OverMeesage()
{
	MessageBox(0, "Закінчилось місце для фігур", "Курсова робота", 0);
}

//створення нової сцени
void ShapeEditor::CreateNewScene()
{
	//видалення елементів з pcshape
	for (int i = 0; i < curr_length;i++)
	{
		pcshape[i] = NULL;
	}

	curr_length = 0;


}