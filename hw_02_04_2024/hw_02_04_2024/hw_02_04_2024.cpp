#include <iostream>
using namespace std;

class Superpower {
public:
    virtual void UseSuperpower() = 0;
};

class Claw : public Superpower {
public:
    void UseSuperpower() override {
        cout << "Use Claw...\n";
    }
};

class Flight : public Superpower {
public:
    void UseSuperpower() override {
        cout << "Use Flight...\n";
    }
};

class Stamina : public Superpower {
public:
    void UseSuperpower() override {
        cout << "Use Stamina...\n";
    }
};

class NightVision : public Superpower {
public:
    void UseSuperpower() override {
        cout << "Use NightVision...\n";
    }
};

class FastRunning : public Superpower {
public:
    void UseSuperpower() override {
        cout << "Use FastRunning...\n";
    }
};

class Good {
public:
    virtual void Mission() {
        cout << "Help people...\n";
    }
};

class Bad {
public:
    virtual void Mission() {
        cout << "Kill all people...\n";
    }
};

class Person {
public:
    virtual void TypOfAbility() {
        cout << "Congenital...\n";
    }
    virtual void Life() {
        cout << "Acquired...\n";
    }
};

class Deitly {
public:
    virtual void TypOfAbility() {
        cout << "Congenital...\n";
    }
    virtual void Life() {
        cout << "Immortal...\n";
    }
};

class Animal {
public:
    virtual void TypOfAbility() {
        cout << "Congenital...\n";
    }
    virtual void Life() {
        cout << "Deadly...\n";
    }
};

class Superhero : public Person, public Good, public Superpower {
public:
    virtual void Name() = 0;
    virtual void UseSuperpower() = 0;
};

class Hulk : public Superhero, public Deitly, public Stamina {
public:
    void Name() override {
        cout << "I'm Hulk\n";
    }

    void UseSuperpower() override {
        cout << "Use Hulk's abilities...\n";
    }
};

class BlackWidow : public Superhero, public Person, public FastRunning {
public:
    void Name() override {
        cout << "I'm Black Widow\n";
    }

    void UseSuperpower() override {
        cout << "Use Black Widow's abilities...\n";
    }
};

class Venom : public Superhero, public Animal, public Claw {
public:
    void Name() override {
        cout << "I'm Venom\n";
    }

    void UseSuperpower() override {
        cout << "Use Venom's abilities...\n";
    }
};

class Falcon : public Superhero, public Person, public Flight {
public:
    void Name() override {
        cout << "I'm Falcon\n";
    }

    void UseSuperpower() override {
        cout << "Use Falcon's abilities...\n";
    }
};


int main() {
    Superhero* superheroes[4];
    superheroes[0] = new Hulk;
    superheroes[1] = new BlackWidow;
    superheroes[2] = new Venom;
    superheroes[3] = new Falcon;

    cout << "Superheroes who can fly:\n";
    for (int i = 0; i < 4; ++i) {
        if (dynamic_cast<Flight*>(superheroes[i])) {
            superheroes[i]->Name();
            superheroes[i]->UseSuperpower();
            cout << "\n";
        }
    }

    for (int i = 0; i < 4; ++i) {
        delete superheroes[i];
    }
}
