main::IO()
main = do
    print 3
    print $ applyEveryKth (* 2) 3 [1..6]
    print $ applyEveryKth (+2) 4 [1..7]


applyEveryKth :: (a -> a) -> Int -> [a] -> [a]
applyEveryKth f k xs = helper k xs
    where
        helper 1 (x:xs) = (f x) : (helper k xs)
        helper k' (x:xs) = x:(helper (k'-1) xs)
        helper k' [] = []

