main :: IO()
main = do
    print (sumDigits 122)
    print (persistence 4)


sumDigits :: Int -> Int 
sumDigits 0 = 1
sumDigits x = (x `mod ` 10) * sumDigits (x `div` 10)

persistence :: Int -> (Int, [Int])
persistence n = (length (helper n), helper n)
    where 
        helper :: Int -> [Int]
        helper x = if x < 10 then [x] else helper' x []
            where 
                helper' a xs = if a < 10 then xs else helper' (sumDigits a) (xs ++ [sumDigits a])
                   
        