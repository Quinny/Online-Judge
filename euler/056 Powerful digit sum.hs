ns = [sumDigits(a ^ b) | a <- [1..100], b <- [1..100]]
sumDigits x = if x == 0 then 0 else (x `mod` 10) + sumDigits(quot x 10)
ans = maximum ns
