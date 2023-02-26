
class SumAvgCalculator
{
    private:

    int number;
    

    public:
    //Big 4
    int size;
    SumAvgCalculator(int* a);
    SumAvgCalculator operator=(const int&) const;
    ~SumAvgCalculator();

    //metods
    int sum();
    void add(const int a);
    void sub(const int a);
    int num(const SumAvgCalculator&);
    double avegare(const SumAvgCalculator&);

    //operators
    SumAvgCalculator operator+(const SumAvgCalculator&) ;
    SumAvgCalculator operator+=(const SumAvgCalculator&) const ;

};