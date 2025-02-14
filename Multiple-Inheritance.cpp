#include <time.h>

#include <iostream>
#include <limits>
#include <string>

using namespace std;

bool hasDigit(const string &s) {
    for (char ch : s) {
        if (isdigit(ch)) {
            return true;
        }
    }
    return false;
}

bool correct(const string &mas) {
    for (char ch : mas) {
        if (strchr("~@#$%^*<>_[]\"=+`\\/|!()", ch)) {
            return true;
        }
    }
    return false;
}

char *checkstring(char *temp) {
    cin.ignore();
    while (true) {
        cin.getline(temp, 41);
        if (cin.fail() || correct(temp) || hasDigit(temp) || strlen(temp) > 40 || strlen(temp) < 1) {
            cout << "Некорректный ввод!" << endl;
            cin.clear();
            cin.ignore();
        } else {
            return temp;
        }
    }
}

int checkgraniz(int &i, int min, int max) {
    while (true) {
        cin >> i;
        if (cin.fail() || i < min || i > max || cin.peek() != '\n') {
            cout << "Некорректный ввод!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        } else {
            return i;
            break;
        }
    }
}

template <class N>
void name(N &type, int age) {
    cout << "\tAge: " << type.age << endl;
}

// абстрактный класс
class mlecopitaushee {
   public:
    virtual void makeSound() = 0;
};

class Animal : public mlecopitaushee {
   private:
    string name;
    int age;

   public:
    Animal(string name, int age) {
        this->name = name;
        this->age = age;
    }
    string getName() { return name; }
    int getAge() { return age; }
    void setName(string name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    template <class T>
    friend void name(T &obj, int age);
    void makeSound() {
        int random_number = rand();
        if (random_number % 2 == 0) {
            cout << "\tThe animal makes a sound." << endl;
        } else {
            cout << "\tThe animal doesnt make a sound." << endl;
        }
    }
};

class HomeAnimal : virtual public Animal {
   private:
    int height;
    int friendliness;

   public:
    HomeAnimal(string name, int age, int friendliness, int height) : Animal(name, age) {
        this->friendliness = friendliness;
        this->height = height;
    }
    void frienship() {
        cout << "\tThe homeanimal is friendliness are " << getfriendliness() << " out of 10." << endl;
    }
    int getfriendliness() { return friendliness; }
    void setfriendliness(int friendliness) { this->friendliness = friendliness; }
    int getheight() { return height; }
    void setheight(int height) { this->height = height; }
    template <class T>
    friend void name(T &obj, int age);
    void makeSound() {
        int random_number = rand();
        if (random_number % 2 == 0) {
            cout << "\tThe animal makes a sound." << endl;
        } else {
            cout << "\tThe animal doesnt make a sound." << endl;
        }
    }
};

class WildAnimal : public virtual Animal {
   private:
    int averageage;
    string furColor;

   public:
    WildAnimal(string name, int age, string furColor, int averageage) : Animal(name, age) {
        this->furColor = furColor;
        this->averageage = averageage;
    }
    string getFurColor() { return furColor; }
    void setFurColor(string furColor) { this->furColor = furColor; }
    int getaverageage() { return averageage; }
    void setaverageage(int averageage) { this->averageage = averageage; }
    template <class T>
    friend void name(T &obj, int age);
    void makeSound() {
        int random_number = rand();
        if (random_number % 2 == 0) {
            cout << "\tThe animal makes a sound." << endl;
        } else {
            cout << "\tThe animal doesnt make a sound." << endl;
        }
    }
};

class monkey : public WildAnimal, public HomeAnimal {
   private:
    string favmeal;
    int koligr;

   public:
    monkey(string name, int age, string furColor, int friendliness, int height, int averageage,
           string favmeal, int koligr)
        : Animal(name, age),
          WildAnimal(name, age, furColor, averageage),
          HomeAnimal(name, age, friendliness, height) {
        this->favmeal = favmeal;
        this->koligr = koligr;
    }
    void frienship() {
        cout << "\tThe monkey is friendliness are " << getfriendliness() << " out of 10." << endl;
    }
    string getfavmeal() { return favmeal; }
    void setfavmeal(string favmeal) { this->favmeal = favmeal; }
    int getkoligr() { return koligr; }
    void setkoligr(int koligr) { this->koligr = koligr; }
    template <class T>
    friend void name(T &obj, int age);
    void makeSound() {
        int random_number = rand();
        if (random_number % 2 == 0) {
            cout << "\tThe animal makes a sound." << endl;
        } else {
            cout << "\tThe animal doesnt make a sound." << endl;
        }
    }
};

int main() {
    int a, ch;
    char b[41];
    srand(time(NULL));
    Animal myAnimal("Cat", 14);
    HomeAnimal myHomeAnimal("dog", 3, 9, 52);
    WildAnimal myWildAnimal("lion", 5, "Gold", 36);
    monkey mymonkey("Bobby", 10, "Brown", 7, 45, 15, "Banana", 8);

    do {
        cout << "1 - create Animal\n2 - create WildAnimal" << endl
             << "3 - create HomeAnimal\n4 - create monkey," << endl
             << "5 - show\n6 - end\nOption: ";
        checkgraniz(ch, 1, 6);
        switch (ch) {
            case 1:
                cout << "Enter the name: ";
                checkstring(b);
                myAnimal.setName(b);
                cout << "Enter the age: ";
                checkgraniz(a, 1, 25);
                myAnimal.setAge(a);
                cout << "MyAnimal" << endl;
                cout << "\tName: " << myAnimal.getName() << endl;
                cout << "\tAge: " << myAnimal.getAge() << endl;
                myAnimal.makeSound();
                break;
            case 2:
                cout << "Enter the name: ";
                checkstring(b);
                myWildAnimal.setName(b);
                cout << "Enter the age: ";
                checkgraniz(a, 1, 25);
                myWildAnimal.setAge(a);
                cout << "Enter the fur color: ";
                checkstring(b);
                myWildAnimal.setFurColor(b);
                cout << "Enter the averange age of life: ";
                checkgraniz(a, 1, 25);
                myWildAnimal.setaverageage(a);
                cout << "MyWildAnimal" << endl;
                cout << "\tName: " << myWildAnimal.getName() << endl;
                cout << "\tAge: " << myWildAnimal.getAge() << endl;
                cout << "\tFur color: " << myWildAnimal.getFurColor() << endl;
                cout << "\tAge of life: " << myWildAnimal.getaverageage() << endl;
                myWildAnimal.makeSound();
                break;
            case 3:
                cout << "Enter the name: ";
                checkstring(b);
                myHomeAnimal.setName(b);
                cout << "Enter the age: ";
                checkgraniz(a, 1, 25);
                myHomeAnimal.setAge(a);
                cout << "Enter the friendliness: ";
                checkgraniz(a, 0, 10);
                myHomeAnimal.setfriendliness(a);
                cout << "Enter height: ";
                checkgraniz(a, 1, 150);
                myHomeAnimal.setheight(a);
                cout << "MyHomeAnimal" << endl;
                cout << "\tName: " << myHomeAnimal.getName() << endl;
                cout << "\tAge: " << myHomeAnimal.getAge() << endl;
                cout << "\tFriendliness: " << myHomeAnimal.getfriendliness() << endl;
                cout << "\tHeight: " << myHomeAnimal.getheight() << endl;
                myHomeAnimal.makeSound();
                break;
            case 4:
                cout << "Enter the name: ";
                checkstring(b);
                mymonkey.setName(b);
                cout << "Enter the age: ";
                checkgraniz(a, 1, 25);
                mymonkey.setAge(a);
                cout << "Enter the fur color: ";
                checkstring(b);
                mymonkey.setFurColor(b);
                cout << "Enter the friendliness: ";
                checkgraniz(a, 0, 10);
                mymonkey.setfriendliness(a);
                cout << "Enter heignt: ";
                checkgraniz(a, 0, 150);
                mymonkey.setheight(a);
                cout << "Enter the averange age of life: ";
                checkgraniz(a, 1, 25);
                myWildAnimal.setaverageage(a);
                cout << "Enter favourite meal: ";
                checkstring(b);
                mymonkey.setfavmeal(b);
                cout << "Enter number of games: ";
                checkgraniz(a, 0, 100);
                mymonkey.setkoligr(a);
                cout << "MyMonkey" << endl;
                cout << "\tName: " << mymonkey.getName() << endl;
                cout << "\tAge: " << mymonkey.getAge() << endl;
                cout << "\tFur color: " << mymonkey.getFurColor() << endl;
                cout << "\tFriendliness: " << mymonkey.getfriendliness() << endl;
                cout << "\tHeight: " << mymonkey.getheight() << endl;
                cout << "\tAge of life: " << mymonkey.getaverageage() << endl;
                cout << "\tFavourite meal: " << mymonkey.getfavmeal() << endl;
                cout << "\tNumber of games: " << mymonkey.getkoligr() << endl;
                mymonkey.makeSound();
                mymonkey.frienship();
                break;
            case 5:
                cout << "MyAnimal" << endl;
                cout << "\tName: " << myAnimal.getName() << endl;
                name(myAnimal, myAnimal.getAge());
                myAnimal.makeSound();
                cout << "MyHomeAnimal" << endl;
                cout << "\tName: " << myHomeAnimal.getName() << endl;
                name(myHomeAnimal, myHomeAnimal.getAge());
                myHomeAnimal.frienship();
                cout << "\tHeight: " << myHomeAnimal.getheight() << endl;
                myHomeAnimal.makeSound();
                cout << "MyWildAnimal" << endl;
                cout << "\tName: " << myWildAnimal.getName() << endl;
                name(myWildAnimal, myWildAnimal.getAge());
                cout << "\tFur color: " << myWildAnimal.getFurColor() << endl;
                cout << "\tAge of life: " << myWildAnimal.getaverageage() << endl;
                myWildAnimal.makeSound();
                cout << "MyMonkey" << endl;
                cout << "\tName: " << mymonkey.getName() << endl;
                name(mymonkey, mymonkey.getAge());
                cout << "\tFur color: " << mymonkey.getFurColor() << endl;
                mymonkey.frienship();
                cout << "\tHeight: " << mymonkey.getheight() << endl;
                cout << "\tAge of life: " << mymonkey.getaverageage() << endl;
                cout << "\tFavourite meal: " << mymonkey.getfavmeal() << endl;
                cout << "\tNumber of games: " << mymonkey.getkoligr() << endl;
                mymonkey.makeSound();
                break;
            case 6:
                return 0;
        }
    } while (true);
    return 0;
}