#include <iostream>
using namespace std;

/*
��������� ����� (Factory Method) � ����������� ������ ��������������, ��������������� ���������� ��������� ��� �������� ����������� ���������� ������.
� ������ �������� ���������� ����� ����������, ����� ����� ���������������. ����� �������, ������� ���������� �������� �������� ����������� ������������� ������.
��� ��������� ������������ � ���� ��������� �� ������������� ������, � �������������� ������������ ��������� �� ����� ������� ������.
��������� �����  ���������� ��������� ��� �������� �������, �� ��������� ���������� ������� � ���, ����� ����� ���������������.

������������
-	������ ������� ����������, ������� ����� ���������� ��� ����� ���������.
-	����� ������������� ���, ����� �������, ������� �� ������, ����������������� �����������.
-	����� ���������� ���� ����������� ������ �� ���������� ��������������� ����������, � ����������� ������������ ������ � ���, ����� ����� ��������� ��� ����������� �� ����.

�����������
��������� ������ ��������� �������������� �� ������������� ���������� � ��� ��������� �� ���������� ������. ��� ����� ���� ������ � �����������
������ Product, ������� �� ����� �������� � ������ ������������� �������������� �������� ���������� ���������.
����������
������������� ���������� ���������� ������ ������� � ���, ��� ��������, ��������, �������� ��������� �������� ������ Creator ��� �������� ���� ������ ������� ConcreteProduct.
*/

//������� (House) ���������� ��������� ��������, ����������� ��������� �������
class Figure abstract
{ 
protected:
	int FigureLayout[4][4] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
	short color[3];
	std::string name;
public:
	void Show()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (FigureLayout[i][j] == 1)
				{
					std::cout << '*';
				}
				else
				{
					std::cout << ' ';
				}
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}
	void SetColor(short* color)
	{
		for (int i = 0; i < 3; i++)
		{
			this->color[i] = color[i];
		}
	}
};

// ���������� ������� ��������� ��������� Product (� ����� ������, House)
class TFigure : public Figure
{
public:
	TFigure()
	{
		FigureLayout[0][0] = 1;
		FigureLayout[0][1] = 1;
		FigureLayout[0][2] = 1;
		FigureLayout[1][1] = 1;
		name = "TFigure";
	}
	
};

// ���������� ������� ��������� ��������� Product (� ����� ������, House)
class OFigure : public Figure
{
public:
	OFigure()
	{
		FigureLayout[0][0] = 1;
		FigureLayout[0][1] = 1;
		FigureLayout[1][0] = 1;
		FigureLayout[1][1] = 1;
		name = "OFigure";
	}
};

class LFigure : public Figure
{
public:
	LFigure()
	{
		FigureLayout[0][0] = 1;
		FigureLayout[1][0] = 1;
		FigureLayout[2][0] = 1;
		FigureLayout[2][1] = 1;
		name = "LFigure";
	}
};

class IFigure : public Figure
{
public:
	IFigure()
	{
		FigureLayout[0][0] = 1;
		FigureLayout[1][0] = 1;
		FigureLayout[2][0] = 1;
		FigureLayout[3][0] = 1;
		name = "IFigure";
	}
};

class SFigure : public Figure
{
public:
	SFigure()
	{
		FigureLayout[0][1] = 1;
		FigureLayout[0][2] = 1;
		FigureLayout[1][0] = 1;
		FigureLayout[1][1] = 1;
		name = "SFigure";
	}
};

class ZFigure : public Figure
{
public:
	ZFigure()
	{
		FigureLayout[0][0] = 1;
		FigureLayout[0][1] = 1;
		FigureLayout[1][2] = 1;
		FigureLayout[1][1] = 1;
		name = "ZFigure";
	}
};

class JFigure : public Figure
{
public:
	JFigure()
	{
		FigureLayout[2][0] = 1;
		FigureLayout[2][1] = 1;
		FigureLayout[1][1] = 1;
		FigureLayout[0][1] = 1;
		name = "JFigure";
	}
};

// Creator ��������� ��������� �����, ������������ ������ ���� Product.
// ����������� ����� ������������ ��������
class FigureCreator abstract
{
	// ��������� �����
public:
	virtual Figure* Create() = 0;
};

// ���������� ��������� �������� ��������� �����, ������������ ������ ConcreteProduct.
// ������ ��������� ����
class TFigureCreator : public FigureCreator
{
public:
	Figure* Create() override
	{
		return new TFigure;
	}
};

// ���������� ��������� �������� ��������� �����, ������������ ������ ConcreteProduct.
// ������ ���������� ����
class OFigureCreator : public FigureCreator
{
public:
	Figure* Create() override
	{
		return new OFigure;
	}
};

class LFigureCreator : public FigureCreator
{
public:
	Figure* Create() override
	{
		return new LFigure;
	}
};

class IFigureCreator : public FigureCreator
{
public:
	Figure* Create() override
	{
		return new IFigure;
	}
};

class JFigureCreator : public FigureCreator
{
public:
	Figure* Create() override
	{
		return new JFigure;
	}
};

class SFigureCreator : public FigureCreator
{
public:
	Figure* Create() override
	{
		return new SFigure;
	}
};

class ZFigureCreator : public FigureCreator
{
public:
	Figure* Create() override
	{
		return new ZFigure;
	}
};

// ������� ��������� ������������ � ���������� ���� ��������� �� ������������� ������, � �������������� ������������ ��������� �� ����� ������� ������.
Figure * Client(FigureCreator *pDev)
{
	return pDev->Create();
}

void main()
{
	FigureCreator* pCreator;
	Figure * pFigure;

	int answer = 0;
	do
	{
		std::cout << "Welcome to figure creator. Choose th figure you want to create\n"
			<< "1-TFigure\n"
			<< "2-OFigure\n"
			<< "3-LFigure\n"
			<< "4-IFigure\n"
			<< "5-SFigure\n"
			<< "6-ZFigure\n"
			<< "7-JFigure\n";
		std::cin >> answer;
		system("CLS");
		switch (answer)
		{
		case 1:
		{
			pCreator = new TFigureCreator;
			pFigure = Client(pCreator);
			pFigure->Show();
			delete pCreator;
			delete pFigure;
			break;
		}
		case 2:
		{
			pCreator = new OFigureCreator;
			pFigure = Client(pCreator);
			pFigure->Show();
			delete pCreator;
			delete pFigure;
			break;
		}
		case 3:
			pCreator = new LFigureCreator;
			pFigure = Client(pCreator);
			pFigure->Show();
			delete pCreator;
			delete pFigure;
			break;
		case 4:
		{
			pCreator = new IFigureCreator;
			pFigure = Client(pCreator);
			pFigure->Show();
			delete pCreator;
			delete pFigure;
			break;
		}
		case 5:
		{
			pCreator = new SFigureCreator;
			pFigure = Client(pCreator);
			pFigure->Show();
			delete pCreator;
			delete pFigure;
			break;
		}
		case 6:
		{
			pCreator = new ZFigureCreator;
			pFigure = Client(pCreator);
			pFigure->Show();
			delete pCreator;
			delete pFigure;
			break;
		}
		case 7:
			pCreator = new JFigureCreator;
			pFigure = Client(pCreator);
			pFigure->Show();
			delete pCreator;
			delete pFigure;
			break;
		case 0:
		{
			std::cout << "Goodbye!\n";
			break;
		}
		default:
		{
			std::cout << "Wrong input try again\n";
			break;
		}
		}
		
	} while (answer != 0);

	system("pause");
}
