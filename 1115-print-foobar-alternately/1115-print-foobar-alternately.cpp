class FooBar {
private:
    int n;
    mutex m;
    condition_variable cv;
    int turn = 0;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        unique_lock<mutex> lock(m);
        for (int i = 0; i < n; i++) {
            while(turn != 0) {
                cv.wait(lock);
            }
        	printFoo();
            turn++;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        unique_lock<mutex> lock(m);
        for (int i = 0; i < n; i++) {
            while(turn != 1) {
                cv.wait(lock);
            }
        	printBar();
            turn--;
            cv.notify_all();
        }
    }
};