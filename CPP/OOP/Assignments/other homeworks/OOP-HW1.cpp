#include <iostream>
#include <cstring>

struct WordDescription
{
  char word[100];
  char interpretation[500];
  bool operator>(WordDescription a) 
  {
    return strcmpi(this->word,a.word) > 0;
  }
};


class Dictionary
{
  private:
  WordDescription *words;
  unsigned int size;
  
  public:
  Dictionary ()
  {
    words = nullptr;
    size = 0;
  }
  
  void addWord(WordDescription);
  void removeWord(char*);
  void meaning(char*);
  Dictionary operator+(Dictionary);
  void sort();
  void print();
};

void Dictionary::print()
{
  for (size_t i = 0; i < size; i++)
  {
    std::cout << this->words[i].word << " - " << this->words[i].interpretation << std::endl;
  }
}

void Dictionary::addWord (WordDescription other)
{
  WordDescription* newWords = new WordDescription[size+1];
  for (size_t i = 0; i < size; i++)
  {
    newWords[i] = this->words[i];
  }
  newWords[size] = other;
  size++;
  
  this->words = new WordDescription[size];
  for (size_t i = 0; i < size; i++)
  {
    this->words[i] = newWords[i];
  }
}

void Dictionary::removeWord ( char* other)
{ 
  for (size_t i = 0; i < size; i++)
  {
    if (strcmp(this->words[i].word, other) == 0)
    {
      WordDescription* newWords = new WordDescription[size-1];
      for (size_t j = 0; j < size; j++)
      {
        if(i > j)
        {
          newWords[j] = this->words[j];
        }
        else if(i < j)
        {
          newWords[j-1] = this->words[j];
        }
      }
      size--;
      
      this->words = new WordDescription[size];
      for (size_t j = 0; j < size; j++)
      {
        this->words[j] = newWords[j];
      }
      break;
    }
  }
}

void Dictionary::meaning (char* other)
{
  bool flag = false;
  for (size_t i = 0; i < size; i++)
  {
    if(strcmp(this->words[i].word,other) == 0)
    {
      std::cout << "Meaning - "<< this->words[i].interpretation <<std::endl;
      flag = true;
      break;
    }
  }
  if(!flag)
  {
    std::cout << "No such word exists" << std::endl;
  }
}



void Dictionary::sort()
{
  bool flag = true;
  while (flag)
  {
    flag = false;
    for (size_t i = 0; i < size - 1; i++)
    {
      if(this->words[i] > this->words[i+1])
      {
        WordDescription* newWord = new WordDescription[size];
        for (size_t j = 0; j < size; j++)
        {
          if(j == i)
          {
            newWord[j] = this->words[j+1];
          }
          else if( j == i+1)
          {
            newWord[j] = this->words[j-1];
          }
         else 
          {
            newWord[j] = this->words[j];
          }
        }
        this->words = new WordDescription[size];
        for (size_t j = 0; j < size; j++)
        {
          this->words[j] = newWord[j];
        }
        flag = true;
      }
    }
  }
}

Dictionary Dictionary::operator+(Dictionary other)
{
  Dictionary newDic;
  for (size_t i = 0; i < this->size; i++)
  {
    newDic.addWord(this->words[i]);
  }
  for (size_t i = 0; i < other.size; i++)
  {
    newDic.addWord(other.words[i]);
  }
  return newDic;
}

int main()
{
  WordDescription god = {"Jeesus","Evrein"};
  WordDescription legend = {"Milko Takev","Mesiyata na FMI"};
  WordDescription devil = {"Stefan Gerdjikov","The grimm reaper"};
  WordDescription acho = {"Anguel","zagubi kotkata si"};
  WordDescription father = {"Mitko Dimitrov","Profesionalen bashta"};
  //WordDescription god = {"Aalah","Evrein"};
  Dictionary d1;
  Dictionary d;
  d.addWord(legend);
  d.addWord(god);
  d1.addWord(devil);
  d1.addWord(acho);
  d1.addWord(father);
  //d.print();
  //d.sort();
  //std::cout <<; std::endl;
  //d.print();
  
  Dictionary sorted = (d + d1);
  sorted.sort();
  sorted.print();
 
  
  // d.meaning(god.word);
  // d.removeWord(god.word);
  // d.print();
  //d.meaning(god.word);
  //std::cout << std::boolalpha << (legend > god) << std::endl;
  
  return 0;
}