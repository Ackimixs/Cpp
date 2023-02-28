#ifndef TP7_ARRAY_H
#define TP7_ARRAY_H

template<class T> class iterator;

template<class T> class array {
private:
    T* data;
    int size;
    T* end;
    friend iterator<T>;

public:
    array(int size) : size(size) {
        this->data = new T[size];
        this->end = this->data + size;
    }

    array(const array& a) {
        this->size = a.size;
        this->data = new T[this->size];
        this->end = this->data + this->size;
        for (int i = 0; i < this->size; i++) {
            this->data[i] = a.data[i];
        }
    }

    ~array() {
        delete[] this->data;
    }

    T* getLast() const {
        return this->end;
    }

    T* getFirst() const {
        return this->data;
    }

    T& operator[](int i) {
        if (i < 0 || i >= this->size) {
            throw std::invalid_argument("index out of range");
        }
        return this->data[i];
    }

    void display() const {
        for (int i = 0; i < this->size; i++) {
            std::cout << this->data[i] << " ";
        }
        std::cout << std::endl;
    }
};


template<class T> class iterator {
private:
    T* ptr;
    int nb;
    int size;
    friend array<T>;

public:
    iterator(T* ptr, int nb, int size) : ptr(ptr), nb(nb), size(size) {}

    iterator(const array<T>& a) : ptr(a.getFirst()), nb(0), size(a.size) {}

    iterator(const iterator& it) {
        this->ptr = it.ptr;
        this->nb = it.nb;
        this->size = it.size;
    }

    T& get() const {
        return *this->ptr;
    }

    int getNb() const {
        return this->nb;
    }

    void decalage(int n) {
        if (n < 0) {
            throw std::invalid_argument("n must be positive");
        }
        if (this->nb + n > this->size) {
            throw std::invalid_argument("n is too big");
        }

        this->ptr += n;
        this->nb += n;
    }

    void operator++(int) {
        if (this->nb < this->size) {
            this->ptr++;
            this->nb++;
        }
    }

    void operator--(int) {
        if (this->nb > 0) {
            this->ptr--;
            this->nb--;
        }
    }

    void set(T value) {
        *this->ptr = value;
    }
};

#endif //TP7_ARRAY_H
