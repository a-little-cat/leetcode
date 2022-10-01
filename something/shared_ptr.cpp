#include <iostream>
#include <memory>
#include <mutex>

using namespace std;

template <class T>
class s_ptr
{
public:
    s_ptr(T* p)
        : data_(p)
        , count_(new int(1))
        , mutex_(new mutex){};

    ~s_ptr()
    {
        sub_count();
    }

    s_ptr(const s_ptr<T>& p_)
        : data_(p_.data_)
        , count_(p_.count_)
    {
        add_count();
    }

    s_ptr<T>& operator=(const s_ptr<T> p)
    {
        if (p.data_ != data_)
        {
            sub_count();
            data_ = p.data_;
            count_ = p.count_;
            mutex_ = p.mutex_;
            add_count();
        }
        return *this;
    }

    T& operator*()
    {
        return *data_;
    }
    T* get()
    {
        return data_;
    }
    int count()
    {
        return *count_;
    }

private:
    void add_count()
    {
        mutex_->lock();
        (*count_)++;
        mutex_->unlock();
    }

    void sub_count()
    {
        bool release_mutex_flag = false;
        mutex_->lock();
        if (--(*count_) == 0)
        {
            delete data_;
            delete count_;
            release_mutex_flag = true;
        }
        mutex_->unlock();
        delete mutex_;
    }

    T* data_;
    int* count_;
    mutex* mutex_;
};

int main()
{
    s_ptr<int> a(new int(1));
    cout << "a.count is " << a.count() << endl;
    {
        auto b = a;
        cout << "a.count is " << a.count() << endl;
        cout << "b is " << *b << endl;
    }
    cout << "a.count is " << a.count() << endl;
    cout << "a is " << *a << endl;
}
