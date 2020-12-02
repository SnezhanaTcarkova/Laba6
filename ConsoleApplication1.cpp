#include <string>
#include <iostream>
using namespace std;

class House
{	string name;
	
public:
	House(string name1)
	{
		name = name1;

	}
	~House();
	virtual void print(string)
	{
		cout << endl;
	};
	virtual int* area(int, int*, int*) = 0;
	virtual int* ar(int, int*, int*) = 0;
};



House::~House()
{
}

class Flat :  public House
{
protected:
	int** flatt;
	int m;
	int n;
	int* lngth=0;
	int* wdth=0;
	int* areaB;

public:
	Flat(string name, int n1, int m1) :House(name)
	{
		n = n1;
		m = m1;
		areaB = new int[n * m];
		flatt = new int* [n];


		for (int i = 0; i < n; i++)
		{
			flatt[i] = new int[m];
		}
	}
	 virtual void print(string)=0;
	virtual int* area(int, int*, int*) = 0;
	virtual int* ar(int, int*, int*) = 0;

	~Flat();

};




Flat::~Flat()
{
	delete[]flatt;
}

class Bath : public Flat
{

public:
	Bath(string name, int n, int m, int* lngth1, int* wdth1) :Flat(name, n, m)
	{

		lngth = lngth1;
		wdth = wdth1;

	}
	~Bath();
	void print(string name)
	{
		cout << name;
		cout << "  Ванна" << endl;
	}

	int* area(int count, int* lngth1, int* wdth1)
	{
		for (int i = 0; i < count; i++)
		{
			areaB[i] = lngth[i] * wdth[i];
		}

		return areaB;
	}

	int* ar(int count, int* lngth1, int* wdth1)
	{

		for (int i = 0; i < count; i++)
		{
			cout << "Площадь ванны " << i + 1 << " квартиры " << areaB[i] << endl;
		}
		return areaB;
	}
};

Bath::~Bath()
{
	delete[]areaB;
}
 class Bedroom:  public Flat
{

public:
	Bedroom(string name, int n, int m, int* lngth1, int* wdth1) :Flat(name, n, m) {
		lngth = lngth1;
		wdth = wdth1;
	}
	~Bedroom();

	void print(string name)
	{
		cout << name;
		cout << "  Спальня" << endl;
	}

	int* area(int count, int* lngth1, int* wdth1)
	{


		for (int i = 0; i < count; i++)
		{
			areaB[i] = lngth[i] * wdth[i];
		}
		return areaB;
	}
	int* ar(int count, int* lngth1, int* wdth1)
	{

		for (int i = 0; i < count; i++)
		{
			cout << "Площадь спальни " << i + 1 << " квартиры " << areaB[i] << endl;
		}
		return areaB;
	}
};
Bedroom::~Bedroom()
{
	delete[]areaB;
}
class Kitchen :  public Flat
{


public:
	Kitchen(string name, int n, int m, int* lngth1, int* wdth1) :Flat(name, n, m) {
		lngth = lngth1;
		wdth = wdth1;

	}
	~Kitchen();
	void print(string name)
	{
		cout << name;
		cout << "  Кухня" << endl;
	}

	int* area(int count, int* lngth1, int* wdth1)
	{
		for (int i = 0; i < count; i++)
		{
			areaB[i] = lngth[i] * wdth[i];
		}
		return areaB;
	}

	int* ar(int count, int* lngth1, int* wdth1)
	{

		for (int i = 0; i < count; i++)
		{
			cout << "Площадь кухни " << i + 1 << " квартиры " << areaB[i] << endl;

		}


		return areaB;
	}
};
Kitchen::~Kitchen()
{
	delete[]areaB;
}


class C12:   public Bath, public Bedroom, public Kitchen
{
	string prntbath;
	string prntbed;
	string prntkitchen;
	string  cnt;

public:
	C12(string name, int n, int m, int* lngth1, int* wdth1, string count1) : Bath(name,n,m,lngth1,wdth1), Bedroom(name, n, m, lngth1, wdth1), Kitchen(name, n, m, lngth1, wdth1)
	{
		prntbath = name;
		prntbed = name;
		prntkitchen = name;
		cnt = count1;
		
	}
	~C12();

	void printV()
	{	
		cout << "Множественное наследование:" << endl;
		Bath:: print(prntbath);
		Bedroom::print(prntbed);
		Kitchen::print(prntkitchen);


	};

	void printDop(string cnt)
	{
		cout << cnt << endl;
	}
	
};
C12::~C12()
{
}

int main()
{
	setlocale(LC_ALL, "Russian");
	bool check = false;
	string nm;
	int cFloor;
	int cFlat;
	cout << "Введите количество этажей " << endl;

	while (!(cin >> cFloor))
	{
		cout << "Введите целочисленное значение" << endl;
		cout << "";
		cout << "Введите количество этажей " << endl;
		cin.clear();
		cin.ignore();
	}
	cout << "Введите количетсво квартир на этаже " << endl;

	while (!(cin >> cFlat))
	{
		cout << "Введите целочисленное значение" << endl;
		cout << "";
		cout << "Введите количество этажей " << endl;
		cin.clear();
		cin.ignore();
	}

	cout << "Введите название дома" << endl;
	cin >> nm;



	int* bathWdth = new int[cFlat * cFloor];
	int* bathLngth = new int[cFlat * cFloor];
	int* areaB = new int[cFlat * cFloor];

	int* bedWdth = new int[cFlat * cFloor];
	int* bedLngth = new int[cFlat * cFloor];

	int* kitchWdth = new int[cFlat * cFloor];
	int* kitchLngth = new int[cFlat * cFloor];

	int* areaBath = new int[cFlat * cFloor];
	int* areaBedroom = new int[cFlat * cFloor];
	int* areaKitchen = new int[cFlat * cFloor];
	int* areaMain = new int[cFlat * cFloor];

	string dop;

	Flat* hs[3];
	Bath bth(nm, cFlat, cFloor, bathWdth, bathLngth);
	Bedroom bdr(nm, cFlat, cFloor, bedWdth, bedLngth);
	Kitchen ktch(nm, cFlat, cFloor, kitchWdth, kitchLngth);
	
	
	hs[0] = &bth;
	hs[1] = &bdr;
	hs[2] = &ktch;
	
	


	for (int i = 0; i < cFlat * cFloor; i++)
	{
		cout << "Введите длину ванны " << i + 1 << " квартиры" << endl;
		cin >> bathLngth[i];
		cout << "Введите ширину ванны " << i + 1 << " квартиры" << endl;
		cin >> bathWdth[i];

		cout << "Введите длину спальни " << i + 1 << " квартиры" << endl;
		cin >> bedLngth[i];
		cout << "Введите ширину спальни " << i + 1 << " квартиры" << endl;
		cin >> bedWdth[i];

		cout << "Введите длину кухни " << i + 1 << " квартиры" << endl;
		cin >> kitchLngth[i];
		cout << "Введите ширину кухни " << i + 1 << " квартиры" << endl;
		cin >> kitchWdth[i];
		cout << endl;
		hs[0]->area(cFlat * cFloor, bathLngth, bathWdth);
		hs[1]->area(cFlat * cFloor, bedLngth, bedWdth);
		hs[2]->area(cFlat * cFloor, kitchLngth, kitchWdth);
		cout << endl;
	}

	hs[0]->print(nm);
	areaBath = hs[0]->ar(cFlat * cFloor, bathLngth, bathWdth);
	cout << endl;
	hs[1]->print(nm);
	areaBedroom = hs[1]->ar(cFlat * cFloor, bedLngth, bedWdth);
	cout << endl;
	hs[2]->print(nm);
	areaKitchen = hs[2]->ar(cFlat * cFloor, kitchLngth, kitchWdth);

	
	cout << "Введите доп. информацию" << endl;
	cin >> dop;
	

	C12  cl12(nm, cFlat, cFloor, bathLngth, bathWdth, dop);
	C12* pt = &cl12;
	cl12.Bath::print(nm);
	cl12.Bedroom::print(nm);
	cl12.Kitchen::print(nm);
	
	pt->printDop(dop);
	/*C12 rem(nm, cFlat, cFloor, bathLngth, bathWdth,dop);
	rem.printV();
	rem.printDop(dop);*/


	cout << "" << endl;

	for (int i = 0; i < cFlat * cFloor; i++)
	{
		cout << "Общая площадь " << i + 1 << " квартиры = ";
		areaMain[i] = areaBath[i] + areaBedroom[i] + areaKitchen[i];
		cout << areaMain[i] << endl;
	}
}

