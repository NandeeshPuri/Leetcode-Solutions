class ZeroEvenOdd {
private:
    int n;
    mutex m0,me,mo;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        me.lock();
        mo.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i=1;i<=n;i++){
            m0.lock();
            printNumber(0);
            if(i%2) mo.unlock();
            else me.unlock();
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i=2;i<=n;i+=2){
            me.lock();
            printNumber(i);
            m0.unlock();
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i=1;i<=n;i+=2){
            mo.lock();
            printNumber(i);
            m0.unlock();
        }
    }
};