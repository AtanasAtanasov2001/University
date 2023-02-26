
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
//---------------TASK1----------------
class Question 
{
    public:
    void print(std::ostream out, const char* q) const;
    void read(std::istream in, char* fileName);
    unsigned int ask() const;
};

class ClosedQuestion : public Question
{

};
class OpenQuestion : public Question
{   
    private:
    char* question = "How are you?";
    char* correctAnswer = "Good, thank you!";
    char* answer;
    
    public:

    void print(std::ostream out, const char* question) const
    {
        out << question;
    }

    unsigned int ask() const
    {
        
        std::cout << question << std::endl;
        std::cout << "Enter your answer: " <<std::endl;
        std::cin >> answer;
        if(strcmp(answer, correctAnswer) == 0)
        {
            std::cout << "tuka";
            return 100;
        }
        else
        {
            std::cout << "tuka2";
            return 0;
        }

    }
};
class Test
{
    private:
    std::vector<Question> questionList;
    OpenQuestion question;
    public:
    void LoadFromFile()
    {
        for (size_t i = 0; i < questionList.size(); i++)
        {
            //questionList[i].read(std::istream in, "questions.txt");
        }
        
    }
    void LoadToFile()
    {
        for (size_t i = 0; i < questionList.size(); i++)
        {
           //questionList[i].print(std::ostream out, "question.txt");
        }
        
    }
    size_t multypleQuestions()
    {
        size_t points;
        questionList.push_back(question);
        for (size_t i = 0; i < questionList.size(); i++)
        {
            points += questionList[i].ask();
        }
        
        return points;
    }
};
//----------------TASK2-------------------
class WorkItem
{
    protected:    
        std::string name;

    public:
    bool status(long now)
    {
        if(now == 1621496040 )
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
};

class SingleTask : public WorkItem
{
    private:
    WorkItem task;
    public:
    long timeOFStart()
    {   
        return 1621496040;
    }
    long lifespan()
    {
        return 5000;
    }
    friend std::ostream& operator<<(std::ostream out, const SingleTask& s)
    {
        out << s.name <<std::endl; 
    }
};
class TaskGroup : public WorkItem
{
    private:

    std::vector<SingleTask> taskGroup;
    SingleTask task;
    public:
    void addTask()
    {
        taskGroup.push_back(task);
    }
    void print()
    {
        for (size_t i = 0; i < taskGroup.size(); i++)
        {
            //std::cout << taskGroup[i] << std::endl;
        }
        
    }
};

bool allDone(std::vector<SingleTask> tasks, int now)
{
    std::cin >> now;
    for (size_t i = 0; i < tasks.size(); i++)
    {
        if(tasks[i].status(now) == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }  
}
int main()
{
    // OpenQuestion q;
    // std::cout << q.ask();
}