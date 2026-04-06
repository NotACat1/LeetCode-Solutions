class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        
        while (left < right) {
            int mid = left + (right - left) / 2; // Предотвращает переполнение
            
            if (isBadVersion(mid)) {
                // Если mid — плохая версия, то первая плохая версия находится в [left, mid]
                right = mid;
            } else {
                // Если mid — хорошая версия, то первая плохая версия находится в [mid+1, right]
                left = mid + 1;
            }
        }
        
        // Когда left == right, это и есть первая плохая версия
        return left;
    }
};