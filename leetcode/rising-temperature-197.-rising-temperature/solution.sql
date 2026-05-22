-- Problem: 197. Rising Temperature
-- URL: https://leetcode.com/problems/rising-temperature/
-- Language: mysql
-- Submission ID: dom-1779440838423
-- Submitted At: 2026-05-22T09:07:18.486Z
SELECT w1.id
FROM Weather w1, Weather w2
WHERE DATEDIFF(w1.recordDate, w2.recordDate) = 1 AND w1.temperature > w2.temperature;
