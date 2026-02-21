#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib> // exit() için

PhoneBook::PhoneBook() {
    _index = 0; // Başlangıçta kimse yok
}

PhoneBook::~PhoneBook() {
}

// ==========================================
// ADD: YENİ KİŞİ EKLEME (CIRCULAR BUFFER)
// ==========================================
void    PhoneBook::addContact() {
    // MODÜLO BÜYÜSÜ (%):
    // _index 0 ise -> 0 % 8 = 0. elemana yaz.
    // _index 7 ise -> 7 % 8 = 7. elemana yaz.
    // _index 8 ise -> 8 % 8 = 0. elemana yaz (En başa döndü ve ezdi!)
    int targetIndex = _index % 8;

    // Contact sınıfındaki o fonksiyonu çağırıyoruz
    // Eğer veri girişi başarılıysa indexi artırıyoruz
    if (_contacts[targetIndex].setInformation()) {
        _index++; 
        // Not: _index sonsuza kadar artabilir, int taşana kadar sorun yok.
        // Önemli olan modülo (%) alarak kullanmamız.
    }
}

// ==========================================
// SEARCH: LİSTELE VE SEÇ
// ==========================================
void    PhoneBook::searchContact() {
    // 1. Eğer rehber boşsa hiç uğraşma
    if (_index == 0) {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }

    // 2. Tablo Başlığını Bas
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|" << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    // 3. Dolu Olan Satırları Bas
    // Eğer 8'den fazla kişi eklendiyse, ekranda hep 8 kişi görünmeli.
    int limit = _index;
    if (limit > 8)
        limit = 8;

    for (int i = 0; i < limit; i++) {
        // Her satırı Contact sınıfına çizdiriyoruz (O fonksiyonu önceki adımda yazmıştık)
        _contacts[i].viewContactRow(i);
    }
    std::cout << "---------------------------------------------" << std::endl;

    // 4. Kullanıcıdan Index İste
    std::string input;
    std::cout << "Enter index to view details: ";
    
    // getline kullanıyoruz çünkü cin >> input yaparsak bufferda 'enter' kalır,
    // sonraki komut girişini bozar.
    if (!std::getline(std::cin, input))
        exit(0); // Ctrl+D koruması

    // 5. Index Kontrolü (Validation)
    // Sadece tek haneli sayıları kabul et (0-7 arası)
    if (input.length() == 1 && std::isdigit(input[0])) {
        int index = input[0] - '0'; // Char'ı Integer'a çevirme (ASCII matematiği)
        
        // Girilen sayı limitin içindeyse detayları göster
        if (index >= 0 && index < limit) {
            _contacts[index].viewContactDetails();
        } else {
            std::cout << "Invalid index: Out of range!" << std::endl;
        }
    } else {
        std::cout << "Invalid index: Not a valid number!" << std::endl;
    }
}