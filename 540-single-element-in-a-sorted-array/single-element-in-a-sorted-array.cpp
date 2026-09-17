class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {

        int ans=0;
        for (int x:a){
            ans^=x;
        }
        return ans;
/*
        int st = 0;
        int n = a.size();
        int end = n - 1;

        while (st <= end) {

            int mid = st + (end - st) / 2;

            if (n == 1)
                return a[0];

            if (mid == n - 1 && a[n - 1] != a[n - 2])
                return a[n - 1];

            if (mid == 0 && a[0] != a[1])
                return a[0];

            if (a[mid - 1] != a[mid] && a[mid] != a[mid + 1])
                return a[mid];

            if (mid % 2 == 0) {      // <-- yahi change hai

                if (a[mid] == a[mid + 1])
                    st = mid + 1;
                else
                    end = mid - 1;

            } else {

                if (a[mid] == a[mid - 1])
                    st = mid + 1;
                else
                    end = mid - 1;
            }
        }
*/
       // return -1;
    }
};