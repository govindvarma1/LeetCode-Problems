class Foo {
    std::mutex m;
    std::condition_variable cv;
    int turn;
public:
    Foo() {
        turn = 1;
    }

    void first(function<void()> printFirst) {
        printFirst();
        turn++;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lock(m);
        while(turn != 2) {
            cv.wait(lock);
        }
        printSecond();
        turn++;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lock(m);
        while(turn != 3) {
            cv.wait(lock);
        }
        printThird();
    }
};