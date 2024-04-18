#include <iostream>

class BankovskiSchet {
private:
    int accountNumber; 
    double balance; 
    double interestRate; 

    

public:
    
    BankovskiSchet(int accNumber, double initialBalance) {
        this->accountNumber = accNumber; 
        this->balance = initialBalance; 
        this->interestRate = 0.0; 
    }

    
    void deposit(double amount) {
        setlocale(LC_ALL, "Russian");
        if (amount > 0) {
            this->balance += amount; 
            std::cout << "Пополнение счета прошло успешно. Баланс: " << this->balance << std::endl;
        }
        else {
            std::cerr << "Ошибка:" << std::endl;
        }
    }

    
    void withdraw(double amount) {
        setlocale(LC_ALL, "Russian");
        if (amount > 0 && amount <= this->balance) {
            this->balance -= amount; 
            std::cout << "Пополнение баланса: " << this->balance << std::endl;
        }
        else {
            std::cerr << "Ошибка: недостаточно средств." << std::endl;
        }
    }


    double getBalance() const {
        return this->balance;
    }

  
    double getInterest() const {
        return (this->balance * this->interestRate) / 12.0;
    }

  
    void setInterestRate(double rate) {
        setlocale(LC_ALL, "Russian");
        this->interestRate = rate;
        std::cout << "Обновленная процентная ставка: " << this->interestRate << std::endl;
    }


    int getAccountNumber() const {
        return this->accountNumber;
    }


    friend bool transfer(BankovskiSchet& from, BankovskiSchet& to, double amount);
};


bool transfer(BankovskiSchet& from, BankovskiSchet& to, double amount) {
    setlocale(LC_ALL, "Russian");
    if (amount > 0 && amount <= from.balance) {
        from.balance -= amount; 
        to.balance += amount; 
        std::cout << "Перевод прошел успешно. Баланс : " << from.balance << std::endl;
        std::cout << "Новый баланс получателя: " << to.balance << std::endl;
        return true;
    }
    else {
        std::cerr << "Ошибка: недостаточно средств или неверная сумма перевода." << std::endl;
        return false;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    BankovskiSchet schet1(123456, 10000.0); 
    BankovskiSchet schet2(654321, 800.0); 

 
    schet1.deposit(600.0);
    schet1.withdraw(300.0);

  
    schet1.setInterestRate(0.05);
    std::cout << "Заработанные проценты: " << schet1.getInterest() << std::endl;


    transfer(schet1, schet2, 400.0);

    return 0;
}

