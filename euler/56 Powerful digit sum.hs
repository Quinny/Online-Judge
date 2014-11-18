ns = [a ^ b | a <- [1..100], b <- [1..100]]
sumDigits x = if x == 0 then 0 else (x `mod` 10) + sumDigits(quot x 10)
sums = [sumDigits x | x <- ns]
ans = maximum sums