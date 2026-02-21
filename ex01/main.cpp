#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main()
{
    PhoneBook   myPhoneBook; // PhoneBook nesnemizi (beyni) yarattık
    std::string command;

    // 80'ler temasına uygun ufak bir karşılama mesajı :)
    std::cout << "========================================\n";
    std::cout << "  WELCOME TO THE 80s AWESOME PHONEBOOK  \n";
    std::cout << "========================================\n";
    std::cout << "Available commands: ADD, SEARCH, EXIT\n";

    // Sonsuz oyun döngüsü
    while (true)
    {
        std::cout << "\n> ";
        
        // Kullanıcıdan komut alıyoruz
        if (!std::getline(std::cin, command))
        {
            // Eğer EOF (Ctrl+D) gelirse std::cin bozulur ve false döner.
            // Bu durumda sonsuz döngüye girmemek için programı anında kapatıyoruz.
            std::cout << "\n[EOF detected] Exiting PhoneBook. Goodbye!" << std::endl;
            break;
        }

        // Komut Yönlendirmeleri
        if (command == "ADD")
        {
            myPhoneBook.addContact();
        }
        else if (command == "SEARCH")
        {
            myPhoneBook.searchContact();
        }
        else if (command == "EXIT")
        {
            std::cout << "Contacts are lost forever! Goodbye." << std::endl;
            break; // Döngüyü kır ve programı bitir
        }
        else if (!command.empty()) // Boş basıp Enter'a basarsa hata verme, sadece bekle
        {
            // PDF Kuralı: "Any other input is ignored." 
            // Biz yine de kullanıcıya ufak bir uyarı verebiliriz.
            std::cout << "Invalid command. Use ADD, SEARCH or EXIT." << std::endl;
        }
    }

    return 0;
}