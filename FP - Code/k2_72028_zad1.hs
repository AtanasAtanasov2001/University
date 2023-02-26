import Data.List
main::IO()

main = do
    print (getIndices [2, 7, 11, 15] 9) 



getIndices :: [Int] -> (Int -> (Int, Int))
getIndices xs = helper n
    where 
        helper ::Int -> (Int,Int)
        helper n 
            |x + y == n = (elemIndex x,elemIndex y)
            |otherwise = ()
                where
                    |x <- xs
                    |y <- xs