#include "Contact.hpp"
#include <iomanip> // std::setw ve hizalama işlemleri için
#include <cstdlib> // exit() için (Ctrl+D durumu)

// Constructor (Kurucu) - Şimdilik içi boş kalabilir
Contact::Contact() {
}

// Destructor (Yıkıcı) - Şimdilik içi boş kalabilir
Contact::~Contact() {
}

// ==========================================
// KULLANICI GİRİŞİ (ADD KOMUTU İÇİN)
// ==========================================
bool Contact::setInformation() {
    std::string input;

    // 1. First Name
    _firstName = "";
    while (_firstName.empty()) {
        std::cout << "First Name: ";
        std::getline(std::cin, _firstName);
        if (std::cin.eof()) exit(1); // 42 Tuzağı: Ctrl+D basılırsa programı güvenlice kapat
    }

    // 2. Last Name
    _lastName = "";
    while (_lastName.empty()) {
        std::cout << "Last Name: ";
        std::getline(std::cin, _lastName);
        if (std::cin.eof()) exit(1);
    }

    // 3. Nickname
    _nickname = "";
    while (_nickname.empty()) {
        std::cout << "Nickname: ";
        std::getline(std::cin, _nickname);
        if (std::cin.eof()) exit(1);
    }

    // 4. Phone Number
    _phoneNumber = "";
    while (_phoneNumber.empty()) {
        std::cout << "Phone Number: ";
        std::getline(std::cin, _phoneNumber);
        if (std::cin.eof()) exit(1);
    }

    // 5. Darkest Secret
    _darkestSecret = "";
    while (_darkestSecret.empty()) {
        std::cout << "Darkest Secret: ";
        std::getline(std::cin, _darkestSecret);
        if (std::cin.eof()) exit(1);
    }

    std::cout << "Contact added successfully!\n" << std::endl;
    return true;
}

// ==========================================
// TABLO GÖRÜNÜMÜ (SEARCH KOMUTU İÇİN)
// ==========================================
void Contact::viewContactRow(int index) const {
    // 10 karakter sınırını ayarlayan küçük bir lambda/inline mantığı
    std::string printFirst = _firstName;
    if (printFirst.length() > 10)
        printFirst = printFirst.substr(0, 9) + ".";

    std::string printLast = _lastName;
    if (printLast.length() > 10)
        printLast = printLast.substr(0, 9) + ".";

    std::string printNick = _nickname;
    if (printNick.length() > 10)
        printNick = printNick.substr(0, 9) + ".";

    // Ekrana formatlı basma (iomanip kütüphanesinin gücü)
    std::cout << std::setw(10) << std::right << index << "|"
              << std::setw(10) << std::right << printFirst << "|"
              << std::setw(10) << std::right << printLast << "|"
              << std::setw(10) << std::right << printNick << std::endl;
}

// ==========================================
// DETAYLI GÖRÜNÜM (SEARCH -> INDEX SEÇİMİ İÇİN)
// ==========================================
void Contact::viewContactDetails() const {
    std::cout << "First Name     : " << _firstName << std::endl;
    std::cout << "Last Name      : " << _lastName << std::endl;
    std::cout << "Nickname       : " << _nickname << std::endl;
    std::cout << "Phone Number   : " << _phoneNumber << std::endl;
    std::cout << "Darkest Secret : " << _darkestSecret << std::endl;
    std::cout << std::endl;
}