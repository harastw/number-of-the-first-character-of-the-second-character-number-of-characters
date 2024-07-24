#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>

// Генерация случайного символа
char getRandomCharacter() {
  const std::string validChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-_$~";
  return validChars[rand() % validChars.size()];
}

// Генерация строки заданной длины
std::vector<char> generateRandomString(int length) {
  std::vector<char> randomString;
  for (int i = 0; i < length; ++i) {
    char randomChar = getRandomCharacter();
    // Проверяем, чтобы символ не был C, P, S, X
    if (randomChar != 'C' && randomChar != 'P' && randomChar != 'S' && randomChar != 'X') {
      randomString.push_back(randomChar);
    } else {
      --i; // Повторяем итерацию, если символ недопустимый
    }
  }
  return randomString;
}

// Замена букв в строке
void replaceLetters(std::vector<char>& str, char replacement, std::vector<bool>& unchangedCounts) {
  for (int i = 0; i < str.size(); i++) {
    if (isalpha(str[i])) {
      if (str[i] != replacement)
	unchangedCounts[i] = false;
      str[i] = replacement;
    }
  }
}

// Замена цифр в строке
void replaceDigits(std::vector<char>& str, char replacement, std::vector<bool>& unchangedCounts) {
  for (int i = 0; i < str.size(); i++) {
    if (isdigit(str[i])) {
      if (str[i] != replacement)
	unchangedCounts[i] = false;
      str[i] = replacement;
    }
  }
}

void printV(std::vector<char> v) {
  for (auto el : v)
    std::cout << el;
  std::cout << "\n";
}
/* для тестирования
void printVB(std::vector<bool> v) {
  for (auto i = 0; i < v.size(); i++)
    std::cout << "element index " << i << " is " << v[i] << "\n";
  std::cout << "\n";
}
*/
// Подсчет символов
void countCharacters(std::vector<char>& str, char firstChar, char secondChar, std::vector<bool>& unchangedCounts) {
  int countFirstChar = std::count(str.begin(), str.end(), firstChar);
  int countSecondChar = std::count(str.begin(), str.end(), secondChar);

  std::cout << "Количество повторов первого символа: " << countFirstChar << std::endl;
  std::cout << "Количество повторов второго символа: " << countSecondChar << std::endl;
  int unchangedCountsNumber = 0;
  for (auto el : unchangedCounts)
    if (el)
      unchangedCountsNumber++;
  std::cout << "Количество символов, которые не были заменены: " << unchangedCountsNumber << std::endl;
}

// Основная функция
int main() {
  srand(time(0)); // Инициализируем генерацию случайных чисел

  int N;
  std::cout << "Введите длину строки (N): ";
  std::cin >> N;
  std::vector<bool> unchangedCounts;
  for (auto i = 0; i < N; i++)
    unchangedCounts.push_back(true);
  // printVB(unchangedCounts);

  std::vector<char> generatedString = generateRandomString(N);
  /*std::vector<char> generatedString; // очень удобно протестировать разные строки
  for (int i = 0; i < N - 1; i++) {
    generatedString.push_back('a');
  }
  generatedString.push_back('+');*/
  std::cout << "Сгенерированная строка: ";
  printV(generatedString);

  char firstChar;
  std::cout << "Введите первый символ для замены букв: ";
  std::cin >> firstChar;

  replaceLetters(generatedString, firstChar, unchangedCounts);
  std::cout << "Строка после замены букв: ";
  printV(generatedString);

  char secondChar;
  std::cout << "Введите второй символ для замены цифр: ";
  std::cin >> secondChar;

  replaceDigits(generatedString, secondChar, unchangedCounts);
  std::cout << "Конечная строка: ";
  printV(generatedString);

  countCharacters(generatedString, firstChar, secondChar, unchangedCounts);

  return 0;
}
