class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        curr_sum = sum(cardPoints[:k])
        ans = curr_sum
        for i in range(k):
            curr_sum = curr_sum - cardPoints[k-i-1] + cardPoints[len(cardPoints)-1-i]
            ans = max(ans, curr_sum)
        return ans
