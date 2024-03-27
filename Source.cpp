#include <iostream>
using namespace std;

/*
Фабричный метод (Factory Method) — порождающий шаблон проектирования, предоставляющий подклассам интерфейс для создания экземпляров некоторого класса.
В момент создания наследники могут определить, какой класс инстанциировать. Иными словами, фабрика делегирует создание объектов наследникам родительского класса.
Это позволяет использовать в коде программы не специфические классы, а манипулировать абстрактными объектами на более высоком уровне.
Фабричный метод  определяет интерфейс для создания объекта, но оставляет подклассам решение о том, какой класс инстанциировать.

Применимость
-	классу заранее неизвестно, объекты каких подклассов ему нужно создавать.
-	класс спроектирован так, чтобы объекты, которые он создаёт, специфицировались подклассами.
-	класс делегирует свои обязанности одному из нескольких вспомогательных подклассов, и планируется локализовать знание о том, какой класс принимает эти обязанности на себя.

Достоинство
Фабричные методы избавляют проектировщика от необходимости встраивать в код зависящие от приложения классы. Код имеет дело только с интерфейсом
класса Product, поэтому он может работать с любыми определенными пользователями классами конкретных продуктов.
Недостаток
Потенциальный недостаток фабричного метода состоит в том, что клиентам, возможно, придется создавать подкласс класса Creator для создания лишь одного объекта ConcreteProduct.
*/

//продукт (House) определяет интерфейс объектов, создаваемых фабричным методом
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

// Конкретный продукт реализует интерфейс Product (в нашем случае, House)
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

// Конкретный продукт реализует интерфейс Product (в нашем случае, House)
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

// Creator объявляет фабричный метод, возвращающий объект типа Product.
// абстрактный класс строительной компании
class FigureCreator abstract
{
	// фабричный метод
public:
	virtual Figure* Create() = 0;
};

// конкретный создатель замещает фабричный метод, возвращающий объект ConcreteProduct.
// строит панельные дома
class TFigureCreator : public FigureCreator
{
public:
	Figure* Create() override
	{
		return new TFigure;
	}
};

// конкретный создатель замещает фабричный метод, возвращающий объект ConcreteProduct.
// строит деревянные дома
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

// Паттерн позволяет использовать в клиентском коде программы не специфические классы, а манипулировать абстрактными объектами на более высоком уровне.
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
