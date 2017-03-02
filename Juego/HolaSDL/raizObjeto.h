#pragma once
class raizObjeto
{

public:
	class Direccion {
	public:
		int x, y;
		Direccion() :x(0), y(0) {};
		Direccion(int a, int b) :x(a), y(b) {};
		~Direccion() {};
		
		void operator=(Direccion &other) {
			this->x = other.x;
			this->y = other.y;
		}

		void set(int a, int b) { this->x = a; this->y = b; };

	};
public:
	raizObjeto(){}
	virtual ~raizObjeto(){}

	virtual void draw() = 0;
	virtual void update() = 0;
	virtual bool onClick() = 0;
	virtual void move(char c) = 0;
	virtual int getx() = 0;
	virtual int gety() = 0;
	virtual Direccion getDir() = 0;
	virtual char getId() = 0;
	virtual bool getDest() = 0;
};

