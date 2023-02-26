#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

//========================TASK1========================
class Question
{
    public:
    virtual void print(std::ostream& os) const = 0;
    virtual void read (std::istream& is) = 0;
    virtual unsigned int ask() const = 0;
};

class ClosedQuestion : public Question
{
    private:
    std::string question;
    char *answers;
    char correct_answer;
    public:
    ClosedQuestion()
    {
        question = nullptr;
        answers = nullptr;
        correct_answer = 0;
    }
    ClosedQuestion(std::string question_, char *answers_, char correct_answer_)
    {
        question = question_;
        answers = new char[strlen(answers_) + 1];
        strcpy(answers,answers_);
        correct_answer = correct_answer_;
    }
    void print(std::ostream& os) const
    {
        os << question  << " " << answers << " " << correct_answer <<std::endl;
    }
    void read(std::istream& is) 
    {
        is >> question >> answers >> correct_answer;
    }
    unsigned int ask() const
    {
        char my_answer;
        std::cout << question <<std::endl;
        std::cin >> my_answer ;
        return( my_answer == correct_answer) ?  1 :  0;
        
    }
};

class OpenQuestion : public Question
{
    private:
    std::string question;
    std::string correct_answer;
    public:
    OpenQuestion()
    {
        question = nullptr;
        correct_answer = nullptr;
    }
    OpenQuestion(std::string question_, std::string correct_answer_)
    {
        question = question_;
        correct_answer = correct_answer_;
    }
    void print(std::ostream& os) const
    {
        os << question  << " " << correct_answer <<std::endl;
    }
    void read(std::istream& is) 
    {
        is >> question  >> correct_answer;
    }
    unsigned int ask() const
    {
        std::string my_answer;
        std::cout << question <<std::endl;
        std::cin >> my_answer ;

        if (my_answer == correct_answer) 
        {
            std::cout << "Correct!" << std::endl;
            return 1;
        }       
        else
        {
            std::cout << "Na esen, s pesen" << std::endl;
            return 0;
        }
    }
};

//========================TASK2========================
class WorkItem
{
    public:
    virtual bool status(long now) = 0;
    virtual std::string name() = 0;
};

class SingleTask : public WorkItem
{
    private:
    long start_time;
    long duration;
    std::string name_;
    public:
    SingleTask()
    {
        start_time = 0;
        duration = 0;
        name_ = nullptr;
    }
    SingleTask(long start_time_,long duration_, std::string name1_ )
    {
        start_time = start_time_;
        duration = duration_;
        name_ = name1_;
    }
    bool status(long now)
    {
        return (now >= (start_time + duration));
    }
    std::string name()
    {
        return name_;
    }
};

class TaskGroup : public WorkItem
{
    private:
    std::vector<WorkItem*> task_group;
    long start_time ;
    long duration;
    std::string name_;
    public:
    TaskGroup()
    {
        start_time = 0;
        duration = 0;
        name_ = nullptr;
    }
    TaskGroup(long start_time_,long duration_, std::string name1_ )
    {
        start_time = start_time_;
        duration = duration_;
        name_ = name1_;
    }
    bool status(long now)
    {
        for (size_t i = 0; i < task_group.size(); i++)
        {
            if(!(task_group[i]->status(now)))
            {
                return false;
                std::cout << std::endl;
            }
        }
        return true;
    }
    std::string name()
    {
        return name_;
    }
    void addTask(WorkItem *new_task)
    {
        task_group.push_back(new_task);
    }
    void print()
    {
        for (size_t i = 0; i < task_group.size(); i++)
        {
            std::cout << task_group[i]->name() << " ";
        }
        std::cout << std::endl;
    }
};

bool allDone(std::vector<WorkItem*> tasks, int now)
{
    bool flag = false;
    for (size_t i = 0; i < tasks.size(); i++)
    {
        (tasks[i]->status(now))? flag = true : flag;
    }
    return flag;
    
}
int main()
{
//========================TASK1========================
    // ClosedQuestion q1("will i pass OOP", "abc", 'c');
    // std::cout << q1.ask();

    // std::cout << std::endl;
    // OpenQuestion q2("Will i pass OOP and Up", "Yes");
    // std::cout << q2.ask();

//========================TASK2========================
    SingleTask s1(0,10,"s1");
    std::cout << s1.name() << std::endl;
    std::cout << std::boolalpha << s1.status(9) << std::endl;

    SingleTask s2(3,9,"s2");

    TaskGroup t1(0,10,"task group 1");
    t1.addTask(&s1);
    t1.addTask(&s2);
    std::cout << t1.name() << std::endl;
    t1.print();
    std::cout << std::boolalpha << t1.status(11) << std::endl;
    
    std::vector<WorkItem*> all_together;
    all_together.push_back(&t1);
    
    std::cout << std::boolalpha << allDone(all_together,12);

}