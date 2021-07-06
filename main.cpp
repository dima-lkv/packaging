//
//  main.cpp
//  boxPackDynamic
//
//  Created by Dima Ilkiv on 01.07.2021.
//

#include <iostream>
#define deb
using namespace std;

class product;
void fillArr(int x , product *arr);
void showArr(product *arr, unsigned size);
void fillOrdID();
void showOrd();
void packaging(unsigned pid, unsigned amount, unsigned boxes);
unsigned pSize = 0;

class product
{
public:
    
    void setid(unsigned id)
    {
        this->id = id;
    }
    void setx(unsigned x)
    {
        this->x = x;
    }
    void sety(unsigned y)
    {
        this->y = y;
    }
    void setz(unsigned z)
    {
        this->z = z;
    }
    
    unsigned getid()
    {
        return id;
    }
    unsigned getx()
    {
        return x;
    }
    unsigned gety()
    {
        return y;
    }
    unsigned getz()
    {
        return z;
    }
    void fillp(unsigned x)
    {
        fillArr(x, this);
    }
    
    void showP()
    {
        showArr(this, pSize);
    }

    unsigned getVolume()
    {
        return volume;
    }
    void setVolume(unsigned x)
    {
        volume = x;
    }
private:
    unsigned id;
    unsigned x = 0,y = 0,z = 0;
    unsigned volume;
};
product *pArr = new product[pSize];



unsigned bSize = 0;
class box : public product
{
public:
    unsigned volume = 70*50*40;
    bool getcheck()
    {
        return check;
    }
    void setcheck(bool check)
    {
        this->check = check;
    }
    void showB()
    {
        showArr(this, bSize);
    }
private:
    bool check = false;
};
box *bArr = new box[bSize];






void fillArr(int x, product *arr)
{
    for (unsigned i = 0; i < pSize; i++) {
        arr[i].setid(i);
        arr[i].setx(rand()%x+1);
        arr[i].sety(rand()%x+1);
        arr[i].setz(rand()%x+1);
        arr[i].setVolume(arr[i].getx()*arr[i].gety()*arr[i].getz());
    }
}





unsigned oSize = 0;
class orderline
{
public:
   
    unsigned getpid()
    {
        return pid;
    }
    unsigned getamount()
    {
        return amount;
    }
    void setpid(unsigned x)
    {
        pid = x;
    }
    
    void setamount(unsigned x)
    {
        amount = x;
    }
    
    void setid(unsigned x)
    {
        id = x;
    }
    unsigned getid()
    {
        return id;
    }
    
    void order(unsigned pid, unsigned amount, unsigned boxes)
    {
        oSize++;
        setpid(pid);
        setamount(amount);
        fillOrdID();
        packaging(pid, amount, boxes);
    }
private:
    unsigned id;
    unsigned amount;
    unsigned pid;
};
orderline *oArr = new orderline[oSize];


void fillOrdID()
{
    for (unsigned i = 0; i < oSize; i++)
    {
        oArr[i].setid(i);
    }
}

void showOrd()
{
    cout << "All orders:\n";
    for (unsigned i = 0; i < oSize; i++)
    {
        cout << "Order ID:\t" << oArr[i].getid() << endl;
        cout << "Product ID:\t" << oArr[i].getpid() << endl;
        cout << "Amount of ordered products:\t" << oArr[i].getamount() << endl;
        cout << endl;
    }
}





void showArr(product *arr , unsigned size)
{
    for (unsigned i = 0; i < size; i++)
    {
        cout << "Product ID:\t" << arr[i].getid() << endl;
        cout << "size X:\t" << arr[i].getx() << endl;
        cout << "size Y:\t" << arr[i].gety() << endl;
        cout << "size Z:\t" << arr[i].getz() << endl;
        cout << "volume:\t" << arr[i].getVolume() << endl;
        cout << endl;
    }
}

void packaging(unsigned pid, unsigned amount, unsigned boxes)
{
    for (unsigned i = 0; i < boxes; i++)
    {
        while (!bArr[i].getcheck())
        {
            bArr[i].setid(i);
            bArr[i].setx(pArr[pid].getx());
            bArr[i].setx(pArr[pid].gety());
            bArr[i].setx(pArr[pid].getz());
            bArr[i].setcheck(1);
            bSize++;
        }
    }
}


int main(int argc, const char * argv[])
{
    pSize = 4;
    pArr[0].fillp(10);
    showArr(pArr, pSize);
    
    oArr[0].order(3, 4, 10);
    
    showOrd();
    showArr(bArr, bSize);

    return 0;
}
