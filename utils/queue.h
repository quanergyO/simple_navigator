#ifndef A2_SIMPLE_NAVIGATOR_V1_0_1_UTILS_QUEUE_H_
#define A2_SIMPLE_NAVIGATOR_V1_0_1_UTILS_QUEUE_H_

#include <deque>

namespace s21
{
template <typename T>
class Queue
{
    using value_type = T;
    using container_type = std::deque<T>;
    using reference = T&;
    using const_reference = const T&;

public:
    Queue() = default;
    ~Queue() = default;
    void push(const_reference value) { container_.push_back(value); }
    value_type pop() { 
        value_type return_value = container_.front();
        container_.pop_front(); 
        return return_value;
    }

    reference top() { return container_.front(); }
    const_reference top() const { return container_.front(); }

    bool empty() const noexcept { return container_.empty(); }

private:
    
    reference front() { return container_.front(); }
    const_reference front() const { return container_.front(); }
    reference back() { return container_.back(); }
    const_reference back() const { return container_.back(); }

private:
    container_type container_;
};


}

#endif // A2_SIMPLE_NAVIGATOR_V1_0_1_UTILS_QUEUE_H_