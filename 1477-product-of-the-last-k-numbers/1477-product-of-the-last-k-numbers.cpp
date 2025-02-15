class ProductOfNumbers {
public:
vector<int>vec;
    ProductOfNumbers() {
        vec.clear();
    }
    
    void add(int num) {
        if(num==0)
        vec.clear();
        else if(vec.empty())
        vec.push_back(num);
        else
        vec.push_back(vec.back()*num);
    }
    
    int getProduct(int k) {
        if(k>vec.size())
        return 0;
        if(k==vec.size())
        return vec.back();
        else
        return vec.back()/vec[vec.size()-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */