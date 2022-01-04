class Solution:
    def maxTaxiEarnings(self, n: int, rides: List[List[int]]) -> int:
        trip_info = defaultdict(list)
        for start, end, tip in rides:
            trip_info[end].append([start, end-start+tip])
        dp = [0]*(n+1)
        for i in range(1, n+1):
            dp[i] = dp[i-1]
            for start, earnings in trip_info[i]:
                dp[i] = max(dp[i], dp[start] + earnings)
        return dp[n]
