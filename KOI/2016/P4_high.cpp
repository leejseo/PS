#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
 
#include <vector>
 
using namespace std;
 
#define square(a) ((a) * (long long)(a))
 
#define MAX_T 10000000
#define MAX_N 30000
 
class Star
{
        public:
                inline void read() {
                        scanf("%d%d%d%d", &m_org_x, &m_org_y, &m_dx, &m_dy);
                        m_x = m_org_x;
                        m_y = m_org_y;
                }
 
                inline int x() const { return m_x; }
                inline int y() const { return m_y; }
 
                inline void place(int t) {
                        m_x = m_org_x + t * m_dx;
                        m_y = m_org_y + t * m_dy;
                }
 
                inline long long distance(const Star &other) const {
                        return square(m_x - other.m_x) + square(m_y - other.m_y);
                }
 
        private:
                int m_org_x;
                int m_org_y;
                int m_dx;
                int m_dy;
                int m_x;
                int m_y;
};
 
inline long long CCW(const Star &P, const Star &P1, const Star &P2) {
        long long x1 = P.x();
        long long x2 = P1.x();
        long long x3 = P2.x();
        long long y1 = P.y();
        long long y2 = P1.y();
        long long y3 = P2.y();
        long long Area = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
        if (Area == 0) return 0;
        if (Area > 0) return 1;
        return -1;
}
 
inline bool operator<(const Star &a, const Star &b) {
        if (a.x() < b.x()) return true;
        if (a.x() > b.x()) return false;
        return a.y() < b.y();
}
 
inline bool check_inc_upper(vector<Star> &U, vector<Star> &L , int i, int j){
        long long a1, a2, a3, a4;
        a1 = U[i+1].y() - U[i].y();
        a2 = L[j].x() - L[j-1].x();
        a3 = L[j].y() - L[j-1].y();
        a4 = U[i+1].x() - U[i].x();
        return (a1 * a2) > (a3 * a4);
}
 
inline void convex_hull(Star stars[], int n, int t, vector<Star> &UP, vector<Star> &LO) {
 
        UP.clear();
        LO.clear();
 
        sort(stars, stars + n);
 
        for (int i = 0; i < n; i++) {
                while ((UP.size() > 1) && (CCW(UP[UP.size() - 2], UP[UP.size() - 1], stars[i]) >= 0))
                        UP.pop_back();
 
                while ((LO.size() > 1) && (CCW(LO[LO.size() - 2], LO[LO.size() - 1], stars[i]) <= 0))
                        LO.pop_back();
 
                UP.push_back(stars[i]);
                LO.push_back(stars[i]);
        }
}
 
inline long long farthest_distance(Star stars[], int n, int t) {
 
        for (int i = 0; i < n; i++)
                stars[i].place(t);
 
        vector<Star> UP, LO;
        convex_hull(stars, n, t, UP, LO);
 
 
        int i = 0;
        int j = LO.size() - 1;
        long long farthest = 0;
        long long dist;
 
 
        while ((i < (int)UP.size() - 1) || (j > 0)) {
                dist = UP[i].distance(LO[j]);
                if (dist > farthest) farthest = dist;
 
                if (i == (int)UP.size() - 1) j--;
                else if (j == 0) i++;
                else if (check_inc_upper(UP, LO, i, j)) i++;
                else j--;
        }
        dist = UP[i].distance(LO[j]);
        if (dist > farthest) farthest = dist;
        return farthest;
}
 
int seek_day(Star stars[], int n, int T, long long &farthest) {
        int left = 0;
        int right = T;
        while (left <= right) {
                int L = (2 * left + right)/3;
                int R = (left + 2 * right + 1)/3;
                if (farthest_distance(stars, n, L) <= farthest_distance(stars, n, R))
                        right = R - 1;
                else left = L + 1;
        }
        farthest = farthest_distance(stars, n, left);
        return left;
}
 
int main() {
        int n, T;
        Star stars[MAX_N];
 
        scanf("%d%d", &n, &T);
        for (int i=0; i<n; i++)
                stars[i].read();
 
        long long d;
        int day = seek_day(stars, n, T, d);
 
        printf("%d\n", day);
        printf("%lld\n", d);
        return 0;
}
