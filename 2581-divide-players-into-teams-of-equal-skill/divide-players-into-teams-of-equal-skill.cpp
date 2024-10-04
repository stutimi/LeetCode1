class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end()); // Sort the skills array

        long long sum = 0;
        int total_skill = skill[0] + skill[n - 1]; // Skill sum of the first and last players (smallest + largest)

        for (int i = 0; i < n / 2; ++i) {
            // Check if each pair has the same total skill
            if (skill[i] + skill[n - i - 1] != total_skill) {
                return -1; // If not, return -1 as it's impossible to form valid teams
            }
            // Calculate the chemistry (product of skills)
            sum += (long long)skill[i] * skill[n - i - 1];
        }

        return sum; // Return the total sum of chemistry
    }
};
