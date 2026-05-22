-- Problem: 197. Rising Temperature
-- URL: https://leetcode.com/problems/rising-temperature/
-- Language: mysql
-- Submission ID: dom-1779439701681
-- Submitted At: 2026-05-22T08:48:21.714Z
# Solution 1
cnt=0
while read line && [ $cnt -le 10 ]; do
  let 'cnt = cnt + 1'
  if [ $cnt -eq 10 ]; then
    echo $line
    exit 0
  fi
done < file.txt

# Solution 2
awk 'FNR == 10 {print }'  file.txt
# OR
awk 'NR == 10' file.txt

# Solution 3
sed -n 10p file.txt

# Solution 4
tail -n+10 file.txt|head -1
