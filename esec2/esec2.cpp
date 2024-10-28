#include <iostream>
#include <string>

using namespace std;

// Функция для шифрования с использованием шифра Виженера
string vigenereEncrypt(const string& text, const string& key) {
    string encryptedText;
    int keyLength = key.length();

    // Проходим по каждому символу открытого текста
    for (int i = 0; i < text.length(); i++) {
        char letter = text[i];

        // Проверяем, является ли символ буквой
        if (isalpha(letter)) {
            // Смещаем по ключу, различая заглавные и строчные буквы
            char offset = isupper(letter) ? 'A' : 'a';
            char keyOffset = isupper(key[i % keyLength]) ? 'A' : 'a';
            char encryptedChar = ((letter - offset + (key[i % keyLength] - keyOffset)) % 26) + offset;
            encryptedText += encryptedChar;
        }
        else {
            encryptedText += letter; // Если символ не буква, оставляем его без изменений
        }
    }
    return encryptedText;
}

// Функция для расшифровки с использованием шифра Виженера
string vigenereDecrypt(const string& encryptedText, const string& key) {
    string decryptedText;
    int keyLength = key.length();

    // Проходим по каждому символу зашифрованного текста
    for (int i = 0; i < encryptedText.length(); i++) {
        char letter = encryptedText[i];

        // Проверяем, является ли символ буквой
        if (isalpha(letter)) {
            // Смещаем по ключу в обратном направлении
            char offset = isupper(letter) ? 'A' : 'a';
            char keyOffset = isupper(key[i % keyLength]) ? 'A' : 'a';
            char decryptedChar = ((letter - offset - (key[i % keyLength] - keyOffset) + 26) % 26) + offset;
            decryptedText += decryptedChar;
        }
        else {
            decryptedText += letter; // Если символ не буква, оставляем его без изменений
        }
    }
    return decryptedText;
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Исходный текст и ключ
    string openText = "HELLOVIGENERECIPHER";
    string key = "ALPHA";

    // Шифрование текста
    string encryptedText = vigenereEncrypt(openText, key);
    cout << "Открытый текст: " << openText << endl;
    cout << "Зашифрованный текст: " << encryptedText << endl;

    // Расшифровка текста
    string decryptedText = vigenereDecrypt(encryptedText, key);
    cout << "Расшифрованный текст: " << decryptedText << endl;

    return 0;
}
