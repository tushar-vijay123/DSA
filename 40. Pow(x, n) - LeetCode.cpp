class Solution {
public:
    double myPow(double x, int n) {

        if(n == 0)
        {
            return 1.0;
        }

        if(x == 0 || x == 1)
        {
            return x;
        }

        if(x == -1 && n%2 == 0)
        {
            return 1.0;
        }

        if(x == -1 && n%2 != 0)
        {
            return -1.0;
        }

        // BINARY EXPONENTIATION
        long binForm = n;
        double ans = 1;

        if(n < 0)
        {
            x = 1/x; // any number raised to negative power becomes reciprocal
            binForm = -binForm; // making power positive
        }

        while(binForm > 0)
        {
            if(binForm % 2 == 1)
            {
                ans = ans * x;
            }

            x *= x;
            binForm /= 2;
        }

        return ans;
    }
};
