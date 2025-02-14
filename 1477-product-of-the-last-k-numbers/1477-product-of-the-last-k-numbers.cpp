class ProductOfNumbers {
public:
    vector<int> prefixProd;  // Stores cumulative products
    
    ProductOfNumbers() {
        prefixProd.clear();
    }
    
    void add(int num) {
        if (num == 0) {
            // Reset the prefix product list when encountering zero
            prefixProd.clear();
        } else {
            if (prefixProd.empty()) {
                prefixProd.push_back(num);
            } else {
                prefixProd.push_back(prefixProd.back() * num);
            }
        }
    }
    
    int getProduct(int k) {
        if (k > prefixProd.size()) return 0;  // If k exceeds available elements, return 0
        if (k == prefixProd.size()) return prefixProd.back();
        return prefixProd.back() / prefixProd[prefixProd.size() - k - 1];
    }
};
