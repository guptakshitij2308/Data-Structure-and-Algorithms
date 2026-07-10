class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n=asteroids.size();
        sort(asteroids.begin(),asteroids.end());
        long long int totalMass=mass,sum=0;
        for(int i=0;i<n;i++) {
            if(asteroids[i]<=totalMass)
            totalMass+=asteroids[i];
            else if(totalMass<asteroids[i]) return false;
            else
            totalMass-=asteroids[i];
        }
        return totalMass>0;
    }
};