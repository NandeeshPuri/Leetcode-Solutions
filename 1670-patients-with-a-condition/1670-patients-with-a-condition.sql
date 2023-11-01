# Write your MySQL query statement below
SELECT * 
FROM patients
WHERE conditions REGEXP '\\bDIAB1'
#\b in a normal string means 'backspace' but in regular expression it's a boundary word and we want \b to work as a boundary word NOT AS A backspace, so use \ before \b (\\b) to work it as a special character in regular expression. (This same theory works for MySQL as well)