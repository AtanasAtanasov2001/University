main :: IO()
main = do
    print (sumOfEvenly 1 10)


isEvenly :: Int -> Bool 
isEvenly x = even (length [ n | n <- [1..x], x `mod` n == 0 ]) 
        
sumOfEvenly :: Int -> Int -> Int
sumOfEvenly a b = sum[n | n <- [a..b], isEvenly n] 


 

