#ifndef SIMPLEVEC_HPP
#define SIMPLEVEC_HPP

namespace medianabox {
namespace containers {

class SimpleVec
{
    public:
        using iterator = int*;
        SimpleVec();
        SimpleVec(const SimpleVec& lhs);
        SimpleVec& operator=(const SimpleVec& lhs);
        SimpleVec(SimpleVec&& lhs) = delete;
        SimpleVec& operator=(SimpleVec&& lhs) = delete;
        inline iterator begin() {return vecData_;};
        inline iterator end() {return vecData_ + vecSize_;}; 
        virtual ~SimpleVec();
        int get(std::size_t) const;
        void set(int, std::size_t);
        void insert(int, std::size_t);
        void push_back(int);
        int& operator[](std::size_t) ;
        const int& operator[](std::size_t) const;
        std::size_t size() const;

    
    private:
        void increaseVecCapacity();
        int* vecData_;
        std::size_t vecSize_;
        std::size_t vecCapacity_;

};

} // namespace containers
} // namespace medianabox

#endif /* SIMPLEVEC_HPP */