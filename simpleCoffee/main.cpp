#include <iostream>
#include <string>

using namespace std;

class Price
{
public:
    explicit Price(int cost = 1): _cost(cost) {}

    int getPrice() {return _cost;}
    void setPrice(int price) {_cost = price;}

private:
    int _cost;
};

class Coffee:
    public Price
{
public:
    explicit Coffee() = default;
    explicit Coffee(Coffee* coffee):
        _coffee(coffee) {}
    virtual ~Coffee() = default;


    virtual int cost() {return _coffee == nullptr ? getPrice() : getPrice() + _coffee->cost();}


private:
    Coffee* _coffee = nullptr;
};

class Sugar:
    public Coffee
{
public:
    explicit Sugar(Coffee* coffee = nullptr): Coffee(coffee) {setPrice(2);}
};

class Milk:
    public Coffee
{
public:
    explicit Milk(Coffee* coffee = nullptr): Coffee(coffee) {setPrice(3);}
};

int main()
{
    Coffee coffee;
    Sugar sugar;
    Milk milk;

    cout << coffee.cost() << endl;
    cout << sugar.cost() << endl;
    cout << milk.cost() << endl;

    Coffee coffeeWMilk(&milk);
    cout << coffeeWMilk.cost() << endl;

    Sugar coffeeFull(&coffeeWMilk);
    cout << coffeeFull.cost() << endl;

    return 0;
}
