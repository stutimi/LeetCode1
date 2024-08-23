class Solution {
public:
    string fractionAddition(string expression) {
        vector<int> numerators, denominators;
        int numerator = 0, denominator = 1;
        
        istringstream ss(expression);
        char sign;
        while (ss >> numerator) {
            ss >> sign; 
            ss >> denominator;
            int lcm = abs(denominator) * abs(denominators.empty() ? 1 : denominators.back()) / gcd(denominator, denominators.empty() ? 1 : denominators.back());
            
            if (!numerators.empty()) {
                numerators.back() = numerators.back() * (lcm / denominators.back()) + numerator * (lcm / denominator);
                denominators.back() = lcm;
            } else {
                numerators.push_back(numerator);
                denominators.push_back(denominator);
            }
        }
        int final_numerator = numerators.back();
        int final_denominator = denominators.back();
        int common_gcd = gcd(abs(final_numerator), abs(final_denominator));
        final_numerator /= common_gcd;
        final_denominator /= common_gcd;
        return to_string(final_numerator) + "/" + to_string(final_denominator);
    }
};

